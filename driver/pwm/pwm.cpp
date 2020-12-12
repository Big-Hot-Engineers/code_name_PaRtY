
#include <iostream>
/*
 * Включаем необходимые библиотеки
 */
#include <wiringPi.h>
#include <softPwm.h>
 
#define PIN1            27
#define PIN2		28
#define RANGE           100
#define VALUE           50
 
using namespace std;
 
int main() {
  /*
   * Инициализируем WiringPi
   */
  if (wiringPiSetup() == 0) {
    /*

     * Задает контакт, на котором будет генерироваться Soft PWM
     * GPIO-контакт 23, диапазон значений - 100, значение - 50
     */
 softPwmCreate(PIN2, VALUE, RANGE);
    softPwmCreate(PIN1, VALUE, RANGE);
    cout << "softPwmCreate(PIN, VALUE, RANGE);" << endl;
    cout << "PIN:   " << PIN1 << endl;
    cout << "RANGE: " << RANGE << endl;
    cout << "VALUE: " << VALUE << endl;
    cout << endl;
 
    /*
     * Обновляем значение (value) ШИМ на 25
     */
    softPwmWrite(PIN1, 25);
    softPwmWrite(PIN2, 25);

	cout << "softPwmWrite(PIN1, 25);" << endl;
    cout << "PIN:   " << PIN1 << endl;
    cout << "VALUE: " << 25 << endl;
    cout << endl;
    delay(5000);
 
    /*
     * Обновляем значение (value) ШИМ на 50
     */
//    softPwmWrite(PIN1, 50);
  //  cout << "softPwmWrite(PIN1, 50);" << endl;
//    cout << "PIN:   " << PIN1 << endl;
  //  cout << "VALUE: " << 50 << endl;
//    cout << endl;
  //  delay(5000);
 
    /*
     * Обновляем значение (value) ШИМ на 75
     */
 //   softPwmWrite(PIN1, 75);
   // cout << "softPwmWrite(PIN, 75);" << endl;
//    cout << "PIN:   " << PIN1 << endl;
  //  cout << "VALUE: " << 75 << endl;
   // cout << endl;
//    delay(5000);
 
    /*
     * Обновляем значение (value) ШИМ на 100
     */
  //  softPwmWrite(PIN1, 100);
  //  cout << "softPwmWrite(PIN1, 100);" << endl;
  //  cout << "PIN:   " << PIN1 << endl;
  //  cout << "VALUE: " << 100 << endl;
  //  cout << endl;
  // / delay(5000);
 
    /*
     * Отключаем ШИМ на GPIO-контакте 7
     */
	softPwmStop(PIN2);   
 softPwmStop(PIN1);
    cout << "softPwmStop(PIN1);" << endl;
    cout << "PIN1:   " << PIN1 << endl;
  }
 
  return 0;
}
