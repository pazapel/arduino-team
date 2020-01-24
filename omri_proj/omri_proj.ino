int PMValue0;
int PMValue1;
int ButtonOld = 1;
int ButtonNew = 1;
int ServoState = 0;
#include <Servo.h>

Servo pitch;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(2, INPUT_PULLUP);
pinMode(10, OUTPUT);
pitch.attach(10);
}

void loop() {
  // put your main code here, to run repeatedly:
  PMValue0 = map(analogRead(A1), 0, 1023, 0, 180);
  PMValue1 = map(analogRead(A2), 0, 1023, 0, 180);
  ButtonNew = digitalRead(2);

  Serial.print(ButtonNew);
  Serial.print("\t");
  Serial.print(PMValue0);
  Serial.print("\t");
  Serial.println(PMValue1);

  
  if(ButtonOld == 0 and ButtonNew == 1) {
    Serial.println("Button Was Pushed");
    Serial.println(ServoState);
    ServoState = 1 - ServoState;   
  }
  
  if(ServoState == 0){
    pitch.write(PMValue0);  
  }
  else{
    pitch.write(PMValue1); 
  }
  ButtonOld = ButtonNew; 
  delay(1);        
}
