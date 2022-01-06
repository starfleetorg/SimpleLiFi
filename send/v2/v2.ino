String stringToSend = "";
String charToSend = "";
int dataLength = "";

int bufferLength = 8;

void setup() {
  Serial.begin(115200);
  Serial.print("Transmitter online, buffer length: ");
  Serial.println(bufferLength);
  pinMode(13,OUTPUT);

}

void loop() {
  if (Serial.available()) {
    stringToSend = Serial.readStringUntil("\n"); // Read data and give feedback
    dataLength = stringToSend.length();
    Serial.print("Data length: ");
    Serial.println(dataLength - 1);
    Serial.println("Transmission begin...");

    if (dataLength - 1 > bufferLength) { // Buffer overflow detection
      Serial.print("Warning! buffer overflow, only the first ");
      Serial.print(bufferLength);
      Serial.println(" characters will be transmitted");
    }
    
    digitalWrite(13,1); // Start bit
    delay(10);
    digitalWrite(13,0);
    
    Serial.print("Data transmitted: ");
    for (int inc = 0; inc < bufferLength; inc ++) { // Transmitting bit by bit
      charToSend = stringToSend.charAt(inc);
      digitalWrite(13, charToSend.toInt());
      Serial.print(charToSend.toInt());
      delay(100);
    }
    
    digitalWrite(13,0); // Reset
    Serial.println("");
    Serial.print("Transmitter online, buffer length: ");
    Serial.println(bufferLength);
  }
}
