#include <iostream>
#include <locale.h>

using namespace std;

unsigned int summ(unsigned int m){
    if (m < 10) {
        return m;
    } else {
        return summ(m/10) + m%10;
    }
}

double f(double x, unsigned int n){
    if (n==0){
        return 1;
    }else if (n%2 != 0){
        return x * f(x,n-1);
    }else{
        return f(x*x,n/2);
    }
}

void dvoich(unsigned int n) {
    if (n > 1) dvoich(n / 2);
    cout << (n % 2);
}

int main(void) {
    setlocale(LC_ALL,"RU");
    unsigned int task1 = summ(765345);
    double task2 = f(2.8, 7);

    cout<<task1<<endl;
    cout<<task2<<endl;

    int n = 4;
    cout<<n<<" в двоичной сс: ";
    dvoich(n);

    return 0;
}
