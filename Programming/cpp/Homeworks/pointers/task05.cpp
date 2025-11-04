#include <iostream>
#include <locale.h>

using namespace std;

int main(void) {
    setlocale(LC_ALL, "Rissian");
    char s[81] = {0};
    cout<<"Введите строку до 80 символов: "<<endl;
    cin.getline(s,81);



    return 0;
}