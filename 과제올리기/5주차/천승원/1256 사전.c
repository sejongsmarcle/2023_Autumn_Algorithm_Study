#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

long fac(long f) {
	long k = 1;
	for (long i = f; i > 0; i--) {
		k = k * i;
	}
	return k;
}

long cal(long i, long j, long k) {
	return fac(i) / fac(j) / fac(k);
}

void makech(char ch[], long n, long p, long i, long j, long k) { //p, i, j, k는 반복문 돌리기 위한 변수(전역 선언하는게 더 편할듯)
	long tmp = n / (cal(i, j, k) + 1);

	while (tmp > 0) {
		n = n - cal(i, j, k);
		p++; i--; k--;
		tmp = n / (cal(i, j, k) + 1);
	}
	i--; j--;

	ch[p] = 'a';
	p++;

	if (i < 0 || j < 0|| k < 0)
		return;

	makech(ch, n, p, i, j, k);
}

int main() {

	long n, m, k;
	scanf("%ld%ld%ld", &n, &m, &k);

	char *ch = (char*)malloc(sizeof(char)*(n + m) + 1); //임시선언

	for (long i = 0; i < n + m; i++) {
		ch[i] = 'z';
	}
	ch[n + m] = '\0';

	if (k <= cal(n + m, n, m)) {
		makech(ch, k, 0, n + m - 1, n - 1, m);
		printf("%s", ch);
	}
	else {
		printf("-1");
	}

	free(ch);

	return 0;
}
