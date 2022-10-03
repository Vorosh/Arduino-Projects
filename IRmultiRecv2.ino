#include <IRremote.h>

// To support more than 5 receivers, remember to change the define
// IR_PARAMS_MAX in IRremoteInt.h as well.
#define RECEIVERS 1

IRrecv *irrecvs[RECEIVERS];

decode_results results;

void setup()
{
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  irrecvs[0] = new IRrecv(2); // Receiver #0: pin 2

  for (int i = 0; i < RECEIVERS; i++)
    irrecvs[i]->enableIRIn();
}

void loop() {
  digitalWrite(2, HIGH);
  for (int i = 0; i < 1; i++)
  {
    if (irrecvs[i]->decode(&results))
    {
      Serial.print("Receiver #");
      Serial.print(i);
      Serial.print(":");
      Serial.println(results.value, HEX);
      irrecvs[i]->resume();
    }
  }
}
