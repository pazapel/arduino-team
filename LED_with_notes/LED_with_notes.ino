  unsigned long currentTime;
  unsigned long previousTime;
  int PMValue;
  int LEDsituation;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(13, OUTPUT);
//digitalWrite(13, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:

/*
  if (millis()<1000) {
    currentTime = 0;
    previousTime = 0;
    PMValue = 0;
    LEDsituation = 0;
  }
*/
  currentTime = millis();
//  Serial.println (PMValue);
 // Serial.println("currentTime");
  //Serial.println(currentTime);

  /*digitalWrite(13, HIGH);
  delay(1023 - PMValue);
  digitalWrite(13, LOW);
  delay(1023 - PMValue);*/
  
  
  if (currentTime - previousTime >= 1000) {
    Serial.println("AAAA");
//    Serial.println(LEDsituation);
    digitalWrite(13, 1 - LEDsituation);
    LEDsituation = 1 - LEDsituation;
    previousTime = millis();
    Serial.println("LEDsituation");
    Serial.println(LEDsituation);
  }

/*  
  if (currentTime - previousTime >= 1000) {
    Serial.println("AAAA");
    Serial.println(LEDsituation);
    if (LEDsituation == 1) {
      Serial.println("BBBBB");
      digitalWrite(13, LOW);
      LEDsituation = 0;
    }
    else {
      Serial.println("CCCCC");
      digitalWrite(13, HIGH);
      LEDsituation = 1;
      Serial.println(LEDsituation);
    }
    previousTime = millis();
  }
*/  
  
}
