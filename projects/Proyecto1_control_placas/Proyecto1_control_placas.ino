#include <LiquidCrystal.h>

/* Inicializadores*/
LiquidCrystal lcd(7,8,9,10,11,12);
int button_up = 50;
int button_down = 52;

/*Variables*/
char* site[] = {"Placas","Radiadores","Agua"};
//int temperature[3];
float temp[3] = {30,31,32};
int current_temp = 0;

byte grad[8] = {
  B01110,
  B01010,
  B01110,
  B00000,
  B00000,
  B00000,
  B00000,
};

void setup(){
  pinMode(button_up,INPUT);
  pinMode(button_down,INPUT);
  lcd.begin(16,2); //lcd.begin(cols, rows)
  lcd.createChar(0, grad);
  lcd.print("Bienvenido");
  Serial.begin(9600);
  delay(500);
  lcd.clear();
}

void loop(){
  boolean press_button_up = digitalRead(button_up);
  boolean press_button_down = digitalRead(button_down);
  float temperature = analogRead(A0);
  temp[0] = (500.0 * temperature)/1023;
  /*float temp=(analogRead(pin)*5.0)/1024.0;
  temp=(temp-0.5)*100;*/
  Serial.print(temperature);
  
  lcd.setCursor(0,0);
  lcd.print(site[current_temp]);
  lcd.setCursor(11,1);
  lcd.print(temp[current_temp]);
  lcd.setCursor(15,1);
  lcd.write(byte(0));
  delay(200);
  
  if (press_button_up){
    lcd.clear();
    if (current_temp < 2){
      current_temp++;
    }else{
      current_temp = 0;
    }
    Serial.println(current_temp);
  }
  if (press_button_down){
    lcd.clear();
    if (current_temp >= 0){
      current_temp--;
    }else{
      current_temp = 0;
    }
    Serial.println(current_temp);
  }
}
