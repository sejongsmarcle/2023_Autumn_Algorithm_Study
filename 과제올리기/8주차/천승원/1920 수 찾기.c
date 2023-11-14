#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int cmp(int* a, int* b) {
	if (*a > * b)
		return 1;
	else if (*a == *b)
		return 0;
	return -1;
}

void binary_search(int* a, int x, int n) {
	int f = 0, r = n - 1, p;
	while (1) {
		p = (f + r) / 2;
		if (a[p] == x) {
			printf("1\n");
			return;
		}
		else if (a[p] > x)
			r = p - 1;
		else
			f = p + 1;

		if (f > r) {
			printf("0\n");
			return;
		}
	}
}

int main() {
	int n;
	scanf("%d", &n);
	int* a = (int*)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	int m;
	scanf("%d", &m);
	int* b = (int*)malloc(sizeof(int*) * m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &b[i]);
	}

	qsort(a, n, sizeof(int), cmp);

	for (int i = 0; i < m; i++) {
		binary_search(a, b[i], n);
	}
	return 0;
}
