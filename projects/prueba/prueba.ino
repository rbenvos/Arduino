#include <LiquidCrystal.h>

/* initializers */
LiquidCrystal lcd(7,8,9,10,11,12);
int button_up = 50;
int button_down = 52;
int button_enter = 46;
int button_back = 48;

char sensor_1 = A0;
char sensor_2 = A1;
char sensor_3 = A2;
char sensor_4 = A3;

/* Variables */
boolean r1 = false;
boolean r2 = false;
boolean r3 = false;
boolean r4 = false;

float s1 = 0.0;
float s2 = 0.0;
float s3 = 0.0;
float s4 = 0.0;


/* Process */
void programmer(){}

/* Main program */
void start(){
  pinMode(button_up,INPUT);
  pinMode(button_down,INPUT);
  pinMode(button_enter,INPUT);
  pinMode(button_back,INPUT);
  
  Serial.begin(9600);
  
  lcd.begin(16,2); //lcd.begin(cols, rows)
  lcd.print("start");
}

void loop(){
  lcd.clear();
  lcd.print("loop");
  
  delay(4000);
  standby();
}

void standby(){
  /*Muestra de forma cambiante las diferentes temperaturas disponibles*/
  lcd.clear();
  lcd.print("standby");
  
  programmer();
  
  boolean press_button_enter = digitalRead(button_enter);
  if (press_button_enter){
    principal();
  }
}

void principal(){
  /*Muestra los 4 valores de temperatura*/
  lcd.clear();
  lcd.print("main");
  
  programmer();
  
  boolean press_button_enter = digitalRead(button_enter);
  if (press_button_enter){
    setting();
  }
}

void setting(){
  /*Permite la configuracion de los parametros de corte*/
  lcd.clear();
  lcd.print("setting");
  
  programmer();
  
  boolean press_button_back = digitalRead(button_back);
  if (press_button_back){
    principal();
  }
}
