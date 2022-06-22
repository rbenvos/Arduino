void render_main_page(double T1, 
                      double T2,
                      double T3) {

   draw_basic_template();

   draw_temperatures(T1, T2, T3);   

   draw_reles();
 
   screen.setBackColor(255,255,255);
}


void init_buttons(int manual_or_auto_button, 
                  int rele1_button, 
                  int rele2_button, 
                  int rele3_button, 
                  int rele4_button){
   buttons.setTextFont(BigFont);
   buttons.setButtonColors(VGA_WHITE, VGA_GRAY, VGA_GRAY, VGA_RED, VGA_WHITE);
   // Manual or auto
   manual_or_auto_button = buttons.addButton(165, 10, 50, 50, "");

   // RELES
   // placas
   rele1_button = buttons.addButton(165, 110, 45, 45, "");
   // caldera
   rele2_button = buttons.addButton(250, 110, 45, 45, "");
   // acs
   rele3_button = buttons.addButton(165, 185, 45, 45, "");
   // sauna
   rele4_button = buttons.addButton(250, 185, 45, 45, "");
   buttons.drawButtons();
}

void set_color_by_rele_status(int rele_status){
  if (rele_status == 0){
       screen.setBackColor(0,255,0);
   }else if (rele_status == 1){
       screen.setBackColor(255,0,0);
   }
}

void draw_basic_template(){
  // Draw basic template
   screen.setBackColor(255,255,255);
   screen.setColor(0,0,0);
   screen.drawRect(0, 80, 319, 82);
   screen.drawRect(0, 160, 319, 162);
   screen.drawRect(160, 0, 162, 239);
   screen.drawRect(240, 80, 242, 239);
 }

void draw_temperatures(double T1,
                       double T2,
                       double T3){
  // Draw titles
   screen.setColor(5,5,5);
   screen.print(thermo_name, 10, 3);
   screen.print(thermo2_name, 10, 83);
   screen.print(thermo3_name, 10, 165);

   screen.printNumI(T1, 30, 27, 4);
   screen.printNumI(T2, 30, 103, 4);
   screen.printNumI(T3, 30, 185, 4);
  }

void draw_reles(){

   int manual_mode_pos_x = 220;
   int manual_mode_pos_y = 10;
   screen.print(manual_mode_name, manual_mode_pos_x, manual_mode_pos_y);
   if (manual_mode){
      screen.print("OFF", manual_mode_pos_x + 50, manual_mode_pos_y + 30);
      screen.setBackColor(0,255,0);
      screen.print("ON", manual_mode_pos_x, manual_mode_pos_y + 30);
   }else{
      screen.print("ON", manual_mode_pos_x, manual_mode_pos_y + 30);
      screen.setBackColor(255,0,0);
      screen.print("OFF", manual_mode_pos_x + 50, manual_mode_pos_y + 30);
      
   }
   
   

  // Draw rele statuses
   int rele_1_pos_x = 165;
   int rele_1_pos_y = 90;
   set_color_by_rele_status(digitalRead(rele1));
   screen.print(rele1_name, rele_1_pos_x, rele_1_pos_y);

   int rele_2_pos_x = 250;
   int rele_2_pos_y = 90;
   set_color_by_rele_status(digitalRead(rele2));
   screen.print(rele2_name, rele_2_pos_x, rele_2_pos_y);

   int rele_3_pos_x = 165;
   int rele_3_pos_y = 165;
   set_color_by_rele_status(digitalRead(rele3));
   screen.print(rele3_name, rele_3_pos_x, rele_3_pos_y);

   int rele_4_pos_x = 250;
   int rele_4_pos_y = 165;
   set_color_by_rele_status(digitalRead(rele4));
   screen.print(rele4_name, rele_4_pos_x, rele_4_pos_y);
  }
