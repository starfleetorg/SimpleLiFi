String testString = "01100001";
String charToSend = "";

void setup() {
  Serial.begin(9600);
  Serial.println("Binary data to send: ");
  pinMode(13,OUTPUT);



  digitalWrite(13,1); // Start bit
  delay(10);
  digitalWrite(13,0);

  for (int inc = 0; inc < 8; inc ++) {
    charToSend = testString.charAt(inc);
    digitalWrite(13, charToSend.toInt());
    Serial.println(charToSend.toInt());
    delay(100);
  }
  digitalWrite(13,0);
}

void loop() {
}
