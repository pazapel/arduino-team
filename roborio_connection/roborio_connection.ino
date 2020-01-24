void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  static const byte magic_value = 'p';
  if(Serial.available()) {
    byte value = Serial.read();
    digitalWrite(13, HIGH);
    if (value == magic_value) {
      Serial.println("Works Bro!");
    }
  }
  delay(50);
}
