#include <iostream>
#include <locale.h>
using namespace std;

typedef unsigned long long int ulli;

int main(void) {
    setlocale(LC_ALL, "Russian");
    double f = 2.5;
    long long int n = *((long long int*) &f);
    cout << "Число " << f << " в 16-ричном виде: " << hex << n << endl << endl;

    ulli sign = (n >> 63) & 0x1;
    ulli exp = (n >> 52) & 0x7FF;
    ulli mantissa = n & 0x7FFFFFFFFFFFF;

    cout << "Знак: " << sign << endl;
    cout << "Экспонента: " << exp << endl;
    cout << "Мантисса: " << mantissa << endl;
    cout << endl;

    exp -= 1023;
    cout << "Экспонента: " << exp << endl;

    ulli one = 1;
    ulli m = n & ((one << 52) - 1);

    ulli e = ((n>>52) & 0x7FF) - 1023;

    cout << "Экспонента: " << e << endl;

    double new_f;

//    unsigned long long int new_n = (sign << 63) | (exp << 52) | mantissa;
//    double new_f = *((double*)&new_n);

//    cout << "Восстановленное число: " << new_f << endl;

//#include <iostream>
//#include <locale.h>
//    using namespace std;
//
//    int main(void)
//    {
//        setlocale(LC_ALL, "rus");
//        float f = 2.5;
//        int n = *((int*)&f);
//        int ex = (n & 0x7F800000);
//        int mant = (n & 0x007FFFFF);
//        mant += 0x00800000;
//        /*cout << ex << endl;*/
//        ex = (ex >> 23)-127;
//        /*cout << ex << endl;*/
//        int cel = mant >> 23-ex;
//        /*cout << hex <<cel  << endl;*/
//        int mask = (1 << (23 - ex)) - 1;
//        int fractional_bits = mant & mask;
//        float drob = (float)fractional_bits / (1 << (23 - ex));
//        cout << "Целая часть: " << cel << endl;
//        cout << "Дробная часть: " << drob << endl;
//        cout << "Исходное число: " << f << endl;
//        cout << "Восстановленное: " << (cel + drob) << endl;
//        return 0;
//    }

    return 0;
}