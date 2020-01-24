double RobotAngle;

double toArcTangent;

double DISbetweenSENS=5;


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
toArcTangent = ((8-3) / DISbetweenSENS);

RobotAngle= (atan(toArcTangent)*180/3.14159265359);

Serial.println(RobotAngle);
}
