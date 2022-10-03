#include <FastLED.h>
#include "GyverEncoder.h"

Encoder enc1(3, 2);
unsigned long previousMillis1;      
unsigned long interval = 16000;

#define NUM_LEDS_PER_STRIP 95
CRGB Lenta1[NUM_LEDS_PER_STRIP];
CRGB Lenta2[NUM_LEDS_PER_STRIP];
CRGB Lenta3[NUM_LEDS_PER_STRIP];
CRGB Lenta4[NUM_LEDS_PER_STRIP];

int thisdelay = 100;          
int thishue = 0;             
int thissat = 255;           
int thisindex = 0;
int idex = 0;
int ihue1 = 212;                
int ihue2 = 212;
int ihue3 = 212;
int ihue4 = 212;
int ibright = 0;
int znach1 = 0;
int znach2 = 1;
int znach3 = 0;
int znach4 = 1;
int ledMode = 1;
int ihue_smena = 30;
int t1 = 1;
int ibright1 = 0;
int ibright2 = 255;
int n = 2;

void setup() {
  Serial.begin(9600);
  LEDS.setBrightness(255);
  FastLED.addLeds<NEOPIXEL, 6>(Lenta1, NUM_LEDS_PER_STRIP);
  FastLED.addLeds<NEOPIXEL, 7>(Lenta2, NUM_LEDS_PER_STRIP);
  FastLED.addLeds<NEOPIXEL, 8>(Lenta3, NUM_LEDS_PER_STRIP);
  FastLED.addLeds<NEOPIXEL, 9>(Lenta4, NUM_LEDS_PER_STRIP);
  previousMillis1 = millis();
}

void red_fade_fast() {
  if (znach1 == 0) {
    ihue1 = ihue1 + 1;
    if (ihue1 == 30) {
      znach1 = 1;
      ihue1 = ihue1 - 1;
    }
    if (ihue1 == 255) {
      ihue1 = 0;
      ihue1 = ihue1 + 1;
    }
  }
  if (znach1 == 1) {
    ihue1 = ihue1 - 1;
    if (ihue1 == 0) {
      ihue1 = 255;
      ihue1 = ihue1 - 1;
    }
    if (ihue1 == 140) {
      znach1 = 0;
      ihue1 = ihue1 + 1;
    }
  }
  for (int idex = 0 ; idex < NUM_LEDS_PER_STRIP; idex++ ) {
    Lenta1[idex] = CHSV(ihue1, thissat, 255);
  }
  if (znach2 == 0) {
    ihue2 = ihue2 + 1;
    if (ihue2 == 30) {
      znach2 = 1;
      ihue2 = ihue2 - 1;
    }
    if (ihue2 == 255) {
      ihue2 = 0;
      ihue2 = ihue2 + 1;
    }
  }
  if (znach2 == 1) {
    ihue2 = ihue2 - 1;
    if (ihue2 == 0) {
      ihue2 = 255;
      ihue2 = ihue2 - 1;
    }
    if (ihue2 == 140) {
      znach2 = 0;
      ihue2 = ihue2 + 1;
    }
  }
  for (int idex = 0 ; idex < NUM_LEDS_PER_STRIP; idex++ ) {
    Lenta2[idex] = CHSV(ihue2, thissat, 255);
  }
  if (znach3 == 0) {
    ihue3 = ihue3 + 1;
    if (ihue3 == 30) {
      znach3 = 1;
      ihue3 = ihue3 - 1;
    }
    if (ihue3 == 255) {
      ihue3 = 0;
      ihue3 = ihue3 + 1;
    }
  }
  if (znach3 == 1) {
    ihue3 = ihue3 - 1;
    if (ihue3 == 0) {
      ihue3 = 255;
      ihue3 = ihue3 - 1;
    }
    if (ihue3 == 140) {
      znach3 = 0;
      ihue3 = ihue3 + 1;
    }
  }
  for (int idex = 0 ; idex < NUM_LEDS_PER_STRIP; idex++ ) {
    Lenta3[idex] = CHSV(ihue3, thissat, 255);
  }
  if (znach4 == 0) {
    ihue4 = ihue4 + 1;
    if (ihue4 == 30) {
      znach4 = 1;
      ihue4 = ihue4 - 1;
    }
    if (ihue4 == 255) {
      ihue4 = 0;
      ihue4 = ihue4 + 1;
    }
  }
  if (znach4 == 1) {
    ihue4 = ihue4 - 1;
    if (ihue4 == 0) {
      ihue4 = 255;
      ihue4 = ihue4 - 1;
    }
    if (ihue4 == 140) {
      znach4 = 0;
      ihue4 = ihue4 + 1;
    }
  }
  for (int idex = 0 ; idex < NUM_LEDS_PER_STRIP; idex++ ) {
    Lenta4[idex] = CHSV(ihue4, thissat, 255);
  }
  LEDS.show();
  delay(thisdelay);
}

