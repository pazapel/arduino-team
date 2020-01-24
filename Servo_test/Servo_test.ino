int S = 1;
void setup() {
  // put your setup code here, to run once:
pinMode(10, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
S = S + 10;
analogWrite(10, S);
Serial.println(S);
delay(1000);
}
