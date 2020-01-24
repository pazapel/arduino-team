int ButtonNew;
int ButtonOld;

void setup() {
  // put your setup code here, to run once:
pinMode(2, OUTPUT);
pinMode(7, INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
ButtonNew = digitalRead(7);
//Serial.println(ButtonNew);
if(ButtonOld == 0 and ButtonNew == 1) {
    Serial.println("Button Was Pushed");
    digitalWrite(2, HIGH);
    delay(100);
    digitalWrite(2, LOW);   
  } 
ButtonOld = ButtonNew;   
delay(1);
}
