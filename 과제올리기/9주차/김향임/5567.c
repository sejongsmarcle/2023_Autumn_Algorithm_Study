#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Graph {
	int** list;
	int  n;
}graph;


void  addedge(graph g ,int a, int b) {
	g.list[a][b] = 1;
	g.list[b][a] = 1;
}

void BFS(graph g, int s) {

	int size = g.n;

	int* q = (int*)malloc(sizeof(int) * size);
	int * visited = (int*) malloc(sizeof(int) * (size+1));

	int rear = 0, front = 0;

	// visited 초기화
	memset(visited, 0, sizeof(int) * (size + 1));


	visited[s] = 1;

	// printf("%d\n", s); // 시작점 세팅
	q[rear++] = s;

	int friend = 0;

	// 상근이의 친구
	s = q[front++];
	for (int i = 0; i <= g.n; i++) {
			if (g.list[s][i] == 1 && !visited[i]) {
				visited[i] = 1;
				//printf("%d\n", i);
				q[rear++] = i;
				friend++;
			}
	}

	int f_rear = rear;

	for (int j = 1; j < f_rear; j ++) {
		s = q[j];
		for (int i = 0; i <= g.n; i++) {
			if (g.list[s][i] == 1 && !visited[i]) {
				visited[i] = 1;
				//printf("%d\n", i);
				q[rear++] = i;
				friend++;
			}
		}

	}

	printf("%d", friend);



}

int main() {

	graph g;

	int n, m, s;

	scanf("%d %d", &n, &m);
	s = 1;
	g.n = n;
	g.list = (int**)malloc(sizeof(int*) * (n + 1));

	for (int i = 0; i <= n; i++) {
		g.list[i] = (int*)malloc(sizeof(int) * (n + 1));
		memset(g.list[i], 0, sizeof(int) * (n + 1));
	}

	int a, b;

	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		addedge(g, a, b);
	}

	BFS(g, s);

}
