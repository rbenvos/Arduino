#include <Servo.h>
Servo servo1;

void setup(){
  servo1.attach(9); 
}

void loop(){
  servo1.write(0);
  delay(500);
  servo1.write(30);
  delay(500);
  servo1.write(60);
  delay(500);
  servo1.write(90);
  delay(500);
  servo1.write(120);
  delay(500);
  servo1.write(150);
  delay(500);
  servo1.write(180);
  delay(500);
  servo1.write(210);
  delay(500);
  servo1.write(240);
  delay(500);
}

