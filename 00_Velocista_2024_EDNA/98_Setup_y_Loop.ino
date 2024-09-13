void setup() {
  //  Serial1.begin(9600);

    // Configuración de pines
    pinMode(LED_DER, OUTPUT);
    pinMode(LED_IZQ, OUTPUT);
    pinMode(ML_IN1, OUTPUT);
    pinMode(ML_IN2, OUTPUT);
    pinMode(ML_PWM, OUTPUT);
    pinMode(MR_IN1, OUTPUT);
    pinMode(MR_IN2, OUTPUT);
    pinMode(MR_PWM, OUTPUT);
    pinMode(BOT_I, INPUT_PULLUP);
    pinMode(BOT_C, INPUT_PULLUP);
    pinMode(BOT_D, INPUT_PULLUP);
    
    attachInterrupt(digitalPinToInterrupt(PC15), InterCalibrar, FALLING);
    attachInterrupt(digitalPinToInterrupt(PC14), InterIniciar, FALLING);
    attachInterrupt(digitalPinToInterrupt(PC13), InterLimpieza, FALLING);
}

void loop() {
    Modulos Etapa = Botones;

    if (Etapa == Calibracion) {
        Calibrar();
    } else if (Etapa == Pid) {
        // if (Serial1.available() >= 1 && Serial1.read()!= 13 && Serial1.read()!= 10){
        //   Serial1.println("Esperando datos de Bluetooth...");
        //   Botones = Bluetooth;
        //   }
        // else { 
          PID();
        //  }
    } else if (Etapa == Limpiar_R){
      Limpieza();
    }/*else if(Etapa == Bluetooth){
      bluetooth();
    }*/
}
