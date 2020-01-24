
int PMValue;
 
void setup() {
  // put your setup code here, to run once:
pinMode(10, OUTPUT);
pinMode(11, OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  PMValue =  analogRead(A2);
  Serial.println(PMValue);
  analogWrite(10, PMValue / 4.1);
  analogWrite(11, 1023 - (PMValue / 4.1));
}
