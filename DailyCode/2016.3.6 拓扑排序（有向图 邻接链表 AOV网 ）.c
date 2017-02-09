#include <stdio.h>
#include <stdlib.h>

#define max_size 1000 //0-999

typedef struct ArcNode{
    int adjvex;
    struct ArcNode* nextarc;
    int info;
}ArcNode;

typedef struct VNode{
    char name;
    int count;
    ArcNode* firstarc;
}VNode;

typedef struct AGraph{
    VNode adjlist[max_size];
    int n,e;
}AGraph;

void CreateGraph(AGraph* G)
{
    //��ʼ����
    printf("�����붥�����ͱ�����\n");
    scanf("%d %d",&G->n,&G->e);

    //���������
    int i;
    printf("���������붥�����ƣ�\n");
    for(i=0;i<G->n;++i)
    {
        fflush(stdin);  scanf("%c",&G->adjlist[i].name); //�����ַ���Ҫ����
        G->adjlist[i].firstarc=NULL;
        G->adjlist[i].count=0;
    }

    //�����߱���ע�⣺�˴���������ͼ������ͼ��
    int j,k;
    ArcNode* p;
    printf("����������Vi<->Vj�Ķ������ţ�\n");
    for(k=0;k<G->e;++k)
    {
        scanf("%d %d",&i,&j);
        //ͷ�巨��i->j
        p=(ArcNode*)malloc(sizeof(ArcNode));
        p->adjvex=j;
        p->nextarc=G->adjlist[i].firstarc;
        G->adjlist[i].firstarc=p;
        ++G->adjlist[j].count;
        //j->i
        /*
        p=(ArcNode*)malloc(sizeof(ArcNode));
        p->adjvex=i;
        p->nextarc=G->adjlist[j].firstarc;
        G->adjlist[j].firstarc=p;
        */
        /*
        //β�巨��
        p->adjvex=j;
        p->nextarc=NULL;
        G->adjlist[i].firstarc->adjvex=i;
        G->adjlist[i].firstarc->nextarc=p;
        p->adjvex=i;
        p->nextarc=NULL;
        G->adjlist[j].firstarc->adjvex=j;
        G->adjlist[j].firstarc->nextarc=p;
        */
    }
}

void PrintGraph(AGraph* G)
{
    int i;
    ArcNode* p=(ArcNode*)malloc(sizeof(ArcNode));
    for(i=0;i<G->n;++i)
    {
        printf("%d %c:",i,G->adjlist[i].name);
        p=G->adjlist[i].firstarc;
        while(p!=NULL)
        {
            printf(" %d",p->adjvex);
            p=p->nextarc;
        }
        printf("\n");
    }
}

int TopSort(AGraph G)
{
    int i,j,n=0;
    int stack[max_size],top=-1;
    for(i=0;i<G.n;++i)
        if(G.adjlist[i].count==0){
            stack[++top]=i;
        }
    ArcNode* p;
    p=(ArcNode*)malloc(sizeof(ArcNode));
    while(top!=-1)
    {
        i=stack[top--];
        printf("%c ",G.adjlist[i].name);
        ++n;
        p=G.adjlist[i].firstarc;
        if(p!=NULL)
            j=p->adjvex;
        while(p!=NULL)
        {
            --(G.adjlist[j].count);
            if(G.adjlist[j].count==0)
            {
                stack[++top]=j;
            }
            p=p->nextarc;
        }
    }
    if(n==G.n)
        return 1;
    else
        return 0;
}

int main()
{
    AGraph G;
    CreateGraph(&G);
    PrintGraph(&G);

    TopSort(G);

    return 0;
}

