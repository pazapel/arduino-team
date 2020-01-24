int PTValue0;
int PTValue1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  PTValue0 = analogRead(A0);
  PTValue1 = analogRead(A1);
  /*Serial.print(PTValue0 "\t");
  Serial.print(PTValue1 "\t");*/
  if (0>PTValue1>20){
    Serial.print("Range 1 "); 
  }
  else if (20>PTValue1>40){
    Serial.print("Range 2 "); 
  }
  else if (40>PTValue1>60){
    Serial.print("Range 3 "); 
  }
  else if (60>PTValue1>80){
    Serial.print("Range 4 "); 
  }
  else if (80>PTValue1>100){
    Serial.print("Range 5 "); 
  }
  else{
    Serial.print("NOT A SLOT "); 
  }
  if(PTValue0 > 200) {
    Serial.println("YELLOW");
  }else{
    Serial.println("NOTHING");
  }
  delay(1);
}
