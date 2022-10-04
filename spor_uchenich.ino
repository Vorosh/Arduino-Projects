#include <FastLED.h>

#define NUM_STRIPS 2
#define LED_COUNT 300

int ledMode = 4;
int max_bright = 255;          
CRGB leds[NUM_STRIPS][LED_COUNT];
// ---------------СЛУЖЕБНЫЕ ПЕРЕМЕННЫЕ-----------------

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
int ibright1 = 0;
int ibright2 = 0;            //-BRIGHTNESS (0-255)
int isat = 0;                //-SATURATION (0-255)
int bouncedirection1 = 0;     //-SWITCH FOR COLOR BOUNCE (0-1)
int bouncedirection2 = 0;
float tcount = 0.0;          //-INC VAR FOR SIN LOOPS
int lcount = 0;              //-ANOTHER COUNTING VAR
// ---------------СЛУЖЕБНЫЕ ПЕРЕМЕННЫЕ-----------------


void setup() {
  Serial.begin(9600);
  LEDS.setBrightness(max_bright);
  // tell FastLED there's 60 NEOPIXEL leds on pin 10
  FastLED.addLeds<NEOPIXEL, 2>(leds[0], LED_COUNT);

  // tell FastLED there's 60 NEOPIXEL leds on pin 11
  FastLED.addLeds<NEOPIXEL, 3>(leds[1], LED_COUNT);
}

void white() { 
  bouncedirection1 = 0;
  ibright1 = 55;             
  if (bouncedirection2 == 0) {
    ibright2 = ibright2 + 25;
    if (ibright2 >= 255) {
      bouncedirection2 = 1;
    }
  }
  for(int x = 0; x < NUM_STRIPS-1; x++) {
    for(int i = 0; i < LED_COUNT; i++) {
      leds[x][i] = CHSV(0, 0, ibright2);
      if (bouncedirection2 == 1) {
        leds[x][i].maximizeBrightness(max_bright);
      }
    }
  }
  for(int x = 1; x < NUM_STRIPS; x++) {
    for(int i = 0; i < LED_COUNT; i++) {
      leds[x][i] = CHSV(0, 0, ibright2);
      if (bouncedirection2 == 1) {
        leds[x][i].maximizeBrightness(max_bright);
      }
  }
  LEDS.show();
  }
}

void Shutdown() {
  bouncedirection1 = 0;
  ibright1 = 55;
  bouncedirection2 = 0;
  ibright2 = 55;
  for(int x = 0; x < NUM_STRIPS-1; x++) {
    for(int i = 0; i < LED_COUNT; i++) {
      leds[x][i].fadeLightBy(55); // Плавное выключение ленты
    }
  }
  for(int x = 1; x < NUM_STRIPS; x++) {
    for(int i = 0; i < LED_COUNT; i++) {
      leds[x][i].fadeLightBy(55); // Плавное выключение ленты
    }
  }
}

void pulse_1() {
  bouncedirection2 = 0;
  ibright2 = 55;              
  if (bouncedirection1 == 0) {
    ibright1 = ibright1 + 25;
    if (ibright1 >= 255) {
      bouncedirection1 = 1;
    }
  }
  for(int x = 1; x < NUM_STRIPS; x++) {
    for(int i = 0; i < LED_COUNT; i++) {
      leds[x][i] = CHSV(0, 0, ibright2);
      leds[x][i].fadeLightBy(55); // Плавное выключение ленты
    }
  }
  for(int x = 0; x < NUM_STRIPS-1; x++) {
    for(int i = 0; i < LED_COUNT; i++) {
      leds[x][i] = CHSV(0, 0, ibright1);
      if (bouncedirection1 == 1) {
        leds[x][i].maximizeBrightness(max_bright);
    }
  }
  LEDS.show();
  }
}

