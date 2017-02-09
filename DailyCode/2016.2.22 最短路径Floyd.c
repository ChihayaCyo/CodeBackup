#include <stdio.h>
#include <stdlib.h>

#define max_size 100//�Բ� ��ά����1000�ͻ�ը
#define INF 1000

typedef struct
{
    int no;
    char name;
} VertexType;

typedef struct
{
    int edge[max_size][max_size];
    int n,e;
    VertexType vex[max_size];
} MGraph;

void PrintMGraph(MGraph G)
{
    int i,j;
    for(i=0; i<G.n; ++i)
    {
        for(j=0; j<G.n; ++j)
            printf("%8d ",G.edge[i][j]);
        printf("\n");
    }
}

//��������ͼ���ڽӾ���
void CreatMGraph(MGraph* G)
{
    int i,j;
    printf("�����붥�����ͱ�����\n");
    scanf("%d %d",&(*G).n,&(*G).e);
    printf("�����붥����ţ����������\n");
    for(i=0; i<(*G).n; ++i)
    {
        fflush(stdin);
        scanf("%c",&(*G).vex[i].name);
    }
    for(i=0; i<(*G).n; ++i)
        for(j=0; j<(*G).n; ++j)
            (*G).edge[i][j]=INF;
    int k,w;
    printf("������i j w��\n");
    for(k=0; k<(*G).e; ++k)
    {
        fflush(stdin);
        scanf("%d %d %d",&i,&j,&w);
        (*G).edge[i][j]=w;
        //(*G).edge[j][i]=w;
    }
}

void printPath(int u,int v,int path[][max_size])
{
    if(path[u][v]==-1)
        printf("%d ",v);
    else{
        int mid=path[u][v];
        printPath(u,mid,path);
        printPath(mid,v,path);
    }
}

void Floyd(MGraph G,int A[][max_size],int path[][max_size])
{
    int i,j;
    for(i=0;i<G.n;++i)
    for(j=0;j<G.n;++j){
        A[i][j]=G.edge[i][j];
        path[i][j]=-1;
    }

    int k;
    for(k=0;k<G.n;++k)
        for(i=0;i<G.n;++i)
            for(j=0;j<G.n;++j)
            {
                if(A[i][k]+A[k][j]<A[i][j]){
                    A[i][j]=A[i][k]+A[k][j];
                    path[i][j]=k;
                }
            }

    for(i=0;i<G.n;++i){
        for(j=0;j<G.n;++j){
            if(i!=j&&A[i][j]<INF){
                printf("��%d��%d�����·��Ϊ��%d\n"
                       "���·��Ϊ��",i,j,A[i][j]);
                printf("%d ",i);
                printPath(i,j,path);
                printf("\n");
            }
        }
    }
}

int main()
{
    MGraph G;
    CreatMGraph(&G);
    printf("�������ڽӾ���Ϊ��\n");
    PrintMGraph(G);

    int A[max_size][max_size];
    int path[max_size][max_size];
    Floyd(G,A,path);

    return 0;
}


