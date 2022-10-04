#include "MPR121.h"
#include <Wire.h>
#include "GyverButton.h"

#define BTN1 3      // кнопка подключена сюда (PIN --- КНОПКА --- GND)
#define numElectrodes 12

GButton butt1(BTN1);

void setup()
{
  Serial.begin(115200);
  butt1.setTickMode(AUTO);
  while(!Serial);  // only needed if you want serial feedback with the
  		   // Arduino Leonardo or Bare Touch Board

  Wire.begin();
  
  // 0x5C is the MPR121 I2C address on the Bare Touch Board
  if(!MPR121.begin(0x5A)){ 
    Serial.println("error setting up MPR121");  
    switch(MPR121.getError()){
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
    while(1);
  }
  
  // pin 4 is the MPR121 interrupt on the Bare Touch Board
  MPR121.setInterruptPin(2);

  // this is the touch threshold - setting it low makes it more like a proximity trigger
  // default value is 40 for touch
  MPR121.setTouchThreshold(30);
  
  // this is the release threshold - must ALWAYS be smaller than the touch threshold
  // default value is 20 for touch
  MPR121.setReleaseThreshold(15);  

  // initial data update
  MPR121.updateTouchData();
}

void loop()
{
  if (butt1.isClick()) Serial.println("language");
  if (butt1.isHold()) Serial.println("language");
  if(MPR121.touchStatusChanged()){
    MPR121.updateTouchData();
    for(int i=0; i<numElectrodes; i++){
      if(MPR121.isNewTouch(i)){
        //Serial.print("ПРЕДМЕТ ");
        Serial.println(i , DEC);  
      }
    } 
  }
}
