#include "cp_car.h"

#include <BluetoothSerial.h>
//#define USE_PIN // Uncomment this to use PIN during pairing. The pin is specified on the line below
const char *pin = "1211";

String device_name = "CP_IOT_CAR";

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

#if !defined(CONFIG_BT_SPP_ENABLED)
#error Serial Bluetooth not available or not enabled. It is only available for the ESP32 chip.
#endif

BluetoothSerial SerialBT;

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

  SerialBT.begin(device_name);
  Serial.printf("The device with name \"%s\" is started.\nNow you can pair it with Bluetooth!\n", device_name.c_str());
//Serial.printf("The device with name \"%s\" and MAC address %s is started.\nNow you can pair it with Bluetooth!\n", device_name.c_str(), SerialBT.getMacString()); // Use this after the MAC method is implemented
#ifdef USE_PIN
  SerialBT.setPin(pin);
  Serial.println("Using PIN");
#endif






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
  //car.forward();

  if (Serial.available()) {
    SerialBT.write(Serial.read());
  }
  if (SerialBT.available()) {
    Serial.write(SerialBT.read());
  }
  delay(20);
}
