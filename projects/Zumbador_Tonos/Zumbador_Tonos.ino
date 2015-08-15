int buzzer = 2;
void setup()
{
     pinMode(buzzer, OUTPUT);   // sets the pin as output
     Serial.begin(9600);
}
 
void loop()
{
     tone(buzzer, 800, 3000); //tone(pin, frequency, duration) 
     //Esta funcion se ejecuta en segundo plano, 
     //y anula a la siguiente.
     tone(buzzer, 1200); //tone(pin, frequency) 
     delay(500); 
     
     //**************************//
     tone(buzzer, 1400, 500);
     delay(500);
     noTone(buzzer);
     
     //**************************//
     tone(buzzer, 200, 500);
     delay(500);
     noTone(buzzer);
     
     tone(buzzer, 1200, 500);
     delay(500);
     noTone(buzzer);
     
     delay(1000);

}
