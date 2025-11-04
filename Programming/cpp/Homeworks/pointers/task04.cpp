#include <iostream>
#include <locale.h>

using namespace std;

int main(void) {
    setlocale(LC_ALL, "Rissian");
    char s[81] = {0};
    cout<<"Введите строку до 80 символов: "<<endl;
    cin.getline(s,81);

    int f1, f2, f3 = 1;
    for (char* p_arr = s; *p_arr!='\0'; p_arr++){
        if (*p_arr == '(') {
            f1 = 0;
        }else if (*p_arr == '[') {
            f2 = 0;
        }else if (*p_arr == '{') {
            f3 = 0;
        }

        if (*p_arr == ')' && f1==0){
            f1=1;
        } else if (*p_arr == ']' && f2==0) {
            f2=1;
        } else if (*p_arr == '}' && f3==0) {
            f3=1;
        }
    }

    if (f1 && f2 && f3){
        cout<<"корректно"<<endl;
    }else{
        cout<<"некорректно"<<endl;
    }

    return 0;
}
