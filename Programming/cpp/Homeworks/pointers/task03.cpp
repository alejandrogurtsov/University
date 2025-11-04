#include <iostream>
#include <locale.h>

using namespace std;

int main(void){
    setlocale(LC_ALL,"Russian");
    char a[81] = {0};
    int b[10]={0};

    cout<<"Введите строку длинной до 80 символов: "<<endl;
    cin.getline(a,81);

    int k = 0;
    int mx_k = 0;
    int n_mx = 0;

    for(char* p_arr = a; *p_arr != '\0'; p_arr++){
        if (*p_arr>='0' && *p_arr<='9'){
            b[*p_arr-'0']++;
            k++;
        }
    }

    if (k==0) {
        cout<<"В введенной строке нет цифр"<<endl;
        return 0;

    }else if (k>0) {
        for (int* p = b; p < b+10; p++)
            if (*p > mx_k) {
                mx_k = *p;
                n_mx = p-b;
            }
    }

    cout<<"Цифра "<<n_mx<< " встречается чаще всего";

    return 0;
}