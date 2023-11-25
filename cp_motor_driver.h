#ifndef _CP_MOTOR_DRIVER_H_
#define _CP_MOTOR_DRIVER_H_


typedef struct _motor_driver_pin {
  int ena;
  int in1;
  int in2;
  int in3;
  int in4;
  int enb;
} motor_driver_pin;


class CPMotorDriver {
public:
  CPMotorDriver();
  CPMotorDriver(motor_driver_pin pin);
  void setPins(motor_driver_pin pin);
  void forward();
  void backward();
  void left();
  void right();
  void stop();

private:
  motor_driver_pin pins;
};

#endif