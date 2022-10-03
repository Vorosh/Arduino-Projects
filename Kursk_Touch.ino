#include <MPR121.h>
#include <MPR121_Datastream.h>
#include <Wire.h>

// touch constants
const uint32_t BAUD_RATE = 115200;
const uint8_t MPR121_ADDR = 0x5A;  // 0x5C is the MPR121 I2C address on the Bare Touch Board
const uint8_t MPR121_INT = 2;  // pin 4 is the MPR121 interrupt on the Bare Touch Board

// MPR121 datastream behaviour constants
const bool MPR121_DATASTREAM_ENABLE = false;

#define PIN_RELAY1 3
#define PIN_RELAY2 5
#define PIN_RELAY3 6
#define PIN_RELAY4 7
#define PIN_RELAY5 8
#define PIN_RELAY6 9


unsigned long myTimer1 = 0;
unsigned long period = 10000;  //мс

void setup() {
  Serial.begin(BAUD_RATE);
  pinMode(PIN_RELAY1, OUTPUT);
  pinMode(PIN_RELAY2, OUTPUT);
  pinMode(PIN_RELAY3, OUTPUT);
  pinMode(PIN_RELAY4, OUTPUT);
  pinMode(PIN_RELAY5, OUTPUT);
  pinMode(PIN_RELAY6, OUTPUT);  
  digitalWrite(PIN_RELAY1, LOW);
  digitalWrite(PIN_RELAY2, LOW);
  digitalWrite(PIN_RELAY3, LOW);
  digitalWrite(PIN_RELAY4, LOW);
  digitalWrite(PIN_RELAY5, LOW);
  digitalWrite(PIN_RELAY6, LOW);

  if (!MPR121.begin(MPR121_ADDR)) {
    Serial.println("error setting up MPR121");
    switch (MPR121.getError()) {
      case NO_ERROR:
        Serial.println("no error");
        break;
      case ADDRESS_UNKNOWN:
        Serial.println("incorrect address");
        break;
      case READBACK_FAIL:
        Serial.println("readback failure");
        break;
      case OVERCURRENT_FLAG:
        Serial.println("overcurrent on REXT pin");
        break;
      case OUT_OF_RANGE:
        Serial.println("electrode out of range");
        break;
      case NOT_INITED:
        Serial.println("not initialised");
        break;
      default:
        Serial.println("unknown error");
        break;
    }
    while (1);
  }

  MPR121.setInterruptPin(MPR121_INT);

  if (MPR121_DATASTREAM_ENABLE) {
    MPR121.restoreSavedThresholds();
    MPR121_Datastream.begin(&Serial);
  } else {
    MPR121.setTouchThreshold(40);  // this is the touch threshold - setting it low makes it more like a proximity trigger, default value is 40 for touch
    MPR121.setReleaseThreshold(20);  // this is the release threshold - must ALWAYS be smaller than the touch threshold, default value is 20 for touch
  }

  MPR121.setFFI(FFI_10);
  MPR121.setSFI(SFI_10);
  MPR121.setGlobalCDT(CDT_4US);  // reasonable for larger capacitances
  
  digitalWrite(LED_BUILTIN, HIGH);  // switch on user LED while auto calibrating electrodes
  delay(1000);
  MPR121.autoSetElectrodes();  // autoset all electrode settings
  digitalWrite(LED_BUILTIN, LOW);
}

void loop() {
  MPR121.updateAll();

  for (int i = 0; i < 12; i++) {
    if (MPR121.isNewTouch(i)) {
      Serial.print("electrode ");
      Serial.print(i, DEC);
      Serial.println(" was just touched");
      if (i==0){
        digitalWrite(PIN_RELAY1, HIGH);
        digitalWrite(PIN_RELAY2, LOW);
        digitalWrite(PIN_RELAY3, LOW);
        digitalWrite(PIN_RELAY4, LOW);
        digitalWrite(PIN_RELAY5, LOW);
        digitalWrite(PIN_RELAY6, LOW);
        Serial.println("Relay1");
      }
      if (i==2){
        digitalWrite(PIN_RELAY2, HIGH);
        digitalWrite(PIN_RELAY1, LOW);
        digitalWrite(PIN_RELAY3, LOW);
        digitalWrite(PIN_RELAY4, LOW);
        digitalWrite(PIN_RELAY5, LOW);
        digitalWrite(PIN_RELAY6, LOW);
        Serial.println("Relay2");
      }
      if (i==3){
        digitalWrite(PIN_RELAY3, HIGH);
        digitalWrite(PIN_RELAY2, LOW);
        digitalWrite(PIN_RELAY1, LOW);
        digitalWrite(PIN_RELAY4, LOW);
        digitalWrite(PIN_RELAY5, LOW);
        digitalWrite(PIN_RELAY6, LOW);
        Serial.println("Relay3");
      }
      if (i==4){
        digitalWrite(PIN_RELAY4, HIGH);
        digitalWrite(PIN_RELAY2, LOW);
        digitalWrite(PIN_RELAY3, LOW);
        digitalWrite(PIN_RELAY1, LOW);
        digitalWrite(PIN_RELAY5, LOW);
        digitalWrite(PIN_RELAY6, LOW);
        Serial.println("Relay4");
      }
      if (i==5){
        digitalWrite(PIN_RELAY5, HIGH);
        digitalWrite(PIN_RELAY2, LOW);
        digitalWrite(PIN_RELAY3, LOW);
        digitalWrite(PIN_RELAY4, LOW);
        digitalWrite(PIN_RELAY1, LOW);
        digitalWrite(PIN_RELAY6, LOW);
        Serial.println("Relay5");
      }
      if (i==6){
        digitalWrite(PIN_RELAY6, HIGH);
        digitalWrite(PIN_RELAY2, LOW);
        digitalWrite(PIN_RELAY3, LOW);
        digitalWrite(PIN_RELAY4, LOW);
        digitalWrite(PIN_RELAY1, LOW);
        digitalWrite(PIN_RELAY5, LOW);
        Serial.println("Relay6");
      }
    } else if (MPR121.isNewRelease(i)) {
      Serial.print("electrode ");
      Serial.print(i, DEC);
      Serial.println(" was just released");
      myTimer1 = millis();
    }
    else {
      if (millis() - myTimer1 >= period) {   
        digitalWrite(PIN_RELAY1, LOW);
        digitalWrite(PIN_RELAY2, LOW);
        digitalWrite(PIN_RELAY3, LOW);
        digitalWrite(PIN_RELAY4, LOW);
        digitalWrite(PIN_RELAY5, LOW);
        digitalWrite(PIN_RELAY6, LOW);
        myTimer1 = millis();
        Serial.println("Timer");
      }
    }
  }

  if (MPR121_DATASTREAM_ENABLE) {
    MPR121_Datastream.update();
  }
}
