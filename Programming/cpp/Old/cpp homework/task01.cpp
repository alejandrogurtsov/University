#include <iostream>
#include <cmath>
#include <locale.h>
#define _USE_MATH_DEFINES
using namespace std;

int main(void){
    setlocale(LC_ALL, "Russian");
    double x;
    double pogr = 1e-7;
    int cht=1, nech=1;
    double y, my;

    for (x=-5; x<=5; x+=0.1){
        y=tan(x);//y=pow(M_E,x) //y=x*x*x*x
        my=tan(-x);//my=pow(M_E,-x) //my=(-x)*(-x)*(-x)*(-x)
        if ((y-my > pogr) || (y-my < -pogr))
            cht = 0;
        if ((y+my > pogr) || (y+my < -pogr))
            nech=0;
    }
    if (cht==1)
        cout<<"Четная"<<endl;
    else if (nech==1)
        cout<<"Нечетная"<<endl;
    else
        cout<<"Ни четная, ни нечетная"<<endl;
    return 0;
}