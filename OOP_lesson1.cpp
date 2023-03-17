#include <iostream>
#include <cmath>
//#include "ConsoleApplication1.h"
using namespace std;

/*1. Создать класс Power, который содержит два вещественных числа. Этот класс должен иметь
две переменные-члена для хранения этих вещественных чисел. Еще создать два метода: один с
именем set, который позволит присваивать значения объявленным в классе переменным,
второй — calculate, который будет выводить результат возведения первого числа в степень второго числа.
Задать значения этих двух чисел по умолчанию.*/

class Power {
public:
    void set(const int as, const int bs);
    int calculate(int a, int n);
    void print();
private:
    int a = 1;
    int b = 1;
};
void Power::set(const int as, const int bs) {
    a = as;
    b = bs;
}

int Power::calculate(int a, int n) { return pow(a, n); }

void Power::print() { cout << a << ", " << b << endl; }

/*2. Написать класс с именем RGBA, который содержит 4 переменные-члена типа
std::uint8_t: m_red, m_green, m_blue и m_alpha (#include cstdint для доступа
к этому типу). Задать 0 в качестве значения по умолчанию для m_red, m_green,
m_blue и 255 для m_alpha. Создать конструктор со списком инициализации членов,
который позволит пользователю передавать значения для m_red, m_blue, m_green
и m_alpha. Написать функцию print(), которая будет выводить значения переменных-членов*/
class RGBA {
public:
    void set(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha) {
        m_red = red;
        m_green = green;
        m_blue = blue;
        m_alpha = alpha;
    }
    void print() {
        cout << static_cast<int> (m_red) << ", "
            << static_cast<int> (m_green) << ", "
            << static_cast<int> (m_blue) << ", "
            << static_cast<int> (m_alpha) << endl;
    }
private:
    uint8_t m_red = 0;
    uint8_t m_green = 0;
    uint8_t m_blue = 0;
    uint8_t m_alpha = 255;
};

int main() {
    Power pow;
    pow.print();
    pow.set(1, 2);
    pow.print();
    cout << pow.calculate(2, 3) << endl;

    RGBA rgba;
    rgba.set(100, 0, 255, 0);
    rgba.print();
}