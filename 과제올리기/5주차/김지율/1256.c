#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define INF 0x3f3f3f3f3f3f3f3f

int cnt;
char* dic;

long long factorial(int N) {
    if (N == 1 || N == 0) return 1;
    long long fac = N * factorial(N - 1);
    if (fac > 1000000000) fac = INF;
    return fac;
}

long long combination(int N, int M) {
    long long com = factorial(N + M) / (factorial(N) * factorial(M));
    if (com > 1000000000) com = INF;
    return com;
}

void aorz(int N, int M, long long K, int i) {

    long long comb;

    if (i == cnt) return;

    if (N <= 1 && M != 1)
        comb = M - 1;
    else if (N != 1 && M <= 1)
        comb = N - 1;
    else if (N == 1 && M == 1)
        comb = 1;
    else
        comb = combination(N - 1, M);

    if (comb >= K) {
        dic[i] = 'a';
        N--;
    }
    else {
        dic[i] = 'z';
        M--;
        K -= comb;
    }

    aorz(N, M, K, i + 1);
}

int main() {

    int N, M, i = 0;
    long long K;

    scanf("%d %d %lld", &N, &M, &K);

    if (K > 1000000000) return 0;

    cnt = N + M;

    if (K > combination(N, M)) {
        printf("-1");
        return 0;
    }

    dic = (char*)malloc((cnt + 1) * sizeof(char));

    aorz(N, M, K, i);

    for (int j = 0; j < cnt; j++)
        printf("%c", dic[j]);

    free(dic);

    return 0;
}