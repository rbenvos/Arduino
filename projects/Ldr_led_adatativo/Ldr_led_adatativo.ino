int ledblue = 13;
char ldr = A0;

void setup(){
   pinMode(ledblue,OUTPUT);
   pinMode(ldr,INPUT);
   Serial.begin(9600);
}

void loop(){
  int value = analogRead(ldr);
  if (value < 400){
      analogWrite(ledblue,0);
  }else if (value < 700){
      analogWrite(ledblue,10);
  }else{
      analogWrite(ledblue,254);
  }
  delay(100);
}
