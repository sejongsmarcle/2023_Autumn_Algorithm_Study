#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> 

int main() {
	int M, n;

	scanf("%d%d", &M, &n);
	getchar();

	char tmp[21]; 

	char **ch = (char**)malloc(sizeof(char*) * M);
	for (int i = 0; i < M; i++) {
		scanf("%s", tmp);
		getchar();
		ch[i] = (char*)malloc(sizeof(char) * strlen(tmp));
		strcpy(ch[i], tmp);  //strcpy안쓰고 =tmp로 해버리면 tmp의 주소가 ch[i]에 연결되서 배열이 꼬임.(내용만 붙여넣어야 함)
	}

	for (int i = 0; i < n; i++) {
		scanf("%s", tmp);
		getchar();
		if (tmp[0] >= '0' && tmp[0] <= '9') { //맨처음자리가 숫자면
			int x = atoi(tmp);
			printf("%s\n", ch[x - 1]);
		}
		else {
			for (int j = 0; j < M; j++) {
				if (strcmp(tmp, ch[j]) == 0) { //strcmp가 문자열 전체를 비교하는 건가?
					printf("%d\n", j + 1);
					break;
				}
			}
		}
	}

	return 0;
}
