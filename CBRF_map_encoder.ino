#include <FastLED.h>
#include "GyverEncoder.h"

Encoder enc1(3, 2);
int max_bright = 255;

unsigned long previousMillis1 = 0;      //храним время последнего Включения светодиода 1
unsigned long interval = 11000;
volatile boolean changeFlag;

#define NUM_LEDS_PER_STRIP 95
CRGB Lenta1[NUM_LEDS_PER_STRIP];
CRGB Lenta2[NUM_LEDS_PER_STRIP];
CRGB Lenta3[NUM_LEDS_PER_STRIP];
CRGB Lenta4[NUM_LEDS_PER_STRIP];

int thisdelay = 100;          //-FX LOOPS DELAY VAR
int thisstep = 10;           //-FX LOOPS DELAY VAR
int thishue = 0;             //-FX LOOPS DELAY VAR
int thissat = 255;           //-FX LOOPS DELAY VAR

int thisindex = 0;
//int thisRED = 0;
//int thisGRN = 0;
//int thisBLU = 0;

int idex = 0;                //-LED INDEX (0 to LED_COUNT-1
int ihue1 = 212;                //-HUE (0-255)
int ihue2 = 212;
int ihue3 = 212;
int ihue4 = 212;
int ibright = 0;             //-BRIGHTNESS (0-255)
int isat = 0;                //-SATURATION (0-255)
int bouncedirection = 0;     //-SWITCH FOR COLOR BOUNCE (0-1)
float tcount = 0.0;          //-INC VAR FOR SIN LOOPS
int lcount = 0;              //-ANOTHER COUNTING VAR
int znach1 = 0;
int znach2 = 1;
int znach3 = 0;
int znach4 = 1;
int ledMode = 3;
int ihue_smena = 30;
int t1 = 1;

void setup() {
  Serial.begin(9600);
  LEDS.setBrightness(240);
  // tell FastLED there's 60 NEOPIXEL leds on pin 10
  FastLED.addLeds<NEOPIXEL, 6>(Lenta1, NUM_LEDS_PER_STRIP);

  // tell FastLED there's 60 NEOPIXEL leds on pin 11
  FastLED.addLeds<NEOPIXEL, 7>(Lenta2, NUM_LEDS_PER_STRIP);

  // tell FastLED there's 60 NEOPIXEL leds on pin 12
  FastLED.addLeds<NEOPIXEL, 8>(Lenta3, NUM_LEDS_PER_STRIP);
  
  // tell FastLED there's 60 NEOPIXEL leds on pin 12
  FastLED.addLeds<NEOPIXEL, 9>(Lenta4, NUM_LEDS_PER_STRIP);
}

void red_fade_fast() {
  if (znach1 == 0) {
    ihue1 = ihue1 + 1;
    if (ihue1 == 30) {
      znach1 = 1;
      Serial.println("ihue1=30 znach1 0");
      ihue1 = ihue1 - 1;
    }
    if (ihue1 == 255) {
      Serial.println("ihue1=255 znach1 0");
      ihue1 = 0;
      ihue1 = ihue1 + 1;
    }
  }
  if (znach1 == 1) {
    ihue1 = ihue1 - 1;
    if (ihue1 == 0) {
      ihue1 = 255;
      Serial.println("ihue1=255 znach1 1");
      ihue1 = ihue1 - 1;
    }
    if (ihue1 == 140){
      znach1 = 0;
      Serial.println("ihue1=140 znach1 1");
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
      Serial.println("ihue2=30 znach2 0");
      ihue2 = ihue2 - 1;
    }
    if (ihue2 == 255) {
      Serial.println("ihue2=255 znach2 0");
      ihue2 = 0;
      ihue2 = ihue2 + 1;
    }
  }
  if (znach2 == 1) {
    ihue2 = ihue2 - 1;
    if (ihue2 == 0) {
      ihue2 = 255;
      Serial.println("ihue2=255 znach2 1");
      ihue2 = ihue2 - 1;
    }
    if (ihue2 == 140){
      znach2 = 0;
      Serial.println("ihue2=140 znach2 1");
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
      Serial.println("ihue3=30 znach3 0");
      ihue3 = ihue3 - 1;
    }
    if (ihue3 == 255) {
      Serial.println("ihue3=255 znach3 0");
      ihue3 = 0;
      ihue3 = ihue3 + 1;
    }
  }
  if (znach3 == 1) {
    ihue3 = ihue3 - 1;
    if (ihue3 == 0) {
      ihue3 = 255;
      Serial.println("ihue3=255 znach3 1");
      ihue3 = ihue3 - 1;
    }
    if (ihue3 == 140){
      znach3 = 0;
      Serial.println("ihue3=140 znach3 1");
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
      Serial.println("ihue4=30 znach4 0");
      ihue4 = ihue4 - 1;
    }
    if (ihue4 == 255) {
      Serial.println("ihue4=255 znach4 0");
      ihue4 = 0;
      ihue4 = ihue4 + 1;
    }
  }
  if (znach4 == 1) {
    ihue4 = ihue4 - 1;
    if (ihue4 == 0) {
      ihue4 = 255;
      Serial.println("ihue4=255 znach4 1");
      ihue4 = ihue4 - 1;
    }
    if (ihue4 == 140){
      znach4 = 0;
      Serial.println("ihue4=140 znach4 1");
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
    case 1: thisdelay = 100; break;    
    case 2: thisdelay = 15 ; break;      
  }
  bouncedirection = 0;
  ledMode = newmode;
}

void change_ihue() {
  if (t1 == 1) {
    ihue_smena = ihue_smena - 1;
    if (ihue_smena == 0) {
      ihue_smena = 255;
      Serial.println("ihue_smena=255");
      ihue_smena = ihue_smena - 1;
    }
    if (ihue_smena == 212){
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

void one_color_all2() {
  for (int idex = 0 ; idex < NUM_LEDS_PER_STRIP; idex++ ) {
    Lenta1[idex] = CHSV(30, thissat, 255);
    Lenta2[idex] = CHSV(30, thissat, 255);
    Lenta3[idex] = CHSV(30, thissat, 255);
    Lenta4[idex] = CHSV(30, thissat, 255);
  }
  LEDS.show();
}


void loop() {
  enc1.tick();
  if (millis()-previousMillis1 >= interval){
      previousMillis1 = 0;
      Serial.println("millis");
      ledMode = 3;    // получаем новый номер следующего режима
      change_mode(ledMode);
    }
  switch (ledMode) {
    case  1: change_ihue(); break;            // 
    case  2: red_fade_fast(); break;            //
    case  3: one_color_all2(); break;
  }
  if (enc1.isTurn()) {
    previousMillis1 = millis();
    ledMode = 2;    // получаем новый номер следующего режима
    change_mode(ledMode);               // меняем режим через change_mode 
    changeFlag = true;
    Serial.println("turn");
  }
}
