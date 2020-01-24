#include <math.h>
double tangent;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
tangent = atan(1.0)*180/3.14;
Serial.println(tangent);
}
