
//定义LED1管脚
const int CP_GPIO[8] = {15, 2, 0, 4, 16, 17, 5, 18};

void setup() {
  delay(1000);
  Serial.begin(115200);

  Serial.println("Serial inited");
  delay(2000);

  //设置LED1引脚为输出模式  
  for (int i = 0; i < 8; i++) {
    pinMode(CP_GPIO[i], OUTPUT);
  }
  
  //LED1引脚输出高电平，点亮
  setState(HIGH);
  delay(2000);//延时200ms
  setState(LOW);
}

void setState(int state) {
  for (int i = 0; i < 8; i++) {
    digitalWrite(CP_GPIO[i], state);
  }
}

void blink(int gpio) {
  digitalWrite(gpio, HIGH);//LED1引脚输出高电平，点亮
  delay(200);//延时200ms
  digitalWrite(gpio, LOW);//LED1引脚输出低电平，熄灭
  delay(200);//延时200ms
}

void loop() {
  for (int i = 0; i < 8; i++) {
    blink(CP_GPIO[i]);
  }  
}
