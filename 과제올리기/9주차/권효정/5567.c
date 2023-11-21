#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable:4996)

int main() {
	int n, m, a, b, cnt = 0;
	int *f;
	scanf("%d", &n);
	scanf("%d", &m);

	f = (int*)malloc(sizeof(int) * (n + 1));

	for (int i = 1; i <= n; i++) {
		f[i] = 0;
	}
	f[1] = 1;

	for (int i = 1; i <= m; i++) {
		scanf("%d %d", &a, &b);
		if (a == 1 || f[a] == 1) {
			f[b] = 2;
		}
		if (b == 1 || f[b] == 1) {
			f[a] = 2;
		}
		if (f[a] == 2) {
			f[b] = 3;
		}
		if (f[b] == 2) {
			f[a] = 3;
		}
	}

	for (int i = 2; i <= n; i++) {
		if (f[i] > 0) {
			cnt++;
		}
	}

	printf("%d", cnt);

}