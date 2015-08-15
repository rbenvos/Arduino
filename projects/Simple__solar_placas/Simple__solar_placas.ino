#include <LiquidCrystal.h>
#include "max6675.h"

/* initializers */

/* LCD */
LiquidCrystal lcd(52,50,46,44,42,40);

/* Botones */
int button_enter = 34;
int button_back = 36;

/* Sensores */
int sensor_1_CS = 24;             // CS pin on MAX6675
int sensor_1_SO = 22;              // SO pin of MAX6675
int sensor_1_SCK = 26;             // SCK pin of MAX6675
float temperatura = 0.0;

/* Temperature sensor */
  MAX6675 temp_1(sensor_1_SCK, sensor_1_CS, sensor_1_SO);

/* Reles */
int rele_1= 30;
boolean rele_mode = false;

/* Led */
int redPin = 35; /*Esta cambiado el aluz por el rojo!*/
int greenPin = 31;
int bluePin = 33;


void setColor(int red, int green, int blue)
{
  /*red = 255 - red;
  green = 255 - green;
  blue = 255 - blue;*/
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);  
}


/* Main program */
void setup(){
  /*´Buttons */
  pinMode(button_enter,INPUT);
  pinMode(button_back,INPUT);
  
  /* Relay */
  pinMode(rele_1,OUTPUT);
  
  /* RGB led */
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);  
  
  /* Serial */
  Serial.begin(9600);
  
  /* Lcd */
  lcd.begin(16,2); //lcd.begin(cols, rows)
  lcd.home();
  lcd.print("start");
}

void draw_LCD(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Temp :");
  lcd.setCursor(8,0);
  lcd.print(temperatura);
  lcd.setCursor(13,0);
  lcd.print("  ");
  lcd.setCursor(0,1);
  lcd.print("Rele :");
  lcd.setCursor(8,1);
  lcd.print(rele_mode);
  
  
  /*Serial.println(temperatura);*/
}

void draw_Led(){
  if (temperatura >= 40){
    setColor(255, 0, 0); 
    Serial.println("A1");
  }
  else if (temperatura < 20){
    setColor(0, 0, 255); 
    Serial.println("A2");
  }
  else if (temperatura >= 20 && temperatura < 25){
    setColor(0, 255, 255); 
    Serial.println("A3");
  }
  else if (temperatura >= 25 && temperatura < 30){
    setColor(255, 0, 255); 
    Serial.println("A4");
  }
  else if (temperatura >= 30 && temperatura < 40){
    setColor(255, 0, 155); 
    Serial.println("A5");
  }
}

void loop(){
  temperatura = temp_1.readCelsius();
  draw_LCD();
  draw_Led();
  if  (temperatura >= 50 && temperatura < 60){
    digitalWrite(rele_1, HIGH);
    rele_mode = true;
  }else{
    digitalWrite(rele_1, LOW);
    rele_mode = false;
  }
  delay(500);
}
