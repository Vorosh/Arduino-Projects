volatile int counter1 = 0;  // переменная-счётчик
volatile int counter2 = 0;  // переменная-счётчик
volatile int counter3 = 0;  // переменная-счётчик
volatile int counter4 = 0;  // переменная-счётчик
volatile int counter5 = 0;  // переменная-счётчик


int buttonState1 = 0;
int znach = 0;

void setup() {
  Serial.begin(9600); // открыли порт для связи
  // подключили кнопку на D2 и GND
  pinMode(2, INPUT_PULLUP); \
  pinMode(18, INPUT_PULLUP);
  pinMode(19, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(21, INPUT_PULLUP);
  // D2 это прерывание 0
  // обработчик - функция buttonTick
  // FALLING - при нажатии на кнопку будет сигнал 0, его и ловим
  attachInterrupt(0, test1, FALLING);
  attachInterrupt(2, test2, FALLING);
  attachInterrupt(3, test3, FALLING);
  attachInterrupt(4, test4, FALLING);
  attachInterrupt(5, test5, FALLING);
  
}
void test1() {
  znach = 1;  // + нажатие
}

void test2() {
  counter2++;  // + нажатие
}

void test3() {
  counter3++;  // + нажатие
}

void test4() {
  counter4++;  // + нажатие
}

void test5() {
  counter5++;  // + нажатие
}

void loop() {
  buttonState1 = digitalRead(2);
  if (znach == 1){
    counter1++;
  }
  Serial.println(buttonState1);  // выводим
  if (buttonState1 == LOW){
    znach = 0;
  }
}
