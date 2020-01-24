int i;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  
for(i=3; i<10; i=i+2)
 { 
  Serial.println(i);
  }
  delay(5000);
}
