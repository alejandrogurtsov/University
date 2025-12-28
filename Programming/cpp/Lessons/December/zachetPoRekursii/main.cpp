#include <iostream>
#include <locale.h>
#include <cstdlib>
#include <ctime>

using namespace std;

int recSquare(int** arr, int i, int j);
int min(int a, int b);
int max(int a, int b);

int n;
int main() {
    setlocale(LC_ALL, "RU");
    cout<<"Введите размер матрицы: "<<endl;
    cin>>n;

    int** arr = new int* [n];

    for (int i = 0; i < n; i++) {
        arr[i] = new int[n];
    }

    srand(time(0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            arr[i][j] = rand() % 2;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    int maxSquare = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            maxSquare = max(maxSquare, recSquare(arr, i, j));
        }
    }
    cout << "Самый большой квадрат из нулей размером: " << maxSquare<<"x"<<maxSquare<< endl;

    delete[] arr;
    return 0;
}

int recSquare(int** arr, int i, int j) {
    if (i >= n || j >= n) return 0;

    if (arr[i][j] == 1) return 0;

    int down = recSquare(arr, i+1, j);
    int right = recSquare(arr, i, j+1);
    int diag = recSquare(arr, i+1, j+1);

    return 1 + min(down, min(right, diag));
}

int min(int a, int b) {
    if (a < b) {
        return a;
    } else {
        return b;
    }
}

int max(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}