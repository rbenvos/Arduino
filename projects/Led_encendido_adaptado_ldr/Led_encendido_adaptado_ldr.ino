int ledblue = 13;
char ldr = A0;

void setup(){
   pinMode(ledblue,OUTPUT);
   pinMode(ldr,INPUT);
   Serial.begin(9600);
}

void loop(){
  int value = (analogRead(ldr))/4;
  Serial.print("valor entrada: ");
  Serial.println(value);
  int value_led = 254 - value;
  Serial.println(value_led);
  analogWrite(ledblue,value_led);
  delay(100);
}
