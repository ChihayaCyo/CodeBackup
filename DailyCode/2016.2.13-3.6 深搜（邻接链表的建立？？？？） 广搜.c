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
    //初始化：
    printf("请输入顶点数和边数：\n");
    scanf("%d %d",&G->n,&G->e);

    //建立顶点表：
    int i;
    printf("请依次输入顶点名称：\n");
    for(i=0;i<G->n;++i)
    {
        fflush(stdin);  scanf("%c",&G->adjlist[i].name); //还有字符串要处理
        G->adjlist[i].firstarc=NULL;
    }

    //建立边表：（注意：此处区分无向图与有向图）
    int j,k;
    ArcNode* p;
    printf("请依次输入Vi<->Vj的顶点对序号：\n");
    for(k=0;k<G->e;++k)
    {
        scanf("%d %d",&i,&j);
        //头插法：
        p=(ArcNode*)malloc(sizeof(ArcNode));
        p->adjvex=j;//p是谁
        p->nextarc=G->adjlist[i].firstarc;//p的后面是谁
        G->adjlist[i].firstarc=p;//p的前面是谁
        p=(ArcNode*)malloc(sizeof(ArcNode));
        p->adjvex=i;
        p->nextarc=G->adjlist[j].firstarc;
        G->adjlist[j].firstarc=p;
        /*
        //尾插法：
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
    CreateGraph(G);//为何这种大逆不道的传递方式可以改变G？！！！！！！！！！！
    PrintGraph(G);

    printf("深度优先搜索结果：\n");
    dfs(G);
    printf("\n");

    int i;
    for(i=0;i<G->n;++i)
        visited[i]=0;
    printf("广度优先搜索结果：\n");
    bfs(G);

    return 0;
}

