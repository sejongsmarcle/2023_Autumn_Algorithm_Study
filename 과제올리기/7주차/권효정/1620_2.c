#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning (disable:4996)

int N;
int num[100000];
char name[100000][21];

int main() {
	int M;
	char q[21];
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		scanf("%s", name[i]);
		getchar();
		num[i] = i + 1;
	}

	/*for (int i = 0; i < N; i++) {
		printf("// %d ", num[i]);
		//printf("// %s", name[i]);
	}*/

	for (int i = 0; i < M; i++) {
		scanf("%s", q);
		getchar();
		for (int i = 0; i < N; i++) {
			//printf("**%s\n", a);
			if (q[0] >= '0' && q[0] <= '9') {
				if (num[i] == atoi(q)) {
					printf("%s\n", name[i]);
					break;
				}
			}
			else { //if ((q[0] >= 'A' && q[0] <= 'Z') || (q[0] >= 'a' && q[0] <= 'z')) {			
				//printf("///// %s %s\n", name[i], q);
				if (strcmp(name[i], q) == 0) {
					printf("%d\n", num[i]);
					break;
				}
			}
		}
	}
}