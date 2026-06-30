/*
  ============================================================
  SilentGuard - INMP441 Microphone TEST sketch
  ============================================================
  Purpose:
    Standalone test for the INMP441 I2S microphone ONLY.
    No LEDs, no motor - just verifies that:
      - I2S is wired and initialized correctly
      - Raw RMS responds to sound
      - EMA filtering smooths it
      - 5-second auto calibration captures a sensible baseline

  Wiring (INMP441 -> ESP32):
    VDD -> 3.3V
    GND -> GND
    L/R -> GND   (selects left channel)
    WS  -> GPIO25
    SD  -> GPIO22
    SCK -> GPIO26

  Open Serial Monitor at 115200 baud.
  Stay quiet during the first 5 seconds (calibration), then
  talk / clap / make noise and watch the RMS values change.
  ============================================================
*/

#include <driver/i2s.h>
#include <math.h>

// ------------------------------------------------------------
// I2S pin configuration
// ------------------------------------------------------------
#define I2S_WS   25
#define I2S_SD   22
#define I2S_SCK  26

#define NUM_SAMPLES 512
int32_t samples[NUM_SAMPLES];

// ------------------------------------------------------------
// EMA filter state
// ------------------------------------------------------------
float filteredRMS  = 0;
bool  firstReading = true;

// ------------------------------------------------------------
// Calibration state
// ------------------------------------------------------------
#define CALIBRATION_TIME 5000   // 5 seconds, ms

float baseline = 0;
bool  calibrated = false;
bool  firstCalibrationReading = true;
unsigned long calibrationStart;


// ============================================================
//  SETUP
// ============================================================
void setup() {
  Serial.begin(115200);

  setupI2S();

  calibrationStart = millis();

  Serial.println("--------------------------------");
  Serial.println("SilentGuard - INMP441 Mic Test");
  Serial.println("Calibrating for 5 seconds...");
  Serial.println("Please keep the room quiet.");
  Serial.println("--------------------------------");
}


// ============================================================
//  MAIN LOOP
// ============================================================
void loop() {
  float rms = readAndFilterRMS();

  if (!calibrated) {
    runCalibrationStep();
    delay(100); // only used during the one-time calibration phase
    return;
  }

  // -------- Normal operation: just print live readings --------
  Serial.print("Raw RMS = ");
  Serial.print(rms);

  Serial.print("   Filtered RMS = ");
  Serial.print(filteredRMS);

  Serial.print("   Baseline = ");
  Serial.println(baseline);

  delay(200);
}


// ============================================================
//  I2S INIT
// ============================================================
void setupI2S() {
  i2s_config_t i2s_config = {
    .mode = (i2s_mode_t)(I2S_MODE_MASTER | I2S_MODE_RX),
    .sample_rate = 16000,
    .bits_per_sample = I2S_BITS_PER_SAMPLE_32BIT,
    .channel_format = I2S_CHANNEL_FMT_ONLY_LEFT,
    .communication_format = I2S_COMM_FORMAT_I2S,
    .intr_alloc_flags = ESP_INTR_FLAG_LEVEL1,
    .dma_buf_count = 8,
    .dma_buf_len = 64,
    .use_apll = false,
    .tx_desc_auto_clear = false,
    .fixed_mclk = 0
  };

  i2s_pin_config_t pin_config = {
    .bck_io_num = I2S_SCK,
    .ws_io_num = I2S_WS,
    .data_out_num = I2S_PIN_NO_CHANGE,
    .data_in_num = I2S_SD
  };

  i2s_driver_install(I2S_NUM_0, &i2s_config, 0, NULL);
  i2s_set_pin(I2S_NUM_0, &pin_config);
}


// ============================================================
//  READ MIC + COMPUTE RMS + APPLY EMA FILTER
//  Returns the raw (unfiltered) RMS of this block, while also
//  updating the global filteredRMS.
// ============================================================
float readAndFilterRMS() {
  size_t bytesRead;

  i2s_read(
    I2S_NUM_0,
    samples,
    sizeof(samples),
    &bytesRead,
    portMAX_DELAY
  );

  double sum = 0;
  for (int i = 0; i < NUM_SAMPLES; i++) {
    float x = samples[i] / 1024.0;
    sum += x * x;
  }

  float rms = sqrt(sum / NUM_SAMPLES);

  // Exponential Moving Average filter
  if (firstReading) {
    filteredRMS = rms;
    firstReading = false;
  } else {
    filteredRMS = 0.8 * filteredRMS + 0.2 * rms;
  }

  return rms;
}


// ============================================================
//  ONE STEP OF AUTO CALIBRATION
//  Tracks the minimum filteredRMS seen during the calibration
//  window as the "quiet room" baseline.
// ============================================================
void runCalibrationStep() {
  if (firstCalibrationReading) {
    baseline = filteredRMS;
    firstCalibrationReading = false;
  }

  if (filteredRMS < baseline) {
    baseline = filteredRMS;
  }

  Serial.print("Calibrating... RMS = ");
  Serial.print(filteredRMS);
  Serial.print("   Baseline = ");
  Serial.println(baseline);

  if (millis() - calibrationStart >= CALIBRATION_TIME) {
    calibrated = true;

    Serial.println();
    Serial.println("===== CALIBRATION COMPLETE =====");
    Serial.print("Baseline RMS = ");
    Serial.println(baseline);
    Serial.println("=================================");
    Serial.println();
  }
}
