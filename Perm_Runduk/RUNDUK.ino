#include <FastLED.h>

#define LED_COUNT 291          // число светодиодов в кольце/ленте
#define LED_DT 2             // пин, куда подключен DIN ленты

int max_bright = 255;         // максимальная яркость (0 - 255)
int ledMode = 0;

unsigned long StartTime = 0;
unsigned long Interval = 20000;  // таймер, после которого идет loop в миллисекундах

// ---------------СЛУЖЕБНЫЕ ПЕРЕМЕННЫЕ-----------------
int BOTTOM_INDEX = 0;        // светодиод начала отсчёта
int TOP_INDEX = int(LED_COUNT / 2);
int EVENODD = LED_COUNT % 2;
struct CRGB leds[LED_COUNT];
int ledsX[LED_COUNT][3];     //-ARRAY FOR COPYING WHATS IN THE LED STRIP CURRENTLY (FOR CELL-AUTOMATA, MARCH, ETC)

int thisdelay = 60;          //-FX LOOPS DELAY VAR
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

void one_color_all(int cred, int cgrn, int cblu) {       //-SET ALL LEDS TO ONE COLOR
  for (int i = 0 ; i < LED_COUNT; i++ ) {
    leds[i].setRGB( cred, cgrn, cblu);
  }
}

void one_color_all1(int cred, int cgrn, int cblu) {       //-SET ALL LEDS TO ONE COLOR
  for (int i = 0 ; i < LED_COUNT-277; i++ ) {
    leds[i].setRGB( cred, cgrn, cblu);
  }
}

void one_color_all2(int cred, int cgrn, int cblu) {       //-SET ALL LEDS TO ONE COLOR
  for (int i = 14 ; i < LED_COUNT-267; i++ ) {
    leds[i].setRGB( cred, cgrn, cblu);
  }
}

void one_color_all3(int cred, int cgrn, int cblu) {       //-SET ALL LEDS TO ONE COLOR
  for (int i = 24 ; i < LED_COUNT-257; i++ ) {
    leds[i].setRGB( cred, cgrn, cblu);
  }
}

void one_color_all4(int cred, int cgrn, int cblu) {       //-SET ALL LEDS TO ONE COLOR
  for (int i = 34 ; i < LED_COUNT-245; i++ ) {
    leds[i].setRGB( cred, cgrn, cblu);
  }
}

void one_color_all5(int cred, int cgrn, int cblu) {       //-SET ALL LEDS TO ONE COLOR
  for (int i = 46 ; i < LED_COUNT-237; i++ ) {
    leds[i].setRGB( cred, cgrn, cblu);
  }
}

void one_color_all6(int cred, int cgrn, int cblu) {       //-SET ALL LEDS TO ONE COLOR
  for (int i = 54 ; i < LED_COUNT-229; i++ ) {
    leds[i].setRGB( cred, cgrn, cblu);
  }
}

void one_color_all7(int cred, int cgrn, int cblu) {       //-SET ALL LEDS TO ONE COLOR
  for (int i = 62 ; i < LED_COUNT-221; i++ ) {
    leds[i].setRGB( cred, cgrn, cblu);
  }
}

void one_color_all8(int cred, int cgrn, int cblu) {       //-SET ALL LEDS TO ONE COLOR
  for (int i = 70 ; i < LED_COUNT-214; i++ ) {
    leds[i].setRGB( cred, cgrn, cblu);
  }
}

void one_color_all9(int cred, int cgrn, int cblu) {       //-SET ALL LEDS TO ONE COLOR
  for (int i = 77 ; i < LED_COUNT-208; i++ ) {
    leds[i].setRGB( cred, cgrn, cblu);
  }
}

void one_color_all10(int cred, int cgrn, int cblu) {       //-SET ALL LEDS TO ONE COLOR
  for (int i = 83 ; i < LED_COUNT-202; i++ ) {
    leds[i].setRGB( cred, cgrn, cblu);
  }
}

void one_color_all11(int cred, int cgrn, int cblu) {       //-SET ALL LEDS TO ONE COLOR
  for (int i = 89 ; i < LED_COUNT-192; i++ ) {
    leds[i].setRGB( cred, cgrn, cblu);
  }
}

