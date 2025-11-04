#include <iostream>
#include <iomanip>
#include <locale.h>
using namespace std;

int main(void){
    setlocale(LC_ALL,"Russian");
    cout<<fixed<<setprecision(4);
    const double post = 1.609344;
    double k;
    cout<<"Введите расстояние:"<<endl;
    cin>>k;
    cout<<"мили"<<"\t\t"<<"км"<<endl;
    double m_mil=1; double n_km=1;
    for(int km=1; km<=k; km++){
        double mil = km/post;
        cout<<mil<<"\t"<<double(km)<<endl;
        if (km==){

        }
        cout<<m_mil<<"\t"<<m_mil*post<<endl;
        m_mil++;
    }
    //проверять, если равны?
    return 0;
}