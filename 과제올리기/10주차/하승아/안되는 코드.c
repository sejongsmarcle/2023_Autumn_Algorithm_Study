#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)
int cnt;
typedef struct Vertex {
	int Ver;
	struct Vertex** adj;

	int flag;
}Vertex;

void get_V(Vertex* G, int i, int ad) {
	G->Ver = i;
	G->flag = 0;
	G->adj[0]->Ver = ad;
}
void flag_(Vertex* V, int last) {
	V->flag = 1;

	int i = 0;
	Vertex* p = V->adj[i];

	while (i <= last) {
		p = p->adj[i++];
		p->flag = 1;
	}
}
void Sort(Vertex** G, int i, int n) {
	Vertex* p = G[i];
	int tmp;
	int last = 0;
	while (1) {
		if (G[i]->Ver == p->adj[last]->Ver) {
			flag_(G[i], last);
			break;
		}
		else if (G[p->adj[last]->Ver]->Ver == p->adj[last]->Ver) break;
		else if (p->adj[last]->flag == 1)break;
		else if (last > n)break;
		else {
			tmp = p->adj[last]->Ver;
			last++;
			p->adj[last]->Ver = G[tmp]->Ver;
		}


	}
}

int main() {
	int n;
	scanf("%d", &n);
	Vertex** Graph = (Vertex*)calloc(n + 1, sizeof(Vertex));


	int i;
	cnt = 0;

	int ad;
	for (i = 1; i <= n; i++) {
		scanf("%d", &ad);
		get_V(Graph[i], i, ad);
	}
	for (i = 1; i <= n; i++) {
		if (Graph[i]->flag == 1)
			continue;
		Sort(Graph, i, n);
	}

	for (i = 1; i <= n; i++) {
		if (Graph[i]->flag == 0)cnt++;
	}
	printf("%d", cnt);
	return 0;
}