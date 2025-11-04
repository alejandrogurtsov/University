#include <iostream>
#include <locale.h>
using namespace std;

int main(void) {
    setlocale(LC_ALL,"Russian");
    int state = 0;
    int n;

    cout<<"Машина Тьюринга 3*n (работает в унарной системе счисления)"<<endl;
    cout<<"Введите число, которое хотите умножить (в десятичной системе счисления): "<<endl;
    cin>>n;

    int size = n*5+1;
    int* a = new int[size]();
    for (int i = 1; i<=n; i++){
        *(a+i) = 1;
    }

    int i=0;
    while (i >= 0 && i < size){
        switch (state){
            case 0:
                if (*(a+i)==0) i++;
                else{
                    state=1;
                    *(a+i)=0;
                    i++;
                }
                break;
            case 1:
                if (*(a+i)==1) i++;
                else{
                    state=2;
                    i++;
                }
                break;
            case 2:
                if (*(a+i)==0){
                    state = 3;
                    *(a+i)=1;
                    i++;
                }else i++;
                break;
            case 3:
                if (*(a+i)==0){
                    state=4;
                    *(a+i)=1;
                    i++;
                }
                break;
            case 4:
                if (*(a+i)==0){
                    state=5;
                    *(a+i)=1;
                    i--;
                }
                break;
            case 5:
                if (*(a+i)==1) i--;
                else{
                    state = 6;
                    i--;
                }
                break;
            case 6:
                if (*(a+i)==1) i--;
                else{
                    state = 7;
                    i++;
                }
                break;
            case 7:
                if (*(a+i)==1){
                    state = 1;
                    *(a+i)=0;
                    i++;
                }else{
                    state = 0;
                    i=size;
                }
                break;
        }
    }

    int c=0;
    for (int j = 0; j<size; j++){
        if (*(a+j)==1){
            c++;
            cout<<*(a+j)<<" ";
        }
    }
    cout<<"("<<c<<" единиц)"<<endl;
    cout<<n<<" * 3 = "<<n*3<<endl;

    delete[] a;
    return 0;
}