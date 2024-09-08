// #define DHTTYPE DHT20
#include "Arduino_SensorKit.h"
#define Environment Environment_I2C



void setup() {
  //uncomment line below if using DHT20
  Wire.begin();
  Serial.begin(9600);
  Environment.begin();
  Pressure.begin();

  Oled.begin();
  Oled.setFlipMode(true);

}

void loop() {
  int temperatur_value = Environment.readTemperature();
  float humidity_value = Environment.readHumidity();
  int altitude_value =  Pressure.readAltitude();

  Serial.print(temperatur_value);
  Serial.println();
  delay(1000);
}