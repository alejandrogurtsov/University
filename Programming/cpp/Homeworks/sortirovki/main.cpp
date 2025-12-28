#include <iostream>

using namespace std;
using namespace chrono;

void InsertionSort(int *arr, int size){
    int buf;
    int i, j;
    for(i=1; i<size; i++){
        buf=arr[i];
        for(j=i-1; j>=0 && buf<arr[j]; j--)
            arr[j+1]=arr[j];
        arr[j+1]=buf;
    }
}

void HeapSort(int *arr, int size) {
    int buf;
    for (int i=size; i>1; i--) {
        int sh = 0;
        for (int j=0; j<i/2;) {
            bool flag = false;

            int largest = j, left=2*j+1, right=2*j+2;
            if (arr[left]>arr[largest]) {
                buf=arr[left];
                arr[left]=arr[largest];
                arr[largest]=buf;
                flag=true;
            }
            if (right<i && arr[right]>arr[largest]) {
                buf=arr[right];
                arr[right]=arr[largest];
                arr[largest]=buf;
                flag=true;
            }
            if (flag && j>0) {
                j=(j-1)/2;
                sh++;
            }else {
                j=j+1+sh;
                sh=0;
            }
        }
        buf=arr[i-1];
        arr[i-1]=arr[0];
        arr[0]=buf;
    }
}

int main() {
    const int N=10000;
    int* arr = new int[N];
    for (int i=0; i<N; i++) arr[i] = N-i;

    auto start = high_resolution_clock::now();
    HeapSort(arr, N);

    // for (int i=0; i<size; i++){
    //     cout<<arr[i]<<" ";
    // }

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    cout << "Время: " << duration.count() << " мс" << endl;

    delete[] arr;
    return 0;
}
