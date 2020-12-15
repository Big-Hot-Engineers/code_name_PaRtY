#include <Wire.h>
#include <I2Cdev.h>
#include "MPU6050.h"

MPU6050 mpu6050; //создание объекта mpu6050 класса MPU 6050

const float KOEF_GYRO_250 = 1 / 131.072; //131.072 - коэффициент масштаба сырых данных при 250град/сек
const float MILLI_SEC_TO_SEC = 1 / 1000.0;
const float NUM_READ = 1024.0;//для оптимизации деления (целого на целое) лучше использоввать 2^n, но нам нужен float
const uint8_t PRINT_CLOCK = 100;

float midArifm();
int rounding(float x);

float driftError = 0.0;
uint32_t currentTime = 0, previousTime = 0, printTime = 0;
float elapsedTime = 0.0;
float yaw = 0;
int16_t ax_raw = 0, ay_raw = 0, az_raw = 0;
int16_t gx_raw = 0, gy_raw = 0, gz_raw = 0; //переменные для значений акселерометра и гироскопа
float gyro_z = 0.0;
double * c;
void setup()
{
  Serial.begin(9600);// Инициирование последовательного соединения со скоростью 9600 бод
  Serial.flush();
  mpu6050.initialize(); // первичная настройка датчика
  mpu6050.setFullScaleAccelRange(MPU6050_ACCEL_FS_2);//режим 8g
  mpu6050.setFullScaleGyroRange(MPU6050_GYRO_FS_250);//Максимальное значение уг. ск-ти 250 град/сек
  Serial.println(mpu6050.testConnection() ? "MPU6050 connection successful" : "MPU6050 connection failed");
  delay(1000);
  driftError = midArifm();
  Serial.println(driftError);
}

void loop()
{
  mpu6050.getMotion6(&ax_raw, &ay_raw, &az_raw, &gx_raw, &gy_raw, &gz_raw);    //опрос
  previousTime = currentTime;        // Previous time is stored before the actual time read
  currentTime = millis();            // Current time actual time read
  elapsedTime = (float)((currentTime - previousTime) * MILLI_SEC_TO_SEC);
  gyro_z = (float)gz_raw * KOEF_GYRO_250 - driftError;
  yaw = yaw + gyro_z * elapsedTime;
  currentTime = millis();
  if (currentTime - printTime >= PRINT_CLOCK )
  { int16_t yaw_rounded = rounding(yaw);
    if (yaw_rounded == 0)
    {
      Serial.print("zero");
      Serial.print('\0');
      Serial.print('\n');
      Serial.flush();
    } else {
    Serial.print(yaw_rounded);
    Serial.print('\0');
    Serial.print('\n');
    Serial.flush();
    }
    printTime = millis();
  }
  

}

float midArifm()
{
  long sum = 0;                       // локальная переменная sum
  for (int i = 0; i < NUM_READ; i++)
  {  // согласно количеству усреднений
    mpu6050.getMotion6(&ax_raw, &ay_raw, &az_raw, &gx_raw, &gy_raw, &gz_raw);//опрос
    sum += gz_raw;
  }// суммируем значения с любого датчика в переменную sum
  return ((float)sum * (float)(1.0 / NUM_READ) * KOEF_GYRO_250);
}

int rounding(float x)
{
  if (abs(modf(x, c)) >= 0.5)
  {
    if (x > 0)
    {
      return (int)(ceil(x));
    }
    else
    {
      return (int)(floor(x));
    }
  }
  else
  {
    if (x > 0)
    {
      return (int)(floor(x));
    }
    else
    {
      return (int)(ceil(x));
    }
  }
  return 0;
}
