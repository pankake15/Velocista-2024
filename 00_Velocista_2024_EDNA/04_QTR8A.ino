

void Calibrar(){
  // CONFIGURACION INICIAL
        qtr.setTypeAnalog();
        qtr.setSensorPins((const uint8_t[]){PB1, PB0, PA7, PA6, PA5, PA4, PA3, PA2}, SensorCount);
        Serial1.println("Calibrando");
        digitalWrite(LED_DER, HIGH);

        // CALIBRACION (10 SEG APROX)
        for (uint16_t i = 0; i < 400; i++) {
            qtr.calibrate();
        }
        digitalWrite(LED_DER, LOW);
        Serial1.println("Termine");
        Botones = Nada;
}
