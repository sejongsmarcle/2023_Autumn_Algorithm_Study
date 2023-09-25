#include<stdio.h>
#include<stdlib.h>

void downHeap(int id);
void rebuildHeap(int id);
int removeMax();

int *H=NULL;
int n=0;

int main() {
	int i;
	scanf("%d", &n);
	int cnt = n;
	n = n * n;
	H = (int*)malloc(sizeof(int) * (n + 1));

	for (i = 1; i <= n; i++) {
		scanf("%d", &H[i]);
	}

	rebuildHeap(1);
	for (i = 0; i < cnt-1; i++) {
		removeMax();
	}

	printf("%d", H[1]);

	return 0;
}

//--downheap�� ��(��Ʈ)�������� �Ʒ���
void downHeap(int id) {
	//�� �� id��ġ�� ����� Ű�� ũ�⿡ �´� ��ġ�� ���� �̵� 
	//--���� ū Ű ���� ��Ʈ�� ������..--
	int left = id * 2;
	int right = id * 2 + 1;

	int BigOne;
	int stm;

	if (left > n) return; //���ʿ� �ƹ��� ��嵵 ���ٸ� ����
	BigOne = left;
	if (right <= n) { //�����ʳ�尡 �ִٸ� ���� �˻�
		if (H[BigOne] < H[right]) //������ Ű�� ���ʺ��� ũ�ٸ�
			BigOne = right; //���� ū Ű�� ���ϴ� �ε�������
	}
	if (H[BigOne] > H[id]) { //���� ���� ū ��Ʈ ��尡 ��庸�� ũ�ٸ�
		stm = H[id];
		H[id] = H[BigOne];
		H[BigOne] = stm;
		downHeap(BigOne);//��Ʈ�� �ٲ� �ڸ����� �ٽ� ũ������� ����
	}
}

void rebuildHeap(int id) {
	if (id > n) return ; //�˰��� ���� �� 1��
	rebuildHeap(2 * id);
	rebuildHeap(2 * id + 1);
	downHeap(id);
}

int removeMax() {
	//d Ű����, ��ȯ�� Ű ��� -> ��ȯ�� �� ���ΰ�/ �Լ� ������ ��� �� ���ΰ�

	int root;
	root = H[1];
	H[1] = H[n]; //��Ʈ �� ����, ������ ��带 ���� �ø���.
	n--;
	downHeap(1); //����
	return root;
}