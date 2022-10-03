#include "FastLED.h"

#define NUM_LEDS_PART_A 50
#define NUM_LEDS_PART_B 50
#define NUM_LEDS_PART_C 50
#define NUM_LEDS_PART_D 50
#define NUM_LEDS_PART_E 50
#define NUM_LEDS_PART_F 50

int button1 = 11;
int button2 = 10;
int button3 = 9;
int buttonState1 = 1;
int buttonState2 = 1;
int buttonState3 = 1;
 
CRGB ledsA[NUM_LEDS_PART_A];
CRGB ledsB[NUM_LEDS_PART_B];
CRGB ledsC[NUM_LEDS_PART_C];
CRGB ledsD[NUM_LEDS_PART_D];
CRGB ledsE[NUM_LEDS_PART_E];
CRGB ledsF[NUM_LEDS_PART_F];
 
void setup() {
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);
  digitalWrite(button1, HIGH);
  digitalWrite(button2, HIGH);
  digitalWrite(button3, HIGH);
  FastLED.addLeds<NEOPIXEL, 2>(ledsA, NUM_LEDS_PART_A);
  FastLED.addLeds<NEOPIXEL, 3>(ledsB, NUM_LEDS_PART_B);
  FastLED.addLeds<NEOPIXEL, 4>(ledsC, NUM_LEDS_PART_C);
  FastLED.addLeds<NEOPIXEL, 5>(ledsD, NUM_LEDS_PART_D);
  FastLED.addLeds<NEOPIXEL, 6>(ledsE, NUM_LEDS_PART_E);
  FastLED.addLeds<NEOPIXEL, 7>(ledsF, NUM_LEDS_PART_F);
}

void loop() {
  buttonState1 = digitalRead(button1);
  buttonState2 = digitalRead(button2);
  buttonState3 = digitalRead(button3);

  if (buttonState1 == LOW) {
    delay(5);
    if (buttonState1 == LOW) {
      for (int i = 0; i < NUM_LEDS_PART_A; i++) {
        RunningLights1(0xff,0xff,0x00, 50);
        FastLED.show();
        fill_solid(ledsA, NUM_LEDS_PART_A, CRGB::Black);
      }
      for (int i = 0; i < NUM_LEDS_PART_B; i++) {
        RunningLights2(0xff,0xff,0x00, 50);
        FastLED.show();
        fill_solid(ledsB, NUM_LEDS_PART_B, CRGB::Black);        
      }
    delay(100);
    }
  }

  if (buttonState2 == LOW) {
    delay(5);
    if (buttonState2 == LOW) {
      for (int i = 0; i < NUM_LEDS_PART_C; i++) {
        RunningLights3(0xff,0xff,0x00, 50);
        FastLED.show();
        fill_solid(ledsC, NUM_LEDS_PART_C, CRGB::Black);
      }
      for (int i = 0; i < NUM_LEDS_PART_D; i++) {
        RunningLights4(0xff,0xff,0x00, 50);
        FastLED.show();
        fill_solid(ledsD, NUM_LEDS_PART_D, CRGB::Black);        
      }
      for (int i = 0; i < NUM_LEDS_PART_E; i++) {
        RunningLights5(0xff,0xff,0x00, 50);
        FastLED.show();
        fill_solid(ledsE, NUM_LEDS_PART_E, CRGB::Black);        
      }
    delay(100);
    }
  }

  if (buttonState3 == LOW) {
    delay(5);
    if (buttonState3 == LOW) {
      for (int i = 0; i < NUM_LEDS_PART_F; i++) {
        RunningLights3(0xff,0xff,0x00, 50);
        FastLED.show();
        fill_solid(ledsF, NUM_LEDS_PART_F, CRGB::Black);
      }
    delay(100);
    }
  }
}

void showStrip() {
 #ifdef ADAFRUIT_NEOPIXEL_H 
   // NeoPixel
   strip.show();
 #endif
 #ifndef ADAFRUIT_NEOPIXEL_H
   // FastLED
   FastLED.show();
 #endif
}

void setPixel(int Pixel, byte red, byte green, byte blue) {
 #ifdef ADAFRUIT_NEOPIXEL_H 
   // NeoPixel
   strip.setPixelColor(Pixel, strip.Color(red, green, blue));
 #endif
 #ifndef ADAFRUIT_NEOPIXEL_H 
   // FastLED
   leds[Pixel].r = red;
   leds[Pixel].g = green;
   leds[Pixel].b = blue;
 #endif
}

void setAll(byte red, byte green, byte blue) {
  for(int i = 0; i < NUM_LEDS_PART_A; i++ ) {
    setPixel(i, red, green, blue); 
  }
  showStrip();
}

