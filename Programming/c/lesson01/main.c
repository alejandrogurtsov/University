#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

unsigned long long gcd(long long x, long long y) {
    unsigned long long a = (x<0) ? -x : x;
    unsigned long long b = (y<0) ? -y : y;
    unsigned long long q;

    while (b!=0){
        q = a % b;
        a = b;
        b = q;
    }

    return a;
}

int main() {
    unsigned long long x = 0, y = 0, g;
    int res;

    res = scanf("%lld %lld", &x, &y);
    assert(res == 2);
    g = gcd(x, y);
    printf("%llu\n", g);
    return 0;
}