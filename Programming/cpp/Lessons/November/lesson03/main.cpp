#include <iostream>
#include <locale.h>

using namespace std;

const int FIB_NUMBER=10;
int* createFib(void)
{
    int* arr = new int[FIB_NUMBER];
    arr[0]=arr[1]=1;
    for (int i=2; i<FIB_NUMBER; i++){
        arr[i]=arr[i-1]+arr[i-2];
    }
    return arr;
}

int main(void) {
    setlocale(LC_ALL,"RU");
    int* fibArr = createFib();
    cout<<"Числа Фибоначчи"<<endl;
    for (int i = 0; i<FIB_NUMBER; i++){
        cout<<fibArr[i]<<" ";
    }
    cout<<endl;
    delete[] fibArr;

    return 0;
}
