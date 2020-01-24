  unsigned long currentTime;
  unsigned long previousTime;
  float PMValue0;
  float PMValue1;
  float PMValue2;
  float LEDsituation10;
  float LEDsituation11;
  float Color0;
  float Color1;
  float Out10;
  float Out11;
  
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(10, OUTPUT);
pinMode(11, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  map(PMValue1, 0, 1023, 0, 255);

  PMValue0 = analogRead(A0);
  Serial.print("\t" "PMValue0=");
  Serial.print(PMValue0);

  PMValue1 = analogRead(A1);
  Serial.print("\t" "PMValue1= ");
  Serial.print(PMValue1);

  PMValue0 = analogRead(A2);
  Serial.print("\t" "PMValue2= ");
  Serial.print(PMValue2);

  
  currentTime = millis();
  Serial.print("\t" "currentTime= ");
  Serial.println(currentTime);

  Color0 = (PMValue2 / 1023);
  Color1 = ((1023 - PMValue2) / 1023);
  Out10 = (Color0 * PMValue1);
  Out11 = (Color1 * PMValue1);
 
  if (currentTime - previousTime >= PMValue0) {
    analogWrite(10, Out10 - LEDsituation10);
    analogWrite(11, Out11 - LEDsituation11);
    LEDsituation10 = Out10 - LEDsituation10;
    LEDsituation11 = Out11 - LEDsituation11;
//    Serial.print("LEDsituation= ");
//    Serial.println(LEDsituation);
     previousTime = millis();
  }

  
}