void change_mode(int newmode) {
  thissat = 255;
  switch (newmode) {
    case 1: thisdelay = 50; break;
    case 2: thisdelay = 10; break;
  }
  znach1 = 0;
  znach2 = 1;
  znach3 = 0;
  znach4 = 1;
  ihue_smena = 30;
  ledMode = newmode;
  ibright1 = 0;
  ibright2 = 255;
  Serial.println("change mode");
}

void change_ihue() {
  if (t1 == 1) {
    ihue_smena = ihue_smena - 1;
    if (ihue_smena == 0) {
      ihue_smena = 255;
      Serial.println("ihue_smena=255");
      ihue_smena = ihue_smena - 1;
    }
    if (ihue_smena == 212) {
      t1 = 0;
      Serial.println("ihue_smena=212");
    }
    for (int idex = 0 ; idex < NUM_LEDS_PER_STRIP; idex++ ) {
      Lenta1[idex] = CHSV(ihue_smena, thissat, 255);
      Lenta2[idex] = CHSV(ihue_smena, thissat, 255);
      Lenta3[idex] = CHSV(ihue_smena, thissat, 255);
      Lenta4[idex] = CHSV(ihue_smena, thissat, 255);
    }
    LEDS.show();
    delay(thisdelay);
  }
}

void perehod() {
  change_ihue();
  Serial.println("perehod test1");
  if (t1 == 0) {
    red_fade_fast();
    Serial.println("perehod test2");
  }
  LEDS.show();
  delay(thisdelay);
}

void one_color_all2() {
  t1 = 1;
  if (n == 1) {
    ibright2 = ibright2 - 1;
    if (ibright2 <= 0) {
      n = 2; 
    }
    Serial.println("test n=1");
    for (int idex = 0 ; idex < NUM_LEDS_PER_STRIP; idex++ ) {
      Lenta1[idex] = CHSV(ihue1, thissat, ibright2);
      Lenta2[idex] = CHSV(ihue2, thissat, ibright2);
      Lenta3[idex] = CHSV(ihue3, thissat, ibright2);
      Lenta4[idex] = CHSV(ihue4, thissat, ibright2);
    }
    LEDS.show();
  }
  if (n == 2) {
    ibright1 = ibright1 + 3;
    Serial.println("test n=2");
    if (ibright1 >= 255) {
      n = 3;
      Serial.println("test n=3");
    }
    for (int idex = 0 ; idex < NUM_LEDS_PER_STRIP; idex++ ) {
      Lenta1[idex] = CHSV(30, thissat, ibright1);
      Lenta2[idex] = CHSV(30, thissat, ibright1);
      Lenta3[idex] = CHSV(30, thissat, ibright1);
      Lenta4[idex] = CHSV(30, thissat, ibright1);
    }
    LEDS.show();
  }
}

void loop() {
  enc1.tick();
  switch (ledMode) {
    case  1: one_color_all2(); break;
    case  2: perehod(); break;
  }
  if (enc1.isTurn()) {
    previousMillis1 = millis();
    if (ledMode != 2) {
      ledMode = 2;
      change_mode(ledMode);
      n = 1;
    }
    Serial.println("turn");
  }
  if (millis() - previousMillis1 > interval) {
    if (ledMode == 2) {
      ledMode = 1;
      change_mode(ledMode);
      ihue1 = 212;                
      ihue2 = 212;
      ihue3 = 212;
      ihue4 = 212;
    }
  }
}
