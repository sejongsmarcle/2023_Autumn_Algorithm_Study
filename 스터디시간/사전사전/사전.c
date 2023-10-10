#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

unsigned long long binomialCoeff(int n, int k) {
	if (k == 0 || k == n) {
		return 1;
	}
	unsigned long long res = 1;
	k = k < (n - k) ? k : (n - k);
	for (int i = 0; i < k; ++i) {
		res *= (n - i);
		res /= (i + 1);
	}
	return res;
}

void makech(char ch[], int n, int p, int i, int j, int k) { //p, i, j, k는 반복문 돌리기 위한 변수(전역 선언하는게 더 편할듯)
	unsigned long long tmp = n / (binomialCoeff(i, j) + 1);

	while (tmp > 0) {
		n = n - binomialCoeff(i, j);
		p++; i--; k--;
		tmp = n / (binomialCoeff(i, j) + 1);
	}
	i--; j--;

	ch[p] = 'a';
	p++;

	if (i < 0 || j < 0|| k < 0)
		return;

	makech(ch, n, p, i, j, k);
}

int main() {

	int n, m;
	unsigned long long k;
	scanf("%d%d%llu", &n, &m, &k);

	char *ch = (char*)malloc(sizeof(char)*(n + m) + 1); //임시선언

	for (long long i = 0; i < n + m; i++) {
		ch[i] = 'z';
	}
	ch[n + m] = '\0';

	if (k <= binomialCoeff(n + m, n)) {
		makech(ch, k, 0, n + m - 1, n - 1, m);
		printf("%s", ch);
	}
	else {
		printf("-1");
	}

	free(ch);

	return 0;
}
