#include <Servo.h>

int yPin = A0;
int xPin = A3;
int sPin = 6;
int servo1Pin = A1;
int servo2Pin = A2;
int anglex = 0;
int angley = 0;
int dt = 50;
int upside;
int xv;
int yv;
int downside;

Servo s1;
Servo s2;

void setup() {
  
  pinMode(xPin, INPUT);
  pinMode(sPin, INPUT);
  pinMode(yPin, INPUT);

  s1.attach(servo1Pin);
  s2.attach(servo2Pin);
  
  digitalWrite(sPin, HIGH);
  Serial.begin(9600);
}

void loop() {
  xv = analogRead(xPin);
  yv = analogRead(yPin);
  
  if (xv > 522){
  anglex += xv * (5./502.); 
  delay(dt);
  } 
  if (xv < 502){
    upside = xv - 512;
    anglex += upside * (5./522.);
    delay(dt);
    }
  if (anglex >= 180){
      anglex = 180;
      }
  if (anglex <= 0){
        anglex = 0;
        } 
  if(xv > 530 && xv < 490){
      anglex = anglex;
    }
    if (yv > 522){
  angley += yv * (5./502.); 
  delay(dt);
  } 
  if (yv < 502){
    downside = yv - 512;
    angley += downside * (5./522.);
    delay(dt);
    }
  if (angley >= 180){
      angley = 180;
      }
  if (angley <= 0){
        angley = 0;
        } 
  if(yv > 530 && yv < 490){
      angley = angley;
    }
  
  Serial.println(anglex);
  s1.write(anglex);
  s2.write(angley);
}
