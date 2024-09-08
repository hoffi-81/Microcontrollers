#define button 4     // connect button to D4
#define LED 6
#include <IRremote.h>



int button_state = 0;         // variable for reading the pushbutton status
 
void setup() {
    Serial.begin(9600);
    // initialize the pushbutton pin as an input:
    pinMode(button, INPUT);
    pinMode(LED,OUTPUT);
    
}
 
void loop() {
  // Check if the button is pressed
  if (digitalRead(buttonPin) == HIGH) {
    // Turn on the IR LED
    digitalWrite(irLedPin, HIGH);

    // Send the IR signal to turn on the Hi-Fi system
    irSender.sendNEC(irCode, 32);

    // Print message to serial monitor for debugging
    Serial.println("Hi-Fi system turned on.");

    // Wait for a moment to debounce the button
    delay(500);

    // Turn off the IR LED
    digitalWrite(irLedPin, LOW);
  }
}