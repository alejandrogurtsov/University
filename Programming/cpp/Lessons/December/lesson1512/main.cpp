#include <iostream>
#include <locale.h>
using namespace std;

void QuickSort (int *arr, int first, int last);
int Mediana (int *arr, int first, int last, int arr_size);

//найти медиану массива взяв за основу алгоритм QuickSort не сортируя весь
int main() {
    setlocale(LC_ALL, "RU");
    const int size = 8;
    int arr[size] = {9,2,4,1,7,3,6,8};
    int med = Mediana(arr, 0, 8, size);

    cout<<med<<" - медиана"<<endl;
    for (int i = 0; i < 8; i++) {
        cout << arr[i] << " ";
    }
    cout<<" - массив не отсортирован"<<endl;

    QuickSort(arr, 0, 8);
    for (int i = 0; i < 8; i++) {
        cout << arr[i] << " ";
    }
    cout<<" - массив отсортирован"<<endl;

    return 0;
}

int Mediana (int *arr, int first, int last, int arr_size) {
    int idx = (arr_size / 2)-1; //индекс медианы

    while (first <= last) { //чтобы не создавать рекурсию
        int i = first, j = last;
        int buf, comp;
        comp = arr[(first + last) / 2];
        do {
            while (arr[i] < comp && i < last)
                i++;
            while (arr[j] > comp &&  j > first)
                j--;
            if (i <= j) {
                if (arr[i] > arr[j]){
                    buf=arr[i];
                    arr[i]=arr[j];
                    arr[j]=buf;
                }
                i++; j--;
                for (int i = 0; i < 8; i++) {
                    cout << arr[i] << " ";
                }
                cout<<endl;
            }
        }while (i <= j);
        if (idx <= j) {
            last=j;// медиана левее
        } else if (idx >= i) {
            first=i;// медиана правее
        }else {
            return arr[idx];//сама медиана
        }
    }
}

void QuickSort (int *arr, int first, int last) {
    int i = first, j = last;
    int buf, comp;
    comp = arr[(first + last) / 2];
    do {
        while (arr[i] < comp && i < last)
            i++;
        while (arr[j] > comp &&  j > first)
            j--;
        if (i <= j) {
            if (arr[i] > arr[j]){
                buf=arr[i];
                arr[i]=arr[j];
                arr[j]=buf;
            }
            i++; j--;
        }
    }while (i <= j);
    if (first < j)
        QuickSort(arr, first, j);
    if (i < last)
        QuickSort(arr, i, last);
}