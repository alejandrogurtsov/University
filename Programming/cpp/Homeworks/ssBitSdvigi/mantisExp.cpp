#include <iostream>
#include <locale.h>
using namespace std;

int main(void) {
    setlocale(LC_ALL, "Russian");
    float f = -2.5;
    int n = *((int *) &f);
    cout << "Число " << f << " в 16-ричном виде: " << hex << n << endl << endl;

    unsigned int sign = (n >> 31) & 0x1;
    unsigned int exp = (n >> 23) & 0xFF;
    unsigned int mantissa = n & 0x7FFFFF;

    cout << "Знак: " << dec << sign << endl;
    cout << "Экспонента: " << dec << exp << endl;
    cout << "Мантисса: " << dec << mantissa << endl;
    cout << endl;

    unsigned int new_n = (sign << 31) | (exp << 23) | mantissa;
    float new_f = *((float*)&new_n);

    cout << "Восстановленное число: " << new_f << endl;

    return 0;
}