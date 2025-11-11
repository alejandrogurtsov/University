#include <stdio.h>

int main(){
    int ch, zn;
    scanf("%d %d", &ch, &zn);

    if (zn<0){
        ch = -ch;
        zn = -zn;
    }

    while (zn != 0){
        int q, r;

        if ((ch >= 0) || (ch % zn == 0)) {
            q = ch / zn;
            r = ch % zn;
        } else {
            q = ch / zn - 1;
            r = ch - q * zn;
        }

        printf("%d", q);
        printf(" ");

        ch = zn;
        zn=r;

    }

    return 0;
}