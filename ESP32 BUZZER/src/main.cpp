#include <Arduino.h>
#include <Buzzer.h>

int btn = 12;
int buzzer = 13;
int intervalMusic = 2000;

void setup() {
  pinMode(btn, INPUT);
  Serial.begin(9600);
  
  ledcSetup(0, 2000, 8);

  delay(3000);
  while(true){
    asaBranca(buzzer, btn);
    delay(intervalMusic);
    imperialMarch(buzzer, btn);
    delay(intervalMusic);
    harryPotter(buzzer, btn);
    delay(intervalMusic);
    starWars(buzzer, btn);
    delay(intervalMusic);
    gameOfThrones(buzzer, btn);
    delay(intervalMusic);
    Doom(buzzer, btn);
    delay(intervalMusic);
  }
}

void loop() {
}