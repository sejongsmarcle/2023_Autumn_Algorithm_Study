#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned long long binomialCoeff(int n, int k) {
    if (k == 0 || k == n) {
        return 1;
    }
    unsigned long long res = 1;
    k = k < (n - k) ? k : (n - k);
    for (int i = 0; i < k; ++i) {
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}

void generateKthString(char* current, int n, int m, unsigned long long k) {
    if (n == 0 && m == 0) {
        current[0] = '\0';
        return;
    }

    if (n > 0) {
        unsigned long long possibilities = binomialCoeff(n + m - 1, n - 1);
        if (k <= possibilities) {
            current[0] = 'a';
            generateKthString(current + 1, n - 1, m, k);
            return;
        }
        else {
            current[0] = 'z';
            generateKthString(current + 1, n, m - 1, k - possibilities);
            return;
        }
    }
    else {
        current[0] = 'z';
        generateKthString(current + 1, n, m - 1, k);
        return;
    }
}

int main() {
    int n, m;
    unsigned long long k;
    scanf("%d %d %llu", &n, &m, &k);

    if (n < 1 || n > 100 || m < 1 || m > 100 || k < 1 || k > binomialCoeff(n + m, n)) {
        printf("-1");
        return 0;
    }

    char* result = (char*)malloc((n + m + 1) * sizeof(char));
    generateKthString(result, n, m, k);

    if (result[0] == '\0') {
        printf("-1");
    }
    else {
        printf("%s", result);
    }

    free(result);

    return 0;
}