#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
int matrix[500][500];

int main() {
  int n, m, a, b; int count = 0;
  int cnt[500] = { 0 };
  
  scanf("%d", &n);
  scanf("%d", &m);
  
  for (int i = 0; i < m; i++) {
    scanf("%d %d", &a, &b);
    matrix[a][b] = 1;
    matrix[b][a] = 1;
  }//그래프의 2차원 배열에 간선 넣어주기
  for (int i = 2; i <= n; i++) {
    if (matrix[1][i] == 1) { //1과 인접한 정점이면
      if (cnt[i] != 1) {
        count++;
        cnt[i] = 1;
      }
    for (int j = 2; j <= n; j++) {
      if (matrix[i][j] == 1&&cnt[j]!=1) { //1과 인접한 정점과 인접한 정점이면
        count++;
        cnt[j] = 1;
        }
    }}
  }
  printf("%d", count);
  
  return 0;
}
