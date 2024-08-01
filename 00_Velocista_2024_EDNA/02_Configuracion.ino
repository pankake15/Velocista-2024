//INSTALAR ANTES DE SEGUIR!!
#include <QTRSensors.h>

//DECLARO QTR
QTRSensors qtr;

//VARIABLES DEL SENSOR
const uint8_t SensorCount = 8;
uint16_t sensorValues[SensorCount];

//VARIABLES DEL PID
int lastError = 0;
float KP = 0.18, KD = 0.4, Ki = 0.001;
int integral = 0;
int maxMotorSpeed = 7000; // Valor máximo teórico para motorSpeed basado en tu sistema
int M1 = 50, M2 = 50;
int MotorF;

//VARIABLE DE LAS INTERRUPCIONES
volatile int Start = 0;
