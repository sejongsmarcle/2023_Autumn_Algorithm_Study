#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int** line;
int* visit;
//int vertex;
int cnt = 0;

typedef struct QUEUE {
    int data[500];
    int front;
    int rear;
    int level[500];
} Queue;

void init(int n) {
    //vertex = n;
    line = (int**)malloc((n + 1) * sizeof(int*));
    visit = (int*)malloc((n + 1) * sizeof(int));

    for (int i = 1; i <= n; i++) {
        line[i] = (int*)malloc((n + 1) * sizeof(int));
        for (int j = 1; j <= n; j++) {
            line[i][j] = 0;
        }
        visit[i] = 0;
    }
}

void BFS(int s, int n) {
    Queue q;

    q.front = 0;
    q.rear = 0;
    visit[s] = 1;
    q.level[s] = 0;

    q.data[++q.rear] = s;

    while (q.front != q.rear) {
        int a = q.data[++q.front];

        for (int i = 1; i <= n; i++) {
            if (line[a][i] == 1 && !visit[i]) {
                visit[i] = 1;
                q.data[++q.rear] = i;
                q.level[i] = q.level[a] + 1;

                if (q.level[i] == 1 || q.level[i] == 2) {
                    cnt++;
                }
            }
        }
    }
}

int main() {
    int n, m, u, v;
    scanf("%d %d", &n, &m);

    init(n);
    visit[1] = 1;

    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &u, &v);
        line[u][v] = 1;
        line[v][u] = 1;
    }

    BFS(1, n);

    printf("%d", cnt);

}
