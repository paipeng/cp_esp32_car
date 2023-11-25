#include "cp_motor_driver.h"
#include <Arduino.h>

CPMotorDriver::CPMotorDriver() {
}

CPMotorDriver::CPMotorDriver(motor_driver_pin pin)
  : pins(pin) {
  setPins(pin);
}

void CPMotorDriver::setPins(motor_driver_pin pin) {
  pins = pin;
  pinMode(pins.in1, OUTPUT);
  pinMode(pins.in2, OUTPUT);
  pinMode(pins.in3, OUTPUT);
  pinMode(pins.in4, OUTPUT);
}

void CPMotorDriver::forward() {
  digitalWrite(pins.in1, LOW);
  digitalWrite(pins.in2, HIGH);
  digitalWrite(pins.in3, HIGH);
  digitalWrite(pins.in4, LOW);
}
void CPMotorDriver::backward() {
  digitalWrite(pins.in1, HIGH);
  digitalWrite(pins.in2, LOW);
  digitalWrite(pins.in3, LOW);
  digitalWrite(pins.in4, HIGH);
}
void CPMotorDriver::left() {
  digitalWrite(pins.in1, LOW);
  digitalWrite(pins.in2, HIGH);
  digitalWrite(pins.in3, LOW);
  digitalWrite(pins.in4, HIGH);
}
void CPMotorDriver::right() {
  digitalWrite(pins.in1, HIGH);
  digitalWrite(pins.in2, LOW);
  digitalWrite(pins.in3, HIGH);
  digitalWrite(pins.in4, LOW);
}

void CPMotorDriver::stop() {
  digitalWrite(pins.in1, LOW);
  digitalWrite(pins.in2, LOW);
  digitalWrite(pins.in3, LOW);
  digitalWrite(pins.in4, LOW);
}