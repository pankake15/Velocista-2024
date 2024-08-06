
void bluetooth() {
    right(0);
    left(0);
    Serial1.print("KP:");
    Serial1.print(KP);
    Serial1.print("KD:");
    Serial1.print(KD);
    Serial1.print("Ki:");
    Serial1.println(KI);
    char k = '7';
    Serial1.flush();  // Esto vacía el buffer de salida de Serial1

    if (Serial1.available() > 0) {  
      // Cambié > 1 por > 0, ya que queremos saber si hay al menos un byte disponible
        k = Serial1.read();

        Serial1.println(k, DEC);
        
        switch(k) {
            case 49:
                KP += 0.1;
                break;
            case 50:
                KD += 0.1;
                break;
            case 51:
                KI += 0.001;
                break;
            case 52:
                KP -= 0.1;
                break;
            case 53:
                KD -= 0.1;
                break;
            case 54:
                KI -= 0.001;
                break;
            case 55:
                Botones = Pid;
                break;
            case 10:
                Serial1.flush();
                break;
            case 13:
                Serial1.flush();
                break;
            default:
             Serial1.print("Caracter Desconocido");
             Botones = Pid;
        }
    }
}
