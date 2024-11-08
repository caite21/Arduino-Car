/*
  Arduino Joystick-Controlled 2-Wheel Car

  Author: caite21

  Description: Joystick controls 2 TT motors. Y axis determines the speed forward or 
    backwards. X axis determines how sharp to turn left or right. The car performs a 
    programmed routine when the joystick is pressed.
  
  OOP Structure: Car class contains 2 Wheel classes.
*/

#include "Car.h"


// Left wheel
int const enA = 9;
int const in1 = 8;
int const in2 = 7;
// Right wheel
int const in3 = 5;
int const in4 = 4;
int const enB = 3;
// Joystick
int const joyX = A0;
int const joyY = A1;
int const joyPress = 10;

Car car = Car(enA, in1, in2, enB, in4, in3);

void setup() {
  Serial.begin(9600);
  pinMode(joyPress, INPUT_PULLUP);
  delay(100);
}

void loop() {
  // Car is steered by joystick or does a programmed routine when joystick is pressed
  if (!digitalRead(joyPress)) {
    Serial.println("routine");
    car.routine();
  }
  else {
    joystickControl();
    delay(200);
  }
  return;
}

void joystickControl() {
  // Adjust to calibrate joystick
  int const X_THRESH = 495;
  int const Y_THRESH = 516;
  int const DELTA = 40;

  int const MAX_SPEED = 100;
  int const MIN_SPEED = 60;

  int X = analogRead(joyX);
  int Y = analogRead(joyY);
  int speedForward = map(Y, 0, Y_THRESH, MAX_SPEED, MIN_SPEED);
  int speedBackward = map(Y, Y_THRESH, 1023, MIN_SPEED, MAX_SPEED);
  
  Serial.print(X);
  Serial.print("\t");
  Serial.println(Y);

  // Resting joystick
  if ( X < X_THRESH + DELTA && X > X_THRESH - DELTA && Y < Y_THRESH + DELTA && Y > Y_THRESH - DELTA ) {
    car.stop();
    Serial.println("stop");
    return;
  } 
  
  // Direction
  if (Y < (Y_THRESH+100)) {
    // Speed
    float speedLeft = map(X, 0, X_THRESH - DELTA, speedForward, MIN_SPEED);
    float speedRight = map(X, X_THRESH + DELTA, 1023, MIN_SPEED, speedForward);
    if (X < (0 + DELTA)) {
      car.turnLeft(speedForward);
      Serial.print(speedForward);
      Serial.println(" sharp left");
    }
    else if (X > (1023 - DELTA)) {
      car.turnRight(speedForward);
      Serial.print(speedForward);
      Serial.println(" sharp right");
    }
    else if (X < (X_THRESH - DELTA)) {
      car.forward(speedLeft, speedForward);
      Serial.print(speedLeft);
      Serial.print(" ");
      Serial.print(speedForward);
      Serial.println(" forward slight left");
    } 
    else if (X > (X_THRESH + DELTA)) {
      car.forward(speedForward, speedRight);
      Serial.print(speedForward);
      Serial.print(" ");
      Serial.print(speedRight);
      Serial.println(" forward slight right");
    } 
    else {
      car.forward(speedForward, speedForward);
      Serial.print(speedForward);
      Serial.println(" forward");
    }
  }
  else {
    // Only straight backup 
    float speedLeft = map(X, 0, X_THRESH - DELTA, speedBackward, MIN_SPEED);
    float speedRight = map(X, X_THRESH + DELTA, 1023, MIN_SPEED, speedBackward);
    car.backward(speedBackward, speedBackward);
    Serial.print(speedBackward);
    Serial.println(" backward");
  }
  
}
