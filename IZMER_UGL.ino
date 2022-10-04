#include <l3g4200d.h>
#include <lis331dlh.h>
#include <LPS331.h>
#include <MadgwickAHRS.h>
#include <TroykaIMU.h>

#include <Wire.h>
Gyroscope gyro;
Accelerometer accel;
float rotationThreshold = 1;   //Минимальная угловая скорость, которую можно не учитывать
float pitchacc;
float currentAngle;
float pitch;
boolean DR;
unsigned long t;
unsigned long tt;
void setup() {
  Serial.begin (115200);
  gyro.begin();
  gyro.setRange(RANGE_500DPS);
  accel.begin();
  DR = true;
  pitch = 0;
}
void loop() {
  // Тут только для первого лупа задаю начальное значие угла отклонения для гироскопа, который равен показанию акселерометра
  if (DR = true)
  {
    currentAngle = atan2(accel.readGY(), accel.readGZ()) * 180 / 3.14;
    t = micros();
    DR = false;
  }
  float gyroRate = gyro.readDegPerSecX();
  tt = micros();
  //Игнорировать показания гироскопа, если они меньше заданного лимита
  if (gyroRate >= rotationThreshold || gyroRate <= -rotationThreshold) {
    currentAngle += gyroRate * (tt - t) / 1000.0;
  }
  Serial.print(currentAngle);
  Serial.print ("\t");
  pitchacc = atan2(accel.readGY(), accel.readGZ()) * 180 / 3.14;
  pitch = (pitchacc * 0.05 + 0.95 * currentAngle);
  Serial.print (pitchacc);
  Serial.print ("\t");
  Serial.println ( pitch);
  t = tt;
  delay(300);
}
