#include <WiFi.h>
#include <ArduinoJson.h>
#include <ArduinoWebsockets.h>

using namespace websockets;

// ============ CONFIGURATION ============
const char* SSID = "Wifi name";          // Change to your Wifi name
const char* PASSWORD = "wifi password"; // Change to your wifi password
const char* SERVER_HOST = "IP server";  // Change to your server IP
const int SERVER_PORT = 3001;

// Device Configuration
const char* DEVICE_NAME = "ESP32-Sensor-01";
const char* DEVICE_VERSION = "1.0.0";

// ============ VARIABLES ============
WebsocketsClient client;
unsigned long lastStatusUpdate = 0;
const unsigned long STATUS_UPDATE_INTERVAL = 5000;  // Send status every 5 seconds
bool wsConnected = false;   // raw WebSocket transport is open

// Socket.IO application-level state — separate from the WS transport.
// The WS can be "open" while Socket.IO itself hasn't finished its handshake yet.
bool sioConnected = false;  // server has ack'd our "40" namespace connect

// Sensor data structure
struct SensorData {
  float temperature;
  int humidity;
  int pressure;
  // Add more sensor fields as needed
};

SensorData sensorData;
unsigned long deviceUptime = 0;

// ============ FUNCTION DECLARATIONS ============
void connectToWiFi();
void initWebSocket();
void onMessageCallback(WebsocketsMessage message);
void onEventsCallback(WebsocketsEvent event, String data);
void registerDevice();
void updateStatus();
void readSensors();
void logMessage(String msg);

// ============ SETUP ============
void setup() {
  Serial.begin(115200);
  delay(1000);

  logMessage("\n\n=== ESP32 Hub Client ===");
  logMessage("Starting setup...");

  // Initialize sensor data
  sensorData.temperature = 0;
  sensorData.humidity = 0;
  sensorData.pressure = 0;

  // Connect to WiFi
  connectToWiFi();

  // Initialize WebSocket
  initWebSocket();

  logMessage("Setup complete!");
}

// ============ LOOP ============
void loop() {
  // Maintain WebSocket connection
  if (WiFi.status() == WL_CONNECTED) {
    if (wsConnected) {
      client.poll();
    } else {
      initWebSocket();
    }
  }

  // Read sensor values
  readSensors();

  // Send status update periodically — only once Socket.IO namespace is actually joined
  if (millis() - lastStatusUpdate > STATUS_UPDATE_INTERVAL && sioConnected) {
    updateStatus();
    lastStatusUpdate = millis();
  }

  // Update uptime
  deviceUptime = millis() / 1000;

  delay(100);  // Small delay to prevent watchdog timeout
}

// ============ WiFi CONNECTION ============
void connectToWiFi() {
  logMessage("Connecting to WiFi: " + String(SSID));

  WiFi.mode(WIFI_STA);
  WiFi.begin(SSID, PASSWORD);

  int attempts = 0;
  while (WiFi.status() != WL_CONNECTED && attempts < 20) {
    delay(500);
    Serial.print(".");
    attempts++;
  }

  if (WiFi.status() == WL_CONNECTED) {
    logMessage("\nWiFi connected!");
    logMessage("IP Address: " + WiFi.localIP().toString());
    logMessage("RSSI: " + String(WiFi.RSSI()) + " dBm");
  } else {
    logMessage("\nFailed to connect to WiFi!");
  }
}

// ============ WEBSOCKET INITIALIZATION ============
void initWebSocket() {
  logMessage("Initializing WebSocket to ws://" + String(SERVER_HOST) + ":" + String(SERVER_PORT));

  // Register callbacks BEFORE connecting
  client.onMessage(onMessageCallback);
  client.onEvent(onEventsCallback);

  bool connected = client.connect(SERVER_HOST, SERVER_PORT, "/socket.io/?EIO=4&transport=websocket");

  if (connected) {
    logMessage("WebSocket transport connect() call succeeded");
  } else {
    logMessage("WebSocket connection failed!");
    wsConnected = false;
    sioConnected = false;
  }
}

