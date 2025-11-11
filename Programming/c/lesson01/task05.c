#include <stdio.h>

int m_pow(int a, int b, int n){
    int res = 1;
    a %= n;
    while(b){
        if (b%2) res = (long long)res * a % n;
        a = (long long)a * a%n;
        b /=2;
    }
    return res;
}

int s_pow(int a, int b, int n){
    if (b==1) return a % n;
    int prev = s_pow(a,b-1,n);
    return m_pow(a, prev, n);
}

int main(){
    int a,b,n;
    scanf("%d %d %d", &a, &b, &n);

    printf("%d\n", s_pow(a,b,n));

    return 0;
}