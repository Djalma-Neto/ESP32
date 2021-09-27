#include <Arduino.h>
#include <ESP32Servo.h>

Servo ServoMotor;

//Pino do potenciometro
const int pino_pot = 12;
//Pino de controle do motor
const int pino_motor = 13;
int valor;
int newValor;
int porcentagem;


void setup() {
  Serial.begin(9600);
  ServoMotor.attach(pino_motor);
  Serial.println("Aguardando 5 segundos....");
  delay(5000);
}

void loop() {
  //Le o valor do potenciometro
  valor = analogRead(pino_pot);

  // transforma o valor em porcentagem(0 ~ 100)
  porcentagem = (valor*100)/4095;

  //Converte o valor para uma faixa entre 0 e 120 que é o valor maximo que o motor em uso suporta
  newValor = map(porcentagem, 0, 100, 0, 120);

  //Mostra o valor no serial monitor
  Serial.print("Potência: ");
  Serial.print(porcentagem);
  Serial.println("%");
  //Envia o valor para o motor
  ServoMotor.write(newValor);
}