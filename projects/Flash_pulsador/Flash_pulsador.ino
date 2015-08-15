int bluepin = 46;
int redpin = 44;
int yellowpin = 52;
int pulsador = 42;
boolean ledEncendido = true;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  pinMode(bluepin, OUTPUT);
  pinMode(redpin, OUTPUT);
  pinMode(yellowpin, OUTPUT);
  pinMode(pulsador, INPUT);
  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {
  boolean botonPulsado = digitalRead(pulsador);
  Serial.print(estado);
    
  if ((botonPulsado)&&(!ledEncendido)){
    ledEncendido = true;
  }else if (!botonPulsado){
    ledEncendido = false; 
  }

  if(ledEncendido){
    digitalWrite(bluepin,HIGH);
    delay(50);
    digitalWrite(bluepin,LOW);
    delay(50);
  }
}
