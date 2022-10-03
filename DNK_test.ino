#define STRIP_PIN 7     
#define NUMLEDS 99     

#define COLOR_DEBTH 3
#include <microLED.h>   
microLED<NUMLEDS, STRIP_PIN, MLED_NO_CLOCK, LED_WS2812, ORDER_GRB, CLI_AVER, SAVE_MILLIS> strip;

int ledMode = 3;
int thisdelay = 1;

void setup() {
  strip.setBrightness(255);
  Serial.begin(115200);
  Serial.setTimeout(1);
  Serial.flush();
}

void loop() {
  if (Serial.available() > 0) {     
    //strip.clear();
    strip.setBrightness(255);
    strip.show();
    ledMode = Serial.parseInt();     
  }
    switch (ledMode) {
      case 1: strip.fill(mRed); breathing(); strip.show(); delay(thisdelay+10); break;
      case 2: strip.fill(mGreen); breathing(); strip.show(); delay(thisdelay+10); break;
      case 3: rainbow(); strip.show(); delay(thisdelay+40); break;
      case 4: strip.fill(mBlack); strip.show(); break;
      default: filler(); strip.show(); delay(thisdelay+40); break;
  }
  
  //rainbow();      // бегущая радуга во всю ленту
  //filler();       // плавное заполнение
  //colorCycle();   // плавная смена цвета
  //runningDots();  // бегущие точки

  // вывод
  //breathing();    // "дыхание" яркости, применяется ко всем эффектам
  //strip.show();   
  //delay(30);      // 30 кадров в секунду
}

void rainbow() {
  static byte counter = 0;
  for (int i = 0; i < NUMLEDS; i++) {
    strip.set(i, mWheel8(counter + i * 99 / NUMLEDS));   // counter смещает цвет
  }
  counter += 3;   // counter имеет тип byte и при достижении 255 сбросится в 0
}
  
void filler() {
  static int counter = 0;
  strip.clear();
  strip.fill(0, counter, mRed);
  counter++;
  if (counter >= NUMLEDS) counter = 0;
}

void custom() {
  static int counter = 0;
  strip.clear();
  strip.fill(0, counter, mRed);
  counter++;
  if (counter >= NUMLEDS) {
    strip.fill(mRed);
    strip.show();
    counter = 0; 
  }
}

void colorCycle() {
  static byte counter = 0;
  strip.fill(mWheel8(counter));
  counter += 3;
}

void runningDots() {
  static byte counter = 0;
  // перемотка буфера со сдвигом (иллюзия движения пикселей)
  for (int i = 0; i < NUMLEDS - 1; i++) strip.leds[i] = strip.leds[i + 1];

  // каждый третий вызов - последний пиксель красным, иначе чёрным
  if (counter % 3 == 0) strip.leds[NUMLEDS - 1] = mRed;
  else strip.leds[NUMLEDS - 1] = mBlack;
  counter++;
  delay(100);   
}

void breathing() {
  static int dir = 1;
  static int bright = 0;
  bright += dir * 5;    // 5 - множитель скорости изменения

  if (bright > 255) {
    bright = 255;
    dir = -1;
  }
  if (bright < 0) {
    bright = 0;
    dir = 1;
  }
  strip.setBrightness(bright);
}
