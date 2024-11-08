#include "Wheel.h"

class Car {
  private:
    Wheel leftWheel;
    Wheel rightWheel;

  public:
    Car(int leftEnable, int leftHigh, int leftLow, int rightEnable, int rightHigh, int rightLow);

    void forward(int speedLeftWheel, int speedRightWheel);

    void backward(int speedLeftWheel, int speedRightWheel);

    void turnRight(int speed);

    void turnLeft(int speed);

    void stop();

    void routine();
};