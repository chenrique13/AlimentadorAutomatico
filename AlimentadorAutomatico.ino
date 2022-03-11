#include "Servo.h"              // Inclui a Biblioteca Servo.h
 
Servo servoMotor;               // Cria o objeto servo para programação

const int servo = 9;            //Define pino do Servo
const int led = 10;             //Define pino do Led
const int buzzer = 11;          //Define pino do Buzzer

int quantidade = 5;             // Quantidade de vezes que vai se repetir antes da pausa mais longa
int angulo = 0;                 // Ajusta o ângulo inicial do Servo
 
void setup() {
  servoMotor.attach(servo);     // Declara o pino do servo
  pinMode(led,OUTPUT);
  pinMode(buzzer,OUTPUT);
}
 
void loop() {
  Serial.println("Alimentador Automatico Ligado");
  digitalWrite(led, HIGH);
  iniciarBuzzer();
  for(int cont = 0; cont < quantidade; cont++) {
      for (angulo = 0; angulo <= 180; angulo += 10) {
        servoMotor.write(angulo); 
         delay(50);
      }
      delay(1000);
     
      for (angulo = 180; angulo >= 0; angulo -= 10) {
        servoMotor.write(angulo);
        delay(50);
      }
      delay(1000);
  }
  digitalWrite(led, LOW);
  delay(3000);
 // delay(28800000); //Pausa de 8 horas
}
void iniciarBuzzer(){
  tone(buzzer,4000);    
  delay(500);
  noTone(buzzer); 
   delay(500);
  tone(buzzer,4000);    
  delay(500);
  noTone(buzzer); 
  delay(500);
  tone(buzzer,4000);    
  delay(500);
  noTone(buzzer); 
}
