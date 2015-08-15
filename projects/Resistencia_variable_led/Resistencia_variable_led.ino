char resistencia = A0;
int bluepin = 46;

void setup(){
  Serial.begin(9600);
  pinMode(resistencia,INPUT);
  pinMode(bluepin, OUTPUT);
}

void loop(){  // cuando este energizado el Arduino
  int valor = analogRead(resistencia);
  Serial.println(valor/4);
  analogWrite(bluepin,(valor/4));
  delay(100);
}
//Fin programa
