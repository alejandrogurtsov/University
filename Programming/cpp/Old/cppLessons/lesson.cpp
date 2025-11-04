#include <iostream>
#include <locale.h>
using namespace std;

int main(void){
    float* x=0;
    x=x+1;
    cout<<x;
    //выведется размерность типа данных char=1, short=2, int=4, float=4, double=8
    return 0;
}