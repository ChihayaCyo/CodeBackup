#include <stdio.h>
#include <stdlib.h>


int main()
{
    int m,n,i,k;//m所在子树的节点数
    while((scanf("%d",&m)!=0)&&(scanf("%d",&n)!=0))
    {
        if(m==0&&n==0) return 0;
        int BTree[n+1];
        for(i=1;i<=n;i++)
        {
            BTree[i]=i;
        }
        k=m;
        int num=1;
        while(k>=1)
        {
            if(k%2==0)
                num++;
            else
                num=num+2;
            k=k/2;
        }
        printf("%d",num);
    }



    return 0;
}
