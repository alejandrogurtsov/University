#include <iostream>
#include <locale.h>
#include <fstream>
#include <cmath>

using namespace std;

bool prime(long long n);

void read(ifstream &in, long long g_idx);

int main(void) {
    setlocale(LC_ALL,"RU");

    char str[11] = {};
    int str_idx=0;
    long long g_idx=0;

    ifstream in("e2mil.txt");
    if (!in.is_open()){
        cout<<"Не удалось прочитать из файла"<<endl;
    }else{
        read(in,0);
    }
    in.close();

//    for (int i = 0; i<11; i++){
//        cout<<str[i]<<" ";
//    }
//    cout<<endl;

//    long long number = 0;
//    for(int i = 0; i<10; i++) {
//        number = number * 10 + (str[i] - '0');
//    }
//    cout<<number<<endl;

    return 0;
}

void read(ifstream &in, long long g_idx){
    in.seekg(g_idx);
}

bool prime(long long n){
    bool f = true;
    for (long long i = 2; i<(int)sqrt(n)+1; i++){
        if (n%i==0){
            f = false;
            break;
        }
    }
    return f;
}