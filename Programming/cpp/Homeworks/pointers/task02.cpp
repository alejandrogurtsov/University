#include <iostream>
#include <locale.h>
#include <string.h>
using namespace std;

int main(void){
    setlocale(LC_ALL,"Russian");
    char A[81] = {0};
    char B[81] = {0};

    cout<<"Введите строку длинной до 80 символов: "<<endl;
    cin.getline(A,81);

    char* p_arr = A;
    char* p_end = A;

    while (*p_end != '\0') {
        p_end++;    //перемещаюсь в конец строки
    }
    p_end--;

    while(p_end >= A && *p_end == ' ')
        p_end--;    //пропускаю пробелы в конце строки

    while (*p_arr==' ') // пропускаю пробелы в начале строки
        p_arr++;

    bool prev_space = false;

    char* p_arr_b = B;

    while (*p_arr != '\0' && p_arr<=p_end){ //иду до конца строки A
        if (*p_arr == ' '){
            if (!prev_space){ //условие на пробел, если это первый, то
                *p_arr_b =' '; //в строку B записываем пробел
                p_arr_b++;
                prev_space=true;
            }
        }else{
            *p_arr_b = *p_arr; //копируем в строку В символ из строки А
            p_arr_b++;
            prev_space = false;
        }
        p_arr++;
    }
    *p_arr_b = '\0';

    cout<<"Исходная строка А: \""<<A<<"\""<<endl;
    cout << "Результат копирования в строку B: \""<< B <<"\"" << endl;

    return 0;
}