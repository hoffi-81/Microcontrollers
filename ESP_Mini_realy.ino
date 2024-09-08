const int Relais = 5; //rael pin is 1

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(Relais, OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(Relais, HIGH);
  Serial.println("Relay closed");
  delay(1000);
  digitalWrite(Relais, LOW);
  Serial.println("Relay open");
  delay(1000);


}
