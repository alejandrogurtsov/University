#include <iostream>
#include <locale.h>

using namespace std;

int main(void) {
    setlocale(LC_ALL,"Russian");
    char a[15]={};
    int idx[9] = {9,8,7,6,5,4,3,2,1};
    cout<<"Введите снилс: ";
    cin.getline(a, 15);

    int ks = 0;

    for (char* p_arr = a; *p_arr!='\0'; p_arr++){
        if (*p_arr == ' '){
            ks = ((*(p_arr + 1) - '0')*10)+(*(p_arr + 2) - '0');
        }
    }

    int s = 0;
    int j = 0;
    for (char* p_arr = a; *p_arr != ' '; p_arr++){
        if (*p_arr >='0' && *p_arr <= '9'){
            s += (*p_arr-'0') * idx[j];
            j++;
        }
    }

    if ( (s % 101 == ks)){
        cout<<"Контрольное число "<<s<<" указано верно.";
    } else{
        cout<<"Контрольное число неверно"<<endl;
    }


    return 0;
}
