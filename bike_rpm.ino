int RPM;
float r_speed, rev_time;
float r = 40; //cm
volatile unsigned long lastflash, flash;

void setup() {
  Serial.begin(9600);  
  attachInterrupt(0,sens,FALLING); 
  pinMode(2, OUTPUT);   
  digitalWrite(2, HIGH);  //подать 5 вольт на 3 пин
}
void sens() {
  flash = micros() - lastflash;   // время между двумя оборотами
  lastflash = micros();
  RPM=60/((float)(micros()-lastflash)/1000000);
  r_speed = (float) 2 * 3.1415 * r / 100 / rev_time * 3.6;
  rev_time = (float) flash / 1000000;
}

void loop() {
  if ((micros()-lastflash)>1000000){ 
    RPM=0;  
    r_speed=0;
  }
    Serial.println(r_speed, 0);   
    delay(800);
}
