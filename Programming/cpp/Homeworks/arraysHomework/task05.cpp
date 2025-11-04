#include <iostream>
#include <locale.h>
using namespace std;

//1 0 0 1 0 0 0 0 0 0
//1 0 1 1 1 0 0 0 1 1
//0 0 1 1 0 0 1 0 1 0
//0 0 0 0 0 1 1 0 1 0
//0 1 0 1 0 0 0 0 0 0
//0 1 1 1 1 1 1 1 0 1
//0 0 1 1 1 1 1 0 0 1
//1 0 1 1 1 1 1 0 1 1
//1 0 0 0 1 1 0 0 1 1
//1 1 1 0 0 0 0 1 1 1

int main(void) {
    setlocale(LC_ALL,"Russian");
    int a[12][12];

    for (int i=0; i<12;i++){
        for (int j=0; j<12;j++){
            a[i][j]=-1;
        }
    }

    cout<<"Заполните массив, где 1 - клетка, принадлежащая многоугольнику, и 0 в противоположном случае"<<endl;
    for (int i=1; i<11;i++){
        for (int j=1; j<11;j++){
            cin>>a[i][j];
        }
    }

    int count = 0;

    for (int i=1; i<11;i++){
        for (int j=1; j<11;j++) {
            if (a[i][j] == 1) {
                count++;

            }
        }
    }

    cout<<count<<endl;

    return 0;
}