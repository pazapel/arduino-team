unsigned int DIPValue;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly
  DIPValue=analogRead(A0);
  Serial.print(DIPValue);
  /*000
    001
    010
    011
    100
    101
    110
    111*/
  if(658 <= DIPValue && 669 >= DIPValue)
  {
    Serial.println("\t 1");  
  }
  else if(625 <= DIPValue && 636 >= DIPValue)
  {
    Serial.println("\t 2");  
  }
  else if(560 <= DIPValue && 571 >= DIPValue)
  {
    Serial.println("\t 3");  
  }
  else if(505 <= DIPValue && 516 >= DIPValue)
  {
    Serial.println("\t 4");  
  }
  else if(463 <= DIPValue && 472 >= DIPValue)
  {
    Serial.println("\t 5");  
  }
  else if(380 <= DIPValue && 392 >= DIPValue)
  {
    Serial.println("\t 6");  
  }
  else if(189 <= DIPValue && 201 >= DIPValue)
  {
    Serial.println("\t 7");  
  }
  else if(0 <= DIPValue && 5 >= DIPValue)
  {
    Serial.println("\t 8");  
  }
  else
  {
    Serial.println("\t oof");  
  }
  delay(100);
}
