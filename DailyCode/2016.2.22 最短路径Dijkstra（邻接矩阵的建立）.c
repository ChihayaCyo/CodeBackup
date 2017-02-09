#include <stdio.h>
#include <stdlib.h>

#define max_size 100//卧槽 二维数组1000就会炸
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
    printf("请输入顶点代号，建立顶点表：\n");
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

void printPath(int path[],int a)
{
    int stack[max_size];
    int top=-1;
    while(path[a]!=-1)
    {
        stack[++top]=a;
        a=path[a];
    }
    stack[++top]=a;
    while(top!=-1)
        printf("%d ",stack[top--]);
    printf("\n");
}

void Dijkstra(MGraph G,int v,int dist[],int path[])
{
    /*初始化*/
    int i,j,min,u;
    int set[max_size];
    for(i=0; i<G.n; ++i)
    {
        set[i]=0;
        dist[i]=G.edge[v][i];
        if(G.edge[v][i]<INF)
            path[i]=v;
        else
            path[i]=-1;
    }
    set[v]=1;
    path[v]=-1;//多余的一句

    /*找最小的dist、更新dist和path*/
    for(i=0; i<G.n; ++i)
    {
        min=INF;
        for(j=0; j<G.n; ++j)
            if(set[j]==0&&dist[j]<min)
            {
                min=dist[j];
                u=j;
            }
        set[u]=1;
        for(j=0; j<G.n; ++j)
        {
            if(set[j]==0&&dist[u]+G.edge[u][j]<dist[j])
            {
                dist[j]=dist[u]+G.edge[u][j];
                path[j]=u;
            }
        }
    }

    for(i=0;i<G.n;++i)
    {
        if(i!=v){
            printf("从%d点到%d点最短路径长度为: ",v,i);
            printf("%d\n",dist[i]);
            printf("路径为: ");
            printPath(path,i);
        }
    }
}

int main()
{
    MGraph G;
    CreatMGraph(&G);
    PrintMGraph(G);

    int v;
    printf("请输入要查询的点：\n");
    scanf("%d",&v);
    int dist[max_size];
    int path[max_size];
    Dijkstra(G,v,dist,path);

    return 0;
}


