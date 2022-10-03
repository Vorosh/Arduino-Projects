#define potent_pin 0   // сюда подключена средняя нога потенциометра
int val;               // переменная для хранения значения с потенциометра

void setup() {
  Serial.begin(9600);
  
}

void loop() {
  val = analogRead(potent_pin);     // запомнить показания с потенциометра
  val = map(val, 0, 1023, 0, 10);   // перевести в диапазон 0.. 10
  val = constrain(val, 0, 10);      // ограничить диапазон 0.. 10
  Serial.println(val);        // вывести в порт
  delay(30);

}
