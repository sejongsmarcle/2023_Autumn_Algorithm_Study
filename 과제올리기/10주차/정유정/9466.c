#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100001

typedef struct Edge {
    int to;
    struct Edge* next;
} Edge;

Edge* edges[MAX_SIZE];
int visited[MAX_SIZE];

Edge* getEdge(int to) {
    Edge* ret = (Edge*)malloc(sizeof(Edge));
    ret->to = to;
    ret->next = NULL;

    return ret;
}

void addEdge(int from, int to) {
    Edge* edge = getEdge(to);
    edge->next = edges[from];
    edges[from] = edge;
}

int dfs(int start, int cur) {
    int stack[MAX_SIZE];
    int top = -1;

    visited[cur] = 1;
    stack[++top] = cur;

    while (top >= 0) {
        int current = stack[top--];
        int next = edges[current]->to;

        if (!visited[next]) {
            visited[next] = 1;
            stack[++top] = next;
        }
        else if (visited[next] && next == start) {
            return 1;
        }
    }

    return 0;
}

int main() {
    int T, n, m;
    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        scanf("%d", &n);
        for (int j = 1; j <= n; j++) {
            scanf("%d", &m);
            addEdge(j, m);
        }

        int failCount = 0;

        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                visited[k] = 0;
            }
            failCount += dfs(j, j);
        }

        printf("%d\n", n - failCount);

        for (int i = 1; i < MAX_SIZE; i++) {
            Edge* current = edges[i];
            while (current != NULL) {
                Edge* next = current->next;
                free(current);
                current = next;
            }
            edges[i] = NULL;
        }
    }

    return 0;
}