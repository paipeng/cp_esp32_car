#ifndef _CP_CAR_H_
#define _CP_CAR_H_

#include "cp_motor_driver.h"

#define DOUBLE_MOTOR_DRIVER 1

class CPCar {
public:
  CPCar();
  // mode 0: back motor; 1: front motor; 2: 4WD
  void init(motor_driver_pin frontDriverPin, motor_driver_pin backDriverPin, int mode);
  void forward();
  void backward();
  void left();
  void right();
  void stop();
private:
  CPMotorDriver frontMotorDriver;
  CPMotorDriver backMotorDriver;
  int mode;
};
#endif