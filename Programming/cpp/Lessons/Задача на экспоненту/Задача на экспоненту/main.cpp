#include <iostream>
#include <locale.h>
#include <fstream>

using namespace std;

int main(void) {
    setlocale(LC_ALL,"RU");

    char str[11] = {};
    for (int i = 0; i<11; i++){
        cout<<str[i]<<" ";
    }
    cout<<endl;

    ifstream in("e2mil.txt");
    if (!in.is_open()){
        cout<<"Не удалось прочитать из файла"<<endl;
    }else{
        in.getline(str,11);
    }
    in.close();

    for (int i = 0; i<11; i++){
        cout<<str[i]<<" ";
    }
    cout<<endl;

    return 0;
}
