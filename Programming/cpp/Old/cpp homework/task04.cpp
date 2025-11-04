#include <iostream>
#include <locale.h>
using namespace std;

int main(void){
    setlocale(LC_ALL, "Russian");
    int k, r, s=0,n=0;
    double dolg=0;
    double p;
    cout<<"Введите размер кредита, процент, прибыль в год:"<<endl;
    cin>>k>>p>>r;
    p=p/100.0;
    dolg=k;
    while (dolg>s && n<100){
        n++;
        dolg=dolg*(1+p);
        s+=r;
    }
    if (s>=dolg)
        cout<<"Погасит через "<<n<<" лет"<<endl;
    else
        cout<<"Не сможет погасить кредит"<<endl;
    return 0;
}