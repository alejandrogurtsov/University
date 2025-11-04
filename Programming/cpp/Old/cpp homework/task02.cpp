#include <iostream>
#include <cmath>
#include <locale.h>
#define _USE_MATH_DEFINES
using namespace std;

int main(void){
    setlocale(LC_ALL, "Russian");
    double y1, y2;
    int p = 1;
//    for (double x=0; x<=5*M_PI; x+=0.1){
//        y1=sin(x)*sin(x);
//        y2=sin(x+M_PI)*sin(x+M_PI);
//        if (fabs(y2-y1)>1e-6)
//            p=0;
//    }
//    for (double x=0; x<=5*M_PI; x+=0.1){
//        y1=tan(x);
//        y2=tan(x+M_PI);
//        if (fabs(y1)>1e3 || fabs(y2)>1e3)
//            continue;
//        if (fabs(y2-y1)>1e-6)
//            p=0;
//    }
    for (double x=0; x<=5*M_PI; x+=0.1){
        if (x==0)
            continue;
        y1=sin(x)/x;
        y2=sin(x+2*M_PI)/(x+2*M_PI);
        if (fabs(y2-y1)>1e-6)
            p=0;
    }
    if (p==1)
        cout<<"Периодическая"<<endl;
    else
        cout<<"Не периодическая"<<endl;
    return 0;
}