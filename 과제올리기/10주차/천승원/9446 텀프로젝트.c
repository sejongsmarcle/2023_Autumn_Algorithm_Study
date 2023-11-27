#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define fresh 0
#define visited 1
#define tree 1
#define back 2

typedef struct Edge {
	int vNum1, vNum2;
	struct Edge* next;
	int eLabel;
} Edge;

typedef struct IncidentEdge {
	Edge* edge;
	struct IncidentEdge* next;
} IncidentEdge;

typedef struct Vertex {
	int vNum;
	IncidentEdge* iEdges;
	struct Vertex* next;
	int vLabel;
} Vertex;

typedef struct Graph {
	Vertex* vertices;
	Edge* edges;
} Graph;

void init(Graph* graph) {
	graph->vertices = graph->edges = NULL;
}

void insertVertex(Graph* graph, int vNumber) {
	Vertex* v = (Vertex*)malloc(sizeof(Vertex));
	v->vNum = vNumber;
	v->iEdges = NULL; //나중에 삽입할것. 지금은 아예 연결 안된 독립정점 선언
	v->next = graph->vertices; //Graph null 초기화 안해줘도 되는진 잘 모르겠음.
	graph->vertices = v;
	v->vLabel = fresh;
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

int opposite(Edge* edge, int vNumber) {
	if (edge->vNum1 == vNumber)
		return edge->vNum2;
	else
		return edge->vNum1;
}

void insertOneIncidentEdge(Graph* graph, int vNumber, Edge* edge) {
	Vertex* v = findVertex(graph, vNumber);
	IncidentEdge* p = v->iEdges; IncidentEdge* r = v->iEdges;
	IncidentEdge* s;
	s = (IncidentEdge*)malloc(sizeof(IncidentEdge)); //malloc안하면 공간할당이 안되서 오류남.
	s->edge = edge; //각 요소 삽입시엔 정확하게 초기화해주어야 함.

	while (p != NULL) {
		if (opposite(edge, vNumber) < opposite(p->edge, vNumber)) //두 간선 비교(시작정점, 끝정점이 서로 같은지)
			break; //p가 새로 들어오는 것보다 더 커지는 순간 종료(새로 들어오는 것보다 작은것중 가장 큰것 = r)
		r = p;
		p = p->next; //여기선 edge를 직접바꾸는거 안됨 주의
	}
	if (p == r) { //처음일때
		s->next = p;
		v->iEdges = s; //자체를 연결
	}
	else {
		s->next = p;
		r->next = s;
	}
}

void insertIncidentEdges(Graph* graph, int vNumber1, int vNumber2, Edge* edge) {
	if (vNumber1 == vNumber2)
		insertOneIncidentEdge(graph, vNumber1, edge);
	else {
		insertOneIncidentEdge(graph, vNumber1, edge);
		insertOneIncidentEdge(graph, vNumber2, edge);
	}
}

void insertEdge(Graph* graph, int vNumber1, int vNumber2) {
	Edge* e = (Edge*)malloc(sizeof(Edge));
	e->vNum1 = vNumber1;
	e->vNum2 = vNumber2;
	e->eLabel = fresh;
	//이건 정렬 안해도 되나 싶긴 함.
	e->next = graph->edges;
	graph->edges = e;

	insertIncidentEdges(graph, vNumber1, vNumber2, e);
}

void processA(Graph* graph, int a) {
	Vertex* v = findVertex(graph, a);
	if (v == NULL) {
		printf("-1\n");
		return;
	}
	IncidentEdge* p = v->iEdges;
	for (; p != NULL; p = p->next) {
		printf("%d ", opposite(p->edge, a));
	}
	printf("\n");
}
void print_all(Graph* g, int numV) {
	for (int i = 1; i <= numV; i++) {
		processA(g, i);
	}
}

void initializeGraph(Graph* g, int numV) {
	for (int i = numV; i >= 1; i--) {
		insertVertex(g, i);
	}

	int a;
	for (int i = 1; i <= numV; i++) {
		scanf("%d", &a);
		insertEdge(g, i, a);
	}
}

int st;

void rDFS(Graph* graph, int s, int r) {
	//아니면 큐를 응용해서 검사하는 방법도 있을것 같긴 함.(DFS결과에 자기자신이 있으면 -- 이런식)
	Vertex* v = findVertex(graph, s); //처음 노드에 방문을 안찍으면 다시 끝으로 돌아옴.(vLabel 미사용)
	//루프를 검사할 것.

	for (IncidentEdge* p = v->iEdges; p != NULL; p = p->next) {
		if (p->edge->eLabel == fresh) {
			Vertex* w = findVertex(graph, opposite(p->edge, s));
			if (w->vLabel == fresh) {
				p->edge->eLabel = tree;
				w->vLabel = visited;
				if (w->vNum == r) {
					st = 1;
				}
				else {
					rDFS(graph, w->vNum, r);
				}
			}
			else {
				p->edge->eLabel = back;
			}
		}
	}
}

void DFS(Graph* graph, int s, int r) {
	for (Vertex* p = graph->vertices; p != NULL; p = p->next)
		p->vLabel = 0;
	for (Edge* p = graph->edges; p != NULL; p = p->next)
		p->eLabel = 0;
	rDFS(graph, s, r);
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		Graph g;
		init(&g);
		int numV;
		scanf("%d", &numV);
		initializeGraph(&g, numV);
		int cnt = numV;
		for (int i = 1; i <= numV; i++) {
			st = 0;
			DFS(&g, i, i);
			if (st == 1) {
				cnt--;
				st = 0;
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}
