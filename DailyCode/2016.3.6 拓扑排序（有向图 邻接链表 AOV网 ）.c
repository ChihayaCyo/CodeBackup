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
        G->adjlist[i].count=0;
    }

    //建立边表：（注意：此处区分无向图与有向图）
    int j,k;
    ArcNode* p;
    printf("请依次输入Vi<->Vj的顶点对序号：\n");
    for(k=0;k<G->e;++k)
    {
        scanf("%d %d",&i,&j);
        //头插法：i->j
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

