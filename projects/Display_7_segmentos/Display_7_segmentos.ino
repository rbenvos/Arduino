int a = 2;
int b = 3;
int c = 4;
int d = 5;
int e = 6;
int f = 7;
int g = 8;
int punto = 9;

void setup(){
  pinMode(a,OUTPUT);
  pinMode(b,OUTPUT);
  pinMode(c,OUTPUT);
  pinMode(d,OUTPUT);
  pinMode(e,OUTPUT);
  pinMode(f,OUTPUT);
  pinMode(g,OUTPUT);
  pinMode(punto,OUTPUT);
}

void sevenLed(int in1, int in2, int in3, int in4,
                  int in5, int in6, int in7){
  digitalWrite(a, in1);
  digitalWrite(b, in2);
  digitalWrite(c, in3);
  digitalWrite(d, in4);
  digitalWrite(e, in5);
  digitalWrite(f, in6);
  digitalWrite(g, in7);
}

void loop(){
  sevenLed(0,1,1,0,0,0,0);//1
  delay(500);
  sevenLed(1,1,0,1,1,0,1);//2
  delay(500);
  sevenLed(1,1,1,1,0,0,1);//3
  delay(500);
  sevenLed(0,1,1,0,0,1,1);//4
  delay(500);
  sevenLed(1,0,1,1,0,1,1);//5
  delay(500);
  sevenLed(1,0,1,1,1,1,1);//6
  delay(500);
  sevenLed(1,1,1,0,0,0,0);//7
  delay(500);
  sevenLed(1,1,1,1,1,1,1);//8
  delay(500);
  sevenLed(1,1,1,0,0,1,1);//9
  delay(500);
  sevenLed(1,1,1,1,1,1,0);//0
  delay(500);
  sevenLed(1,1,1,0,0,1,1);//Punto
  delay(500);
  digitalWrite(punto, HIGH);
}
