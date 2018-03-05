#include <Servo.h>

class Secuencia
  { private:
      int sup;
      int inf;
      int frecuencia;
      int frecuencia2;
      int actual;
      int checkSup;
      int checkInf;
      int cantSaltos;
      int salto;
      int sentido;
      int tiempoEspera;
  

      public:
      Secuencia(int s, int i, int fr, int fr2, int act, int cantS, int ckS, int ckI){
       sup = s;
       inf = i;
       frecuencia = fr;
       frecuencia2 = fr2;
       actual = act;
       cantSaltos = cantS;
       salto = (sup - inf)/cantSaltos;
       sentido = 1;
       tiempoEspera = frecuencia;
       checkSup = ckS;
       checkInf = ckI; 
       Serial.print(salto);
      }
      int siguientePosicion(){
          if(actual > sup || actual < inf ){
            sentido = sentido * -1;
          }
          if(actual < checkInf || actual > checkSup){
            tiempoEspera = frecuencia2; 
          }
          else{
            tiempoEspera = frecuencia;
          }
          actual = actual + (salto*sentido);
        
        delay(tiempoEspera);
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
Secuencia s(130,50,50,100,defaultPos,40,115,65);//Secuencia(int s, int i, int fr, int fr2, int act, int cantS, int ckS, int ckI)
Secuencia s2(90,110,50,100, defaultPos, 40, 100,90);







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
//servoMotorVertical.write(s2.siguientePosicion());



}


