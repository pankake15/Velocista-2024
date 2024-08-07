void PID(){
  char estado;
        
  // CALCULA POSICION DE LINEA NEGRA SEGUN LECTURA DE SENSORES (0-7000)
        uint16_t position = qtr.readLineWhite(sensorValues);
 //       Serial1.println("POS: ");
 //       Serial1.print(position);

        // CALCULO PID
        float error = position - 3500;
        integral = integral + error;
        integral = constrain(integral, -1200, 1200); //limitamos la integral para no causar problemas
        float motorSpeed = KP * error + KD * (error - lastError) + KI * integral;
        lastError = error;
        //Serial1.print("  Error: ");
        //Serial1.print(error);
        
        //                      ---revisar---
        //motorSpeed = constrain(motorSpeed, -maxMotorSpeed, maxMotorSpeed);
        
        // Mapeo de motorSpeed a rango de -255 a 255
        MotorF = map(motorSpeed, -maxMotorSpeed, maxMotorSpeed, -255, 255);
        MotorF = constrain(MotorF, -255, 255);
        
        int m1Speed = M1 + MotorF;
        int m2Speed = M2 - MotorF;

        right(m1Speed);
//        Serial1.print("  Izquierda: ");
//        Serial1.println(m1Speed);

        left(m2Speed);
//        Serial1.print("  Derecha: ");
//        Serial1.println(m2Speed);

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
