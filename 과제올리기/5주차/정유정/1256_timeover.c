#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count = 1, cnt = 0;

void generateStrings(char* current, int n, int m, int nCount, int mCount, int index, int k) {
    if (cnt == 1) return;

    if (index == n + m) {
        current[index] = '\0';
        if (count == k) {
            printf("%s", current);
            cnt = 1;
            return;
        }
        count++;
    }

    if (nCount < n) {
        current[index] = 'a';
        generateStrings(current, n, m, nCount + 1, mCount, index + 1, k);
    }

    if (mCount < m) {
        current[index] = 'z';
        generateStrings(current, n, m, nCount, mCount + 1, index + 1, k);
    }
}

int main() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);

    char* current = (char*)malloc((n + m + 1) * sizeof(char));

    generateStrings(current, n, m, 0, 0, 0, k);

    if (cnt == 0) printf("-1");

    free(current);

    return 0;
}