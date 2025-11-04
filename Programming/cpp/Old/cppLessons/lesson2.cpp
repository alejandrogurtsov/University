#include <iostream>
#include <locale.h>
using namespace std;

int main(void){
    char src[] = "Some string";
    char dst[20];


    const char* psrc=src;
    char* pdst=dst;
    psrc=src;
    pdst=dst;
    while (*pdst++ = *psrc++); // Пустой цикл!
    cout<<dst<<endl;
    return 0;
}