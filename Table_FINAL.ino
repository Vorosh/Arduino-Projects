#include <FastLED.h>

#define LED_COUNT 8
CRGB Lenta0[LED_COUNT];
CRGB Lenta1[LED_COUNT];
CRGB Lenta2[LED_COUNT];
CRGB Lenta3[LED_COUNT];
CRGB Lenta4[LED_COUNT];

//const int button1 = 12;
//const int button2 = 11;
//const int button3 = 10;
//const int button4 = 9;
//const int button5 = 2;

const int button1 = 8;
const int button2 = 9;
const int button3 = 10;
const int button4 = 11;
const int button5 = 12;

int znach1 = 0;
int znach2 = 0;
int znach3 = 0;
int znach4 = 0;
int znach5 = 0;

volatile int button1State = 1;
volatile int button2State = 1; 
volatile int button3State = 1; 
volatile int button4State = 1; 
volatile int button5State = 1;

// ---------------СЛУЖЕБНЫЕ ПЕРЕМЕННЫЕ-----------------
int thisdelay = 7;          //-FX LOOPS DELAY VAR
int thisstep = 7;           //-FX LOOPS DELAY VAR
int thishue = 0;             //-FX LOOPS DELAY VAR
int thissat = 255;           //-FX LOOPS DELAY VAR

int idex0 = 0;
int idex7 = 0;
int idex2 = 0;
int idex3 = 0;
int idex4 = 0;
int ihue0 = 0;
int ihue7 = 0;
int ihue2 = 0;
int ihue3 = 0;
int ihue4 = 0;
int isat = 0;                //-SATURATION (0-255)
int bouncedirection = 0;     //-SWITCH FOR COLOR BOUNCE (0-1)

void setup() {
  Serial.begin(115200);
  LEDS.setBrightness(250);
  Serial.setTimeout(1);
  //Serial.flush();
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);
  pinMode(button4, INPUT_PULLUP);
  pinMode(button5, INPUT_PULLUP);
  // tell FastLED there's 60 NEOPIXEL leds on pin 10
  FastLED.addLeds<NEOPIXEL, 3>(Lenta0, LED_COUNT);
  FastLED.addLeds<NEOPIXEL, 4>(Lenta1, LED_COUNT);
  FastLED.addLeds<NEOPIXEL, 5>(Lenta2, LED_COUNT);
  FastLED.addLeds<NEOPIXEL, 6>(Lenta3, LED_COUNT);
  FastLED.addLeds<NEOPIXEL, 7>(Lenta4, LED_COUNT);
  one_color_all(0, 0, 0);          // погасить все светодиоды
  LEDS.show();

}

void one_color_all0(int cred, int cgrn, int cblu) {
  for (int s = 0 ; s < LED_COUNT; s++ ) {
    Lenta0[s].setRGB( cred, cgrn, cblu);
  }
}

void one_color_all1(int cred, int cgrn, int cblu) {
  for (int s = 0 ; s < LED_COUNT; s++ ) {
    Lenta1[s].setRGB( cred, cgrn, cblu);
  }
}

void one_color_all2(int cred, int cgrn, int cblu) {       //-SET ALL LEDS TO ONE COLOR
  for (int s = 0 ; s < LED_COUNT; s++ ) {
    Lenta2[s].setRGB( cred, cgrn, cblu);
  }
}

void one_color_all3(int cred, int cgrn, int cblu) {       //-SET ALL LEDS TO ONE COLOR
  for (int s = 0 ; s < LED_COUNT; s++ ) {
    Lenta3[s].setRGB( cred, cgrn, cblu);
  }
}

void one_color_all4(int cred, int cgrn, int cblu) {       //-SET ALL LEDS TO ONE COLOR
  for (int s = 0 ; s < LED_COUNT; s++ ) {
    Lenta4[s].setRGB( cred, cgrn, cblu);
  }
}

void one_color_all(int cred, int cgrn, int cblu) {       //-SET ALL LEDS TO ONE COLOR
  for (int s = 0 ; s < LED_COUNT; s++ ) {
    Lenta0[s].setRGB( cred, cgrn, cblu);
    Lenta1[s].setRGB( cred, cgrn, cblu);
    Lenta2[s].setRGB( cred, cgrn, cblu);
    Lenta3[s].setRGB( cred, cgrn, cblu);
    Lenta4[s].setRGB( cred, cgrn, cblu);
  }
}