void pulse_2() { 
  bouncedirection1 = 0;
  ibright1 = 55;             
  if (bouncedirection2 == 0) {
    ibright2 = ibright2 + 25;
    if (ibright2 >= 255) {
      bouncedirection2 = 1;
    }
  }
  for(int x = 0; x < NUM_STRIPS-1; x++) {
    for(int i = 0; i < LED_COUNT; i++) {
      leds[x][i] = CHSV(0, 0, ibright1);
      leds[x][i].fadeLightBy(55); // Плавное выключение ленты
    }
  }
  for(int x = 1; x < NUM_STRIPS; x++) {
    for(int i = 0; i < LED_COUNT; i++) {
      leds[x][i] = CHSV(0, 0, ibright2);
      if (bouncedirection2 == 1) {
        leds[x][i].maximizeBrightness(max_bright);
      }
  }
  LEDS.show();
  }
}

void rainbow_fade() {                         //-m2-FADE ALL LEDS THROUGH HSV RAINBOW
  ihue++;
  if (ihue > 255) {
    ihue = 0;
  }
  for(int x = 1; x < NUM_STRIPS; x++) {
    for(int i = 0; i < LED_COUNT; i++) {
      leds[x][i] = CHSV(ihue, thissat, 255);
  }
  LEDS.show();
  }
  for(int x = 0; x < NUM_STRIPS-1; x++) {
    for(int i = 0; i < LED_COUNT; i++) {
      leds[x][i] = CHSV(ihue, thissat, 255);
  }
  LEDS.show();
  }
  delay(thisdelay);
}

void pulse_one_color_all() {             
  if (bouncedirection1 == 0) {
    ibright1 = ibright1 + 5;
    if (ibright1 >= 255) {
      bouncedirection1 = 1;
    }
  }
  if (bouncedirection1 == 1) {
    ibright1 = ibright1 - 5;
    if (ibright1 <= 5) {
      bouncedirection1 = 0;
    }
  }
  for(int x = 0; x < NUM_STRIPS-1; x++) {
    for(int i = 0; i < LED_COUNT; i++) {
      leds[x][i] = CHSV(160, thissat, ibright1);  
  }
  }
  LEDS.show();
               
  if (bouncedirection2 == 0) {
    ibright2 = ibright2 + 5;
    if (ibright2 >= 255) {
      bouncedirection2 = 1;
    }
  }
  if (bouncedirection2 == 1) {
    ibright2 = ibright2 - 5;
    if (ibright2 <= 5) {
      bouncedirection2 = 0;
    }
  }
  for(int x = 1; x < NUM_STRIPS; x++) {
    for(int i = 0; i < LED_COUNT; i++) {
      leds[x][i] = CHSV(255, thissat, ibright2);  
  }
  }
  LEDS.show();
}

void pulse_one_color_all_white() {             
  if (bouncedirection1 == 0) {
    ibright1 = ibright1 + 5;
    if (ibright1 >= 255) {
      bouncedirection1 = 1;
    }
  }
  if (bouncedirection1 == 1) {
    ibright1 = ibright1 - 5;
    if (ibright1 <= 5) {
      bouncedirection1 = 0;
    }
  }
  for(int x = 0; x < NUM_STRIPS-1; x++) {
    for(int i = 0; i < LED_COUNT; i++) {
      leds[x][i] = CHSV(0, 0, ibright1);  
  }
  }
  LEDS.show();
               
  if (bouncedirection2 == 0) {
    ibright2 = ibright2 + 5;
    if (ibright2 >= 255) {
      bouncedirection2 = 1;
    }
  }
  if (bouncedirection2 == 1) {
    ibright2 = ibright2 - 5;
    if (ibright2 <= 5) {
      bouncedirection2 = 0;
    }
  }
  for(int x = 1; x < NUM_STRIPS; x++) {
    for(int i = 0; i < LED_COUNT; i++) {
      leds[x][i] = CHSV(0, 0, ibright2);  
  }
  }
  LEDS.show();
}

void loop() {
  
  if (Serial.available() > 0) {    
    ledMode = Serial.parseInt();
  }
  switch (ledMode) {
    case 0: pulse_one_color_all_white(); break;
    case 1: pulse_1(); break;
    case 2: pulse_2(); break;
    case 3: pulse_one_color_all(); break;
    case 4: white(); break;
    default: pulse_one_color_all_white(); break;
  }
}
