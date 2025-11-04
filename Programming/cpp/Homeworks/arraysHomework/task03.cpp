#include <iostream>
#include <string>
using namespace std;

int main() {
    int arr[9000];
    int c=999;

    for (int i=0; i<9000; i++){
        c++;
        arr[i]=c;
    }

    for (int i=0; i<9000; i++){
        int f=1;
        string s = to_string(arr[i]);
        for (int g=0; g<4; g++){
            for (int k=0; k<4; k++){
                if (g==k)
                    continue;
                if (s[g]==s[k]){
                    f=0;
                    break;
                }
            }
        }
        if (f==1){
            cout<<arr[i]<<endl;
        }
    }
    return 0;
}
