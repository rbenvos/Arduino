#include <LiquidCrystal.h>

/* initializers */
LiquidCrystal lcd(7,8,9,10,11,12);
int button_up = 52;
int button_down = 50;
int button_enter = 46;
int button_back = 48;

char sensor_1 = A0;
char sensor_2 = A1;
char sensor_3 = A2;
char sensor_4 = A3;

/* Variables */
int state = 0;
int num_states = 3;

int sub_state_main = 1;
int num_sub_state_main = 2;

int sub_state_standby = 1;
int num_sub_state_standby = 4;

int interval_standby_change = 5000;

boolean r1 = false;
boolean r2 = false;
boolean r3 = false;
boolean r4 = false;

float s1 = 31.9;
float s2 = 31.9;
float s3 = 31.9;
float s4 = 31.9;

/* Createchar */
byte arrow_down[8] = {
        B00000,
        B00000,
        B00000,
        B00000,
        B00000,
        B11111,
        B01110,
        B00100
};

byte arrow_up[8] = {
        B00100,
        B01110,
        B11111,
        B00000,
        B00000,
        B00000,
        B00000,
        B00000
};

/* Process */
void programmer(){


  /*•	Cuando  S1  es un 8% mayuor que s3 activa R1, y si la temperatura de S2 es un 8% más que la de S3 seguirá funcionando*/
  
  if (s1 > 40.0){
    r1 = true;
  }
  
  /*Cuando S1 sea inferior a 8ºC se activa R1, comprobar cada 2 minuto la temperatura y si S1_nuevo es 4grados mas que S1_antiguo se desactiva */
  if (s1 < 8.0){}
  
  /*Cuando S3 supera los 95ºC activa R2*/

  if (s3 > 95){
    r2 = true;
  }

  //Cuando S3 es 12ºC mayor que S4 activa R4 

  if (s3 > (s4 + 12.0)){
    r4 = true;
  }

  //Cuando S3 es 8c menor que s4 desactiva r4

  if (s3 < (s4 + 8.0)){
    r4 = false;
  }

  //Si S3 es mayor que 28c activa R3

  if (s3 > 28.0){
    r3 = true;
  }

}

/* Display processes */
void selector_display(int num_display){
  if (num_display == 1){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Paneles solares");
    lcd.setCursor(10,1);
    lcd.print(s1);
  }

  if (num_display == 2){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Temp Bajada");
    lcd.setCursor(10,1);
    lcd.print(s2);
  }
  
  if (num_display == 3){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Acumulador");
    lcd.setCursor(10,1);
    lcd.print(s3);
  }
  
  if (num_display == 4){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Sensor A.C.S.");
    lcd.setCursor(10,1);
    lcd.print(s4);
  }
}

void standby_display(){
  int num_display = 1;
  unsigned long time_change;
  unsigned long initial_time = 0;
  
  while(state == 1){
    time_change = millis();
    control_keys();
    // HAY QUE CONTROLAR PARA CUANDO millis() SEA 0.
    if ((time_change - initial_time) > interval_standby_change){
      Serial.print("cambio pantalla");
      Serial.print(num_display);
      if (num_display <= num_sub_state_standby){
        num_display++;
      }else{
        num_display = 1;
      }
      selector_display(num_display);
      initial_time = time_change;
    }
  }  
}

void temp_display(){
  lcd.setCursor(0,0);
  lcd.print("PS");
  lcd.setCursor(3,0);
  lcd.print(s1);
  lcd.setCursor(7,0);
  lcd.print(" ");

  lcd.setCursor(8,0);
  lcd.print("Ba");
  lcd.setCursor(11,0);
  lcd.print(s2);
  lcd.setCursor(15,0);
  lcd.write(1);
  
  lcd.setCursor(0,1);
  lcd.print("Ac");
  lcd.setCursor(3,1);
  lcd.print(s3);
  lcd.setCursor(7,1);
  lcd.print(" ");
  
  lcd.setCursor(8,1);
  lcd.print("AS");
  lcd.setCursor(11,1);
  lcd.print(s4);
  lcd.setCursor(15,1);
  lcd.print(" ");
}

void circulator_display(){
  lcd.setCursor(0,0);
  lcd.print("PS");
  lcd.setCursor(3,0);
  if (r1){
    lcd.print("ON");
  }else{
    lcd.print("OFF");
  }

  lcd.setCursor(8,0);
  lcd.print("Di");
  lcd.setCursor(11,0);
  if (r2){
    lcd.print("ON");
  }else{
    lcd.print("OFF");
  }
  lcd.setCursor(15,0);
  //lcd.write(0);
  
  lcd.setCursor(0,1);
  lcd.print("Ca");
  lcd.setCursor(3,1);
  if (r3){
    lcd.print("ON");
  }else{
    lcd.print("OFF");
  }
  
  lcd.setCursor(8,1);
  lcd.print("AS");
  lcd.setCursor(11,1);
  if (r4){
    lcd.print("ON");
  }else{
    lcd.print("OFF");
  }
  lcd.setCursor(15,1);
  lcd.write(2);
}

void refresh_display(){
  //Standby
  if (state == 1){
    lcd.clear();
    //lcd.print("standby");
    standby_display();
  }
  //Main
  else if (state == 2){
    lcd.clear();
    if (sub_state_main == 1){
      temp_display();
    }else if (sub_state_main == 2){
      circulator_display();
    }
  }
  //Setting
  else if (state == 3){
    lcd.clear();
    lcd.print("setting");
  }
}

/* Main process */

void control_keys(){
  boolean press_button_enter = digitalRead(button_enter);
  boolean press_button_back = digitalRead(button_back);
  boolean press_button_up = digitalRead(button_up);
  boolean press_button_down = digitalRead(button_down);
  if (press_button_enter){
    if (state<(num_states)){
      state++;
    }
    refresh_display();
    Serial.println(state);
  }
  if (press_button_back){
    if (state>1){
      state--;
    }
    refresh_display();
    Serial.println(state);
  }  
  
  if (press_button_up){
    if (state == 2){
      if (sub_state_main<num_sub_state_main){
        sub_state_main++;
      }
    }
    refresh_display();
    Serial.println("sub state: ");
    Serial.print(sub_state_main);
  }
  
  if (press_button_down){
    if (state == 2){
      if (sub_state_main>1){
        sub_state_main--;
      }
    }
    refresh_display();
    Serial.println("sub state: ");
    Serial.print(sub_state_main);
  }
}

/* Main program */
void setup(){
  pinMode(button_up,INPUT);
  pinMode(button_down,INPUT);
  pinMode(button_enter,INPUT);
  pinMode(button_back,INPUT);
  
  Serial.begin(9600);
  
  lcd.createChar(1, arrow_up);
  lcd.createChar(2, arrow_down);
  
  lcd.begin(16,2); //lcd.begin(cols, rows)
  lcd.print("start");
}

void loop(){
  control_keys();
  programmer();
  delay(200);
}
