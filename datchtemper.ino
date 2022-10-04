int sensorPin = 0; //аналоговый ввод для выхода датчика TMP36
    //разрешение 10 мВ / градус цельсия со смещением на 500 мВ 
    //для отрицательной температуры
    void setup()
    {
    Serial.begin(9600);
    }
    void loop()
    {
    int reading = analogRead(sensorPin);
    // преобразуем показания в напряжение, для 3.3v использовать значение 3.3
    float voltage = reading * 5.0;
    voltage /= 1024.0;
    // выводим напряжение
    Serial.print(voltage); Serial.println(" volts");
    float temperatureC = (voltage - 0.5) * 100 ; //исходя из 10 мВ на градус со смещением 500 мВ
    Serial.print(temperatureC); Serial.println(" degrees C");
    // в фаренгейтах
    float temperatureF = (temperatureC * 9.0 / 5.0) + 32.0;
    Serial.print(temperatureF); Serial.println(" degrees F");
    delay(1000); //ждем секунду
    }
