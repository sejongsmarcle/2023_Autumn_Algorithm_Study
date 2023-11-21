#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <time.h>
#pragma warning (disable:4996)

#define MAX 501

int adj[MAX][MAX]; // ������� 
int level[MAX];    // ���� ���� �迭

typedef struct Queue {
    int save[MAX];
    int front;
    int rear;
} Queue;

void bfs(int start, int n);

int main() {
    int n, m;

    scanf("%d %d", &n, &m);



    for (int i = 0; i < m; i++) {
        int v1, v2;
        scanf("%d %d", &v1, &v2);
        adj[v1][v2] = 1;
        adj[v2][v1] = 1;
    }

    bfs(1, n);
    return 0;
}

void bfs(int start, int n) {
    int current, next;
    int count = 0;
    Queue q;

    q.front = q.rear = -1;


    level[start] = 0; // ������� ������ 0

    q.save[++q.rear] = start;

    while (q.front < q.rear) {
        current = q.save[++q.front];

        for (int i = 1; i <= n; i++) {
            if (adj[current][i] == 1) {
                if (current == 1 && level[i] == NULL) {
                    level[i] = 1; // ����̿� ���������� ����� ��� ���� 1�� ����
                    q.save[++q.rear] = i;
                }

                else if (current != 1 && i != 1) {
                    if (level[current] == 1 && level[i] == NULL) {
                        level[i] = 2;
                        q.save[++q.rear] = i;
                    }
                    else if (level[i] == 1 && level[current] == NULL) {
                        level[current] = 2;
                        q.save[++q.rear] = current;
                    }
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (level[i] == 1 || level[i] == 2) { // ������ 1�̳� 2�� �л� ī��Ʈ
            count++;
        }
    }
    printf("%d", count);
}
