#pragma warning (disable:4996)
#include <string.h>
#include <stdio.h>
#include <string.h>

#define MAX 100001

int N, cnt;
int want[MAX];
int visited[MAX];
int done[MAX]; // 방문이 끝났는지 여부

void DFS(int nodeNum) {
    visited[nodeNum] = 1;

    int next = want[nodeNum];

    if (!visited[next])
        DFS(next);
    else if (!done[next]) {
        for (int i = next; i != nodeNum; i = want[i])
            cnt++;
        cnt++;
    }

    done[nodeNum] = 1; 
}

int main(void) {
    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        memset(visited, 0, sizeof(visited));
        memset(done, 0, sizeof(done));

        scanf("%d", &N);

        for (int j = 1; j <= N; j++)
            scanf("%d", &want[j]);

        cnt = 0;

        for (int j = 1; j <= N; j++)
            if (!visited[j])
                DFS(j); // 팀을 이루는 사람들을 센다

        printf("%d\n", N - cnt);
    }

    return 0;
}

