void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
//pinMode(13, OUTPUT);
//digitalWrite(13, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long currentTime = millis();
  delay(100);

    Serial.println (currentTime);

  unsigned long previousTime = millis();
  currentTime = millis();
  delay(100);
  
}
