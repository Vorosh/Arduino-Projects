#define PIN_RELAY 3

bool relayState = 0;
int EngineMode = 0;

void setup() {
  Serial.begin(115200);
  Serial.setTimeout(1);
  Serial.flush();
  pinMode(PIN_RELAY, OUTPUT);
}

void loop() {
  relayState = digitalRead(PIN_RELAY);
  if (Serial.available() > 0) {     
    EngineMode = Serial.parseInt();     
  }
    switch (EngineMode) {
      case 3: digitalWrite(PIN_RELAY, HIGH); break; // engine start 
      case 4: digitalWrite(PIN_RELAY, LOW); break;  // engine stop
  }
}