// ============ WEBSOCKET MESSAGE HANDLER ============
// This is where Socket.IO's own protocol lives. Engine.IO frames a packet type
// as the FIRST character(s) of the text payload:
//   0 = open (server->client, contains sid/pingInterval/pingTimeout)
//   1 = close
//   2 = ping   (server->client — WE MUST REPLY WITH "3" OR THE SERVER DROPS US)
//   3 = pong   (client->server reply to the above)
//   4 = message (wraps a Socket.IO packet, e.g. "40" = CONNECT ack, "42[...]" = EVENT)
//   6 = noop
// Socket.IO packet types (the char right after the leading "4"):
//   0 = CONNECT ack, 1 = DISCONNECT, 2 = EVENT, 3 = ACK, 4 = ERROR
void onMessageCallback(WebsocketsMessage message) {
  String data = message.data();
  logMessage("Received: " + data);

  if (data.length() == 0) return;

  char engineIoType = data.charAt(0);

  switch (engineIoType) {
    case '0':
      // Engine.IO OPEN packet from server. Session/ping info is in the JSON
      // that follows — not strictly needed here, but this confirms the
      // transport-level handshake is complete. Now ask to join the
      // default Socket.IO namespace.
      client.send("40");
      break;

    case '2':
      // Engine.IO PING from server — must reply immediately with PONG,
      // or the server will consider us dead and close the connection.
      // This missing reply is what causes repeated connect/disconnect cycles.
      client.send("3");
      break;

    case '3':
      // Engine.IO PONG — no action needed (only relevant if we ever send "2" ourselves).
      break;

    case '4':
      // Wraps a Socket.IO-level packet.
      if (data.length() >= 2) {
        char sioType = data.charAt(1);
        if (sioType == '0') {
          // "40..." — server confirmed our namespace connection.
          // Safe to start emitting events now.
          sioConnected = true;
          logMessage("Socket.IO namespace connected");
          registerDevice();
        } else if (sioType == '1') {
          // "41" — server disconnected our namespace.
          sioConnected = false;
          logMessage("Socket.IO namespace disconnected");
        } else if (sioType == '2') {
          // "42[...]" — an EVENT from the server. Hand off to your app logic here.
          logMessage("Event from server: " + data.substring(2));
        } else if (sioType == '4') {
          logMessage("Socket.IO ERROR packet: " + data);
        }
      }
      break;

    default:
      // Unrecognized/engine.io noop etc — ignore
      break;
  }
}

// ============ WEBSOCKET EVENT HANDLER ============
// ArduinoWebsockets uses a flat (event, data) callback signature.
void onEventsCallback(WebsocketsEvent event, String data) {
  if (event == WebsocketsEvent::ConnectionOpened) {
    logMessage("WebSocket transport connected!");
    wsConnected = true;
    // Do NOT send "40" or register here — wait for the server's Engine.IO
    // "0" open packet in onMessageCallback, then send "40" from there.
    // Sending "40" before the server is ready is a common source of the
    // exact same connect/disconnect symptom.
  } else if (event == WebsocketsEvent::ConnectionClosed) {
    logMessage("WebSocket disconnected!");
    wsConnected = false;
    sioConnected = false;
  } else if (event == WebsocketsEvent::GotPing) {
    // WebSocket protocol-level ping (not Socket.IO's "2") — the library
    // answers this automatically at the protocol layer.
    logMessage("Got WS-level ping");
  } else if (event == WebsocketsEvent::GotPong) {
    logMessage("Got WS-level pong");
  }
}

// ============ DEVICE REGISTRATION ============
void registerDevice() {
  if (!sioConnected) return;

  // Get device MAC address for unique ID
  String deviceId = WiFi.macAddress();
  deviceId.replace(":", "");

  // Create JSON registration message
  StaticJsonDocument<256> doc;
  doc["id"] = deviceId;
  doc["name"] = DEVICE_NAME;
  doc["ip"] = WiFi.localIP().toString();
  doc["version"] = DEVICE_VERSION;
  doc["rssi"] = WiFi.RSSI();
  doc["heap"] = ESP.getFreeHeap();
  doc["temperature"] = sensorData.temperature;

  // Send register event using Socket.IO v4 format (4 = message, 2 = EVENT)
  String payload;
  serializeJson(doc, payload);
  String message = "42[\"register\"," + payload + "]";

  client.send(message);
  logMessage("Device registered with ID: " + deviceId);
}

// ============ SEND STATUS UPDATE ============
void updateStatus() {
  if (!sioConnected) {
    // Attempt to reconnect if the WS transport itself dropped
    if (WiFi.status() == WL_CONNECTED && !wsConnected) {
      initWebSocket();
    } else if (WiFi.status() != WL_CONNECTED) {
      connectToWiFi();
    }
    return;
  }

  StaticJsonDocument<256> doc;
  doc["uptime"] = deviceUptime;
  doc["rssi"] = WiFi.RSSI();
  doc["heap"] = ESP.getFreeHeap();
  doc["temperature"] = sensorData.temperature;

  String payload;
  serializeJson(doc, payload);
  String message = "42[\"status:update\"," + payload + "]";

  client.send(message);
}

// ============ READ SENSOR VALUES ============
void readSensors() {
  // Example sensor readings
  // Replace with your actual sensor code

  // Simulated temperature (replace with real sensor reading)
  sensorData.temperature = 25.5 + (random(0, 10) / 10.0);

  // Simulated humidity (replace with real sensor reading)
  sensorData.humidity = 60 + random(0, 20);

  // Simulated pressure (replace with real sensor reading)
  sensorData.pressure = 1013 + random(-5, 5);

  // For real sensors, you would read from I2C/SPI
  // Example DHT22:
  // sensorData.temperature = dht.readTemperature();
  // sensorData.humidity = dht.readHumidity();

  // Example BMP280:
  // sensorData.temperature = bmp.readTemperature();
  // sensorData.pressure = bmp.readPressure() / 100.0F;

  // Example Analog Sensor:
  // int rawValue = analogRead(ADC_PIN);
  // sensorData.temperature = (rawValue / 1023.0) * 3.3;
}

// ============ LOGGING UTILITY ============
void logMessage(String msg) {
  Serial.println("[" + String(millis() / 1000) + "s] " + msg);
}
