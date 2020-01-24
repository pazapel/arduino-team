

#include <Servo.h>

Servo pitch;
Servo yaw;

int Ppos = 0;
int Ypos = 0; 

void setup() {
  Serial.begin(9600);
  pitch.attach(10);
  yaw.attach(11);
}

void loop() {


  
  for (Ppos = 0; Ppos <= 180; Ppos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    Serial.println(Ppos);
    pitch.write(Ppos);
    delay(20);                      
  }
  for (Ppos = 180; Ppos >= 0; Ppos -= 1) {
    Serial.println(Ppos);
    pitch.write(Ppos);                           
    delay(20);                       
  }


  
  for (Ypos = 0; Ypos <= 180; Ypos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    Serial.println(Ypos);
    yaw.write(Ypos);
    delay(20);                      
  }
  for (Ypos = 180; Ypos >= 0; Ypos -= 1) {
    Serial.println(Ypos);
    yaw.write(Ypos);                           
    delay(20);                       
  }
}
