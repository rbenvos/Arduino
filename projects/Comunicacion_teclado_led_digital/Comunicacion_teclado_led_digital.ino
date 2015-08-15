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
    Serial.println("hola");
    char contenido = Serial.read();
    Serial.println(contenido);
    if (contenido == '1'){
      digitalWrite(pinBlue,HIGH);
    }else if (contenido == '0'){
      digitalWrite(pinBlue,LOW);
    }
  }
}



