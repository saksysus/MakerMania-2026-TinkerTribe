#include <driver/i2s.h>
#include <math.h>

// I2S / Microphone configuration  (UNCHANGED from original)
#define I2S_WS   25
#define I2S_SD   22
#define I2S_SCK  26

#define NUM_SAMPLES 512
int32_t samples[NUM_SAMPLES];

float filteredRMS  = 0;
bool  firstReading = true;
// Calibration configuration  (UNCHANGED logic from original)

#define CALIBRATION_TIME 5000   // 5 seconds, ms
float baseline = 0;
#define NUM_LEDS 6

const int ledPins[NUM_LEDS] = {
  13,  // 0: GREEN_1
  12,  // 1: GREEN_2
  14,  // 2: YELLOW_1
  27,  // 3: YELLOW_2
  33,  // 4: RED_1
  32   // 5: RED_2  (last LED - "maximum" level)
};

const char* ledNames[NUM_LEDS] = {
  "GREEN_1", "GREEN_2", "YELLOW_1", "YELLOW_2", "RED_1", "RED_2"
};

// Motor vibration pin

#define MOTOR_PIN 4
// Per-LED thresholds = baseline + offset.
// Offsets widen as level increases (same reasoning as before:
// loudness perception isn't linear, so higher levels need a
// bigger jump to avoid flickering between adjacent LEDs).
// The LAST offset (32000) is intentionally kept the same value
// the old RED_THRESHOLD used, so the motor still triggers at
// the same real-world loudness as before.
const float LED_OFFSETS[NUM_LEDS] = {
  3000,    // GREEN_1
  7000,    // GREEN_2
  12000,   // YELLOW_1
  18000,   // YELLOW_2
  25000,   // RED_1
  32000    // RED_2 (loudest - matches old RED_THRESHOLD)
};

float ledThresholds[NUM_LEDS]; // computed once, after calibration

// Current LED level: 0 = nothing lit, NUM_LEDS = fully lit
int currentLevel = 0;
// Motor state machine

  MOTOR_IDLE,        // bar not fully lit, motor off
  MOTOR_CONFIRMING,  // bar just became fully lit, timing how long it persists
  MOTOR_VIBRATING,   // motor is currently ON
  MOTOR_COOLDOWN     // motor just finished a pulse, short rest before re-checking
};

MotorState motorState = MOTOR_IDLE;

unsigned long redConfirmStartTime = 0;   // when the bar first became fully lit
unsigned long motorOnStartTime    = 0;   // when motor was switched ON
unsigned long motorCooldownStart  = 0;   // when the cooldown period began

const unsigned long RED_CONFIRM_TIME    = 1000; // ms - bar must stay fully lit this long before vibrating
const unsigned long MOTOR_ON_TIME       = 2000; // ms - vibration burst length
const unsigned long MOTOR_COOLDOWN_TIME = 1000; // ms - rest between bursts while still fully lit

// Debug print throttling (avoid flooding Serial every ~32 ms,
// since one I2S read of 512 samples @16kHz takes about that long)

const unsigned long DEBUG_PRINT_INTERVAL = 300; // ms
unsigned long lastDebugPrintTime = 0;


void setup() {
  Serial.begin(115200);

  setupPins();
  setupI2S();

  Serial.println("--------------------------------");
  Serial.println("SilentGuard - Smart Study Monitor");
  Serial.println("Calibrating for 5 seconds...");
  Serial.println("Please keep the room quiet.");
  Serial.println("--------------------------------");

  runCalibration();
  computeThresholds();

  Serial.println();
  Serial.println("===== CALIBRATION COMPLETE =====");
  Serial.print("Baseline RMS = "); Serial.println(baseline);
  for (int i = 0; i < NUM_LEDS; i++) {
    Serial.print(ledNames[i]);
    Serial.print(" turns on above  ");
    Serial.println(ledThresholds[i]);
  }
  Serial.println("=================================");
  Serial.println();
}

//  MAIN LOOP

void loop() {
  // 1. Acquire one block of audio and update the filtered RMS.
  //    i2s_read() blocks until 512 samples are ready (~32 ms
  //    at 16 kHz). That natural cadence paces the whole loop,
  //    so no extra delay() is needed here.
  readAndFilterRMS();

  // 2. Work out how many LEDs (0..6) should be lit.
  currentLevel = computeLedLevel(filteredRMS);

  // 3. Light the LEDs as a bar graph, one after another.
  updateLEDs(currentLevel);

  // 4. Run the motor state machine (non-blocking, millis() based).
  updateMotor(currentLevel);

  // 5. Periodically print debug info.
  printDebugInfo();
}

