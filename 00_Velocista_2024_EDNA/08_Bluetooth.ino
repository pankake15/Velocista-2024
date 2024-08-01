void selector(char ent){
char x;
  if (Serial1.available() > 0)
  {
  lola:
  x = Serial1.read();
    if(x == 10 || x == 13 || x == -1){
      goto lola;
    }
    if(ent == '+'){
  switch(x){
    case '1':
    KP += 0.1;
    break;
    case '2':
    KD += 0.1;
    break;
    case '3':
    Ki += 0.1;
    break;
    case '4':
    //parar
    right(0);
    left(0);
    break;
  }
  }else if(ent == '-'){
  switch(x){
    case '1':
    KP -= 0.1;
    break;
    case '2':
    KD -= 0.1;
    break;
    case '3':
    Ki -= 0.1;
    break;
    case '4':
    //parar
    right(0);
    left(0);
    break;
  }
  }

  Serial1.flush();
  //i++
  Start = 2;
  
  }
  Serial1.print("KP:");
  Serial1.print(KP);
  Serial1.print("KD:");
  Serial1.print(KD);
  Serial1.print("Ki:");
  Serial1.print(Ki);
}






void bluetooth(){
  char dato;
if (Serial1.available() > 1)
  {
  hola:
  dato = Serial1.read();
    if(dato == 10 || dato == 13 || dato == -1){
      goto hola;
    }
    
    // Mostrar el dato recibido
    selector(dato);
    
    Serial1.flush();
    // Esperar un corto tiempo para evitar la lectura repetida de datos
    delay(100);
  }
}
