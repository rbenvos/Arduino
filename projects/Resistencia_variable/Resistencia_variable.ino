char resistencia = A0;

void setup(){
  Serial.begin(9600);
  pinMode(resistencia,INPUT);
}

void loop(){  // cuando este energizado el Arduino
  int valor= analogRead(resistencia);
  Serial.println(valor);
  delay(100);
}
//Fin programa
