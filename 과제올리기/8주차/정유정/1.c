#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define maxsize 100019

int h(int k) {
	return (k % maxsize + maxsize) % maxsize;
}

int main() {

	int N, n, M;
	scanf("%d", &N);
	bool* A = (bool*)calloc(maxsize, sizeof(bool));

	for (int i = 0; i < N; i++) {
		scanf("%d", &n);
		n = h(n);
		A[n] = true;
	}

	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		scanf("%d", &n);
		n = h(n);
		printf("%d\n", A[n] ? 1 : 0);
	}

	free(A);

	return 0;
}