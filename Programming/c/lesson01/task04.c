#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
    unsigned int x;
    unsigned int y;
    unsigned int a[32];
    int i=0;

    scanf("%u", &x);
    scanf("%u", &y);

    unsigned int tmp = x;

    while (tmp>0){
        a[i] = tmp % y;
        tmp /= y;
        i++;
    }

    for (int j=i-1; j>=0; j--){
        printf("%d", a[j]);
    }
    printf("\n");

    return 0;
}