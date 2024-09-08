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

  Oled.setFont(u8x8_font_chroma48medium8_r); 
  Oled.setCursor(0, 0);    
  
  Oled.println("Temperatur: ");   
  Oled.print(temperatur_value);
  Oled.println("°C");  

  Oled.println("Feuchtigkeit: ");
  Oled.print(humidity_value);
  Oled.println("%");

   .println("Hoehe: ");
  Oled.print(altitude_value);
  Oled.println("m");

  Oled.refreshDisplay();    

  Serial.print(temperatur_value);
  Serial.println();
  delay(1000);
}