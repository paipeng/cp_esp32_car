#include "cp_car.h"

// Motor Driver 0: back
#define DRIVER_0_IN1_PIN 27  // The ESP32 pin GPIO27 connected to the IN1 pin L298N
#define DRIVER_0_IN2_PIN 26  // The ESP32 pin GPIO26 connected to the IN2 pin L298N
#define DRIVER_0_IN3_PIN 25  // The ESP32 pin GPIO25 connected to the IN3 pin L298N
#define DRIVER_0_IN4_PIN 33  // The ESP32 pin GPIO33 connected to the IN4 pin L298N

// Motor Driver 1: front
#define DRIVER_1_IN1_PIN 4   // The ESP32 pin GPIO27 connected to the IN1 pin L298N
#define DRIVER_1_IN2_PIN 0   // The ESP32 pin GPIO26 connected to the IN2 pin L298N
#define DRIVER_1_IN3_PIN 2   // The ESP32 pin GPIO25 connected to the IN3 pin L298N
#define DRIVER_1_IN4_PIN 15  // The ESP32 pin GPIO33 connected to the IN4 pin L298N

CPCar car;


void setup() {
  delay(1000);
  Serial.begin(115200);

  Serial.println("Serial inited");
  delay(2000);


  motor_driver_pin front_driver_pin;
  front_driver_pin.in1 = DRIVER_0_IN1_PIN;
  front_driver_pin.in2 = DRIVER_0_IN2_PIN;
  front_driver_pin.in3 = DRIVER_0_IN3_PIN;
  front_driver_pin.in4 = DRIVER_0_IN4_PIN;

  motor_driver_pin back_driver_pin;
  back_driver_pin.in1 = DRIVER_1_IN1_PIN;
  back_driver_pin.in2 = DRIVER_1_IN2_PIN;
  back_driver_pin.in3 = DRIVER_1_IN3_PIN;
  back_driver_pin.in4 = DRIVER_1_IN4_PIN;

  car.init(front_driver_pin, back_driver_pin, 2);

  delay(2000);  //延时200ms
}

void loop() {
  car.forward();
}
