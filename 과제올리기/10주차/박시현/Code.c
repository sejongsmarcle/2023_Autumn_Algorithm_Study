#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable:4996)

typedef struct Edge {
	//연결된 정점
	int start;
	int end;

	//상태
	char state;
}Edge;

typedef struct Incid_Node {
	struct Incid_Node* next;
	int edge_idx;
}Incid_Node;

typedef struct Vertex {
	struct Incid_Node* In_list;
	int id;

	//상태
	char state;
}Vertex;

typedef struct Graph {
	Vertex* vertex;
	Edge* edge;
}Graph;

Incid_Node* makeIncidNode(int n) {
	Incid_Node* node = (Incid_Node*)malloc(sizeof(Incid_Node));

	node->next = NULL;
	node->edge_idx = n;

	return node;
}

void init_Vertex(Vertex* v,int n) {
	for (int i = 0; i < n; i++) {
		v[i].id = i + 1;
		v[i].In_list = makeIncidNode(-1);
	}
}


void init_Graph(Graph* graph,int n) {
	graph->vertex = (Vertex*)malloc(sizeof(Vertex) * n);
	graph->edge = (Edge*)malloc(sizeof(Edge) * n);

	init_Vertex(graph->vertex,n);
}

void add_Node(Vertex* vertex, int from, int to) {
	Incid_Node* p = vertex[to].In_list;

	Incid_Node* node = makeIncidNode(from);


	for (; p->next != NULL; p = p->next)
		;

	node->next = p->next;
	p->next = node;

}

void modify_Edge(Graph* graph, int from, int to) {
	//================간선 리스트 변경==================
	graph->edge[from - 1].start = from - 1;
	graph->edge[from- 1].end = to - 1;

	//================인접 리스트 변경==================
	add_Node(graph->vertex,from-1,to-1);

}

//==============멤버수 파악==================
int opposite(Graph *graph, int idx) {
	return graph->edge[idx].end;
}

int rDFS(Graph* graph, int idx,int start,int sum) {
	graph->vertex[idx].state = 'V';//Visited라는 뜻으로, 방문했음을 의미.

	int w=opposite(graph, idx);
	int result = sum;

	if (graph->edge[idx].state == 'F') {
		if (graph->vertex[w].state == 'F') {
			graph->edge[idx].state = 'T';//방문한 간선

			result++;
			sum=rDFS(graph, w,start,result);
		}

		else
			graph->edge[idx].state = 'B';//Bac
	}
	
	if (start == w)
		return result;
	else
		return sum;
}

int DFS(Graph* graph,int N) {
	int result=0;
	for (int i = 0; i < N; i++)
		graph->vertex[i].state = 'F'; //방문하지 않은 상태
	
	for (int i = 0; i < N; i++)
		graph->edge[i].state = 'F'; //방문하지 않은 상태

	for (int i = 0; i < N; i++) {
		if (graph->vertex[i].state == 'F')
			result=rDFS(graph, i,i,result);
	}
	
	return result;
}

int isLoop(Graph *graph,int idx) {
	Incid_Node* p = graph->vertex[idx].In_list->next;

	for (; p != NULL; p = p->next) {
		if (p->edge_idx == idx) {
			return 1;
		}
	}

	return 0;
}

void printNonMem(Graph* graph,int N) {
	int member=0;

	//루프 판단
	for (int i = 0; i < N; i++) {
		member += isLoop(graph, i);
	}

	//싸이클 판단
	member += DFS(graph, N);

	printf("%d\n", N - member);
}


int main(void)
{

	//=================그래프 설정===================
	Graph* graph = (Graph*)malloc(sizeof(Graph));

	int T, N;
	int choice;

	scanf("%d", &T);
	
	for (int i = 0; i < T; i++) {
		scanf("%d", &N);
		init_Graph(graph,N);

		for (int j = 0; j < N; j++) {
			scanf("%d", &choice);
			modify_Edge(graph, j+ 1, choice);
		}

		printNonMem(graph,N);
	}

}
