/*
   Режим опроса - автоматический
*/

#define BTN1 3			// кнопка подключена сюда (PIN --- КНОПКА --- GND)
#define BTN2 5        	// кнопка подключена сюда (PIN --- КНОПКА --- GND)
#define BTN3 9        	// кнопка подключена сюда (PIN --- КНОПКА --- GND)
#define BTN4 11          // кнопка подключена сюда (PIN --- КНОПКА --- GND)

#include "GyverButton.h"
GButton butt1(BTN1);
GButton butt2(BTN2);
GButton butt3(BTN3);
GButton butt4(BTN4);

void setup() {
  Serial.begin(9600);
  butt1.setTickMode(AUTO);
  butt2.setTickMode(AUTO);
  butt3.setTickMode(AUTO);
  butt4.setTickMode(AUTO);
}

void loop() {
  if (butt1.isClick()) Serial.println("1");
  if (butt2.isClick()) Serial.println("2");
  if (butt3.isClick()) Serial.println("3");
  if (butt4.isClick()) Serial.println("4");
}
