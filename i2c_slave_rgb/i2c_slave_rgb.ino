#include <Wire.h>
#include "FastLED.h"
#define SLAVE_ADDRESS 0x04
#define LED_COUNT 240         // число светодиодов
#define LED_DT 2             // пин ленты 
int max_bright = 200;         // максимальная яркость (0 - 255)
int ledMode = 0;
int number = 0;
int state = 0;

byte ballColors[3][3] = {
  {0xff, 0, 0},
  {0xff, 0xff, 0xff},
  {0   , 0   , 0xff}
};

// ---------------СЛУЖЕБНЫЕ ПЕРЕМЕННЫЕ-----------------
int BOTTOM_INDEX = 0;        
int TOP_INDEX = int(LED_COUNT / 2);
int EVENODD = LED_COUNT % 2;
struct CRGB leds[LED_COUNT];
int ledsX[LED_COUNT][3];     //-ARRAY FOR COPYING WHATS IN THE LED STRIP CURRENTLY (FOR CELL-AUTOMATA, MARCH, ETC)

int thisdelay = 150;          //-FX LOOPS DELAY VAR
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
  pinMode(13, OUTPUT);
  Serial.begin(9600);

  // initialize i2c as slave
  Wire.begin(SLAVE_ADDRESS);

  // define callbacks for i2c communication
  Wire.onReceive(receiveData);
  Wire.onRequest(sendData);
  Serial.println("Ready!");
  LEDS.setBrightness(max_bright);  // ограничить максимальную яркость
  LEDS.addLeds<WS2812, LED_DT, GRB>(leds, LED_COUNT);
  one_color_all(0, 0, 0);          // погасить все светодиоды
  LEDS.show();
}

void loop() {
  delay(1000);
}

// callback for received data
void receiveData(int byteCount){
  while(Wire.available()) {
    number = Wire.read();
    Serial.print("data received: ");
    Serial.println(number);
    if (number == 1){
      digitalWrite(13, HIGH); // set the LED on
      FadeInOut(0xff, 0x00, 0x00);
      FastLED.show();
      FadeInOut(0xff, 0x00, 0x00);
      FastLED.show();
      FadeInOut(0xff, 0x00, 0x00);
      FastLED.show();
      FadeInOut(0xff, 0x00, 0x00);
      FastLED.show();
      FadeInOut(0xff, 0x00, 0x00);
      FastLED.show();
      FadeInOut(0xff, 0x00, 0x00);
      FastLED.show();
      FadeInOut(0xff, 0x00, 0x00);
      FastLED.show();
      FadeInOut(0xff, 0x00, 0x00);
      FastLED.show();
      FadeInOut(0xff, 0x00, 0x00);
      FastLED.show();
      FadeInOut(0xff, 0x00, 0x00);
      FastLED.show();
      one_color_all(0, 0, 0);          // погасить все светодиоды
      FastLED.show();
      }
  }
}

// callback for sending data
void sendData(){
  Wire.write(number);
}
