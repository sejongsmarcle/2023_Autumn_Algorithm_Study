#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>


void print_median(int n, int* arr) {
	int* sorted = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) sorted[i] = arr[i];

	for (int i = 1; i < n; i++) {
		int tmp = sorted[i];
		int j = i - 1;

		while (j >= 0 && sorted[j] > tmp) {
			sorted[j + 1] = sorted[j];
			j--;
		}

		sorted[j + 1] = tmp;
	}

	printf("%d ", sorted[n / 2]);

	free(sorted);
}


int main() {

	int T;

	scanf("%d", &T);

	for (int i = 0; i < T; i++) {
		int M;
		scanf("%d", &M);
		int* arr = (int*)malloc(sizeof(int) * M); 


		printf("%d\n", (M + 1) / 2);
	

		for (int j = 0; j < M; j++) {
			scanf("%d", &arr[j]);
			if ((j+1) % 2 == 1) {
				print_median(j+1,arr);
			}
		}
		printf("\n");
		

		free(arr);
	}
	return 0;
}


/*
3
9
1 2 3 4 5 6 7 8 9
9
9 8 7 6 5 4 3 2 1
23
23 41 13 22 -3 24 -31 -11 -8 -7 3 5 103 211 -311 -45 -67 -73 -81 -99 -33 24 56
*/