//  PIN SETUP

void setupPins() {
  for (int i = 0; i < NUM_LEDS; i++) {
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], LOW); // all LEDs off at boot
  }

  pinMode(MOTOR_PIN, OUTPUT);
  digitalWrite(MOTOR_PIN, LOW); // motor off at boot
}


//  I2S INIT  (UNCHANGED from original working code)

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

void runCalibration() {
  unsigned long calibrationStart = millis();
  bool firstCalibrationReading = true;

  while (millis() - calibrationStart < CALIBRATION_TIME) {

    readAndFilterRMS(); // updates global filteredRMS

    if (firstCalibrationReading) {
      baseline = filteredRMS;
      firstCalibrationReading = false;
    }

    // Track the quietest reading seen - this becomes our
    // "silent room" noise floor.
    if (filteredRMS < baseline) {
      baseline = filteredRMS;
    }

    Serial.print("Calibrating... RMS = ");
    Serial.print(filteredRMS);
    Serial.print("   Baseline = ");
    Serial.println(baseline);
  }
}

void computeThresholds() {
  for (int i = 0; i < NUM_LEDS; i++) {
    ledThresholds[i] = baseline + LED_OFFSETS[i];
  }
}
void readAndFilterRMS() {
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
}


int computeLedLevel(float rms) {
  int level = 0;
  for (int i = 0; i < NUM_LEDS; i++) {
    if (rms > ledThresholds[i]) {
      level = i + 1; // LEDs are 1-indexed in terms of "count lit"
    }
  }
  return level;
}


// ============================================================
//  LED CONTROL - bar graph: LEDs 1..level are ON, the rest OFF
// ============================================================
void updateLEDs(int level) {
  for (int i = 0; i < NUM_LEDS; i++) {
    digitalWrite(ledPins[i], (i < level) ? HIGH : LOW);
  }
}


void updateMotor(int level) {
  unsigned long now = millis();
  bool fullyLit = (level >= NUM_LEDS); // true only when the LAST LED (RED_2) is on

  switch (motorState) {

    case MOTOR_IDLE:
      if (fullyLit) {
        redConfirmStartTime = now;
        motorState = MOTOR_CONFIRMING;
      }
      break;

    case MOTOR_CONFIRMING:
      if (!fullyLit) {
        // Dropped before 1s elapsed -> short, harmless sound. Ignore.
        motorState = MOTOR_IDLE;
      } else if (now - redConfirmStartTime >= RED_CONFIRM_TIME) {
        digitalWrite(MOTOR_PIN, HIGH);
        motorOnStartTime = now;
        motorState = MOTOR_VIBRATING;
      }
      break;

    case MOTOR_VIBRATING:
      if (now - motorOnStartTime >= MOTOR_ON_TIME) {
        digitalWrite(MOTOR_PIN, LOW);
        motorCooldownStart = now;
        motorState = MOTOR_COOLDOWN;
      }
      break;

    case MOTOR_COOLDOWN:
      if (now - motorCooldownStart >= MOTOR_COOLDOWN_TIME) {
        if (fullyLit) {
          digitalWrite(MOTOR_PIN, HIGH);
          motorOnStartTime = now;
          motorState = MOTOR_VIBRATING;
        } else {
          motorState = MOTOR_IDLE;
        }
      }
      break;
  }
}


void printDebugInfo() {
  unsigned long now = millis();
  if (now - lastDebugPrintTime < DEBUG_PRINT_INTERVAL) {
    return;
  }
  lastDebugPrintTime = now;

  Serial.print("Filtered RMS: ");
  Serial.println(filteredRMS);

  Serial.print("Baseline: ");
  Serial.println(baseline);

  Serial.print("LED Level: ");
  Serial.print(currentLevel);
  Serial.print(" / ");
  Serial.print(NUM_LEDS);
  Serial.print("  (");
  Serial.print(currentLevel == 0 ? "none" : ledNames[currentLevel - 1]);
  Serial.println(")");

  Serial.println();
}