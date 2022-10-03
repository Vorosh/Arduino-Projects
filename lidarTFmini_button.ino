#include "TFLidar.h"

#define BTN1 5      // кнопка подключена сюда (PIN --- КНОПКА --- GND)
#define BTN2 6          // кнопка подключена сюда (PIN --- КНОПКА --- GND)

#include "GyverButton.h"
 
#include <SoftwareSerial.h>
 
#define LIDAR_SERIAL    mySerial
 
SoftwareSerial mySerial(4, 2);
TFLidar lidar;
GButton butt1(BTN1);
GButton butt2(BTN2);

int dist;
int lastValue;
int currentValue;
int a;
String myStr;


void setup() {
  Serial.begin(9600);
  while (!Serial);
 
  //Serial.print("Serial init OK\r\n");
  mySerial.begin(115200);
  lidar.begin(&LIDAR_SERIAL);
  butt1.setTickMode(AUTO);
  butt2.setTickMode(AUTO);    
}

void loop() {
  if (butt1.isClick()) Serial.println("a");
  if (butt2.isClick()) Serial.println("b");
  lidar.getData(dist);
  // Вычисляем расстояние до объекта
  currentValue = dist;
  // Задаем диапазон от 0 до 3 метров
  currentValue = constrain(currentValue, 0, 300); 
  if (currentValue!=lastValue + abs(a)){
    myStr = String(currentValue);
    Serial.println(myStr);
  }
  lastValue = dist;
  delay(10); 
}
