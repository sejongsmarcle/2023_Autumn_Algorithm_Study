#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 201

long long dp[MAX][MAX]; // 자료형 크기 때문에 long long 사용

void generate() {
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            if (j == 0 || i == j) {
                dp[i][j] = 1;
            }
            else {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j]; // MAX 값 만큼의 
            }
        }
    }
}

void find_result(int N, int M, long long K) {
    int length = N + M;
    int num_a = N;
    int num_z = M;
    char result[MAX] = { 0 };
    int index = 0;

    for (int i = 0; i < length; i++) {
        if (num_a == 0) {
            result[index++] = 'z';
            num_z--;
        }
        else if (num_z == 0) {
            result[index++] = 'a';
            num_a--;
        }
        else {
            long long count = dp[num_a + num_z - 1][num_a - 1];
            printf("count = %d %lld\n",i, count);
            if (count >= K) {
                result[index++] = 'a';
                num_a--;
            }
            else {
                result[index++] = 'z';
                K -= count;
                num_z--;
            }
        }
    }

    if (K > 1) {
        printf("-1\n");
    }
    else {
        printf("%s\n", result);
    }
}

int main() {
    int N, M;
    long long K;

    scanf("%d %d %lld", &N, &M, &K);

    generate();
    find_result(N, M, K);

    return 0;
}
