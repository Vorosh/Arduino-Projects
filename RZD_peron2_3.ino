#include "Bounce2.h"
#define CW 7 // CW инициализируется на контакте 7 штора//
#define CCW 8 // CCW инициализируется на контакте 8 штора//
#define CW2 9 // баллерины 9 контакт// 
#define CCW2 10 // баллерины 10 контакт//
//#define PIN_INPUT_PULLUP 2
#define PIN_LED 13

Bounce bouncer = Bounce();
int RelayMode = 0;
int buttonState = 0;

unsigned long StartTime = 0;
unsigned long Interval = 40000;  // таймер, после которого идет loop в миллисекундах

void setup() { 

  Serial.begin(9600);
  bouncer .attach(2); // устанавливаем кнопку
  bouncer .interval(5); // устанавливаем параметр stable interval = 5 мс
  pinMode(CW, OUTPUT); // настраиваем CW в качестве выхода//
  pinMode(CCW, OUTPUT); // настраиваем CCW в качестве выхода//
  //pinMode(PIN_INPUT_PULLUP, INPUT_PULLUP);
  pinMode(PIN_LED, OUTPUT);
  pinMode(2 ,INPUT); // кнопка на пине 2
  digitalWrite(2 ,HIGH);
  pinMode(CW2, OUTPUT);
  pinMode(CCW2, OUTPUT);

}

void loop() { // цикл отрабатывает бесконечное количество раз//
  if (bouncer.update()) { //если произошло событие
    if (bouncer.read()==0) { //если кнопка нажата 
      Serial.println("p"); 
  }
 }
  
  if (Serial.available() > 0) {     
    RelayMode = Serial.parseInt();
    StartTime = millis(); 
    switch (RelayMode) {
      case 1: digitalWrite(CW, LOW); digitalWrite(CCW, LOW); delay(500); digitalWrite(CCW, HIGH); break;      // поднятие шторы
      case 2: digitalWrite(CW, LOW); digitalWrite(CCW, LOW); delay(500); digitalWrite(CW, HIGH); break;     // опускание шторы
      case 3: digitalWrite(CW2, LOW); digitalWrite(CCW2, LOW); delay(500); digitalWrite(CW2, HIGH); break;
      case 4: digitalWrite(CW2, LOW); digitalWrite(CCW2, LOW); delay(500); digitalWrite(CCW2, HIGH); break;
      default: digitalWrite(CW, LOW); delay(500); digitalWrite(CCW, LOW); digitalWrite(CW2, LOW); delay(500); digitalWrite(CCW2, LOW); break;
  }
  }
  else {
    if (StartTime != 0 && millis() - StartTime < Interval) {
      //Serial.println("timer work");
  } else {
    StartTime = 0;
    //Serial.println("timer stop");
    digitalWrite(CW, LOW); delay(500); digitalWrite(CCW, LOW); digitalWrite(CW2, LOW); digitalWrite(CCW2, LOW);
  }
  }
}
