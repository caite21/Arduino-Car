#include "Car.h"
#include "Arduino.h"

Car::Car(int leftEnable, int leftHigh, int leftLow, int rightEnable, int rightHigh, int rightLow) 
  : leftWheel(leftEnable, leftHigh, leftLow), 
    rightWheel(rightEnable, rightHigh, rightLow) {
}

void Car::forward(int speedLeftWheel, int speedRightWheel) {
  leftWheel.forward(speedLeftWheel);
  rightWheel.forward(speedRightWheel);
}

void Car::backward(int speedLeftWheel, int speedRightWheel) {
  leftWheel.backward(speedLeftWheel);
  rightWheel.backward(speedRightWheel);
}

void Car::turnRight(int speed) {
  leftWheel.forward(speed);
  rightWheel.stop();
}

void Car::turnLeft(int speed) {
  leftWheel.stop();
  rightWheel.forward(speed);
}

void Car::stop() {
  leftWheel.stop();
  rightWheel.stop();
}

void Car::routine() {
  // Give user time to put down joystick
  delay(3000);

  forward(100, 100);
  delay(600);
  turnLeft(120);
  delay(800);
  backward(100, 160);
  delay(700);

  // Rock back and forth
  for (int i = 0; i < 2; i++) {
    forward(100, 100);
    delay(700);
    forward(70, 70);
    delay(200);
    backward(100, 110);
    delay(700);
    backward(70, 70);
    delay(200);
  }

  stop();
  delay(200);

  turnLeft(200);
  delay(500);
  turnRight(200);
  delay(550);

  // Swivel forward
  for (int i = 0; i < 2; i++) {
    forward(220, 60);
    delay(300);
    forward(60, 230);
    delay(300);
  }
  
  stop();
  delay(400);

  // Backup to starting point
  backward(125, 110);
  delay(800);
  backward(130, 60);
  delay(420);

  stop();
}