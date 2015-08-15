int bluepin = 46;
int valorIntensidad = 0;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  pinMode(bluepin, OUTPUT);
  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {
  //Serial.print(estado);
  
  if (valorIntensidad<255){
    valorIntensidad +=1;
  }else{
    valorIntensidad = 0;
  }
  analogWrite(bluepin,valorIntensidad);
  delay(10);

}
