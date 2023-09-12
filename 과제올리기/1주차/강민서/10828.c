#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int stack[10001];
int count = -1;

int empty() {
	if (count == -1)
		return 1; 
	else
		return 0; 
}
int top() {
	if (empty())
		return -1; 
	else
		return stack[count];
}
int push(int x) {
	stack[++count] = x; 
}
int pop() {
	if (empty())
		return -1;
	else
		return stack[count--]; 
}
int size() {
	return count+1;
}
int main(void) {
	int N;
	char arr[6];
    
	scanf("%d", &N);
    
	for (int i = 0; i < N; i++) {
		scanf("%s", arr);
		if (strcmp(arr, "push") == 0) {
			int num;
			scanf("%d", &num);
			push(num);
		}
		else if (strcmp(arr, "pop") == 0) {
			printf("%d\n", pop());			
		}
		else if (strcmp(arr, "top") == 0) {
			printf("%d\n", top());
		}
		else if (strcmp(arr, "size") == 0) {
			printf("%d\n", size());
		}
		else if (strcmp(arr, "empty") == 0) {
			printf("%d\n", empty());
		}
	}
	return 0;
}
