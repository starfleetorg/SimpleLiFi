String stringToSend = "";
String charToSend = "";
int bitLength = 0;
int bitCursor = 0;
int bufferLength = 0;
int bufferCursor = 1;

int bufferLengthPreset = 8;
int startBitTiming = 10;
int dataBitTiming = 50;
int disconnectTiming = 500;

void setup() {
  Serial.begin(115200);
  Serial.print("Transmitter online, buffer length: ");
  Serial.println(bufferLengthPreset);
  pinMode(13,OUTPUT);

}

void loop() {
  if (Serial.available()) {
    stringToSend = Serial.readStringUntil("\n"); // Read data and give feedback
    bitLength = stringToSend.length();
    Serial.print("Data length in bits: ");
    Serial.println(bitLength - 1);
    Serial.print("Data length in buffers: ");
    bufferLength = (bitLength - 1)/8;
    Serial.println(bufferLength);
    Serial.println("Transmission begin...");

    while (bitCursor < bitLength - 1) {
      digitalWrite(13,1); // Start bit
      delay(startBitTiming);
      digitalWrite(13,0);
      
      Serial.print("Data transmitted: ");
      while (bitCursor < bufferCursor * bufferLengthPreset) { // Transmitting bit by bit to transmitte the entire buffer
        charToSend = stringToSend.charAt(bitCursor);
        digitalWrite(13, charToSend.toInt());
        Serial.print(charToSend.toInt());
        delay(dataBitTiming);
        bitCursor = bitCursor + 1;
      }

      digitalWrite(13,0); // Preparing for the next buffer
      Serial.println(" One buffer done, disconnecting");
      bufferCursor = bufferCursor + 1;
      delay(disconnectTiming);
    }

    digitalWrite(13,0); // Reset
    bufferCursor = 1;
    bitCursor = 0;
    Serial.println("");
    Serial.print("Transmitter online, buffer length: ");
    Serial.println(bufferLengthPreset);
  }
}
