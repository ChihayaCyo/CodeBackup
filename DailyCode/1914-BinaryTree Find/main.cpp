#include <stdio.h>
#include<math.h>

void Print(int* BiTree,int layer,int n)
{
    if(n<pow(2,layer-1))
    {
        printf("EMPTY");
    }
    else
    {
        int i=0;
        for(i=pow(2,layer-1); (i<pow(2,layer)-1)&&(i<=n-1); i++)
        {
            printf("%d ",BiTree[i]);
        }
        printf("%d",BiTree[i]);
    }
    printf("\n");
}

int main()
{
    int n;
    scanf("%d",&n);
    do
    {
        int BiTree[1001];
        for(int i=0; i<n; i++)
        {
            scanf("%d",&BiTree[i+1]);
        }
        int layer;
        scanf("%d",&layer);
        Print(BiTree,layer,n);


        scanf("%d",&n);
    }
    while(n!=0);

    return 0;
}
