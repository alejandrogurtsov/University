#include <iostream>
#include <locale.h>
using namespace std;

int main(void){
    setlocale(LC_ALL, "Russian");
    int a,b;
    cout<<"Введите a и b:"<<endl;
    cin>>a>>b;

    for (int y=b; y>=-b; y--){
        for (int x=-a; x<=a; x++){
            double usl=((double)(x*x)/(a*a) + (double)(y*y)/(b*b));
            if (usl<=1.0)
                cout<<"*";
            else
                cout<<" ";
        }
        cout<<endl;
    }
    return 0;
}