#include "cp_car.h"
#include <Arduino.h>

CPCar::CPCar() {
}

void CPCar::init(motor_driver_pin frontDriverPin, motor_driver_pin backDriverPin, int mode) {
  this->mode = mode;
  frontMotorDriver.setPins(frontDriverPin);
  backMotorDriver.setPins(backDriverPin);
}
void CPCar::forward() {
  Serial.println("car forward");
  if (mode == 2) {
    frontMotorDriver.backward();
    backMotorDriver.forward();
  } else if (mode == 1) {
    frontMotorDriver.backward();
  } else {
    backMotorDriver.forward();
  }
}
void CPCar::backward() {
  Serial.println("car backward");
  if (mode == 2) {
    frontMotorDriver.forward();
    backMotorDriver.backward();
  } else if (mode == 1) {
    frontMotorDriver.forward();
  } else {
    backMotorDriver.backward();
  }
}
void CPCar::left() {
  Serial.println("car left");
  if (mode == 2) {
    frontMotorDriver.left();
    backMotorDriver.left();
  } else if (mode == 1) {
    frontMotorDriver.left();
  } else {
    backMotorDriver.left();
  }
}
void CPCar::right() {
  Serial.println("car right");
  if (mode == 2) {
    frontMotorDriver.right();
    backMotorDriver.right();
  } else if (mode == 1) {
    frontMotorDriver.right();
  } else {
    backMotorDriver.right();
  }
}

void CPCar::stop() {
  Serial.println("car stop");
  if (mode == 2) {
    frontMotorDriver.stop();
    backMotorDriver.stop();
  } else if (mode == 1) {
    frontMotorDriver.stop();
  } else {
    backMotorDriver.stop();
  }

}