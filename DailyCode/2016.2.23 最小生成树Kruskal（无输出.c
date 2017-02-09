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

typedef struct{
    int a,b;
    int w;
}Road;

Road road[max_size];
int v[max_size];

int getRoot(int a)
{
    while(a!=v[a])
        a=v[a];
    return a;
}

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
        (*G).edge[j][i]=w;
        road[k].a=i;
        road[k].b=j;
        road[k].w=w;
    }
}

void BubbleSort(Road road[],int n)
{
    int i,j,flag;
    for(i=1;i<=n;++i){
        flag=0;
        for(j=n;j>=i;--j){
                if(road[j].w<road[j-1].w){
                    Road temp=road[j];
                    road[j]=road[j-1];
                    road[j-1]=temp;
                    flag=1;
                }
        }
        if(flag==0)
            return;
    }
}

void QuickSort(Road road[],int l,int r)
{
    Road temp=road[l];
    int i=l,j=r;
    if(l<r)
    {
        while(i!=j)
        {
            while(i<j&&temp.w<road[j].w)
                --j;
            if(i<j)
                road[i]=road[j];
            ++i;

            while(i<j&&road[i].w<temp.w)
                ++i;
            if(i<j)
                road[j]=road[i];
            --j;
        }
        road[i]=temp;
        QuickSort(road,l,i-1);
        QuickSort(road,i+1,r);
    }
}

void Kruskal(MGraph G,int* sum)
{
    int i;
    for(i=0;i<G.n;++i)
        v[i]=i;

    //BubbleSort(road,G.e);
    QuickSort(road,0,G.e-1);

    int a,b;
    (*sum)=0;
    for(i=0;i<G.e;++i){
        a=getRoot(road[i].a);
        b=getRoot(road[i].b);
        if(a!=b){
            v[b]=a;
            if(road[i].w<INF)
                (*sum)+=road[i].w;
        }
    }

    printf("Kruskal算法生成的最小生成树为：\n");

    printf("这棵最小生成树的权值为：%d\n",(*sum));
}

int main()
{
    MGraph G;
    CreatMGraph(&G);
    printf("建立的邻接矩阵为：\n");
    PrintMGraph(G);

    int sum=0;
    Kruskal(G,&sum);

    return 0;
}


