/*
void bluetooth() {
    right(0);
    left(0);

    char k = '9';
    Serial1.flush();  // Esto vacía el buffer de salida de Serial1

    if (Serial1.available() > 0) {  
      // Cambié > 1 por > 0, ya que queremos saber si hay al menos un byte disponible
        k = Serial1.read();
        Serial1.println(k, DEC);
        
        switch(k) {
            case 49:
                KP += 0.05;
                Serial1.flush();
                break;
            case 50:
                KD += 0.1;
                Serial1.flush();
                break;
            case 51:
                KI += 0.001;
                Serial1.flush();
                break;
            case 52:
                KP -= 0.05;
                Serial1.flush();
                break;
            case 53:
                KD -= 0.1;
                Serial1.flush();
                break;
            case 54:
                KI -= 0.001;
                Serial1.flush();
                break;
            case 55:
                Velocidad += 5;
                Serial1.flush();
                break;
            case 56:
                Velocidad -= 5;
                Serial1.flush();
                break;
            case 10:
                break;
            case 13:
                break;
            default:
             Serial1.println("Caracter Desconocido ");
             Botones = Pid;
        }
           Serial1.print("KP:");
           Serial1.print(KP);
           Serial1.print(" - KD:");
           Serial1.print(KD);
           Serial1.print(" - KI:");
           Serial1.println(KI, 3);
           Serial1.print("M:");
           Serial1.println(Velocidad);

    }
}
*/