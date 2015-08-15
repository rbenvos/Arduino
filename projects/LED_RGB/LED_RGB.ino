int redpin = 49;    // select the input pin for the potentiometer

int bluepin =51;      // select the pin for the LED

int yellowpin =53;

int val;

 

void setup() {

  pinMode(redpin, OUTPUT);

  pinMode(bluepin, OUTPUT);

  pinMode(yellowpin, OUTPUT);

  Serial.begin(9600);

}

 

void loop() 

{

for(val=255; val>0; val--)

  {

   analogWrite(49, val);

   analogWrite(51, 255-val);

   analogWrite(53, 128-val);

   delay(1); 

  }

for(val=0; val<255; val++)

  {

   analogWrite(49, val);

   analogWrite(51, 255-val);

   analogWrite(53, 128-val);

   delay(1); 

  }

 Serial.println(val, DEC);

}