void RunningLights1(byte red, byte green, byte blue, int WaveDelay) {
  int Position = 0;

  for (int i = 0; i < NUM_LEDS_PART_A * 2; i++)
  {
    Position++; // = 0; //Position + Rate;
    for (int i = 0; i < NUM_LEDS_PART_A; i++) {
      // sine wave, 3 offset waves make a rainbow!
      //float level = sin(i+Position) * 127 + 128;
      //setPixel(i,level,0,0);
      //float level = sin(i+Position) * 127 + 128;
      setPixel(i, ((sin(i + Position) * 127 + 128) / 255)*red,
               ((sin(i + Position) * 127 + 128) / 255)*green,
               ((sin(i + Position) * 127 + 128) / 255)*blue);
    }

    FastLED.show();
    delay(WaveDelay);
  }
}

void RunningLights2(byte red, byte green, byte blue, int WaveDelay) {
  int Position = 0;

  for (int i = 0; i < NUM_LEDS_PART_B * 2; i++)
  {
    Position++; // = 0; //Position + Rate;
    for (int i = 0; i < NUM_LEDS_PART_B; i++) {
      // sine wave, 3 offset waves make a rainbow!
      //float level = sin(i+Position) * 127 + 128;
      //setPixel(i,level,0,0);
      //float level = sin(i+Position) * 127 + 128;
      setPixel(i, ((sin(i + Position) * 127 + 128) / 255)*red,
               ((sin(i + Position) * 127 + 128) / 255)*green,
               ((sin(i + Position) * 127 + 128) / 255)*blue);
    }

    FastLED.show();
    delay(WaveDelay);
  }
}

void RunningLights3(byte red, byte green, byte blue, int WaveDelay) {
  int Position = 0;

  for (int i = 0; i < NUM_LEDS_PART_C * 2; i++)
  {
    Position++; // = 0; //Position + Rate;
    for (int i = 0; i < NUM_LEDS_PART_C; i++) {
      // sine wave, 3 offset waves make a rainbow!
      //float level = sin(i+Position) * 127 + 128;
      //setPixel(i,level,0,0);
      //float level = sin(i+Position) * 127 + 128;
      setPixel(i, ((sin(i + Position) * 127 + 128) / 255)*red,
               ((sin(i + Position) * 127 + 128) / 255)*green,
               ((sin(i + Position) * 127 + 128) / 255)*blue);
    }

    FastLED.show();
    delay(WaveDelay);
  }
}

void RunningLights4(byte red, byte green, byte blue, int WaveDelay) {
  int Position = 0;

  for (int i = 0; i < NUM_LEDS_PART_D * 2; i++)
  {
    Position++; // = 0; //Position + Rate;
    for (int i = 0; i < NUM_LEDS_PART_D; i++) {
      // sine wave, 3 offset waves make a rainbow!
      //float level = sin(i+Position) * 127 + 128;
      //setPixel(i,level,0,0);
      //float level = sin(i+Position) * 127 + 128;
      setPixel(i, ((sin(i + Position) * 127 + 128) / 255)*red,
               ((sin(i + Position) * 127 + 128) / 255)*green,
               ((sin(i + Position) * 127 + 128) / 255)*blue);
    }

    FastLED.show();
    delay(WaveDelay);
  }
}

void RunningLights5(byte red, byte green, byte blue, int WaveDelay) {
  int Position = 0;

  for (int i = 0; i < NUM_LEDS_PART_E * 2; i++)
  {
    Position++; // = 0; //Position + Rate;
    for (int i = 0; i < NUM_LEDS_PART_E; i++) {
      // sine wave, 3 offset waves make a rainbow!
      //float level = sin(i+Position) * 127 + 128;
      //setPixel(i,level,0,0);
      //float level = sin(i+Position) * 127 + 128;
      setPixel(i, ((sin(i + Position) * 127 + 128) / 255)*red,
               ((sin(i + Position) * 127 + 128) / 255)*green,
               ((sin(i + Position) * 127 + 128) / 255)*blue);
    }

    FastLED.show();
    delay(WaveDelay);
  }
}

void RunningLights6(byte red, byte green, byte blue, int WaveDelay) {
  int Position = 0;

  for (int i = 0; i < NUM_LEDS_PART_F * 2; i++)
  {
    Position++; // = 0; //Position + Rate;
    for (int i = 0; i < NUM_LEDS_PART_F; i++) {
      // sine wave, 3 offset waves make a rainbow!
      //float level = sin(i+Position) * 127 + 128;
      //setPixel(i,level,0,0);
      //float level = sin(i+Position) * 127 + 128;
      setPixel(i, ((sin(i + Position) * 127 + 128) / 255)*red,
               ((sin(i + Position) * 127 + 128) / 255)*green,
               ((sin(i + Position) * 127 + 128) / 255)*blue);
    }

    FastLED.show();
    delay(WaveDelay);
  }
}
