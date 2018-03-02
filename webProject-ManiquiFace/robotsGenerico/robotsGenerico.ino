#include <Servo.h>


// Declaramos la variable para controlar el servo
Servo servoMotorHorizontal;
Servo servoMotorVertical;
Servo servoMotorLateral;

int indexSecuencia = 0;
int cantSecuencias = 1;
int defaultPos = 90;

int pulsador = 4;

class Secuencia
  { private:
      int sup;
      int inf;
      int frecuencia;
      int difFrec;
      int actual;
      int checkSup;
      int checkInf;
      int cantSaltos;
      int salto;
  

      public:
      Secuencia(int s, int i, int fr, int dFr, int act, int ckS, int ckI, int cantS){
       sup = s;
       inf = i;
       frecuencia = fr;
       difFrec = dFr;
       actual = act;
       checkSup = ckS;
       checkInf = ckI;
       cantSaltos = cantS;
       salto = (sup - inf)/cantSaltos;
       Serial.print(salto);
      }
      int siguientePosicion(){
        
      }

};



void iniciarServos() {
  servoMotorHorizontal.attach(6);
  servoMotorVertical.attach(7);
  servoMotorLateral.attach(8);

  servoMotorHorizontal.write(defaultPos);
  delay(500);
  servoMotorVertical.write(defaultPos);
  delay(500);
  servoMotorLateral.write(defaultPos);
  delay(500);

}

 boolean apretarBoton(int pin){
  while(digitalRead(pin) == HIGH){
  Serial.println("se esta apretando");
}
indexSecuencia = indexSecuencia + 1;
return true;
}



void setup() {
  Serial.begin(9600);
  iniciarServos();
  Secuencia s(1,1,1,1,1,1,1,1);

}

void loop() {
if(digitalRead(pulsador) == HIGH){
  apretarBoton(pulsador);
  if(indexSecuencia == cantSecuencias){
    indexSecuencia = 0;
  }
}
}


