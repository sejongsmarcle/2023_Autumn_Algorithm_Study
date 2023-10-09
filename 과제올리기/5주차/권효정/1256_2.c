#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning(disable:4996)

char result[201]; //문자열 result 생성

long long binomialCoeff(int n, int k) { // 이항 계수를 계산하는 함수
    if (k == 0 || k == n) //k가 0이거나 n과 같으면
    {
        return 1; //1을 return한다
    }
    return binomialCoeff(n - 1, k - 1) + binomialCoeff(n - 1, k);
}

void find(int N, int M, long long K) { // K번째 문자열을 찾는 함수
    int index = 0;
    if (K > binomialCoeff(N + M, N)) {
        printf("-1"); // K가 가능한 문자열의 수보다 크면 -1 출력
        return;
    }

    while (N > 0 && M > 0) { //N과 M이 모두 0보다 클 때
        long long combination = binomialCoeff(N + M - 1, N - 1);

        if (K <= combination) {
            result[index++] = 'a'; //문자열에 a 대입
            N--; //N값 1 감소
        }
        else {
            result[index++] = 'z'; //문자열에 z 대입
            M--; //M값 1 감소
            K -= combination; //K에 (K - combination) 값 대입
        }
    }

    while (N > 0) { //N이 0보다 클 때
        result[index++] = 'a'; //문자열에 a 대입
        N--; //N값 1 감소
    }

    while (M > 0) { //M이 0보다 클 때
        result[index++] = 'z'; //문자열에 z 대입
        M--; //M값 1 감소
    }

    result[index] = '\0'; //NULL값 대입
    printf("%s\n", result); //문자열 출력
}

int main() {
    int N, M;
    long long K;

    scanf("%d %d %lld", &N, &M, &K);

    find(N, M, K);

    return 0;
}
