#include <iostream>
#include <locale.h>
using namespace std;

typedef unsigned long long int ulli;

int main(void) {
    setlocale(LC_ALL, "Russian");
    double f = -7.9;
    long long int n = *((long long int*) &f);
    cout << "Число " << f << " в 16-ричном виде: " << hex << n << endl << endl;

    int sign = (n >> 63) & 0x1 ? -1 : 1;

    ulli one = 1;
    ulli m = n & ((one << 52) - 1);
    ulli e = ((n>>52) & 0x7FF) - 1023;

    cout << "Знак: " << dec<< sign << endl;
    cout << "Экспонента: " << dec << e << endl;
    cout << "Мантисса: " << dec << m << endl;
    cout << endl;

    m += (one << 52);//учитываем единицу

    ulli cel = m >> (52 - e);
    ulli lli_drob = m & ((one << (52 - e)) - 1);
    double d_drob = (double)lli_drob / (one << (52 - e));

    double new_f = sign * (cel + d_drob);
    cout<<new_f<<endl;

    return 0;
}