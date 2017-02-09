#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
输入：n个数大小乱序排列，这n个数大小在0-999之间。（100<=n<=999）
输出：从小到大顺序输出这n个数
*/

void CreatNumber(int n,int R[])
{
    int i;
    srand(time(NULL));
    for(i=0;i<n;++i)
    {
        R[i]=rand()%999+0;
    }
}

/*
Bubble的两个for循环检查的时候只需要检查两头
即把第一个for的最大最小情况代入第二个for中检验是否合理
其他程序检查循环都一样，只需检查两头
*/
void BubbleSort(int n,int R[])
{
    int i=0,j=0,flag=0;
    for(i=1;i<=n;++i)
    {
        flag=0;//0代表这次冒泡没有移动发生
        for(j=n;j>=i;--j)
        {
            if(R[j]<R[j-1])
            {
                int temp=0;
                temp=R[j-1];
                R[j-1]=R[j];
                R[j]=temp;
                flag=1;
            }
        }
        if(flag==0) return;
    }
}

/*
QuickSort是一个递归调用算法，和先序中序后序遍历、递归地DFS、BFS一样的递归算法
记住递归
*/
void QuickSort(int R[],int l,int r)
{
     int temp;
     int i=l,j=r;
     if(l<r)
     {
         temp=R[l];
         while(i!=j)
         {
             while(i<j&&R[j]>=temp)  --j;//--j直到R[j]<temp的位置，将其交换到temp左面
             if(i<j){
                R[i]=R[j];
                ++i;
             }

             while(i<j&&R[i]<=temp)  ++i;
             if(i<j){
                R[j]=R[i];
                --j;
             }
         }
         R[i]=temp;
         QuickSort(R,l,i-1);
         QuickSort(R,i+1,r);
     }
}

void TestPrint(int n,int R[])
{
    int i;
    for(i=0;i<n;++i)
    {
        printf("%d\n",R[i]);
    }
}

int main()
{
    int n;
    printf("请输入n的大小： ");
    scanf("%d",&n);

    int R[n];
    CreatNumber(n,R);
    printf("产生的随机数为：\n");
    TestPrint(n,R);
/*
    BubbleSort(n,R);
    printf("Bubble排序结果：\n");
    TestPrint(n,R);
*/
    QuickSort(R,0,n-1);
    printf("Quick排序结果：\n");
    TestPrint(n,R);

    return 0;
}

/*
常有的事 想写Bubble结果复习完srRnd就没力气了
*/