void one_color_all12(int cred, int cgrn, int cblu) {       //-SET ALL LEDS TO ONE COLOR
  for (int i = 99 ; i < LED_COUNT-185; i++ ) {
    leds[i].setRGB( cred, cgrn, cblu);
  }
}

void one_color_all13(int cred, int cgrn, int cblu) {       //-SET ALL LEDS TO ONE COLOR
  for (int i = 106 ; i < LED_COUNT-177; i++ ) {
    leds[i].setRGB( cred, cgrn, cblu);
  }
}

void one_color_all14(int cred, int cgrn, int cblu) {       //-SET ALL LEDS TO ONE COLOR
  for (int i = 114 ; i < LED_COUNT-165; i++ ) {
    leds[i].setRGB( cred, cgrn, cblu);
  }
}

void one_color_all15(int cred, int cgrn, int cblu) {       //-SET ALL LEDS TO ONE COLOR
  for (int i = 126 ; i < LED_COUNT-153; i++ ) {
    leds[i].setRGB( cred, cgrn, cblu);
  }
}

void one_color_all16(int cred, int cgrn, int cblu) {       //-SET ALL LEDS TO ONE COLOR
  for (int i = 138 ; i < LED_COUNT-145; i++ ) {
    leds[i].setRGB( cred, cgrn, cblu);
  }
}

void one_color_all17(int cred, int cgrn, int cblu) {       //-SET ALL LEDS TO ONE COLOR
  for (int i = 146 ; i < LED_COUNT-137; i++ ) {
    leds[i].setRGB( cred, cgrn, cblu);
  }
}

void one_color_all18(int cred, int cgrn, int cblu) {       //-SET ALL LEDS TO ONE COLOR
  for (int i = 154 ; i < LED_COUNT-127; i++ ) {
    leds[i].setRGB( cred, cgrn, cblu);
  }
}

void one_color_all19(int cred, int cgrn, int cblu) {       //-SET ALL LEDS TO ONE COLOR
  for (int i = 164 ; i < LED_COUNT-101; i++ ) {
    leds[i].setRGB( cred, cgrn, cblu);
  }
}

void one_color_all20(int cred, int cgrn, int cblu) {       //-SET ALL LEDS TO ONE COLOR
  for (int i = 190 ; i < LED_COUNT-87; i++ ) {
    leds[i].setRGB( cred, cgrn, cblu);
  }
}

void one_color_all21(int cred, int cgrn, int cblu) {       //-SET ALL LEDS TO ONE COLOR
  for (int i = 204 ; i < LED_COUNT; i++ ) {
    leds[i].setRGB( cred, cgrn, cblu);
  }
}

void setup() { 
	Serial.begin(9600);
	LEDS.addLeds<WS2812,LED_DT,GRB>(leds,LED_COUNT);
	LEDS.setBrightness(255);
  one_color_all(0, 0, 0);
  LEDS.show();            // погасить все светодиоды                     // отослать команду
}

void fadeall() { for(int i = 0; i < LED_COUNT; i++) { leds[i].nscale8(250); } }

void random_march(int SpeedDelay) {                   //-m14-RANDOM MARCH CCW
  copy_led_array();
  int iCCW;
  leds[0] = CHSV(random(0, 255), 255, 255);
  for (int idex = 1; idex < LED_COUNT ; idex++ ) {
    iCCW = adjacent_ccw(idex);
    leds[idex].r = ledsX[iCCW][0];
    leds[idex].g = ledsX[iCCW][1];
    leds[idex].b = ledsX[iCCW][2];
  }
  LEDS.show();
  delay(SpeedDelay);
}

void rainbow_fade() {                         //-m2-FADE ALL LEDS THROUGH HSV RAINBOW
  ihue++;
  if (ihue > 255) {
    ihue = 0;
  }
  for (int idex = 0 ; idex < LED_COUNT; idex++ ) {
    leds[idex] = CHSV(ihue, thissat, 255);
  }
  LEDS.show();
  delay(thisdelay);
}

