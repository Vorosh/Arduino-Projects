#include "GyverEncoder.h"
#include <FastLED.h>

// How many leds in your strip?
#define LED_COUNT 10          // число светодиодов в кольце/ленте
#define NUM_STRIPS 10
 
Encoder enc1(3, 2);

int value1 = 0;
int value2 = 0;

// ---------------СЛУЖЕБНЫЕ ПЕРЕМЕННЫЕ-----------------
CRGB leds[NUM_STRIPS][LED_COUNT];

int thisdelay = 10;          //-FX LOOPS DELAY VAR
int thisstep = 10;           //-FX LOOPS DELAY VAR
int thishue = 0;             //-FX LOOPS DELAY VAR
int thissat = 255;           //-FX LOOPS DELAY VAR

int thisindex = 0;
int thisRED = 0;
int thisGRN = 0;
int thisBLU = 0;

int idex = 0;                //-LED INDEX (0 to LED_COUNT-1
int ihue = 0;                //-HUE (0-255)
int ibright = 0;             //-BRIGHTNESS (0-255)
int isat = 0;                //-SATURATION (0-255)
int bouncedirection = 0;     //-SWITCH FOR COLOR BOUNCE (0-1)
float tcount = 0.0;          //-INC VAR FOR SIN LOOPS
int lcount = 0;              //-ANOTHER COUNTING VAR

void setup() {
  Serial.begin(9600);
  LEDS.setBrightness(250);
  // tell FastLED there's 60 NEOPIXEL leds on pin 10
  FastLED.addLeds<NEOPIXEL, 4>(leds[0], LED_COUNT);
  FastLED.addLeds<NEOPIXEL, 5>(leds[1], LED_COUNT);
  FastLED.addLeds<NEOPIXEL, 6>(leds[2], LED_COUNT);
  FastLED.addLeds<NEOPIXEL, 7>(leds[3], LED_COUNT);
  FastLED.addLeds<NEOPIXEL, 8>(leds[4], LED_COUNT);
  FastLED.addLeds<NEOPIXEL, 9>(leds[5], LED_COUNT);
  FastLED.addLeds<NEOPIXEL, 10>(leds[6], LED_COUNT);
  FastLED.addLeds<NEOPIXEL, 11>(leds[7], LED_COUNT);
  FastLED.addLeds<NEOPIXEL, 12>(leds[8], LED_COUNT);
  FastLED.addLeds<NEOPIXEL, 13>(leds[9], LED_COUNT);
  one_color_all(0, 0, 0);          // погасить все светодиоды
  LEDS.show();
}

void one_color_all1(int cred, int cgrn, int cblu) {
  for(int x = 0; x < NUM_STRIPS-9; x++){
    for (int i = 0 ; i < LED_COUNT; i++ ) {
    leds[x][i].setRGB( cred, cgrn, cblu);
  } 
  }
}

void one_color_all2(int cred, int cgrn, int cblu) {       //-SET ALL LEDS TO ONE COLOR
  for(int z = 1; z < NUM_STRIPS-8; z++){
    for (int y = 0 ; y < LED_COUNT; y++ ) {
    leds[z][y].setRGB( cred, cgrn, cblu);
  } 
  }
}

void one_color_all3(int cred, int cgrn, int cblu) {       //-SET ALL LEDS TO ONE COLOR
  for(int a = 2; a < NUM_STRIPS-7; a++){
    for (int b = 0 ; b < LED_COUNT; b++ ) {
    leds[a][b].setRGB( cred, cgrn, cblu);
  } 
  }
}

void one_color_all4(int cred, int cgrn, int cblu) {       //-SET ALL LEDS TO ONE COLOR
  for(int c = 3; c < NUM_STRIPS-6; c++){
    for (int d = 0 ; d < LED_COUNT; d++ ) {
    leds[c][d].setRGB( cred, cgrn, cblu);
  } 
  }
}

