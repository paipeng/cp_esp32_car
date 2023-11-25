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
}
void CPCar::backward() {
}
void CPCar::left() {
}
void CPCar::right() {
}