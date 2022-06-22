
#include <UTFT.h>
#include <URTouch.h>
#include <UTFT_Buttons.h>
#include "max6675.h"

extern uint8_t SmallFont[];
extern uint8_t BigFont[];
extern uint8_t SevenSegNumFont[];

bool DEBUG = false;

int DELAY_MAIN_PROCESS = 500;

float RELE_WAIT_TIME = 5.0;

int SO_1 = 42;
int CS_1 = 43;
int SCLK_1 = 45;

int SO_2 = 12;
int CS_2 = 11;
int SCLK_2 = 13;

int SO_3 = 10;
int CS_3 = 9;
int SCLK_3 = 8;

MAX6675 thermo(SCLK_1, CS_1, SO_1);
String thermo_name = "Placas";
MAX6675 thermo2(SCLK_2, CS_2, SO_2);
String thermo2_name = "Termo";
MAX6675 thermo3(SCLK_3, CS_3, SO_3);
String thermo3_name = "A.C.S.";

const int rele1 = 47;
const String rele1_name = "PLAC";
bool rele1_active = false;
const int rele2 = 49;
const String rele2_name = "CALD";
bool rele2_active = false;
const int rele3 = 46;
const String rele3_name = "ACS";
bool rele3_active = false;
const int rele4 = 48;
const String rele4_name = "SAUNA";
bool rele4_active = false;

float timer_rele1 = 0;
float timer_rele2 = 0;
float timer_rele3 = 0;
float timer_rele4 = 0;

bool manual_mode = false; // Modo False - Auto, Modo True - Manual
const String manual_mode_name = "MANUAL";

// Buttons
int manual_or_auto_button, rele1_button, rele2_button, rele3_button, rele4_button, pressed_button;

UTFT screen(ITDB32S,38,39,40,41);
URTouch screen_touch(6,5,4,3,2);

UTFT_Buttons buttons(&screen, &screen_touch);
  
void setup() {
  Serial.begin(9600);
  pinMode(rele1,OUTPUT);
  pinMode(rele2,OUTPUT);
  pinMode(rele3,OUTPUT);
  pinMode(rele4,OUTPUT);

  digitalWrite(rele1, HIGH); // LOW - enciende / HIGH - apagado
  digitalWrite(rele2, HIGH);
  digitalWrite(rele3, HIGH);
  digitalWrite(rele4, HIGH);

  screen.InitLCD();
  screen.setContrast(16);
  screen.setBrightness(16);
  
  screen.setFont(BigFont);
  screen.clrScr();

  screen_touch.InitTouch();
  screen_touch.setPrecision(PREC_HI);
  
  Serial.println("Initialing ...");
  // wait for MAX chip to stabilize
  delay(1000);
  Serial.println("Initializated!");

  screen.fillScr(VGA_WHITE);

  init_buttons(manual_or_auto_button,
               rele1_button,
               rele2_button,
               rele3_button,
               rele4_button);
  Serial.println(rele1_button);
  Serial.println(rele2_button);
  Serial.println(rele3_button);
  Serial.println(rele4_button);
}


void loop() {

   double T1 = thermo.readCelsius();
   double T2 = thermo2.readCelsius();
   double T3 = thermo3.readCelsius();

   render_main_page(T1, T2, T3);

   if (not manual_mode){
    check_conditions(T1, T2, T3);
   }
   
   control_time_rele();

   process_buttons(manual_or_auto_button,
                   rele1_button,
                   rele2_button,
                   rele3_button,
                   rele4_button, 
                   pressed_button);
 
   delay(DELAY_MAIN_PROCESS);
}
