int buzzer = 2;
void setup()
{
     pinMode(buzzer, OUTPUT);   // sets the pin as output
}
 
void loop()
{
     analogWrite(buzzer,10); //emite sonido
     delay(500); //espera medio segundo
     digitalWrite(buzzer, LOW); //deja de emitir
     delay(500);//espera medio segundo
}
