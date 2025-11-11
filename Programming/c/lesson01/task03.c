#include <stdio.h>

int main() {
    int x;
    scanf("%d", &x);

    if (x==1){
        printf("1");
        return 0;
    }

    int fib[50];
    int n = 2;

    fib[0] = 1;
    fib[1] = 2;

    while (1) {
        long long next = (long long)fib[n-1] + fib[n-2];
        if (next > x) break;
        fib[n] = (int)next;
        n++;
    }

    int i = n;

    int a[50];
    for (int j = i-1; j>=0; j--){
        if (x-fib[j] >= 0){
            x-=fib[j];
            a[j]=1;
        }else{
            a[j]=0;
        }
    }

    for (int j = i-1; j>=0; j--){
        printf("%d", a[j]);
    }

    return 0;
}