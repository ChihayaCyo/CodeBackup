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
            printf("%8d ",G.edge[i][j]);
        printf("\n");
    }
}

//建立(无)(有)向图的邻接矩阵
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
        (*G).edge[j][i]=w;//Prim和Kruskal算法都是针对无向图的
    }
}

void Prim(MGraph G,int v,int* sum)
{
    int i,j,min,u;
    int lowcost[max_size],vset[max_size];
    (*sum)=0;
    for(i=0;i<G.n;++i)
    {
        lowcost[i]=G.edge[v][i];
        vset[i]=0;
    }
    vset[v]=1;

    for(i=0;i<G.n;++i)
    {
        min=INF;
        for(j=0;j<G.n;++j)
        {
            if(vset[j]==0&&lowcost[j]<min){
                min=lowcost[j];
                u=j;
            }
        }
        vset[u]=1;
        (*sum)+=min;
        for(j=0;j<G.n;++j)
        {
            if(vset[j]==0&&G.edge[u][j]<lowcost[j]){
                lowcost[j]=G.edge[u][j];
            }
        }
    }

    printf("产生的最小生成树为：\n");

    printf("这棵最小生成树的权值为：%d\n",(*sum));
}

int main()
{
    MGraph G;
    CreatMGraph(&G);
    printf("建立的邻接矩阵为：\n");
    PrintMGraph(G);

    int sum=0,v;
    printf("请输入起点v：\n");
    scanf("%d",&v);
    Prim(G,v,&sum);

    return 0;
}


