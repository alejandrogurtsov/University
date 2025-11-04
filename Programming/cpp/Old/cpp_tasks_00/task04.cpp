#include <iostream>
#include <locale.h>
using namespace std;

int main(void){
    setlocale(LC_ALL, "Russian")
    int k, p, r, s,n;
    cout<<"Введите размер кредита, процент, прибыль в год:"<<endl;
    cin>>k>>p>>r;
    while (k<s){
        k=k*(1+p);
        s+=r;
        n+=1
    }
    cout<<n<<endl;
    return 0;
}