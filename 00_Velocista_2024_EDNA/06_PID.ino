void PID(){
  int sensores_c = 0;
  int sensoresSuma = 0;
        
  // CALCULA POSICION DE LINEA NEGRA SEGUN LECTURA DE SENSORES (0-7000)
        uint16_t position = qtr.readLineWhite(sensorValues);
        qtr.read(Valores_rampa);
        
        // CALCULO PID
        float error = position - 3500;
        integral = integral + error;
        integral = constrain(integral, -1200, 1200); //limitamos la integral para no causar problemas
        float motorSpeed = KP * error + KD * (error - lastError) + KI * integral;
        lastError = error;
        
        // Mapeo de motorSpeed a rango de -255 a 255
        MotorF = map(motorSpeed, -maxMotorSpeed, maxMotorSpeed, -255, 255);
        MotorF = constrain(MotorF, -255, 255);

        for (uint8_t i = 0; i < SensorCount; i++){
            Serial1.print(i);
            Serial1.print(": ");
            Serial1.print(Valores_rampa[i]);
            Serial1.print("    ");
            sensoresSuma += Valores_rampa[i];
        }
        
        Serial1.println("");

            if(sensoresSuma/8 >= Valores_rampa[0]-10 && sensoresSuma/8 <= Valores_rampa[0]+10 ){
              MotorF = 0;
            digitalWrite(LED_IZQ, HIGH);
            digitalWrite(LED_DER, HIGH);
            }
        
        int m1Speed = Velocidad + MotorF;
        int m2Speed = Velocidad - MotorF;

        right(m1Speed);
        left(m2Speed);

        // VELOCIDAD MOTORES
        if (error > 0) {
            digitalWrite(LED_IZQ, HIGH);
            digitalWrite(LED_DER, LOW);
        } else if (error < 0) {
            digitalWrite(LED_IZQ, LOW);
            digitalWrite(LED_DER, HIGH);
        }
//}
}
