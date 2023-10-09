#include<stdio.h>
#include<string.h>

int factorial(int n) {
    if (n == 0)
        return 1;
    else
        return n * factorial(n - 1);
}



int main() {
    int N;
    int M;
    int k;
    scanf("%d %d %d", &N, &M, &k);
    float c = 0;
    int max = factorial(N + M) / (factorial(N) * factorial(M));
    int num_a = 0;
    float o;
    while (k - 1 - c >= 0) {
        o = c;
        c = factorial(M + num_a) * 1.0 / (factorial(num_a) * factorial(M) * 1.0);
        num_a++;
    }
    num_a--;
    printf("o=%d\n", (int)o);
    printf("num_a = %d", num_a);

    char dc[200];
    if (k > max) {
        printf("-1");
        return 0;
    }
    for (int i = num_a; i < N; i++) {
        prinf('a');
    }
    int l = k - (int)o;
    int i=0;
    for (int j = 0; j < k; j++) {
        i = i + 1;
        if (i % M == 1&&j!=0)i--;
        if (j == 3)i--;
    }
    int* arr;
    arr = (int*)malloc(sizeof(int) * (l+1));

    if (k > M + 2) {
        array_str(k,o,M,num_a);
    }

    for (int i = 1; i <= l; i++) {
        if(i%M==0) arr[i]='z'
       
    }
    return 0;
}