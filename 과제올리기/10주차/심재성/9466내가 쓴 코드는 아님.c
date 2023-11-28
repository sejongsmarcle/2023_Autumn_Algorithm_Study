#include <stdio.h>
#pragma warning(disable:4996)

int T; // 테스트 케이스의 수
int N; // 학생의 수
int S[100000 + 10]; // 학생들의 팀 관계를 나타내는 배열
int visit[100000 + 10]; // 방문 여부를 나타내는 배열
int done[100000 + 10]; // 처리 여부를 나타내는 배열
int cnt; // 팀을 이루지 못하는 학생들의 수

// 깊이 우선 탐색 함수
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
	scanf("%d", &T); // 테스트 케이스의 수 입력

	for (int i = 0; i < T; i++) {
		N = 0;
		cnt = 0;
		scanf("%d", &N); // 학생의 수 입력

		// 학생들의 팀 관계와 배열 초기화
		for (int j = 1; j <= N; j++) {
			scanf("%d", &S[j]);
			visit[j] = 0;
			done[j] = 0;
		}

		// 모든 학생에 대해 DFS 수행
		for (int j = 1; j <= N; j++) {
			if (visit[j] != 1) {
				DFS(j);
			}
		}

		printf("%d", N - cnt); // 팀을 이루지 못하는 학생 수 출력

		if (i < T - 1)
			printf("\n"); // 테스트 케이스 사이에 개행 문자 출력
	}

	return 0; // 프로그램 종료
}
