uint32_t chipId = 0;

void setup() {
  Serial.begin(115200);
}

void loop() {
  Serial.println("AT+CDKEY=E58A21088E53774C480E2E56EC4DDA3A");
  delay(3000);
}



// 10057864
// ec:64:c9:99:78:88
// 100578647888
// 10057864C999



// 4C8199C964EC