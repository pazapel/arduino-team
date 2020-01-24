  unsigned long currentTime;
  unsigned long previousTime;
  int PMValue;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(10, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  PMValue = analogRead(A0);
  Serial.println("PMValue");
  Serial.println(PMValue);
  //map(PMValue, 0, 1023, 0, 255);
  analogWrite(10, PMValue / 4.1);
  
  currentTime = millis();
  Serial.println("currentTime");
  Serial.println(currentTime);

  }
  
