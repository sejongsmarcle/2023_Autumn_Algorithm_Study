#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define NUMV_MAX 99999
#define IN -1
#define OUT 1

typedef struct Edge {
    int orgIdx;
    int desIdx;
} Edge;

typedef struct IncidentEdge {
    int edgeIdx;
    struct IncidentEdge* next;
} IncidentEdge;

typedef struct Vertex {
    int vName;
    int inDegree;
    IncidentEdge* InIEdges;
    IncidentEdge* OutIEdges;
} Vertex;

typedef struct Graph {
    Vertex* vertices;
    Edge* edges;
} Graph;

typedef struct Node {
    int vIdx;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

Graph G;
int n, m; // 정점, 간선 수
int topOrder[NUMV_MAX + 1]; // DAG 여부[0]. 위상 순서[1:n]
Queue Q; // 정점 대기용 큐

int isEmpty();
void enqueue(int vIdx);
int dequeue();

void initializeGraph() {
    G.vertices = (Vertex*)malloc((NUMV_MAX + 1) * sizeof(Vertex));
}

void insertVertex(int vName, int vIdx) {
    G.vertices[vIdx].vName = vName;
    G.vertices[vIdx].inDegree = 0;
    G.vertices[vIdx].InIEdges = NULL;
    G.vertices[vIdx].OutIEdges = NULL;
}

int index(int vName) {
    for (int i = 0; i < n; ++i) {
        if (G.vertices[i].vName == vName) {
            return i;
        }
    }
    return -1; // Vertex not found
}

void addFirst(IncidentEdge** H, int i) {
    IncidentEdge* node = (IncidentEdge*)malloc(sizeof(IncidentEdge));
    node->edgeIdx = i;
    node->next = *H;
    *H = node;
}

void insertIncidentEdge(int vIdx, int eIdx, int in_or_out) {
    if (in_or_out == IN) {
        addFirst(&G.vertices[vIdx].InIEdges, eIdx);
    }
    else {
        addFirst(&G.vertices[vIdx].OutIEdges, eIdx);
    }
}

void insertDirectedEdge(int uName, int wName, int eIndex) {
    int uIdx = index(uName);
    int wIdx = index(wName);

    if (uIdx != -1 && wIdx != -1) {
        G.edges[eIndex].orgIdx = uIdx;
        G.edges[eIndex].desIdx = wIdx;

        insertIncidentEdge(wIdx, eIndex, IN);
        insertIncidentEdge(uIdx, eIndex, OUT);

        G.vertices[wIdx].inDegree++;
    }
}

void buildGraph() {
    initializeGraph();

    //printf("Enter the number of vertices: ");
    scanf("%d", &n);

    int cnt = 1;

    for (int i = 0; i < n; ++i) {
        int vName;
        //  printf("Enter vertex name: ");
        vName = cnt;
        insertVertex(vName, i);
        cnt++;
    }

    cnt = 1;

    //printf("Enter the number of edges: ");
   // scanf("%d", &m);  // 추가: 간선 수 입력 받기

    G.edges = (Edge*)malloc(n * sizeof(Edge));

    for (int i = 0; i < n; ++i) {
        int u, w;
        //  printf("Enter directed edge (u w): ");
        u = cnt;
        scanf("%d", &w);
        insertDirectedEdge(u, w, i);
        cnt++;
    }
}

void topologicalSort() {
    int v, w;
    int count = 0;

    for (v = 0; v < n; v++) {
        if (G.vertices[v].inDegree == 0) {
            enqueue(v);
        }
    }

    while (!isEmpty()) {
        v = dequeue();
        topOrder[++count] = v;

        IncidentEdge* edge = G.vertices[v].OutIEdges;
        while (edge != NULL) {
            w = G.edges[edge->edgeIdx].desIdx;
            G.vertices[w].inDegree--;

            if (G.vertices[w].inDegree == 0) {
                enqueue(w);
            }

            edge = edge->next;
        }
    }

    if (count < n) {
        printf("%d\n", count);
        topOrder[0] = 0; // Graph has a cycle
    }
    else {
        topOrder[0] = 1; // Graph is DAG
    }
}

int main() {

    int k;
    scanf("%d", &k);
    
    for (int i = 0; i < k; i++) {

        buildGraph();

        Q.front = NULL;
        Q.rear = NULL;

        topologicalSort();

        /*
        if (topOrder[0] == 0) {
            printf("0\n");
        }
        else {
            //  printf("Topological order:");
            for (int i = 1; i <= n; ++i) {
                printf("%d ", G.vertices[topOrder[i]].vName);
            }
            printf("\n");
        }
        */

    }
    free(G.edges);
    free(G.vertices);

    return 0;
}

int isEmpty() {
    return Q.front == NULL;
}

void enqueue(int vIdx) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vIdx = vIdx;
    newNode->next = NULL;

    if (isEmpty()) {
        Q.front = newNode;
        Q.rear = newNode;
    }
    else {
        Q.rear->next = newNode;
        Q.rear = newNode;
    }
}

int dequeue(void) {
    if (isEmpty()) {
        return -1; // Queue is empty
    }
    else {
        int vIdx = Q.front->vIdx;
        Node* temp = Q.front;
        Q.front = Q.front->next;
        free(temp);
        return vIdx;
    }
}
