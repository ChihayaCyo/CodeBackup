#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
���룺n������С�������У���n������С��0-999֮�䡣��100<=n<=999��
�������С����˳�������n����
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
Bubble������forѭ������ʱ��ֻ��Ҫ�����ͷ
���ѵ�һ��for�������С�������ڶ���for�м����Ƿ����
����������ѭ����һ����ֻ������ͷ
*/
void BubbleSort(int n,int R[])
{
    int i=0,j=0,flag=0;
    for(i=1;i<=n;++i)
    {
        flag=0;//0�������ð��û���ƶ�����
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
QuickSort��һ���ݹ�����㷨���������������������ݹ��DFS��BFSһ���ĵݹ��㷨
��ס�ݹ�
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
             while(i<j&&R[j]>=temp)  --j;//--jֱ��R[j]<temp��λ�ã����佻����temp����
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
    printf("������n�Ĵ�С�� ");
    scanf("%d",&n);

    int R[n];
    CreatNumber(n,R);
    printf("�����������Ϊ��\n");
    TestPrint(n,R);
/*
    BubbleSort(n,R);
    printf("Bubble��������\n");
    TestPrint(n,R);
*/
    QuickSort(R,0,n-1);
    printf("Quick��������\n");
    TestPrint(n,R);

    return 0;
}

/*
���е��� ��дBubble�����ϰ��srRnd��û������
*/
