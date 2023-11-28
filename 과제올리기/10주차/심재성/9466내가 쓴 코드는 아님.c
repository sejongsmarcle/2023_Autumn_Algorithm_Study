#include <stdio.h>
#pragma warning(disable:4996)

int T; // �׽�Ʈ ���̽��� ��
int N; // �л��� ��
int S[100000 + 10]; // �л����� �� ���踦 ��Ÿ���� �迭
int visit[100000 + 10]; // �湮 ���θ� ��Ÿ���� �迭
int done[100000 + 10]; // ó�� ���θ� ��Ÿ���� �迭
int cnt; // ���� �̷��� ���ϴ� �л����� ��

// ���� �켱 Ž�� �Լ�
void DFS(int i) {
	int next = S[i];
	visit[i] = 1;

	if (visit[next] == 0) {
		DFS(next);
	}
	else {
		if (done[next] == 0) {
			for (int j = next; j != i; j = S[j]) {
				cnt++;
			}
			cnt++;
		}
	}
	done[i] = 1;
}

int main() {
	scanf("%d", &T); // �׽�Ʈ ���̽��� �� �Է�

	for (int i = 0; i < T; i++) {
		N = 0;
		cnt = 0;
		scanf("%d", &N); // �л��� �� �Է�

		// �л����� �� ����� �迭 �ʱ�ȭ
		for (int j = 1; j <= N; j++) {
			scanf("%d", &S[j]);
			visit[j] = 0;
			done[j] = 0;
		}

		// ��� �л��� ���� DFS ����
		for (int j = 1; j <= N; j++) {
			if (visit[j] != 1) {
				DFS(j);
			}
		}

		printf("%d", N - cnt); // ���� �̷��� ���ϴ� �л� �� ���

		if (i < T - 1)
			printf("\n"); // �׽�Ʈ ���̽� ���̿� ���� ���� ���
	}

	return 0; // ���α׷� ����
}
