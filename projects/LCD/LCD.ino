#include <LiquidCrystal.h>

LiquidCrystal lcd(52,50,46,44,42,40);
/*LiquidCrystal(rs, enable, d4, d5, d6, d7) 
LiquidCrystal(rs, rw, enable, d4, d5, d6, d7) 
LiquidCrystal(rs, enable, d0, d1, d2, d3, d4, d5, d6, d7) 
LiquidCrystal(rs, rw, enable, d0, d1, d2, d3, d4, d5, d6, d7)*/

const char* data = "Hola de nuevo";

void setup(){
  lcd.begin(16,2); //lcd.begin(cols, rows)
  
  lcd.print("Hola mundo"); //lcd.print(data) 
                           //lcd.print(data, BASE)
  //lcd.setCursor(0, 1);
}

void loop(){
  lcd.setCursor(0, 1);
  lcd.print(millis()/1000);
  //lcd.write(data);//Write a character to the LCD.
  lcd.write("Prueba");
  if ((millis()/1000)==10){
    lcd.clear(); //Clear the LCD
    lcd.home(); //Positions the cursor in the upper-left of the LCD
  }
}


