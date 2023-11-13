#pragma warning (disable:4996)
#include <stdio.h>
#include <stdbool.h>
#define SIZE 10000

bool Existence[SIZE];

void insert(int num) {
	Existence[num] = 1;
}

int search(int num) {
	return Existence[num];
}

int main() {
	int n, m;
	scanf("%d", &n); 

	for (int i = 1; i < n; i++) {
		int num;
		scanf("%d", &num);
		insert(num);
	}

	scanf("%d", &m);

	for (int i = 1; i < m; i++) {
		int num;
		scanf("%d", &num);

		if (search(num)) {
			printf("1\n");
		}
		else {
			printf("0\n");
		}
	}

	return 0;
}
