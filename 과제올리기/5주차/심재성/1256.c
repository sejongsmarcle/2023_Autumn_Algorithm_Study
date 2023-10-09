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

	// K�� ������ �Ѿ�� -1 ����ϰ� ����
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
		result *= n - i + 1; //���丮�� ����
		result /= i; // ���丮�� ����
	}
	return result;
}

void append(char *str, int n, int m, long long k) {
	int cnt_a = n;
	int cnt_z = m;

	for (int i = 0; i < n + m; i++) {
		//a�� ���� �����ϸ� ������ ���� ��ȯ�ϰ� a�� ���ٸ� 0�� ��ȯ�ؼ� z�� �Էµ� �� �ְԲ��Ѵ�.
		long long comb = (cnt_a > 0) ? nCr(cnt_a + cnt_z - 1, cnt_a - 1) : 0; 

		if (k <= comb) { // k�� ������ �� �� a�� �������� a�� ���� �� �ִ� ������ ���� ������ a�� �ְ�
			str[i] = 'a';
			cnt_a--;
		}
		else { // k�� a�� ���� �� �ִ� ������ ���� �Ѱ�ٸ� z�� �ִ´�
			str[i] = 'z';
			cnt_z--;
			k -= comb;
		}
	}

	str[n + m] = '\0'; // �����Ⱚ�� ���� NULL�� �߰�
}
