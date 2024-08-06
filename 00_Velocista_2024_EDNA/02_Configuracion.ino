//INSTALAR ANTES DE SEGUIR!!
#include <QTRSensors.h>

//DECLARO QTR
QTRSensors qtr;

//VARIABLES DEL SENSOR
const uint8_t SensorCount = 8;
uint16_t sensorValues[SensorCount];

//VARIABLES DEL PID
float lastError = 0;
float KP = 0.38, KD = 1.35, KI = 0.002;
float integral = 0;
int maxMotorSpeed = 7000; // Valor máximo teórico para motorSpeed basado en tu sistema
int M1 = 60, M2 = 60;
int MotorF; 

// hice float a integral, error, lasterror

//VARIABLE DE LAS INTERRUPCIONES
volatile int Start = 0;

typedef enum {
  Nada,        //0
  Calibracion, //1
  Pid,         //2 
  Limpiar_R,   //3
  Bluetooth    //4
} Modulos;

volatile Modulos Botones;
