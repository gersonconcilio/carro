#include <HCSR04.h>

// Define os pinos de utilização do Driver L298.
int motorA1  = 6;
int motorA2  = 5;
int motorB1  = 10;
int motorB2  = 11;

int eccoPinA  = 9;
int eccoPinB  = 12;
int eccoPinC  = 13;
int trigPin   = 4;

int speedR = 250;
int speedL = 255;

HCSR04 hF(4, 9); //initialisation class HCSR04 (trig pin , echo pin)   FRENTE
HCSR04 hD(4, 12); //initialisation class HCSR04 (trig pin , echo pin)  DIREITA
HCSR04 hE(4, 13); //initialisation class HCSR04 (trig pin , echo pin)  ESQUERDA

void setup() {
  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);
}

void loop(){

int dist = hF.dist();
  
  if (dist < 25) {
    
    move('S');   //PARA
    
    delay(400);
    
    int distR = hD.dist();
      
    delay(400);
    int distL = hE.dist();
    
    
    if(distR > distL) {
      if (dist < 10){
        move('H');  //TRÁS ESQUERDA
      } else {
        move('R');  //DIREITA
      }
      delay(420);
    } else {
        if (dist < 10){
        move('J');   //TRÁS DIREITA
      } else {
        move('L');   //ESQUERDA
      }

     delay(280);
    }
    move('S');      //PARA
  } else {
    move('F');      //FRENTE
  }
  
  delay(50); 
}

void move (char state) {
    // Se o estado recebido for igual a 'F', o carro se movimenta para frente.
  if (state == 'F') {
    analogWrite(motorB1, speedR);
    analogWrite(motorA1, speedL);
    analogWrite(motorA2, 0);
    analogWrite(motorB2, 0);
  }

    else if (state == 'I') {  // Se o estado recebido for igual a 'I', o carro se movimenta para Frente Esquerda.
    analogWrite(motorA1, speedL); 
    analogWrite(motorA2, 0);
    analogWrite(motorB1, 100);    
    analogWrite(motorB2, 0);
  }

    else if (state == 'G') {   // Se o estado recebido for igual a 'G', o carro se movimenta para Frente Direita.
    analogWrite(motorA1, 100); 
    analogWrite(motorA2, 0);
    analogWrite(motorB1, speedR);      
    analogWrite(motorB2, 0);
  }

  else if (state == 'B') { // Se o estado recebido for igual a 'B', o carro se movimenta para trás.
    analogWrite(motorA1, 0);
    analogWrite(motorB1, 0);
    analogWrite(motorB2, 255);
    analogWrite(motorA2, 255);
  }

   else if (state == 'H') {  // Se o estado recebido for igual a 'H', o carro se movimenta para Trás Esquerda.
    analogWrite(motorA1, 0);   
    analogWrite(motorA2, 255);
    analogWrite(motorB1, 0); 
    analogWrite(motorB2, 255);
  }
  
  else if (state == 'J') {  // Se o estado recebido for igual a 'J', o carro se movimenta para Trás Direita.
    analogWrite(motorA1, 0);   
    analogWrite(motorA2, 255);
    analogWrite(motorB1, 0);   
    analogWrite(motorB2, 255);
  }

  else if (state == 'L') {   // Se o estado recebido for igual a 'L', o carro se movimenta para esquerda.
    analogWrite(motorA1, 0);
    analogWrite(motorA2, speedL);
    analogWrite(motorB1, speedR);
    analogWrite(motorB2, 0);
  }
  else if (state == 'R') {   // Se o estado recebido for igual a 'R', o carro se movimenta para direita.
    analogWrite(motorA1, speedL);
    analogWrite(motorA2, 0);
    analogWrite(motorB1, 0);
    analogWrite(motorB2, speedR);
  }
  else if (state == 'S') {   // Se o estado recebido for igual a 'S', o carro permanece parado.
    analogWrite(motorA1, 0);
    analogWrite(motorA2, 0);
    analogWrite(motorB1, 0);
    analogWrite(motorB2, 0);
  }
}