void change_mode(int newmode) {
  thissat = 255;
  switch (newmode) {
    case 1: thisdelay = 20; break;
    case 2: thisdelay = 20; break;
    case 3: thisdelay = 20; break;
    case 4: thisdelay = 20; break;
    case 5: thisdelay = 20; break;
    case 6: thisdelay = 20; break;
    case 7: thisdelay = 20; break;
    case 8: thisdelay = 20; break;
    case 9: thisdelay = 20; break;
    case 10: thisdelay = 20; break;
    case 11: thisdelay = 20; break;
    case 12: thisdelay = 20; break;
    case 13: thisdelay = 20; break;
    case 14: thisdelay = 20; break;
    case 15: thisdelay = 20; break;
    case 16: thisdelay = 20; break;
    case 17: thisdelay = 20; break;
    case 18: thisdelay = 20; break;
    case 19: thisdelay = 20; break;
    case 20: thisdelay = 20; break;
    case 21: thisdelay = 20; break;
    case 22: thisdelay = 20; break;
    case 23: thisdelay = 20; break;
    case 24: thisdelay = 20; break;
    case 25: thisdelay = 20; break;
    case 26: thisdelay = 20; break;
    case 27: thisdelay = 20; break;
    case 28: thisdelay = 20; break;
    case 29: thisdelay = 20; break;
    case 30: thisdelay = 20; break;
    case 31: thisdelay = 20; break;
    case 32: thisdelay = 20; break;
    case 33: thisdelay = 20; break;
    case 34: thisdelay = 20; break;
    case 35: thisdelay = 20; break;
    case 36: thisdelay = 20; break;
    case 37: thisdelay = 20; break;
    case 38: thisdelay = 20; break;
    case 39: thisdelay = 20; break;
    case 40: thisdelay = 20; break;
    case 41: thisdelay = 20; break;
    case 42: thisdelay = 20; break;
  }
  bouncedirection = 0;
  one_color_all(45, 45, 45);
  ledMode = newmode;
}

