#include <iostream>
#include <locale>
#include <fstream>
#include <string.h>

using namespace std;

const int STR_LENGHT=80;

bool readLine(ifstream& in, char* buffer);
void centerLine(char* buffer);

int main(void) {
    setlocale(LC_ALL,"RU");
    ifstream in("in.txt");
    if (!in.is_open())
    {
        cout<<"Файл in.txt не существует"<<endl;
        return -1;
    }
    ofstream out("out.txt");
    if (!out.is_open())
    {
        cout<<"Немозможно создать выходной файл out.txt"<<endl;
        return -2;
    }
    char buffer[STR_LENGHT+1];
    while (readLine(in,buffer))
    {
        centerLine(buffer);
        out<<buffer<<endl;
    }

    return 0;
}

bool readLine(ifstream& in, char* buffer){
    buffer[0] = 0;
    in.getline(buffer, STR_LENGHT+1, '\n');
    if (in.fail())
    {
        if (buffer[0]>0)
            cout<<"Слишком длинная строка во входном файле"<<endl;
        return false;
    }
    return true;
}

void centerLine(char* buffer){
    int len = strlen(buffer);
    int shift = (STR_LENGHT-len)/2;
    if (shift==0)
        return;
    for (int i=len; i>=0; i--)
        buffer[i+shift]=buffer[i];
    for (int i=0; i<shift; i++)
        buffer[i]=' ';
}