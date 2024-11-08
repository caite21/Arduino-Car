#include "Arduino.h"
#include "Wheel.h"

Wheel::Wheel(int enable, int inHigh, int inLow) {
  this->enable = enable;
  this->inHigh = inHigh;
  this->inLow = inLow;

  pinMode(enable, OUTPUT);
  pinMode(inHigh, OUTPUT);
  pinMode(inLow, OUTPUT);

  stop();
  setSpeed(default_speed);
}

void Wheel::setSpeed(int speed) {
  analogWrite(this->enable, speed);
}

void Wheel::forward(int speed) {
  setSpeed(speed);
  digitalWrite(this->inHigh, HIGH);
  digitalWrite(this->inLow, LOW);
}

void Wheel::backward(int speed) {
  setSpeed(speed);
  digitalWrite(this->inHigh, LOW);
  digitalWrite(this->inLow, HIGH);
}

void Wheel::stop() {
  digitalWrite(this->inHigh, LOW);
  digitalWrite(this->inLow, LOW);
}