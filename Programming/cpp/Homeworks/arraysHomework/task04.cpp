#include <iostream>
#include <locale.h>
using namespace std;

int main(void){
    setlocale(LC_ALL,"Russian");
    int n=0;
    cout<<"Введите n - размер массива:"<<endl;
    cin>>n;

    int a[n];
    cout<<"Введите элементы массива через пробел:"<<endl;
    for (int i=0; i<n; i++){
        cin>>a[i];
    }
    int k=0;
    int maxK=0;
    for (int i=0; i<n; i++){
        if (a[i]==0){
            k++;
            if (k>maxK){
                maxK=k;
            }
        }else{
            k=0;
        }
    }

    cout<<"Самая длинная последовательность подряд идущих нулей: "<<maxK;

    return 0;
}