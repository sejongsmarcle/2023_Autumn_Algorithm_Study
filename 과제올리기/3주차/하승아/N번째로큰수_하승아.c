#include<stdio.h>
#include<stdlib.h>

void down(int id, int n, int* arr);

int main() {

	int arr[1500 * 2];
	int n;

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		arr[i] = 0;
	}

	for (int j = 0; j < n; j++) {
		for (int i = 1; i <= n; i++) {
			scanf("%d", &arr[n + i]);
		}
		/*
		for (int i = 0; i < n*2; i++) {
			printf(" %d", arr[i]);
		}printf("\n");*/

		down(0, 2 * n, arr);
		/*
		for (int i = 0; i < n * 2; i++) {
			printf(" %d", arr[i]);
		}printf("\n");*/
	}

	printf("%d", arr[n - 1]);

	return 0;
}

void down(int id, int n, int* arr) {
	int i, max, max_id;
	if (id == n)return;
	max = arr[id];
	for (i = id; i < n; i++) {
		if (arr[i] >= max) {
			max = arr[i];
			max_id = i;
		}
	}
	int tmp = arr[id];
	arr[id] = arr[max_id];
	arr[max_id] = tmp;

	down(id + 1, n, arr);
}