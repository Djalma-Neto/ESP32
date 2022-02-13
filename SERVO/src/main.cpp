#include <Arduino.h>
#include <Servo.h>

const int SERVO = 13;
const int TOUCH = 12;

int value = 0;

int timePrint = 0;

Servo myservo;

void printar(int val, int value, int valueRead){
  Serial.print("val: ");
  Serial.println(val);

  Serial.print("value: ");
  Serial.println(value);

  Serial.print("valueRead: ");
  Serial.println(valueRead);
  Serial.println("--------------------");
}

void printServo(int val){
  int X = 100;
  int Y = 80;

  if(value == X){
    value = Y;
    myservo.write(value);
    delay(1000);
    myservo.write(90);
  } else {
    value = X;
    myservo.write(value);
    delay(1140);
    myservo.write(90);
  }

  int valueRead = myservo.read();
  printar(val, value, valueRead);
}

void setup() {
  Serial.begin(9600);
  myservo.attach(SERVO);
  myservo.write(90);
}

void loop() {
  int val = digitalRead(TOUCH);
  
  if(millis()-timePrint == 1000){
    if(val){
      printServo(val);
    }
    timePrint = millis();
  }
}