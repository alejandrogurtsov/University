#include <iostream>
#include <locale.h>
using namespace std;


int main(void) {
    setlocale(LC_ALL, "Russian");
    float f = -2.5;
    int n = *((int *) &f);
    cout << "Число " << f << " в 16-ричном виде: " << hex << n << endl << endl;

    int sign = (n >> 31) & 0x1 ? -1 : 1;
    int exp = (n >> 23) & 0xFF;
    int mantissa = n & 0x7FFFFF;

    cout << "Знак: " << dec << sign << endl;
    cout << "Экспонента: " << dec << exp << endl;
    cout << "Мантисса: " << dec << mantissa << endl;
    cout << endl;

    exp -= 127;
    mantissa += 0x800000; //учли единичку
    int cel = mantissa >> (23-exp);
    int i_drob = mantissa & ((1<<(23-exp))-1);

    float f_drob = (float)i_drob / (1 << (23-exp));
    float new_f = sign * (cel + f_drob);

    //    for (int i = 31; i>=0; i--){
//        unsigned int bit = (n >> i) & 1;
//        cout<<bit;
//
//        if (i == 31 || i == 23)
//            cout<<" ";
//    }
//    cout<<endl<<endl;

    cout << "Восстановленное число: " << new_f << endl;

    return 0;
}