void rainbow_loop0() {                        //-m3-LOOP HSV RAINBOW
  idex0++;
  ihue0 = ihue0 + thisstep;
  if (idex0 >= LED_COUNT) {
    idex0 = 0;
  }
  if (ihue0 > 255) {
    ihue0 = 0;
  }
  Lenta0[idex0] = CHSV(ihue0, thissat, 255);
  //FastLED.show();
  delay(thisdelay);
}

void rainbow_loop1() {                        //-m3-LOOP HSV RAINBOW
  idex7++;
  ihue7 = ihue7 + thisstep;
  if (idex7 >= LED_COUNT) {
    idex7 = 0;
  }
  if (ihue7 > 255) {
    ihue7 = 0;
  }
  Lenta1[idex7] = CHSV(ihue7, thissat, 255);
  delay(thisdelay);
}

void rainbow_loop2() {                        //-m3-LOOP HSV RAINBOW
  idex2++;
  ihue2 = ihue2 + thisstep;
  if (idex2 >= LED_COUNT) {
    idex2 = 0;
  }
  if (ihue2 > 255) {
    ihue2 = 0;
  }
  Lenta2[idex2] = CHSV(ihue2, thissat, 255);
  //FastLED.show();
  delay(thisdelay);
}

void rainbow_loop3() {                        //-m3-LOOP HSV RAINBOW
  idex3++;
  ihue3 = ihue3 + thisstep;
  if (idex3 >= LED_COUNT) {
    idex3 = 0;
  }
  if (ihue3 > 255) {
    ihue3 = 0;
  }
  Lenta3[idex3] = CHSV(ihue3, thissat, 255);
  //FastLED.show();
  delay(thisdelay);
}

void rainbow_loop4() {                        //-m3-LOOP HSV RAINBOW
  idex4++;
  ihue4 = ihue4 + thisstep;
  if (idex4 >= LED_COUNT) {
    idex4 = 0;
  }
  if (ihue4 > 255) {
    ihue4 = 0;
  }
  Lenta4[idex4] = CHSV(ihue4, thissat, 255);
  //FastLED.show();
  delay(thisdelay);
}

void loop() {
  button1State = digitalRead(button1);
  button2State = digitalRead(button2);
  button3State = digitalRead(button3);
  button4State = digitalRead(button4);
  button5State = digitalRead(button5);

  if (button1State == LOW) {           
    rainbow_loop0();
    FastLED.show();
    znach1 = 0;
    Serial.println("button 1 press");
  }
  if (button2State == LOW) {           
    rainbow_loop1();
    FastLED.show();
    znach2 = 0;
    Serial.println("button 2 press");
  }
  if (button3State == LOW) {           
    rainbow_loop2();
    FastLED.show();
    znach3 = 0;
    Serial.println("button 3 press");
  }
  if (button4State == LOW) {           
    rainbow_loop3();
    FastLED.show();
    znach4 = 0;
    Serial.println("button 4 press");
  }
  if (button5State == LOW) {           
    rainbow_loop4();
    FastLED.show();
    znach5 = 0;
    Serial.println("button 5 press");
  }
  
  if (button1State == HIGH) {           
    one_color_all0(0, 0, 0);
    FastLED.show();
    znach1 = 0;
    //Serial.println("button 1 release");
  }
  if (button2State == HIGH) {           
    one_color_all1(0, 0, 0);
    FastLED.show();
    znach2 = 0;
    //Serial.println("button 2 release");
  }
  if (button3State == HIGH) {           
    one_color_all2(0, 0, 0);
    FastLED.show();
    znach3 = 0;
    //Serial.println("button 3 release");
  }
  if (button4State == HIGH) {           
    one_color_all3(0, 0, 0);
    FastLED.show();
    znach4 = 0;
    //Serial.println("button 4 release");
  }
  if (button5State == HIGH) {           
    one_color_all4(0, 0, 0);
    FastLED.show();
    znach5 = 0;
    //Serial.println("button 5 release");
  }
  
  
}
