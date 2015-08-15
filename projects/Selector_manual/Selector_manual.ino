int bluepin = 46;
int redpin = 44;
int yellowpin = 52;
int pulsador = 42;
char coloresLed[] = {bluepin, redpin, yellowpin};
boolean ledEncendido = true;
int colorEncendido = 2;


// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  pinMode(bluepin, OUTPUT);
  pinMode(redpin, OUTPUT);
  pinMode(yellowpin, OUTPUT);
  pinMode(pulsador, INPUT);
  Serial.begin(9600);
}

int cambioLed(int x){
  if (x==2){
    x = 0;
  }else{
    x = x+1;
  }
  digitalWrite(coloresLed[x],HIGH);
  return x;
  
}


// the loop function runs over and over again forever
void loop() {
  boolean botonPulsado = digitalRead(pulsador);
  //Serial.print(estado);
  
  if ((botonPulsado)&&(!ledEncendido)){
    colorEncendido = cambioLed(colorEncendido);
    ledEncendido = true;
  }else if (!botonPulsado){
    Serial.print(colorEncendido);
    digitalWrite(coloresLed[colorEncendido],LOW);
    ledEncendido = false; 
  }
  delay(50);
}
