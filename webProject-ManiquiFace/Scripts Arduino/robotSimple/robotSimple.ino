#include <Servo.h>


// Declaramos la variable para controlar el servo
Servo servoMotorHorizontal;
Servo servoMotorVertical;
Servo servoMotorLateral;


int inicial;
int fin;
int frecuencia;
int derecha;
int izquierda;
int actualH;
int actualV;
int actualL;
int pulsador = 4;
int indexSecuencia = 0;
int cantSecuencias = 2;



void inicializar(int i, Servo s) {
  s.write(i);
}


int mover(int a , int i, int f, Servo s, int intervalo) {
  Serial.print(indexSecuencia);
  int actual = a;
  int checkPoint = f - (15);
  int checkPoint2 = i + (15);

  s.write(f);
  delay(intervalo);
  s.write(i);
  delay(intervalo);
  return actual;
}


void iniciarServos() {
  servoMotorHorizontal.attach(6);
  servoMotorVertical.attach(7);
  servoMotorLateral.attach(8);

  inicializar(actualH, servoMotorHorizontal);
  delay(500);
  inicializar(actualV, servoMotorVertical);
  delay(500);
  inicializar(actualL, servoMotorLateral);
}
 boolean apretarBoton(int pin){
  while(digitalRead(pin) == HIGH){
  Serial.println("se esta apretando");
}
indexSecuencia = indexSecuencia + 1;
return true;
}



void setup() {
  // Iniciamos el monitor serie para mostrar el resultado
  Serial.begin(9600);
  inicial = 60;
  fin = 120;
  frecuencia = 6000;
  derecha = +2;
  izquierda = -2;
  actualH = 90;
  actualV = 90;
  actualL = 90;
  iniciarServos();


}

void loop() {
   if(digitalRead(pulsador) == HIGH){
  apretarBoton(pulsador);
  if(indexSecuencia == cantSecuencias){
    indexSecuencia = 0;
  }
}

  if (indexSecuencia == 0){
   actualH = mover(actualH, 50, 130, servoMotorHorizontal, frecuencia);

  }
  else{
    actualV = mover(actualV, 90, 110, servoMotorVertical, frecuencia);
  }
}
 

  

  
  
  //actualV = mover(actualV, 90, 110, servoMotorVertical, frecuencia);
  //actualL = mover(actualL, 100, 110, servoMotorLateral, frecuencia);