void one_color_all5(int cred, int cgrn, int cblu) {       //-SET ALL LEDS TO ONE COLOR
  for(int e = 4; e < NUM_STRIPS-5; e++){
    for (int f = 0 ; f < LED_COUNT; f++ ) {
    leds[e][f].setRGB( cred, cgrn, cblu);
  } 
  }
}

void one_color_all6(int cred, int cgrn, int cblu) {       //-SET ALL LEDS TO ONE COLOR
  for(int g = 5; g < NUM_STRIPS-4; g++){
    for (int h = 0 ; h < LED_COUNT; h++ ) {
    leds[g][h].setRGB( cred, cgrn, cblu);
  } 
  }
}

void one_color_all7(int cred, int cgrn, int cblu) {       //-SET ALL LEDS TO ONE COLOR
  for(int j = 6; j < NUM_STRIPS-3; j++){
    for (int l = 0 ; l < LED_COUNT; l++ ) {
    leds[j][l].setRGB( cred, cgrn, cblu);
  } 
  }
}

void one_color_all8(int cred, int cgrn, int cblu) {       //-SET ALL LEDS TO ONE COLOR
  for(int m = 7; m < NUM_STRIPS-2; m++){
    for (int n = 0 ; n < LED_COUNT; n++ ) {
    leds[m][n].setRGB( cred, cgrn, cblu);
  } 
  }
}

void one_color_all9(int cred, int cgrn, int cblu) {       //-SET ALL LEDS TO ONE COLOR
  for(int o = 8; o < NUM_STRIPS-1; o++){
    for (int p = 0 ; p < LED_COUNT; p++ ) {
    leds[o][p].setRGB( cred, cgrn, cblu);
  } 
  }
}

void one_color_all10(int cred, int cgrn, int cblu) {       //-SET ALL LEDS TO ONE COLOR
  for(int q = 9; q < NUM_STRIPS; q++){
    for (int r = 0 ; r < LED_COUNT; r++ ) {
    leds[q][r].setRGB( cred, cgrn, cblu);
  } 
  }
}

void one_color_all(int cred, int cgrn, int cblu) {       //-SET ALL LEDS TO ONE COLOR
  for(int w = 0; w < NUM_STRIPS; w++){
    for (int s = 0 ; s < LED_COUNT; s++ ) {
    leds[w][s].setRGB( cred, cgrn, cblu);
  } 
  }
}

void loop() {
  // обязательная функция отработки. Должна постоянно опрашиваться
  enc1.tick();

  if (enc1.isLeft()) {                                //энкодер1 поворот влево
    one_color_all(0, 0, 0);
    value1--;
    value2 = 0;
  
  if (value1 <= -15) {
    Serial.println(value1);
    one_color_all6(255, 255, 255);
    LEDS.show();
    delay(2000);
    one_color_all7(255, 255, 255);
    LEDS.show();
    delay(2000);
    one_color_all3(255, 255, 255);
    Serial.println("strel");
    LEDS.show();
    delay(2000);
    one_color_all4(255, 255, 255);
    LEDS.show();
    delay(2000);
    one_color_all5(255, 255, 255);
    LEDS.show();
    delay(7000);
    one_color_all(0, 0, 0);
    LEDS.show();
}
}
  
  if (enc1.isRight()) {                                //энкодер1 поворот влево
    one_color_all(0, 0, 0);
    value2++;
    value1 = 0;
    Serial.println("rigggght");
  
  if (value2 >= 15) {
    Serial.println(value2);
    one_color_all1(255, 255, 255);
    LEDS.show();
    delay(2000);
    one_color_all2(255, 255, 255);
    LEDS.show();
    delay(2000);
    one_color_all8(255, 255, 255);
    LEDS.show();
    delay(2000);
    one_color_all9(255, 255, 255);
    LEDS.show();
    delay(2000);
    one_color_all10(255, 255, 255);
    LEDS.show();
    delay(7000);
    one_color_all(0, 0, 0);
    LEDS.show();
  }
}
}
