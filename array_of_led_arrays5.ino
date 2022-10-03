#include <FastLED.h>

#define NUM_STRIPS 6
#define NUM_LEDS_PER_STRIP 70
#define BRIGHTNESS  20
CRGB leds[NUM_STRIPS][NUM_LEDS_PER_STRIP];

const int button1 = 8;
const int button2 = 9;
const int button3 = 10;


// variables will change:
int button1State = 1;         // pushbutton status
int button2State = 1;
int button3State = 1;

int BOTTOM_INDEX = 0;        // светодиод начала отсчёта
int TOP_INDEX = int(NUM_LEDS_PER_STRIP / 2);
int EVENODD = NUM_LEDS_PER_STRIP % 2;
struct CRGB leds[NUM_LEDS_PER_STRIP];
int ledsX[NUM_LEDS_PER_STRIP][3];

// For mirroring strips, all the "special" stuff happens just in setup.  We
// just addLeds multiple times, once for each strip
void setup() {
  // tell FastLED there's 60 NEOPIXEL leds on pin 10
  FastLED.addLeds<NEOPIXEL, 2>(leds[0], NUM_LEDS_PER_STRIP);

  // tell FastLED there's 60 NEOPIXEL leds on pin 11
  FastLED.addLeds<NEOPIXEL, 3>(leds[1], NUM_LEDS_PER_STRIP);

  // tell FastLED there's 60 NEOPIXEL leds on pin 12
  FastLED.addLeds<NEOPIXEL, 4>(leds[2], NUM_LEDS_PER_STRIP);

  FastLED.addLeds<NEOPIXEL, 5>(leds[3], NUM_LEDS_PER_STRIP);

  // tell FastLED there's 60 NEOPIXEL leds on pin 11
  FastLED.addLeds<NEOPIXEL, 6>(leds[4], NUM_LEDS_PER_STRIP);

  // tell FastLED there's 60 NEOPIXEL leds on pin 12
  FastLED.addLeds<NEOPIXEL, 7>(leds[5], NUM_LEDS_PER_STRIP);

  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);

}
void copy_led_array() {
  for (int i = 0; i < NUM_LEDS_PER_STRIP; i++ ) {
    leds[i][0] = leds[i].r;
    leds[i][1] = leds[i].g;
    leds[i][2] = leds[i].b;
  }
}

void setPixel(int Pixel, byte red, byte green, byte blue) {
  ledsX[Pixel].r = red;
  ledsX[Pixel].g = green;
  ledsX[Pixel].b = blue;
}

void setAll(byte red, byte green, byte blue) {
  for (int i = 0; i < NUM_LEDS_PER_STRIP; i++ ) {
    setPixel(i, red, green, blue);
  }
  FastLED.show();
}
void RunningLights(byte red, byte green, byte blue, int WaveDelay) {
  int Position = 0;

  for (int i = 0; i < NUM_LEDS_PER_STRIP * 2; i++)
  {
    Position++; // = 0; //Position + Rate;
    for (int i = 0; i < NUM_LEDS_PER_STRIP; i++) {
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

void loop() {
  button1State = digitalRead(button1);
  button2State = digitalRead(button2);
  button3State = digitalRead(button3);
  // This outer loop will go over each strip, one at a time
  //for(int x = 0; x < NUM_STRIPS; x++) {
    // This inner loop will go over each led in the current strip, one at a time
   int x = 0;
   for(int i = 0; i < NUM_LEDS_PER_STRIP; i++) {
    if (button1State == LOW) {
      leds[x][i] = CRGB::White;
      leds[x][i+1] = CRGB::White;
      leds[x][i+2] = CRGB::White;
      leds[x+1][i] = CRGB::White;
      leds[x+1][i+1] = CRGB::White;
      leds[x+1][i+2] = CRGB::White;
      FastLED.show();
      leds[x][i] = CRGB::Black;
      leds[x][i+1] = CRGB::Black;
      leds[x][i+2] = CRGB::Black;
      leds[x+1][i] = CRGB::Black;
      leds[x+1][i+1] = CRGB::Black;
      leds[x+1][i+2] = CRGB::Black;
      delay(10);
      leds[x][i] = CRGB::White;
      leds[x][i+1] = CRGB::White;
      leds[x][i+2] = CRGB::White;
      leds[x+1][i] = CRGB::White;
      leds[x+1][i+1] = CRGB::White;
      leds[x+1][i+2] = CRGB::White;
      FastLED.show();
      leds[x][i] = CRGB::Black;
      leds[x][i+1] = CRGB::Black;
      leds[x][i+2] = CRGB::Black;
      leds[x+1][i] = CRGB::Black;
      leds[x+1][i+1] = CRGB::Black;
      leds[x+1][i+2] = CRGB::Black;
    }
    else if (button2State == LOW) {
      leds[x+2][i] = CRGB::White;
      leds[x+2][i+1] = CRGB::White;
      leds[x+2][i+2] = CRGB::White;
      leds[x+3][i] = CRGB::White;
      leds[x+3][i+1] = CRGB::White;
      leds[x+3][i+2] = CRGB::White;
      leds[x+4][i] = CRGB::White;
      leds[x+4][i+1] = CRGB::White;
      leds[x+4][i+2] = CRGB::White;
      FastLED.show();
      leds[x+2][i] = CRGB::Black;
      leds[x+2][i+1] = CRGB::Black;
      leds[x+2][i+2] = CRGB::Black;
      leds[x+3][i] = CRGB::Black;
      leds[x+3][i+1] = CRGB::Black;
      leds[x+3][i+2] = CRGB::Black;
      leds[x+4][i] = CRGB::Black;
      leds[x+4][i+1] = CRGB::Black;
      leds[x+4][i+2] = CRGB::Black;
      delay(20);
      leds[x+2][i] = CRGB::White;
      leds[x+2][i+1] = CRGB::White;
      leds[x+2][i+2] = CRGB::White;
      leds[x+3][i] = CRGB::White;
      leds[x+3][i+1] = CRGB::White;
      leds[x+3][i+2] = CRGB::White;
      leds[x+4][i] = CRGB::White;
      leds[x+4][i+1] = CRGB::White;
      leds[x+4][i+2] = CRGB::White;
      FastLED.show();
      leds[x+2][i] = CRGB::Black;
      leds[x+2][i+1] = CRGB::Black;
      leds[x+2][i+2] = CRGB::Black;
      leds[x+3][i] = CRGB::Black;
      leds[x+3][i+1] = CRGB::Black;
      leds[x+3][i+2] = CRGB::Black;
      leds[x+4][i] = CRGB::Black;
      leds[x+4][i+1] = CRGB::Black;
      leds[x+4][i+2] = CRGB::Black; 
    }
    else if (button3State == LOW) {
      leds[x+5][i] = CRGB::White;
      leds[x+5][i+1] = CRGB::White;
      leds[x+5][i+2] = CRGB::White;
      FastLED.show();
      leds[x+5][i] = CRGB::Black;
      leds[x+5][i+1] = CRGB::Black;
      leds[x+5][i+2] = CRGB::Black;
      delay(5);
      leds[x+5][i] = CRGB::White;
      leds[x+5][i+1] = CRGB::White;
      leds[x+5][i+2] = CRGB::White;
      FastLED.show();
      leds[x+5][i] = CRGB::Black;
      leds[x+5][i+1] = CRGB::Black;
      leds[x+5][i+2] = CRGB::Black;
    else {
      RunningLights();
    }
    }
  }      
}
