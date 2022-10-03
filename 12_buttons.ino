/*
   Пример использования библиотеки GyverButton, 5 кнопок
   Режим опроса - автоматический
*/

#define BTN1 2			// кнопка подключена сюда (PIN --- КНОПКА --- GND)
#define BTN2 3        	// кнопка подключена сюда (PIN --- КНОПКА --- GND)
#define BTN3 4        	// кнопка подключена сюда (PIN --- КНОПКА --- GND)
#define BTN4 5       	// кнопка подключена сюда (PIN --- КНОПКА --- GND)
#define BTN5 6        	// кнопка подключена сюда (PIN --- КНОПКА --- GND)
#define BTN6 7          // кнопка подключена сюда (PIN --- КНОПКА --- GND)
#define BTN7 8          // кнопка подключена сюда (PIN --- КНОПКА --- GND)
#define BTN8 9          // кнопка подключена сюда (PIN --- КНОПКА --- GND)
#define BTN9 10          // кнопка подключена сюда (PIN --- КНОПКА --- GND)
#define BTN10 11          // кнопка подключена сюда (PIN --- КНОПКА --- GND)
#define BTN11 12          // кнопка подключена сюда (PIN --- КНОПКА --- GND)
#define BTN12 1          // кнопка подключена сюда (PIN --- КНОПКА --- GND)

#include "GyverButton.h"
GButton butt1(BTN1);
GButton butt2(BTN2);
GButton butt3(BTN3);
GButton butt4(BTN4);
GButton butt5(BTN5);
GButton butt6(BTN6);
GButton butt7(BTN7);
GButton butt8(BTN8);
GButton butt9(BTN9);
GButton butt10(BTN10);
GButton butt11(BTN11);
GButton butt12(BTN12);

void setup() {
  Serial.begin(9600);
  butt1.setTickMode(AUTO);
  butt2.setTickMode(AUTO);
  butt3.setTickMode(AUTO);
  butt4.setTickMode(AUTO);
  butt5.setTickMode(AUTO);
  butt6.setTickMode(AUTO);
  butt7.setTickMode(AUTO);
  butt8.setTickMode(AUTO);
  butt9.setTickMode(AUTO);
  butt10.setTickMode(AUTO);
  butt11.setTickMode(AUTO);
  butt12.setTickMode(AUTO);
}

void loop() {
  if (butt1.isClick()) Serial.println("1");
  if (butt2.isClick()) Serial.println("2");
  if (butt3.isClick()) Serial.println("3");
  if (butt4.isClick()) Serial.println("4");
  if (butt5.isClick()) Serial.println("5");
  if (butt6.isClick()) Serial.println("6");
  if (butt7.isClick()) Serial.println("7");
  if (butt8.isClick()) Serial.println("8");
  if (butt9.isClick()) Serial.println("9");
  if (butt10.isClick()) Serial.println("10");
  if (butt11.isClick()) Serial.println("11");
  if (butt12.isClick()) Serial.println("12");
}
