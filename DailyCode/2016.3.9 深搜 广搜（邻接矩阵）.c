#include <stdio.h>
#include <stdlib.h>

#define max_s 100//卧槽 二维数组1000就会炸
#define INF 1000

typedef struct
{
    int no;
    char name;
} VertexType;

typedef struct
{
    int edge[max_s][max_s];
    int n,e;
    VertexType vex[max_s];
} MGraph;

void PrintMGraph(MGraph G)
{
    int i,j;
    for(i=0; i<G.n; ++i)
    {
        for(j=0; j<G.n; ++j)
            printf("%d ",G.edge[i][j]);
        printf("\n");
    }
}

//建立无向图的邻接矩阵
void CreatMGraph(MGraph* G)
{
    int i,j;
    printf("请输入顶点数和边数：\n");
    scanf("%d %d",&(*G).n,&(*G).e);
    printf("请输入每个顶点的代号字母：\n");
    for(i=0; i<(*G).n; ++i)
    {
        fflush(stdin);
        scanf("%c",&(*G).vex[i].name);
    }
    for(i=0; i<(*G).n; ++i)
        for(j=0; j<(*G).n; ++j)
            (*G).edge[i][j]=INF;
    int k,w;
    printf("请输入i j w：\n");
    for(k=0; k<(*G).e; ++k)
    {
        fflush(stdin);
        scanf("%d %d %d",&i,&j,&w);
        (*G).edge[i][j]=w;
        (*G).edge[j][i]=w;
    }
}

void DFS(MGraph G,int v,int visited[])
{
    printf("%c ",G.vex[v].name);
    visited[v]=1;
    int i;
    for(i=0;i<G.n;++i)
    {
        if(G.edge[v][i]<INF)
        {
          if(visited[i]==0)
          {
              DFS(G,i,visited);
          }
        }
    }
}

void dfs(MGraph G,int visited[])
{
    int i,j;
    for(i=0;i<G.n;++i){
        if(visited[i]==0){
            DFS(G,i,visited);
            for(j=0;j<G.n;++j)
                visited[j]=0;
        }
        printf("\n");
    }
}

void BFS(MGraph G,int v,int visited[])
{
    int i,j;
    for(i=0;i<G.n;++i)
        visited[i]=0;
    int que[max_s],front=0,rear=0;
    rear=(rear+1)%max_s;
    que[rear]=v;
    printf("%c ",G.vex[v].name);
    visited[v]=1;
    while(front!=rear)
    {
        front=(front+1)%max_s;
        j=que[front];
        for(i=0;i<G.n;++i)
        {
            if(G.edge[j][i]<INF)
            {
                if(visited[i]==0)
                {
                    rear=(rear+1)%max_s;
                    que[rear]=i;
                    printf("%c ",G.vex[i].name);
                    visited[i]=1;
                }
            }
        }
    }
}

void bfs(MGraph G,int visited[])
{
    int i,j;
    for(i=0;i<G.n;++i){
        if(visited[i]==0){
            BFS(G,i,visited);
            for(j=0;j<G.n;++j)
                visited[j]=0;
        }
        printf("\n");
    }
}

int main()
{
    MGraph G;
    CreatMGraph(&G);
    PrintMGraph(G);

    int visited[max_s],i;
    for(i=0;i<G.n;++i)
    {
        visited[i]=0;
    }

    dfs(G,visited);

    bfs(G,visited);

    return 0;
}
