#include <iostream>
#include <locale.h>

using namespace std;

int main(void) {
    setlocale(LC_ALL,"Russian");
    cout<<"Преобразование в двоичную систему счисления"<<endl;
    double x;
    do{
        cout<<"Введите вещ. число 0<x<1: ";
        cin>>x;
    }while (x<=0 || x>=1);
    cout<<"Двоичное число: 0.";

    for (int i=0; i<24; i++){
        x *= 2;
        cout<<(int)x;
        x -= (int)x;
        if (x <= 1e-8)
            break;
    }
    cout<<endl;
    return 0;
}