// Smart Pump Monitoring System

#define TEMP_PIN 34
#define VIB_PIN 35
#define CURR_PIN 32
#define FLOW_PIN 33
#define RELAY_PIN 25

int temp, vibration, current, flow;

void setup() {
  Serial.begin(115200);
  
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, HIGH); // Pump ON initially
}

void loop() {
  // Simulated sensor readings
  temp = analogRead(TEMP_PIN);
  vibration = analogRead(VIB_PIN);
  current = analogRead(CURR_PIN);
  flow = analogRead(FLOW_PIN);

  Serial.println("---- Pump Status ----");
  Serial.print("Temp: "); Serial.println(temp);
  Serial.print("Vibration: "); Serial.println(vibration);
  Serial.print("Current: "); Serial.println(current);
  Serial.print("Flow: "); Serial.println(flow);

  bool fault = false;

  // Simple thresholds (adjust in simulation)
  if (temp > 2500) {
    Serial.println("⚠️ Overheating Detected!");
    fault = true;
  }

  if (vibration > 2500) {
    Serial.println("⚠️ High Vibration!");
    fault = true;
  }

  if (current > 2500) {
    Serial.println("⚠️ Overcurrent!");
    fault = true;
  }

  if (flow < 1000) {
    Serial.println("⚠️ Dry Run (No Flow)!");
    fault = true;
  }

  if (fault) {
    digitalWrite(RELAY_PIN, LOW); // Turn OFF pump
    Serial.println("🚨 Pump Turned OFF!");
  } else {
    digitalWrite(RELAY_PIN, HIGH); // Pump ON
    Serial.println("✅ Pump Running Normally");
  }

  delay(2000);
}
