#include <iostream>
#include <locale.h>
#include <cmath>

using namespace std;

int main() {
    int arr[] = {1000,100,50,20,10,5,2,1};
    const int k = sizeof(arr) / sizeof(arr[0]) ;
    int m = 27;

    int left[k]={0};
    int right[k]={0};

    int mass = m;

    for (int i = 0; i<k; i++){
        int w = arr[i];
        if (mass == 0)
            break;
        if (abs(mass - w) < abs(mass)){
            right[i]=1;
            mass-=w;
        }else if (abs(mass + w) < abs(mass)){
            left[i]=1;
            mass+=w;
        }
    }

    for (int i = 0; i<k; i++){
        if (left[i]){
            cout<<arr[i]<<" ";
        }
    }


    return 0;
}

1001
0101

1100
0101
1001