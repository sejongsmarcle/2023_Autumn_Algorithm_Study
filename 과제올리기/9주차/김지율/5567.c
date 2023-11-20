#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void BFS(int** graph, int* visited, int n, int v) {
    int front = 0, rear = 0, num = 0;
    int* queue = (int*)malloc(sizeof(int) * (n + 1));
    int* depth = (int*)malloc(sizeof(int) * (n + 1));

    visited[v] = 1;
    queue[rear++] = v;
    depth[v] = 0;

    while (front < rear) {        
        int pop = queue[front++];
        for (int i = 1; i <= n; i++) {
            if (visited[i] == 0 && graph[pop][i] == 1) {
                visited[i] = 1;
                depth[i] = depth[pop] + 1;
                if (depth[i] <= 2) {
                    queue[rear++] = i;
                    num++;
                }
            }
        }
    }

    printf("%d", num);

    free(queue);
    free(depth);
}

int main() {
    int n, m, a, b;

    scanf("%d %d", &n, &m);

    int** graph = (int**)malloc(sizeof(int*) * (n + 1));
    for (int i = 0; i <= n; i++) {
        graph[i] = (int*)calloc(n + 1, sizeof(int));
    }

    int* visited = (int*)calloc(n + 1, sizeof(int));

    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        graph[a][b] = 1;
        graph[b][a] = 1;
    }

    BFS(graph, visited, n, 1);

    for (int i = 0; i <= n; i++)
        free(graph[i]);
    free(graph);
    free(visited);

    return 0;
}