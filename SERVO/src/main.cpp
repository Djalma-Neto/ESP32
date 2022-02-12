#include <Arduino.h>
#include <ESP32Servo.h>

const int SERVO = 13;
const int TOUCH = 12;

int minUs = 1000;
int maxUs = 2000;
int value = 0;

Servo myservo;
ESP32PWM pwm;

void setup() {
  Serial.begin(9600);
}

void loop() {
  myservo.attach(SERVO);

  int val = digitalRead(TOUCH);

  if(val){
    if(value == 0){
      value = 180;
      myservo.write(value);
    }else{
      value = 0;
      myservo.write(value);
    }
  }

  delay(1000);
  printar(val, value);
}

void printar(int val, int value){
  Serial.print("val: ");
  Serial.println(val);

  Serial.print("value: ");
  Serial.println(value);
}