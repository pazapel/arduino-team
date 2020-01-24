unsigned long currentTime;
unsigned long previousTime;
int DIP1;
int DIP2;
int DIP3;
int DIP4;
int DIPAll;
int LEDsituation0;
int LEDsituation1;
int LEDsituation2;
int PTValue0;
int PTValue1;
int ButtonOld;
int ButtonNew;
#include <Wire.h>
#include <VL53L0X.h>
VL53L0X sensor;

void setup() {
  // put your setup code here, to run once:
  
  //PIN stuff;
  
  Serial.begin(9600);
  pinMode(2, OUTPUT); // LED
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(7, INPUT);
  pinMode(9,  INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  pinMode(11, INPUT_PULLUP);
  pinMode(12, INPUT_PULLUP);

  //RNG begin stiff;
  
  Wire.begin();

  sensor.setTimeout(500);
  if (!sensor.init())
  {
    Serial.println("Failed to detect and initialize sensor!");
    while (1) {}
  }

  // Start continuous back-to-back mode (take readings as
  // fast as possible).  To use continuous timed mode
  // instead, provide a desired inter-measurement period in
  // ms (e.g. sensor.startContinuous(100)).
  sensor.startContinuous();
}

void loop() {
  // put your main code here, to run repeatedly:
  
  //DIP stuff;

  Serial.print("DIP1-4= ");
  DIP1 = digitalRead(9);
  //Serial.print(DIP1);

  DIP2 = digitalRead(10);
  //Serial.print(DIP2);

  DIP3 = digitalRead(11);
  //Serial.print(DIP3);

  DIP4 = digitalRead(12);
  
  DIPAll = DIP1+DIP2+DIP3+DIP4;
  Serial.print(DIPAll);
  Serial.print("\t");

  //PT stuff;
  
  PTValue0 = analogRead(A0);
  Serial.print("PTValue0= ");
  Serial.print(PTValue0);
  Serial.print("\t");
  /*if(PTValue0 > 300) {
    Serial.print("BLACK");
    Serial.print("\t");
  }else{
    Serial.print("WHITE");
    Serial.print("\t");
  }*/

  PTValue1 = analogRead(A1);
  Serial.print("PTValue1= ");
  Serial.print(PTValue1);
  Serial.print("\t");
  /*if(PTValue1 > 300) {
    Serial.print("BLACK");
    Serial.print("\t");
  }else{
    Serial.print("WHITE");
    Serial.print("\t");
  }*/

  //LED stuff;
  
  currentTime = millis();
  if (currentTime - previousTime >= 1000) {
    analogWrite(2, 1 - LEDsituation0);
    LEDsituation0 = 1 - LEDsituation0;
//    Serial.print("LEDsituation0= ");
//    Serial.println(LEDsituation0);
  }


  if (currentTime - previousTime >= 2000) {
    analogWrite(3, 1 - LEDsituation1);
    LEDsituation1 = 1 - LEDsituation1;
//    Serial.print("LEDsituation1= ");
//    Serial.println(LEDsituation1);
  }

  
if (currentTime - previousTime >= 3000) {
    analogWrite(4, 1 - LEDsituation2);
    LEDsituation2 = 1 - LEDsituation2;
//    Serial.print("LEDsituation2= ");
//    Serial.println(LEDsituation2);
    previousTime = millis();
  }


  //PB stuff;
  
  ButtonNew = digitalRead(7);
  //Serial.println(ButtonNew);
  if(ButtonOld == 0 and ButtonNew == 1) {
    Serial.println("Button Was Pushed");
  }
    ButtonOld = ButtonNew;   
    delay(1);


  //RNG void stuff;
    
  Serial.print("RNGValue= ");
  Serial.print(sensor.readRangeContinuousMillimeters());
  if (sensor.timeoutOccurred()) { Serial.print(" TIMEOUT"); }

  Serial.println();
}