void loop() {
  
  if (Serial.available() > 0) {     // если что то прислали
    one_color_all(45, 45, 45);
    ledMode = Serial.parseInt();     // парсим в тип данных int
    change_mode(ledMode);
    StartTime = millis();
    // меняем режим через change_mode 
    switch (ledMode) {
      case 1: one_color_all1(0, 255, 0); LEDS.show(); delay(2500); one_color_all(45, 45, 45); LEDS.show(); break;
      case 2: one_color_all1(255, 0, 0); LEDS.show(); delay(2500); one_color_all(45, 45, 45); LEDS.show(); break;
      case 3: one_color_all2(0, 255, 0); LEDS.show(); delay(2500); one_color_all(45, 45, 45); LEDS.show(); break;
      case 4: one_color_all2(255, 0, 0); LEDS.show(); delay(2500); one_color_all(45, 45, 45); LEDS.show(); break;
      case 5: one_color_all3(0, 255, 0); LEDS.show(); delay(2500); one_color_all(45, 45, 45); LEDS.show(); break;
      case 6: one_color_all3(255, 0, 0); LEDS.show(); delay(2500); one_color_all(45, 45, 45); LEDS.show(); break;
      case 7: one_color_all4(0, 255, 0); LEDS.show(); delay(2500); one_color_all(45, 45, 45); LEDS.show(); break;
      case 8: one_color_all4(255, 0, 0); LEDS.show(); delay(2500); one_color_all(45, 45, 45); LEDS.show(); break;
      case 9: one_color_all5(0, 255, 0); LEDS.show(); delay(2500); one_color_all(45, 45, 45); LEDS.show(); break;
      case 10: one_color_all5(255, 0, 0); LEDS.show(); delay(2500); one_color_all(45, 45, 45); LEDS.show(); break;
      case 11: one_color_all6(0, 255, 0); LEDS.show(); delay(2500); one_color_all(45, 45, 45); LEDS.show(); break;
      case 12: one_color_all6(255, 0, 0); LEDS.show(); delay(2500); one_color_all(45, 45, 45); LEDS.show(); break;
      case 13: one_color_all7(0, 255, 0); LEDS.show(); delay(2500); one_color_all(45, 45, 45); LEDS.show(); break;
      case 14: one_color_all7(255, 0, 0); LEDS.show(); delay(2500); one_color_all(45, 45, 45); LEDS.show(); break;
      case 15: one_color_all8(0, 255, 0); LEDS.show(); delay(2500); one_color_all(45, 45, 45); LEDS.show(); break;
      case 16: one_color_all8(255, 0, 0); LEDS.show(); delay(2500); one_color_all(45, 45, 45); LEDS.show(); break;
      case 17: one_color_all9(0, 255, 0); LEDS.show(); delay(2500); one_color_all(45, 45, 45); LEDS.show(); break;
      case 18: one_color_all9(255, 0, 0); LEDS.show(); delay(2500); one_color_all(45, 45, 45); LEDS.show(); break;
      case 19: one_color_all10(0, 255, 0); LEDS.show(); delay(2500); one_color_all(45, 45, 45); LEDS.show(); break;
      case 20: one_color_all10(255, 0, 0); LEDS.show(); delay(2500); one_color_all(45, 45, 45); LEDS.show(); break;
      case 21: one_color_all11(0, 255, 0); LEDS.show(); delay(2500); one_color_all(45, 45, 45); LEDS.show(); break;
      case 22: one_color_all11(255, 0, 0); LEDS.show(); delay(2500); one_color_all(45, 45, 45); LEDS.show(); break;
      case 23: one_color_all12(0, 255, 0); LEDS.show(); delay(2500); one_color_all(45, 45, 45); LEDS.show(); break;
      case 24: one_color_all12(255, 0, 0); LEDS.show(); delay(2500); one_color_all(45, 45, 45); LEDS.show(); break;
      case 25: one_color_all13(0, 255, 0); LEDS.show(); delay(2500); one_color_all(45, 45, 45); LEDS.show(); break;
      case 26: one_color_all13(255, 0, 0); LEDS.show(); delay(2500); one_color_all(45, 45, 45); LEDS.show(); break;
      case 27: one_color_all14(0, 255, 0); LEDS.show(); delay(2500); one_color_all(45, 45, 45); LEDS.show(); break;
      case 28: one_color_all14(255, 0, 0); LEDS.show(); delay(2500); one_color_all(45, 45, 45); LEDS.show(); break;
      case 29: one_color_all15(0, 255, 0); LEDS.show(); delay(2500); one_color_all(45, 45, 45); LEDS.show(); break;
      case 30: one_color_all15(255, 0, 0); LEDS.show(); delay(2500); one_color_all(45, 45, 45); LEDS.show(); break;
      case 31: one_color_all16(0, 255, 0); LEDS.show(); delay(2500); one_color_all(45, 45, 45); LEDS.show(); break;
      case 32: one_color_all16(255, 0, 0); LEDS.show(); delay(2500); one_color_all(45, 45, 45); LEDS.show(); break;
      case 33: one_color_all17(0, 255, 0); LEDS.show(); delay(2500); one_color_all(45, 45, 45); LEDS.show(); break;
      case 34: one_color_all17(255, 0, 0); LEDS.show(); delay(2500); one_color_all(45, 45, 45); LEDS.show(); break;
      case 35: one_color_all18(0, 255, 0); LEDS.show(); delay(2500); one_color_all(45, 45, 45); LEDS.show(); break;
      case 36: one_color_all18(255, 0, 0); LEDS.show(); delay(2500); one_color_all(45, 45, 45); LEDS.show(); break;
      case 37: one_color_all19(0, 255, 0); LEDS.show(); delay(2500); one_color_all(45, 45, 45); LEDS.show(); break;
      case 38: one_color_all19(255, 0, 0); LEDS.show(); delay(2500); one_color_all(45, 45, 45); LEDS.show(); break;
      case 39: one_color_all20(0, 255, 0); LEDS.show(); delay(2500); one_color_all(45, 45, 45); LEDS.show(); break;
      case 40: one_color_all20(255, 0, 0); LEDS.show(); delay(2500); one_color_all(45, 45, 45); LEDS.show(); break;
      case 41: one_color_all21(0, 255, 0); LEDS.show(); delay(2500); one_color_all(45, 45, 45); LEDS.show(); break;
      case 42: one_color_all21(255, 0, 0); LEDS.show(); delay(2500); one_color_all(45, 45, 45); LEDS.show(); break;
      default: one_color_all(45, 45, 45); LEDS.show(); break;
  }
  }
  else {
    if (StartTime != 0 && millis() - StartTime < Interval) {
      one_color_all(0, 0, 0);
  } else {
    StartTime = 0;
    random_march(60);
  }
  }
}
