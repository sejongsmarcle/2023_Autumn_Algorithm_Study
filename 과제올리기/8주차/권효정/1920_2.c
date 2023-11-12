#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning (disable:4996)

int compare(int* a, int* b) {
	return (*a - *b);
}

/*int compare(void * x, void* y) {
	int a = *(int*)x;
	int b = *(int*)y;

	if (a > b) return 1;
	else if (a < b) return -1;
	else return 0;
}*/

int binarySearch(int a[], int low, int high, int key) {
	if (low > high) {
		return 0;
	}

	int mid = low + (high - low) / 2;

	//printf("///%d\n", mid);

	if (a[mid] == key) {
		return 1;
	}
	else if (a[mid] > key) {
		return binarySearch(a, low, mid - 1, key);
	}
	else {
		return binarySearch(a, mid + 1, high, key);
	}
}

int main() {
	int N, M, * A, num;
	scanf("%d", &N);

	A = (int*)malloc(sizeof(int) * N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}

	qsort(A, N, sizeof(int), compare);

	scanf("%d", &M);

	for (int i = 0; i < M; i++) {
		scanf("%d", &num);

		printf("%d\n",binarySearch(A, 0, N, num));
	}

}