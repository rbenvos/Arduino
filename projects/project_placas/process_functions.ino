void check_conditions(double T1,
                      double T2,
                      double T3){
    /*
     * Modo 0 - Sin nada
     * Modo 1 - Modo invierno
     * Modo 2 - Modo eq. termico
     * Modo 3 - Emerg. Sauna
     * Modo 4 - Circula caldera
     * Modo 5 - ACS
     */

     rele1_active = false;
     rele2_active = false;
     rele3_active = false;
     rele4_active = false;

     
     if (DEBUG == true){
       Serial.println("T1: ");
       Serial.println(T1);
       Serial.println("T2: ");
       Serial.println(T2);
       Serial.println("T3: ");
       Serial.println(T3);
     }
     

    // Modo invierno si las placas tienen un valor menor que 5. Activa rele placas
    if (T1 <= float(5.0)) {
       rele1_active = true;
    };

    // Si las placas estan por encima de 65ª (+- 2), se activa rele 1
    // Mientras que haya una diferencia de 15 grados entre temperatura placas y termo. activa rele placas
    if (((T1 - T2) > float(15.0)) && (T1 > float(65.0))){
      rele1_active = true;
    };

    // Si el termo supera 95º, activa rele sauna
    if (T2 > float(95.0)){
      rele4_active = true;
    };

    // Si termo es mayor que 30º, activa rele caldera
    if (T2 > float(32.0)){
      rele2_active = true;
    };

    // Si el termo esta a una temperatura mayor que 70º, y el ACS menor que 55º y existe una direrencia 
    // entre ellos mayor que 15º se activara
    if (T2 > float(70.0) && T3 < float(55.0) && (T2 > T3) && ((T2 - T3) > float(15.0))){
      rele3_active = true;
    };
                        
}



void control_time_rele(){

  // Obtenemos el estado del rele actual
  bool old_state_rele1 = digitalRead(rele1) == LOW;
  bool old_state_rele2 = digitalRead(rele2) == LOW;
  bool old_state_rele3 = digitalRead(rele3) == LOW;
  bool old_state_rele4 = digitalRead(rele4) == LOW;

  if (DEBUG == true){
    Serial.print("Timer 1: ");
    Serial.println(timer_rele1);
  
    Serial.print("RL: ");
    Serial.println(rele1_active);
  
    Serial.print("AC: ");
    Serial.println(old_state_rele1);

    Serial.print("Timer 2: ");
    Serial.println(timer_rele2);
  
    Serial.print("RL: ");
    Serial.println(rele2_active);
  
    Serial.print("AC: ");
    Serial.println(old_state_rele2);

    Serial.print("Timer 3: ");
    Serial.println(timer_rele3);
  
    Serial.print("RL: ");
    Serial.println(rele3_active);
  
    Serial.print("AC: ");
    Serial.println(old_state_rele3);

    Serial.print("Timer 4: ");
    Serial.println(timer_rele4);
  
    Serial.print("RL: ");
    Serial.println(rele4_active);
  
    Serial.print("AC: ");
    Serial.println(old_state_rele4);
  }

  // Reinciamos los contadores en caso de cambio de estado 
 if (old_state_rele1 != rele1_active){
    timer_rele1 += 0.5;
  }else{
    timer_rele1 = 0.0;
  }
  
  if (old_state_rele2 != rele2_active){
    timer_rele2 += 0.5;
  }else{
    timer_rele2 = 0.0;
  }

  if (old_state_rele3 != rele3_active){
    timer_rele3 += 0.5;
  }else{
    timer_rele3 = 0.0;
  }

  if (old_state_rele4 != rele4_active){
    timer_rele4 += 0.5;
  }else{
    timer_rele4 = 0.0;
  }

  // Procesamos los temporizadores y estados
  if (timer_rele1 > RELE_WAIT_TIME or manual_mode == true){
    if (rele1_active == true){
       digitalWrite(rele1, LOW);
    }else{
       digitalWrite(rele1, HIGH);
    }
  }
  
  if (timer_rele2 > RELE_WAIT_TIME or manual_mode == true){
    if (rele2_active == true){
       digitalWrite(rele2, LOW);
    }else{
       digitalWrite(rele2, HIGH);
    }
  }

  if (timer_rele3 > RELE_WAIT_TIME or manual_mode == true){
    if (rele3_active == true){
       digitalWrite(rele3, LOW);
    }else{
       digitalWrite(rele3, HIGH);
    }
  }

  if (timer_rele4 > RELE_WAIT_TIME or manual_mode == true){
    if (rele4_active == true){
       digitalWrite(rele4, LOW);
    }else{
       digitalWrite(rele4, HIGH);
    }
  }


  }

void process_buttons(int manual_or_auto_button, 
                     int rele1_button, 
                     int rele2_button, 
                     int rele3_button, 
                     int rele4_button, 
                     int pressed_button){
  if (screen_touch.dataAvailable() == true)
    {
      pressed_button = buttons.checkButtons();
      if (pressed_button==0){
        manual_mode = !manual_mode;
      }
      else if (pressed_button==1){
        rele1_active = !rele1_active;
        manual_mode = true;
      }
      else if (pressed_button==2){
        rele2_active = !rele2_active;
        manual_mode = true;
      }
      else if (pressed_button==3){
        rele3_active = !rele3_active;
        manual_mode = true;
      }
      else if (pressed_button==4){
        rele4_active = !rele4_active;
        manual_mode = true;
      }
    }
}
