#include <iostream>
#include <locale.h>
using namespace std;

int main() {
    setlocale(LC_ALL,"Russian");
    double num;
    cout<<"Введите вещественное число: "<<endl;
    cin>>num;

    int cel = int(num);
    double ves = num-cel;

    int binValue = 0x40000000;
    cout<<"Двоичное число: ";
    if (cel==0){
        cout<<"0";
    }

    while (binValue > cel) binValue >>= 1;
    while (binValue>0){
        if (cel>= binValue){
            cout<<"1";
            cel -= binValue;
        }
        else
            cout<<"0";
        binValue >>= 1;
    }

    cout<<".";

    for (int i=0; i<24; i++){
        ves *= 2;
        cout<<(int)ves;
        ves -= (int)ves;
        if (ves <= 1e-8)
            break;
    }

    cout<<endl;

    return 0;
}
