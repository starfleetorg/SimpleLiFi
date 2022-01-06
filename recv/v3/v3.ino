int bufferLength = 8;
int startBitTiming = 15;
int dataBitTiming = 50;
int delayTiming = 500;


void setup() {
  pinMode(13, INPUT);
  Serial.begin(115200);
  Serial.println("Recv mode");
}

void loop() {
  if (!digitalRead(13) == 1) {
    delay(startBitTiming);
    for (int inc = 0; inc < bufferLength; inc ++) {
      Serial.print(!digitalRead(13));
      delay(dataBitTiming);
    }
    Serial.print(" ");
  }
}
