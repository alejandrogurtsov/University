#include <iostream>
#include <locale.h>

using namespace std;

int main(void) {
    setlocale(LC_ALL, "Russian");
    int k=0;

    for (int i = 1; i<=1e7; i++){
        int k_bin1 = 0;
        int k_oct1 = 0;

        for (int j = 31; j>=0; j--){
            unsigned int bit = (i >> j) & 1;
            if (bit==1)
                k_bin1++;
        }

        int temp = i;
        while (temp>0){
            if (temp % 8 == 1)
                k_oct1++;
            temp /= 8;
        }

        if (k_bin1 == k_oct1){
            k++;
        }

    }
    cout<<k<<endl;

    return 0;
}