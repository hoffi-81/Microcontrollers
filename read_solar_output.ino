const int fanTachPin = 2; // Pin to which the tachometer signal is connected (GPIO2 for ESP8266, GPIO2 for ESP32)
volatile unsigned long fanPulseCount = 0; // Count of pulses from the fan
unsigned long previousMillis = 0;
const unsigned long interval = 1000; // Interval at which to calculate RPM

void setup() {
  Serial.begin(115200);
  pinMode(fanTachPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(fanTachPin), fanPulseCounter, FALLING);
}

void loop() {
  unsigned long currentMillis = millis();
  
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    // Convert pulse count to RPM
    unsigned long rpm = (fanPulseCount / 2) * (60000 / interval);
    
    // Print RPM to Serial Monitor
    Serial.print("Fan Speed: ");
    Serial.print(rpm);
    Serial.println(" RPM");

    // Reset pulse count for the next interval
    fanPulseCount = 0;
  }
}

void fanPulseCounter() {
  fanPulseCount++;
}
