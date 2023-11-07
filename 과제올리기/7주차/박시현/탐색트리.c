#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>
#pragma warning (disable:4996)

//노드 구조체
typedef struct Node {
	struct Node* lChild;
	struct Node* rChild;
	struct Node* parent;

	char name[21];
	int height;
	int key;
}Node;

typedef struct Tree {
	Node* root;
}Tree;

//트리
Tree BST;

//함수
void init(Tree* T);

Node* makeNode();

int isExternal(Node* node);

void findNum(char *ch);

int my_atoi( char* str) {
	int ret = 0;
	int i;
	for (i = 0; str[i] != '\0'; i++)	//NULL문자만나면 for문 종료
		ret = ret * 10 + (str[i] - '0');	//숫자 문자에 '0'을 빼면 레알 숫자가 구해짐
	return ret;
}

void findName(Node *r, char *ch) {
	if (isExternal(r))
		return;

	int k = my_atoi(ch);

	if (r->key == k) {
		printf("%s\n", r->name);
		return;
	}

	else {
		findName(r->lChild,ch);
		findName(r->rChild,ch);
	}
	
}

Node* treeSearch(Node* r, char* ch);

void insertItem(char *ch,int k);

void inOrder(Node* root);

int main(void)
{
	int N, M;
	char ch[21];
	int k=1;
	char question[21];

	init(&BST);

	scanf("%d %d", &N,&M);

	for (int i = 0; i < N; i++) {
		scanf("%s", ch);
		insertItem(ch,k);
		k++;
	}

	for (int i = 0; i < M; i++) {
		scanf("%s", &question);

		if ((question[0] >= '1') && (question[0] <= '9')) //숫자
			findName(BST.root,question);

		else //알파벳
			findNum(question);

	}
}

void init(Tree* T) {
	T->root = makeNode();

	T->root->lChild = NULL;
	T->root->rChild = NULL;
	T->root->parent = NULL;
	

}

Node* makeNode() { //외부노드를 형성

	Node* node = (Node*)malloc(sizeof(Node));

	node->parent = NULL;
	node->lChild = NULL;
	node->rChild = NULL;

	node->height = 0;

	node->key = 0;

	return node;
}

int isExternal(Node* node) {
	if ((node->lChild == NULL) && (node->rChild == NULL))
		return 1;

	else
		return 0;
}

Node* treeSearch(Node* r,char* ch) {

	if (isExternal(r))
		return r;

	if (strcmp(r->name, ch) < 0)
		return treeSearch(r->rChild,ch);

	else if (strcmp(r->name, ch) == 0)
		return r;

	else
		return treeSearch(r->lChild, ch);
	
}

void findNum(char* ch) {
	Node* find = treeSearch(BST.root, ch);

	if (isExternal(find))
		return;
	else
		printf("%d\n", find->key);
}

void insertItem(char *ch,int k) {
	Node* node = treeSearch(BST.root, ch);

	if (isExternal(node)) {
		strcpy(node->name, ch);
		node->height = 1;
		node->key = k;

		node->lChild = makeNode(0);
		node->lChild->parent = node;

		node->rChild = makeNode(0);
		node->rChild->parent = node;
	}

	else return;
}

void inOrder(Node* root) {
	if (isExternal(root))
		return;

	inOrder(root->lChild);
	printf(" %s", root->name);
	inOrder(root->rChild);

}
