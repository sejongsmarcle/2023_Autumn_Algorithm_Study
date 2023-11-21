#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma warning (disable:4996)

//==========사용된 자료구조===========
#define MAX_SIZE 500

typedef struct { // 큐 타입
	int queue[MAX_SIZE];
	int  front, rear;
}QueueType;

typedef struct GraphType {
	int n; //정점 수
	int adj_matrix[MAX_SIZE][MAX_SIZE];
}GraphType;

int visited[MAX_SIZE];

int cnt = 0;
//===============큐 ADT===================
void init_Queue(QueueType* q)
{
	q->front = q->rear = 0;
}

void enqueue(QueueType* q, int item)
{
	q->rear++;
	q->queue[q->rear] = item;
}

int dequeue(QueueType* q)
{
	q->front++;
	return q->queue[q->front];
}

//==============인접행렬======================

void init_Graph(GraphType* g) {
	int i, j;
	g->n;
	for (i = 0; i < MAX_SIZE; i++)
		for (j = 0; j < MAX_SIZE; j++)
			g->adj_matrix[i][j] = 0; //인접행렬
}

void insert_vertex(GraphType* g, int v) {
	if (((g->n) + 1) > MAX_SIZE) {
		return;
	}
	g->n++;
}

void insert_edge(GraphType* g, int start, int end) {
	g->adj_matrix[start][end] = 1;
	g->adj_matrix[end][start] = 1;
}

//=============그래프 순회================
void BFS(GraphType* g, int v) {
	int w;

	//방문 차례 표현하기 위한 큐 구현
	QueueType q;
	init_Queue(&q);
	enqueue(&q, v);

	//방문 여부 기록하기 위한 배열
	visited[v] = 1;

	
	while (q.front!=q.rear) {
		v = dequeue(&q);		// 큐에 정점 추출 

		for (w = 0; w < g->n; w++)	// 인접 정점 탐색 
			if (g->adj_matrix[v][w] && !visited[w]) { //연결되어 있고 방문한 적이 없다면.
				visited[w] = 1;    // 방문 표시
				enqueue(&q, w); 	// 방문한 정점을 큐에 저장
			}
	}
}


void printNum(GraphType* g) {
	int w;

	//방문 차례 표현하기 위한 큐 구현 - 우선 상근이부터 접근
	QueueType q;
	init_Queue(&q);
	enqueue(&q, 0);

	//방문 여부 기록하기 위한 배열 - 우선 상근이부터 접근
	visited[0] = 1;

	int v;
	int type = -1; //친구의 친구까지 표현하기 위해

	while ((q.front != q.rear)&&(type!=q.front)) { //친구의 친구까지만
		v = dequeue(&q);		// 큐에 정점 추출 

		for (w = 0; w < g->n; w++)	// 인접 정점 탐색 
			if (g->adj_matrix[v][w] && !visited[w]) { //연결되어 있고 방문한 적이 없다면.
				visited[w] = 1;    // 방문 표시
				enqueue(&q, w); // 방문한 정점을 큐에 저장
				cnt++;
			}

		if (type == -1)
			type = q.rear;

	}
}

int main(void)
{
	GraphType* g;
	g = (GraphType*)malloc(sizeof(GraphType));

	//정점의 수
	int N;
	scanf("%d", &N);
	g->n = N;

	//간선을 만들어줄 리스트
	int M;
	scanf("%d", &M);

	int v1, v2;

	for (int i = 0; i < M; i++) {
		scanf("%d %d", &v1, &v2);
		insert_edge(g, v1, v2);
	}

	printNum(g);
	printf("%d\n", cnt);
	free(g);
}

