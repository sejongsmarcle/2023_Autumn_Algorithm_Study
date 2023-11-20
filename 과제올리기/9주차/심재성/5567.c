#pragma warning(disable:4996)
#include <stdio.h>



int martrix[501][501];  

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	
	int a, b;
	int invite_cnt = 0;

	int check[501] = { 0 };

	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		martrix[a][b] = 1;
		martrix[b][a] = 1;
	}

	for (int i = 2; i <= n; i++) {
		if (martrix[1][i] == 1) {
			check[i] = 1;
			for (int j = 2; j <= n; j++) {
				if (martrix[j][i] == 1) {
					check[j] = 1;
				}
			}
		}
	}

	for (int i = 2; i <= n; i++) {
		invite_cnt += check[i];
	}

	printf("%d\n", invite_cnt);

	return 0;
}
