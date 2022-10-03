#include "GyverButton.h"

#define BTN1 4      // кнопка подключена сюда (PIN --- КНОПКА --- GND)
#define BTN2 5          // кнопка подключена сюда (PIN --- КНОПКА --- GND)
#define CW 2
int RelayMode = 0;

GButton butt1(BTN1);
GButton butt2(BTN2);

void setup() {
  Serial.begin(9600);
  butt1.setTickMode(AUTO);
  butt2.setTickMode(AUTO);
  pinMode(CW, OUTPUT);
}

void loop() {
  if (butt1.isClick()) Serial.println("1");
  if (butt2.isClick()) Serial.println("2");
  if (Serial.available() > 0) {     
    RelayMode = Serial.parseInt(); 
    switch (RelayMode) {
      case 1: digitalWrite(CW, HIGH); break;
      case 2: digitalWrite(CW, LOW); break;
      default: break;
  }
  }
}
