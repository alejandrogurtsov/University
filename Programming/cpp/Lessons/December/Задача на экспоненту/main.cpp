#include <iostream>
#include <locale.h>
#include <fstream>
#include <cmath>

using namespace std;

const int DIGITS = 500; //кол-во знаков после запятой

bool prime(long long n);
void exp(int e[]);

int main(void) {
    setlocale(LC_ALL,"RU");
    int e[DIGITS]={0};
    exp(e);

    for (int i = 0; i <= DIGITS - 10 + 1; i++) {
        long long int num = 0;
        for (int j = 0; j < 10; j++) {
            num = num * 10 + e[i + j];
        }
        if (prime(num)){
            cout<<num<<" "<<i<<"-позиция";
            break;
        }
    }

    return 0;
}

bool prime(long long int n){
    bool f = true;
    for (long long i = 2; i<(int)sqrt(n)+1; i++){
        if (n%i==0){
            f = false;
            break;
        }
    }
    return f;
}

void exp(int e[]){
    e[0] = 2;
    int n = 1000; // кол-во членов ряда суммы обратных факториалов

    for (int i = 2; i <= n; ++i) {
        int term[DIGITS]={0};
        term[0] = 1;

        // делю term на i факториал
        for (int j = 1; j <= i; j++) {
            int carry = 0;
            for (int k = 0; k < DIGITS; k++) {
                int cur = term[k] + carry * 10;
                term[k] = cur / j;
                carry = cur % j;
            }
        }
        // собрал всё в массив е
        int carry = 0;
        for (int k = DIGITS - 1; k >= 0; k--) {
            int sum = e[k] + term[k] + carry;
            e[k] = sum % 10;
            carry = sum / 10;
        }
    }
}