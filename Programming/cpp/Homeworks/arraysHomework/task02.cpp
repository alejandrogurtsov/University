#include <iostream>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main(void) {
    setlocale(LC_ALL, "Russian");
    int n;
    cout << "Введите n - размер массива(число целое и неотрицательное)" << endl;
    cin >> n;
    int A[n*(n-1)];
    int B[n][n];

//Заполнил нулями массив В
    for (int i=0; i<n;i++){
        for (int j=0; j<n; j++){
            B[i][j]=0;
        }
    }

//Заполнил случайными числами массив А
    srand(time(0));
    for (int i = 0; i<(n*(n-1)); i++){
        A[i]=rand()%100;
    }

//Отсортировал массив А по возрастанию
    for(int j=0; j<(n*(n-1))-1; j++) {
        for (int i = 0; i < (n * (n - 1) - 1); i++) {
            if (A[i] > A[i + 1]) {
                int c = A[i];
                A[i] = A[i + 1];
                A[i + 1] = c;
            }
        }
    }

//Заполняю массив В по спирали (так как массив А размером n*n-1, а
//массив В размером n*n, первую строку не заполняю(оставляю нули))
    int chislo=0;
    int top = 1, bottom = n-1, left = 0, right = n-1;

    while(top<=bottom && left<=right){
        for(int i=top; i<=bottom && chislo<(n*(n-1)); i++){
            B[i][right]=A[chislo++];
        }
        right--;
        for(int j=right; j>=left && chislo<(n*(n-1)); j--){
            B[bottom][j]=A[chislo++];
        }
        bottom--;
        for(int i=bottom; i>=top && chislo<(n*(n-1)); i--){
            B[i][left]=A[chislo++];
        }
        left++;
        for (int j=left; j<=right && chislo<(n*(n-1)); j++){
            B[top][j]=A[chislo++];
        }
        top++;
    }

    cout<<"Отсортированный массив А:"<<endl;
    for (int i=0; i<(n*(n-1)); i++){
        cout<<A[i]<<" ";
    }
    cout<<endl<<endl;

    cout<<"Массив В:"<<endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << B[i][j] << "\t";
        }
        cout << "\n";
    }

    return 0;
}