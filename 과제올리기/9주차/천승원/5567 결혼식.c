#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define fresh 0
#define visited 1
#define tree 1
#define cross 2

typedef struct Edge {
	int vNum1, vNum2;
	struct Edge* next;
	int eLabel;
} Edge;

typedef struct Vertex {
	int vNum;
	struct Vertex* next;
	int vLabel;
} Vertex;

typedef struct Graph {
	Vertex* vertices;
	Edge* edges;
	Edge* adjmtx[101][101];
} Graph;

void init(Graph* graph) {
	graph->vertices = graph->edges = NULL;
	memset(graph->adjmtx, NULL, sizeof(graph->adjmtx));
}

void insertVertex(Graph* graph, int vNumber) {
	Vertex* v = (Vertex*)malloc(sizeof(Vertex));
	v->vNum = vNumber;
	v->vLabel = 0;
	v->next = graph->vertices; //Graph null 초기화 안해줘도 되는진 잘 모르겠음.
	graph->vertices = v;
}

Vertex* findVertex(Graph* graph, int vNumber) {
	Vertex* p = graph->vertices;
	while (p != NULL) {
		if (p->vNum == vNumber) {
			return p;
		}
		p = p->next;
	}
	return NULL;
}

Edge* findEdge(Graph* graph, int vNumber1, int vNumber2) {
	Edge* p = graph->edges;
	while (p != NULL) {
		if (p->vNum1 == vNumber1 && p->vNum2 == vNumber2) {
			return p;
		}
		else if (p->vNum1 == vNumber2 && p->vNum2 == vNumber1) {
			return p;
		}
		p = p->next;
	}
	return NULL;
}

void insertAdjMat(Graph* g, int vNum1, int vNum2, Edge* edge) {
	g->adjmtx[vNum1][vNum2] = edge;
	g->adjmtx[vNum2][vNum1] = edge;
}

void insertEdge(Graph* g, int vNum1, int vNum2) {
	Edge* e = (Edge*)malloc(sizeof(Edge));
	e->vNum1 = vNum1;
	e->vNum2 = vNum2;
	e->next = g->edges; //간선리스트에 삽입도 하고
	e->eLabel = fresh;
	g->edges = e;

	insertAdjMat(g, vNum1, vNum2, e); //인접행렬과 연결도 함.
}


void processA(Graph* graph, int a, int numV) {
	Vertex* v = findVertex(graph, a);
	if (v == NULL) {
		printf("-1\n");
		return;
	}
	for (int i = 1; i <= numV; i++) {
		if (graph->adjmtx[a][i] != NULL)
			printf("%d ", i);
	}
	printf("\n");
}
void print_all(Graph* g, int numV) {
	for (int i = 1; i <= numV; i++) {
		processA(g, i, numV);
	}
}

void initializeGraph(Graph* g, int numV, int numE) {
	for (int i = numV; i >= 1; i--) {
		insertVertex(g, i);
	}

	int a, b;
	for (int i = 0; i < numE; i++) {
		scanf("%d%d", &a, &b);
		insertEdge(g, a, b);
	}
}

int opposite(Edge* edge, int vNumber) {
	if (edge->vNum1 == vNumber)
		return edge->vNum2;
	else
		return edge->vNum1;
}

int cnt = 0;

void BFS1(Graph* graph, int s, int numV) {
	Vertex* L[100][100];
	memset(L, NULL, sizeof(L));
	Vertex* v = findVertex(graph, s);
	v->vLabel = visited;
	L[0][0] = v;
	int i = 0;
	while (L[i][0] != NULL) {
		int idx = 0;
		for (int a = 0; a < numV; a++) {
			if (L[i][a] != NULL) { //전 레벨의 원소들
				for (int b = 1; b <= numV; b++) {
					if (graph->adjmtx[L[i][a]->vNum][b] != NULL) {
						if (graph->adjmtx[L[i][a]->vNum][b]->eLabel == fresh) {
							Vertex* w = findVertex(graph, opposite(graph->adjmtx[L[i][a]->vNum][b], L[i][a]->vNum));
							if (w->vLabel == fresh) {
								graph->adjmtx[L[i][a]->vNum][b]->eLabel = tree;
								w->vLabel = visited;
								cnt++;
								L[i + 1][idx++] = w;
							}
							else {
								graph->adjmtx[L[i][a]->vNum][b]->eLabel = cross;
							}
						}
					}
				}
			}
		}
		if (i == 1)
			return;
		i++;
	}
}

void BFS(Graph* graph, int s, int numV) {
	BFS1(graph, s, numV);
}

int main()
{
	Graph g;
	init(&g);
	int numV, numE;
	scanf("%d%d", &numV, &numE);
	initializeGraph(&g, numV, numE);

	BFS(&g, 1, numV);
	printf("%d", cnt);

	return 0;
}
