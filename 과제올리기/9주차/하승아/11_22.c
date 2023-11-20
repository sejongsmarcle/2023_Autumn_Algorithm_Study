#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)


int sum(int n) {
	int i;
	int cnt = 0;
	for (i = 1; i <= n; i++) {
		if (adj[i][1] == 1) {
			cnnt[i] = 1;
			//printf("adj[%d][1]  cnt : %d\n", i, cnt);
			for (int j = 2; j <= n; j++) {
				if (adj[i][j] == 1)
					cnnt[j] = 1;
			}
		}
	}

	for (i = 0; i <= n; i++) cnt += cnnt[i];
	return (cnt);
}


int main() {
	int a, b;
	int n, m;
	int i;


	int** adj;
	int* cnnt;

	scanf("%d", &n);

	adj = (int**)calloc(N + 1, sizeof(int*));
	int i;
	for (i = 0; i <= N; i++) {
		adj[i] = (int*)calloc(N + 1, sizeof(int));
	}
	cnnt = (int*)calloc(n + 1, sizeof(int));


	scanf("%d", &m);

	for (i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		adj[a][b] = 1;
		adj[b][a] = 1;
	}

	int cnt = 0;

	for (i = 1; i <= n; i++) {
		if (adj[i][1] == 1) {
			cnnt[i] = 1;
			//printf("adj[%d][1]  cnt : %d\n", i, cnt);
			for (int j = 2; j <= n; j++) {
				if (adj[i][j] == 1)
					cnnt[j] = 1;
			}
		}
	}

	for (i = 0; i <= n; i++) cnt += cnnt[i];

	printf("%d", cnt);

	return 0;
}