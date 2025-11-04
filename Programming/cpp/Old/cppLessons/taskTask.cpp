#include <iostream>
#include <locale.h>
#include <string.h>
#include <cmath>
using namespace std;

int main(void){
    setlocale(LC_ALL,"Russian");
    int p;
    do{
        cout<<"Введите основание системы p (2-36): "<<endl;
        cin>>p;
    } while (p<2 || p>36);
    const int MAX_LEN = 30;

    char x[MAX_LEN+1];
    cout<<"Введите число (не более "<<MAX_LEN<<" разрядов): ";
    cin.getline(x,1,'\n'); // перевод строки
    cin.getline(x, MAX_LEN+1,'\n');

    int n=0;

    for (int i=0; x[i]!=0; i++){
        n*=p;

        int d=-1;
        if (x[i]>='0' && x[i]<='9')
            d=x[i]-'0';
        else if (x[i]>='a' && x[i]<='z')
            d=10+x[i]-'a';
        else if (x[i]>='A' && x[i]<='Z')
            d=10+x[i]-'A';
        if (d<0 || d>=p){
            cout<<"Цифра "<<x[i]<<" некорректна"<<endl;
            return 0;
        }

        n+=d;
    }
    cout<<"Число в десятичной системе счисления: "<<n<<endl;


    int n_max= MAX_LEN *log10(35.0) + 2;
    char* n_10 = new char[n_max];
    n_10[0]='0';
    n_10[1]='\0';

    for (char* p_x = x; *p_x != '\0'; p_x++) {
        int d;

        if (*p_x >= '0' && *p_x <= '9')
            d = *p_x - '0';
        else if (*p_x >= 'a' && *p_x <= 'z')
            d = 10 + (*p_x - 'a');
        else if (*p_x >= 'A' && *p_x <= 'Z')
            d = 10 + (*p_x - 'A');
        if (d < 0 || d >= p) {
            cout << "Цифра " << *p_x << " некорректна" << endl;
            delete[] n_10;
            return 0;
        }

        int carry = 0; // для переноса старшего разряда
        int len = strlen(n_10);
        for (int i = len-1; i>=0; i--){
            int temp = (n_10[i]-'0')*p + carry;
            n_10[i] = (temp % 10) + '0';
            carry = temp / 10;
        }
        while (carry>0){
            for (int i = strlen(n_10); i >= 0; i--)
                n_10[i+1] = n_10[i];
            n_10[0] = (carry % 10) + '0';
            carry /= 10;
        }

        carry = d;
        for (int i = strlen(n_10)-1; i>=0 && carry>0; i--){
            int temp = (n_10[i] - '0') + carry;
            n_10[i] = (temp % 10) + '0';
            carry = temp / 10;
        }
        while (carry > 0){
            for (int i = strlen(n_10); i>=0; i--)
                n_10[i+1] = n_10[i];
            n_10[0]=(carry%10)+'0';
            carry /=10;
        }
    }
    cout<<"Число в десятичной системе счисления: "<<n_10<<endl;

    delete[] n_10;
    return 0;
}