#include <LiquidCrystal.h>

/* Inicializadores*/
LiquidCrystal lcd(7,8,9,10,11,12);
#define up 44;
#define down 46;
#define enter 48;
#define back 50;

/*Variables*/
char* site[] = {"Placas","Radiadores","Agua","Configuracion"};
//int temperature[3];

int current_temp = 0;

float temp1;
float temp2;
float temp3;

boolean circuit1 = false;
boolean circuit2 = false;
boolean circuit3 = false;


byte grad[8] = {
  B01110,
  B01010,
  B01110,
  B00000,
  B00000,
  B00000,
  B00000,
};

byte arrow[8] = {
	0b00000,
	0b00100,
	0b00010,
	0b11111,
	0b00010,
	0b00100,
	0b00000,
	0b00000
};

void setup(){
  pinMode(button_up,INPUT);
  pinMode(button_down,INPUT);
  lcd.begin(16,2); //lcd.begin(cols, rows)
  lcd.createChar(0, grad);
  lcd.createChar(1, arrow);
  Serial.begin(9600);
}

void printScreen(){
  lcd.setCursor(0,0);
  lcd.write(site[current_temp]);
  lcd.setCursor(11,1);
  lcd.write(temp[current_temp]);
  lcd.setCursor(15,1);
  lcd.write(byte(0));
}

void menuConfig(){}

void menuMain(){}

void stanby(){}

void loop(){
  lcd.setCursor(0,0);
  lcd.print("# Solarthermal #");
  lcd.setCursor(5,1);
  lcd.print("Entrar");
  lcd.write(byte(1));
  delay(10000);
  
  
  boolean press_button_up = digitalRead(button_up);
  boolean press_button_down = digitalRead(button_down);
  float temperature = analogRead(A0);
  temp[0] = (500.0 * temperature)/1023;
  /*float temp=(analogRead(pin)*5.0)/1024.0;
  temp=(temp-0.5)*100;*/
  
  printScreen();
  
  if (press_button_up){
    lcd.clear();
    if (current_temp < 3){
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
  
  delay(200);
}

/*
// DESPLAZA EL CURSOR UNA POSICION EN LA DIRECCION INDICADA
void LCDMueveCursor(int *pos, int max, char ope)
{
	// Precondición:	El parámetro ope debería de ser el carácter 's' o 'r' para sumar o restar una posición.
	//					El parámetro max indica el numero de opciones a elegir.
	// Poscondición:	Se devuelve por referencia el nuevo valor del cursor.
 
	if(ope == 's')
		if(*pos < max)	*pos += 1;
		else			*pos = 0;
	else
		if(*pos > 0)	*pos -= 1;
		else			*pos = max;
 
	// Se borran los cursores:
	lcd.setCursor(0, 0); lcd.print(" ");
	lcd.setCursor(0, 1); lcd.print(" ");
	lcd.setCursor(0, 2); lcd.print(" ");
	lcd.setCursor(0, 3); lcd.print(" ");
}*/
 
 /*
 
// PROCEDIMIENTO QUE COMPRUEBA SI HA HABIDO NUEVAS PULSACIONES CON LOS BOTONES:
void getButtonPush(char *resultButton, int pin, int pause)
{
	// Precondición:	El parámetro pin ha de ser un pin Analógico del Arduino.
	// Poscondición:	El parámetro resultButton es una cadena por referencia que devolverá el botón pulsado.
	//					El parámetro pause ha de ser un numero entero igual o mayor que 0.
	// Info:			El teclado usado es este: http://giltesa.com/?p=11458 , según el tipo de resistencias habrá que cambiar las condicionales para adaptarse al valor leído desde el pin Analógico.
 
	int data = analogRead(0);
 
	if (data > 10)
	{
		if (data > 500 && data < 540)
			strcpy(resultButton,"up");
		else if (data > 330 && data < 370)
			strcpy(resultButton,"left");
		else if (data > 240 && data < 280)
			strcpy(resultButton,"bottom");
		else if (data > 190 && data < 230)
			strcpy(resultButton,"right");
 
		delay(pause);
	}
}*/
