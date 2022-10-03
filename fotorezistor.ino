int ldr1 = 0; //и фоторезистора
int ldr2 = 1;
int ldr3 = 2;
int ldr4 = 3;
int ldr5 = 4;

int photocellReading1;
int photocellReading2;
int photocellReading3;
int photocellReading4;
int photocellReading5;

void setup() 

{

Serial.begin(9600);

}

void loop() 
{
  photocellReading1 = analogRead(ldr1);
  photocellReading2 = analogRead(ldr2);
  photocellReading3 = analogRead(ldr3);
  photocellReading4 = analogRead(ldr4);
  photocellReading5 = analogRead(ldr5);

if (analogRead(ldr1) > 200) Serial.println("датчик 1");
if (analogRead(ldr2) > 200) Serial.println("датчик 2");
if (analogRead(ldr3) > 200) Serial.println("датчик 3");
if (analogRead(ldr4) > 200) Serial.println("датчик 4");
if (analogRead(ldr5) > 200) Serial.println("датчик 5");

delay(1100);
}
