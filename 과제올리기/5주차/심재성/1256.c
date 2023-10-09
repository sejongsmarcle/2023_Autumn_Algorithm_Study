#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long nCr(int n, int r);
void append(char *str, int n, int m, long long k);

int main() {
	int N, M;
	long long K;


	scanf("%d %d %lld", &N, &M, &K);

	char *result = (char *)malloc((N + M + 1) * sizeof(char));

	// K가 범위를 넘어서면 -1 출력하고 종료
	if (K < 1 || K > nCr(N + M, N)) {
		printf("-1\n");
		free(result);
		return 0;
	}

	append(result, N, M, K);

	printf("%s\n", result);

	free(result); 

	return 0;
}

//nCr = n! / (r! * (n - r)!) 
long long nCr(int n, int r) {
	long long result = 1;
	for (int i = 1; i <= r; i++) {
		result *= n - i + 1; //팩토리얼 구현
		result /= i; // 팩토리얼 구현
	}
	return result;
}

void append(char *str, int n, int m, long long k) {
	int cnt_a = n;
	int cnt_z = m;

	for (int i = 0; i < n + m; i++) {
		//a가 아직 존재하면 조합의 수를 반환하고 a가 없다면 0을 반환해서 z가 입력될 수 있게끔한다.
		long long comb = (cnt_a > 0) ? nCr(cnt_a + cnt_z - 1, cnt_a - 1) : 0; 

		if (k <= comb) { // k가 조합의 수 즉 a를 기준으로 a가 찍힐 수 있는 조합의 수가 나오면 a를 넣고
			str[i] = 'a';
			cnt_a--;
		}
		else { // k가 a가 나올 수 있는 조합의 수를 넘겼다면 z를 넣는다
			str[i] = 'z';
			cnt_z--;
			k -= comb;
		}
	}

	str[n + m] = '\0'; // 쓰레기값이 떠서 NULL값 추가
}
