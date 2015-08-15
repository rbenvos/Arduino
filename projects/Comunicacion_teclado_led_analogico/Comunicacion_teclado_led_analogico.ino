int pinBlue = 44;

void setup()
{
  // start serial port at 9600 bps:
  Serial.begin(9600);
  pinMode(pinBlue,OUTPUT);
}

void loop()
{
  if (Serial.available()>0){
    int contenido = Serial.parseInt(); 
    //Con parseInt nos permite leer un valor ASCII y parsearlo
    // a Int.
    Serial.println(contenido);
    analogWrite(pinBlue,contenido);
  }
}



