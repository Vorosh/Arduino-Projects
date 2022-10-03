#include "Keyboard.h"

#define BTN1 2      
#define BTN2 3          
#define BTN3 4          
#define BTN4 5          
#define BTN5 6          
#define BTN6 7
#define BTN7 8

#include "GyverButton.h"
GButton butt1(BTN1);
GButton butt2(BTN2);
GButton butt3(BTN3);
GButton butt4(BTN4);
GButton butt5(BTN5);
GButton butt6(BTN6);
GButton butt7(BTN7);

void setup() {
  Serial.begin(9600);
  butt1.setTickMode(AUTO);
  butt2.setTickMode(AUTO);
  butt3.setTickMode(AUTO);
  butt4.setTickMode(AUTO);
  butt5.setTickMode(AUTO);
  butt6.setTickMode(AUTO);
  butt7.setTickMode(AUTO);
  Keyboard.begin();
}

void loop() {
  if (butt1.isClick()) Keyboard.write('6');
  if (butt2.isClick()) Keyboard.write('1');
  if (butt3.isClick()) Keyboard.write('5');
  if (butt4.isClick()) Keyboard.write('7');
  if (butt5.isClick()) Keyboard.write('8');
  if (butt6.isClick()) Keyboard.write('2');
  if (butt7.isClick()) Keyboard.write('3');
}
