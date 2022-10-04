#include "GyverEncoder.h"
Encoder enc1(13, 12);
Encoder enc2(11, 10);
Encoder enc3(9, 8);
Encoder enc4(7, 6);
Encoder enc5(5, 4);
Encoder enc6(3, 2);
Encoder enc7(24, 22);

int value1 = 0;
int value2 = 0;
int value3 = 0;
int value4 = 0;
int value5 = 0;
int value6 = 0;
int value7 = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  // обязательная функция отработки. Должна постоянно опрашиваться
  enc1.tick();
  enc2.tick();
  enc3.tick();
  enc4.tick();
  enc5.tick();
  enc6.tick();
  enc7.tick();
  
  if (enc1.isLeft()){                                 //энкодер1 поворот влево
    value1--;
    if (value1 <= -45) {
      Serial.println("1");
      value1 = 0;
    }
  }
  if (enc1.isRight()){
    value1++;
    if (value1 >= 45) {
      Serial.println("1");
      value1 = 0;
    }
  }
  if (enc2.isLeft()){                                //энкодер2 поворот влево
    value2--;
    if (value2 <= -45) {
      Serial.println("2");
      value2 = 0;
    }
  }
  if (enc2.isRight()){
    value2++;
    if (value2 >= 45) {
      Serial.println("2");
      value2 = 0;
    }
  }
  if (enc3.isLeft()){                                //энкодер3 поворот влево
    value3--;
    if (value3 <= -45) {
      Serial.println("3");
      value3 = 0;
    }
  }
  if (enc3.isRight()){
    value3++;
    if (value3 >= 45) {
      Serial.println("3");
      value3 = 0;
    }
  }
  if (enc4.isLeft()){                                //энкодер4 поворот влево
    value4--;
    if (value4 <= -45) {
      Serial.println("7");
      value4 = 0;
    }
  }
  if (enc4.isRight()){
    value4++;
    if (value4 >= 45) {
      Serial.println("7");
      value4 = 0;
    }
  }
  if (enc5.isLeft()){                                //энкодер5 поворот влево
    value5--;
    if (value5 <= -45) {
      Serial.println("5");
      value5 = 0;
    }
  }
  if (enc5.isRight()){
    value5++;
    if (value5 >= 45) {
      Serial.println("5");
      value5 = 0;
    }
  }
  if (enc6.isLeft()){                                //энкодер6 поворот влево
    value6--;
    if (value6 <= -45) {
      Serial.println("4");
      value6 = 0;
    }
  }
  if (enc6.isRight()){
    value6++;
    if (value6 >= 45) {
      Serial.println("4");
      value6 = 0;
    }
  }
  if (enc7.isLeft()){                                //энкодер7 поворот влево
    value7--;
    if (value7 <= -45) {
      Serial.println("6");
      value7 = 0;
    }
  }
  if (enc7.isRight()){
    value7++;
    if (value7 >= 45) {
      Serial.println("6");
      value7 = 0;
    }  
  }
}
