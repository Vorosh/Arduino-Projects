
#include <NewPing.h>

#define ITERATIONS    1 // Number of iterations.
#define TRIGGER_PIN   4 // Arduino pin tied to trigger pin on ping sensor.
#define ECHO_PIN      5 // Arduino pin tied to echo pin on ping sensor.
#define MAX_DISTANCE 300 // Maximum distance (in cm) to ping.
#define PING_INTERVAL 33 // Milliseconds between sensor pings (29ms is about the min to avoid cross-sensor echo).

unsigned long pingTimer[ITERATIONS]; // Holds the times when the next ping should happen for each iteration.
unsigned int cm[ITERATIONS];         // Where the ping distances are stored.
uint8_t currentIteration = 0;        // Keeps track of iteration step.
unsigned long lastValue;
unsigned long currentValue;


NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.


#include "FastLED.h"         

#define LED_COUNT 299         // число светодиодов
#define LED_DT 2             // пин ленты 
int max_bright = 100;         // максимальная яркость (0 - 255)
int ledMode = 0;

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

int thisdelay = 48;          //-FX LOOPS DELAY VAR
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

void setup()
{              
  Serial.begin(115200);
  pingTimer[0] = millis() + 75;            // First ping starts at 75ms, gives time for the Arduino to chill before starting.
  for (uint8_t i = 1; i < ITERATIONS; i++) // Set the starting time for each iteration.
    pingTimer[i] = pingTimer[i - 1] + PING_INTERVAL;
  LEDS.setBrightness(max_bright);  // ограничить максимальную яркость
  LEDS.addLeds<WS2812, LED_DT, GRB>(leds, LED_COUNT);
  one_color_all(0, 0, 0);          // погасить все светодиоды
  LEDS.show();                     
}

void echoCheck() { // If ping received, set the sensor distance to array.
  if (sonar.check_timer())
    cm[currentIteration] = sonar.ping_result / US_ROUNDTRIP_CM;
}

void randompix(unsigned long Value) {
  copy_led_array();
  int iCCW;
  one_color_all(0, 0, 0);
  leds[0] = CHSV(140, 255, 255);
  for (int idex = 1; idex < Value ; idex++ ) {
    iCCW = adjacent_ccw(idex);
    leds[idex].r = ledsX[iCCW][0];
    leds[idex].g = ledsX[iCCW][1];
    leds[idex].b = ledsX[iCCW][2];
  }
  LEDS.show();
}

void oneSensorCycle() { // All iterations complete, calculate the median.
  unsigned int uS[ITERATIONS];
  uint8_t j, it = ITERATIONS;
  uS[0] = NO_ECHO;
  for (uint8_t i = 0; i < it; i++) { // Loop through iteration results.
    if (cm[i] != NO_ECHO) { // Ping in range, include as part of median.
      if (i > 0) {          // Don't start sort till second ping.
        for (j = i; j > 0 && uS[j - 1] < cm[i]; j--) // Insertion sort loop.
          uS[j] = uS[j - 1];                         // Shift ping array to correct position for sort insertion.
      } else j = 0;         // First ping is sort starting point.
      uS[j] = cm[i];        // Add last ping to array in sorted position.
    } else it--;            // Ping out of range, skip and don't include as part of median.
  }
  currentValue = uS[it >> 1];
  if(currentValue!=lastValue){
    Serial.print(currentValue);
    Serial.println("cm");
  }
  lastValue = uS[it >> 1];
}

void loop() {
  for (uint8_t i = 0; i < ITERATIONS; i++) { // Loop through all the iterations.
    if (millis() >= pingTimer[i]) {          // Is it this iteration's time to ping?
      pingTimer[i] += PING_INTERVAL * ITERATIONS; // Set next time this sensor will be pinged.
      if (i == 0 && currentIteration == ITERATIONS - 1) oneSensorCycle(); // Sensor ping cycle complete, do something with the results.
      sonar.timer_stop();          // Make sure previous timer is canceled before starting a new ping (insurance).
      currentIteration = i;        // Sensor being accessed.
      cm[currentIteration] = 0;    // Make distance zero in case there's no ping echo for this iteration.
      sonar.ping_timer(echoCheck); // Do the ping (processing continues, interrupt will call echoCheck to look for echo). 
      randompix(currentValue);
    }
  } 
}
