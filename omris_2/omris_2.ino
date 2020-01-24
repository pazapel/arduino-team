int PMValue0;
int PMValue1;
int ButtonOld = 1;
int ButtonNew = 1;
int ServoState = 0;
int count;
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

    
    pitch.write(69);  
    delay(2000);
    pitch.write(30); 
    delay(2000);    
    Serial.println(count);
    count++; 
}
