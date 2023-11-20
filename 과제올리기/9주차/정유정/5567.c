#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_V 501

int graph[MAX_V][MAX_V], visited[MAX_V];

void insertEdge(int v1, int v2) {
    graph[v1][v2] = graph[v2][v1] = 1;
}

int BFS(int u, int n) {
    int cnt = 0;
    visited[u] = 1;

    for (int i = 1; i <= n; i++) {
        if (graph[u][i] == 1 && visited[i] != 1) {
            cnt++;
            visited[i] = 1;
        }
        if (graph[u][i] == 1 && visited[i] == 1) {
            for (int j = 1; j <= n; j++) {
                if (graph[i][j] == 1 && visited[j] != 1) {
                    cnt++;
                    visited[j] = 1;
                }
            }
        }
    }

    return cnt;
}

int main() {

    int n, m;
    int a, b;
    scanf("%d", &n);
    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        insertEdge(a, b);
    }
    printf("%d", BFS(1, n));

    return 0;
}