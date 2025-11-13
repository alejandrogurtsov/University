#include <iostream>
#include <locale.h>
#include <ctime>

using namespace std;

int main(void)
{
    setlocale(LC_ALL,"RU");
    int board[8][8]={0};

    //заполнили доску моентками
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
    cout<<endl;


    unsigned int ish_board=0;
    for (int bits = 0; bits < 6; bits++) {
        int count = 0;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                int cell = i * 8 + j;
                if (((cell >> bits) & 1) && (board[i][j] == 0))
                    count+=1;
            }
        }
        if (count % 2 == 1) {
            ish_board = ish_board | (1 << bits);
        }
    }

    cout<<ish_board<<endl;


    return 0;
}
