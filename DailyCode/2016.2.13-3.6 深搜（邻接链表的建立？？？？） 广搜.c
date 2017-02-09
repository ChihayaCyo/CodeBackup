#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max_size 1000 //0-999

int visited[max_size];

typedef struct ArcNode{
    int adjvex;
    struct ArcNode* nextarc;
    int info;
}ArcNode;

typedef struct VNode{
    char name;
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
    }

    //�����߱���ע�⣺�˴���������ͼ������ͼ��
    int j,k;
    ArcNode* p;
    printf("����������Vi<->Vj�Ķ������ţ�\n");
    for(k=0;k<G->e;++k)
    {
        scanf("%d %d",&i,&j);
        //ͷ�巨��
        p=(ArcNode*)malloc(sizeof(ArcNode));
        p->adjvex=j;//p��˭
        p->nextarc=G->adjlist[i].firstarc;//p�ĺ�����˭
        G->adjlist[i].firstarc=p;//p��ǰ����˭
        p=(ArcNode*)malloc(sizeof(ArcNode));
        p->adjvex=i;
        p->nextarc=G->adjlist[j].firstarc;
        G->adjlist[j].firstarc=p;
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

void DFS(AGraph* G,int v)
{
    ArcNode* p=(ArcNode*)malloc(sizeof(ArcNode));
    visited[v]=1;
    printf("%c ",G->adjlist[v].name);
    p=G->adjlist[v].firstarc;
    while(p!=NULL)
    {
        if(visited[p->adjvex]==0){
            DFS(G,p->adjvex);
        }
        p=p->nextarc;
    }
}
void dfs(AGraph* G)
{
    int i,j;
    for(i=0;i<G->n;++i)
    {
        if(visited[i]==0){
            DFS(G,i);
            for(j=0;j<G->n;++j)
                visited[j]=0;
        }
        printf("\n");
    }
}

void BFS(AGraph* G,int v)
{
    int que[max_size],front=0,rear=0;
    int visited[max_size];
    int i,j;
    for(i=0;i<G->n;++i)
        visited[i]=0;
    rear=(rear+1)%max_size;
    que[rear]=v;
    printf("%c ",G->adjlist[v].name);
    visited[v]=1;
    ArcNode* p;
    while(front!=rear)
    {
        front=(front+1)%max_size;
        j=que[front];
        p=G->adjlist[j].firstarc;
        while(p!=NULL)
        {
            if(visited[p->adjvex]==0)
            {
                printf("%c ",G->adjlist[p->adjvex].name);
                visited[p->adjvex]=1;
                rear=(rear+1)%max_size;
                que[rear]=p->adjvex;
            }
            p=p->nextarc;
        }
    }
}

void bfs(AGraph* G)
{
    int i;
    for(i=0;i<G->n;++i){
        if(visited[i]==0)
            BFS(G,i);
        printf("\n");
    }
}

int main()
{
    AGraph* G=(AGraph*)malloc(sizeof(AGraph));
    CreateGraph(G);//Ϊ�����ִ��治���Ĵ��ݷ�ʽ���Ըı�G����������������������
    PrintGraph(G);

    printf("����������������\n");
    dfs(G);
    printf("\n");

    int i;
    for(i=0;i<G->n;++i)
        visited[i]=0;
    printf("����������������\n");
    bfs(G);

    return 0;
}

