#include <iostream>
#include <locale.h>
#include <ctime>

using namespace std;

int main(void)
{
    setlocale(LC_ALL,"RU");
    srand(time(NULL));

    int board[8][8]={0};

    //заполнили доску монетками
    for (int i = 0; i<8; i++){
        for (int j = 0; j<8; j++){
            board[i][j] = rand() % 2;
        }
    }

    for (int i = 0; i<8; i++){
        for (int j = 0; j<8; j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }

    //четность исходной доски
    int ish_board=0;
    for (int bits = 0; bits < 6; bits++) {
        int count = 0;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                int cell = i * 8 + j;
                if (((cell >> bits) & 1) && (board[i][j] == 1))
                    count+=1;
            }
        }
        if (count % 2 == 1) {
            ish_board = ish_board | (1 << bits);
        }
    }

    for(int i=5; i>=0; i--){
        int bit = (ish_board >> i) & 1;
        cout<<bit;
    }
    cout<<" - четность исходной доски"<<endl;

    //тролль выбирает монету
    int tr_row, tr_col = 0;
    cout<<"Введите номер загаданной монеты в формате - строка колонка (нумерация с 0):"<<endl;
    cin>>tr_row>>tr_col;
    int tr_cell = tr_row * 8 + tr_col;

//xor-им исходную четность доски и загаданную троллем монету => получаем номер монеты которую перевернёт 1-ый программист
    int cell_num = tr_cell ^ ish_board;

//первый программист переворачивает монету
    board[cell_num/8][cell_num%8] ^= 1;

//второй программист находит четность новой доски что и является номером загаданной монеты
    int isk_moneta=0;
    for (int bits = 0; bits < 6; bits++) {
        int count = 0;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                int cell = i * 8 + j;
                if (((cell >> bits) & 1) && (board[i][j] == 1))
                    count+=1;
            }
        }
        if (count % 2 == 1) {
            isk_moneta = isk_moneta | (1 << bits);
        }
    }

    for(int i=5; i>=0; i--){
        int bit = (isk_moneta >> i) & 1;
        cout<<bit;
    }
    cout<<" - номер загаданной монеты"<<endl;

    return 0;
}
