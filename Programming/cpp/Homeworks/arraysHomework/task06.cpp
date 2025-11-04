#include <iostream>
#include <locale.h>
using namespace std;

int main(void) {
    setlocale(LC_ALL, "Russian");
    int n=0;
    cout<<"Введите n - размер массива:"<<endl;
    cin>>n;

    int a[n];
    cout<<"Введите элементы массива через пробел:"<<endl;
    for (int i=0; i<n; i++){
        cin>>a[i];
    }

    for (int j=0; j<n; j++) {
        for (int i = 1; i < n; i++) {
            if (a[i] != 0 && a[i - 1] == 0) {
                a[i - 1] = a[i];
                a[i] = 0;
            }
        }
    }

    for (int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }

    return 0;
}