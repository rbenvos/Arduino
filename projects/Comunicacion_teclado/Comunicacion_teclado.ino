void setup()
{
  // start serial port at 9600 bps:
  Serial.begin(9600);
}

void loop()
{
  if (Serial.available()>0){
    Serial.println("hola");
    char contenido = Serial.read();
    Serial.println(contenido);
  }
}



