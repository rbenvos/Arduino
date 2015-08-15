int bluepin = 46;
int redpin = 44;
int yellowpin = 52;
int pulsador = 42;
boolean ledEncendido = false;
boolean estadoAnterior = false;

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
  //Serial.print(estado);
  if (botonPulsado && !estadoAnterior){
    ledEncendido = !ledEncendido; 
  }
  
  estadoAnterior = botonPulsado;

  if(ledEncendido){
    digitalWrite(bluepin,HIGH);
  }else{
    digitalWrite(bluepin,LOW);
  }
    delay(100);
}
