#include <Servo.h>

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
      int sentido;
  

      public:
      Secuencia(int s, int i, int fr, int dFr, int act, int cantS){
       sup = s;
       inf = i;
       frecuencia = fr;
       difFrec = dFr;
       actual = act;
       cantSaltos = cantS;
       salto = (sup - inf)/cantSaltos;
       sentido = 1;
       Serial.print(salto);
      }
      int siguientePosicion(){
        if(sentido == 1){
          if(actual <= sup ){
            actual = actual  + (salto*sentido);
          }
          else{
            sentido = sentido * -1;
          }
        }
        else{
          if (actual> inf){
            actual = actual + (salto*sentido);
          }
          else{
            sentido = sentido * -1;

          }
        }
        delay(frecuencia);
        return actual;
        
      }

};


// Declaramos la variable para controlar el servo
Servo servoMotorHorizontal;
Servo servoMotorVertical;
Servo servoMotorLateral;

int indexSecuencia = 0;
int cantSecuencias = 1;
int defaultPos = 90;

int pulsador = 4;
Secuencia s(130,50,50,50,defaultPos,40);;







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
  

}

void loop() {
if(digitalRead(pulsador) == HIGH){
  apretarBoton(pulsador);
  if(indexSecuencia == cantSecuencias){
    indexSecuencia = 0;
  }
}
Serial.print(s.siguientePosicion());
//servoMotorHorizontal.write(s.siguientePosicion());


}


