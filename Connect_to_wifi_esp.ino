#include <WiFi.h>

// Replace with your own network credentials
const char* ssid = "bibi";
const char* password = "40623745482941825812";
const int ledPin = 2;


void setup(){
  Serial.begin(115200);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  // Serial.println("\nConnecting to WiFi Network ..");
  pinMode(ledPin, OUTPUT);
  while(WiFi.status() != WL_CONNECTED){
      // Serial.print(".");
      // delay(100);
      digitalWrite(ledPin, HIGH);
      delay(500);
      digitalWrite(ledPin, LOW);
  }

  digitalWrite(ledPin, HIGH);
  // Serial.println("\nConnected to the WiFi network");
  // Serial.print("Local ESP32 IP: ");
  Serial.println(WiFi.localIP());
}
 
void loop(){
    // Do Nothing
}