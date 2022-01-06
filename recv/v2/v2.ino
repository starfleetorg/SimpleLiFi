int bufferLength = 8;

void setup() {
  pinMode(13, INPUT);
  Serial.begin(115200);
  Serial.println("Recv mode");
}

void loop() {
  if (!digitalRead(13) == 1) {
    delay(50);
    for (int inc = 0; inc < bufferLength; inc ++) {
      Serial.print(!digitalRead(13));
      delay(100);
    }
    Serial.print(" ");
  }
}
