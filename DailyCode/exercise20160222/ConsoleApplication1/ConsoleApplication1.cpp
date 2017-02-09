// ConsoleApplication1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

#define max_size 100
#define INF 1000

typedef struct VertexType{
	int no;
	char name;
}VertexType;

typedef struct MGraph{
	int edge[max_size][max_size];
	int n, e;
	VertexType vex[max_size];
}MGraph;

void PrintMGraph(MGraph G)
{
	int i, j;
	for (i = 0; i<G.n; ++i){
		for (j = 0; j<G.n; ++j)
			printf("%d ", G.edge[i][j]);
		printf("\n");
	}
}

//��������ͼ���ڽӾ���
void CreatMGraph(MGraph G)
{
	int i, j;
	printf("�����붥�����ͱ�����\n");
	scanf("%d %d", &G.n, &G.e);
	printf("�����붥����ţ����������\n");
	for (i = 0; i<G.n; ++i)
		scanf("%c", &G.vex[i].name);
	for (i = 0; i<G.n; ++i)
		for (j = 0; j<G.n; ++j)
			G.edge[i][j] = INF;
	int k, w;
	printf("������i j w��\n");
	for (k = 0; k<G.e; ++k){
		scanf("%d %d %d", &i, &j, &w);
		G.edge[i][j] = w;
		G.edge[j][i] = w;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	MGraph G;
	CreatMGraph(G);
	PrintMGraph(G);
	return 0;
}

