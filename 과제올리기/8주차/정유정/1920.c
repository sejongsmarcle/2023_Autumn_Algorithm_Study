#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int h(int x, int N) {
	return x % N;
}

void insertItem(int* A, int k, int N) {
	int v = h(k, N);
	while (A[v] != 0) {
		v = (v + 1) % N;
	}
	A[v] = k;
}

int findElement(int* A, int k, int N) {
	int v = h(k, N);
	int original_v = v;
	while (A[v] != 0) {
		if (A[v] == k) {
			return 1;
		}
		v = (v + 1) % N;
		if (v == original_v) {
			break;
		}
	}
	return 0;
}

int main() {

	int N, n, M;
	scanf("%d", &N);
	int* A = (int*)malloc((N + 1) * sizeof(int));
	for (int i = 0; i <= N; i++)
		A[i] = 0;


	for (int i = 0; i < N; i++) {
		scanf("%d", &n);
		insertItem(A, n, N);
	}

	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		scanf("%d", &n);
		printf("%d\n", findElement(A, n, N));
	}

	free(A);

	return 0;
}