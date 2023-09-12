#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int queue[10001];
int queue_size = 0;

void push(int x){
	queue[queue_size] = x;
    queue_size += 1;
}

int empty() {
	if(queue_size == 0){
    	return 1;
    }
    return 0;
}

int pop() {
	if(empty()) {
    	return -1;
    }
    queue_size -= 1;
    return queue[0];
}

int front(){
	if(empty()) {
    	return -1;
    }
    return queue[queue_size - queue_size];
}

int back() {
	if(empty()) {
    	return -1;
    }
    return queue[queue_size-1];
}

void setting(){
	for(int i = 0; i < queue_size; i++)
    {
    	queue[i]=queue[i+1];
    }
}

int main() {
	int N = 0, x=0;
    char arr[6] = {0, };
    
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
    	scanf("%s", arr);
    
    	if(!strcmp(arr, "push")){
            scanf("%d", &x);
            push(x);
        }
        else if(!strcmp(arr, "pop")){
            printf("%d\n", pop());
            setting();
        }
        else if(!strcmp(arr, "empty")) {
            printf("%d\n", empty());
        }
        else if(!strcmp(arr, "size")) {
            printf("%d\n", queue_size);
        }
        else if(!strcmp(arr, "front")){
            printf("%d\n", front());
        }
        else if(!strcmp(arr, "back")) {
            printf("%d\n", back());
        }
    }

    return 0;
}
