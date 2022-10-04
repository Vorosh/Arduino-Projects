#include <Wire.h>
int address = 0;

void setup() {
  Wire.begin();        // join i2c bus (address optional for master)
  Serial.begin(9600);  
}

void loop() {
  Wire.requestFrom(address, 1);    // request 6 bytes from slave device #8

  while (Wire.available()) { 
    char c = Wire.read(); // receive a byte as character
    Serial.print(c);         
  }

  delay(500);
}
