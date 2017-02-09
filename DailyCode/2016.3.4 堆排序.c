#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define max_s 450

void CreatNumber(int R[],int n)
{
    int i;
    srand(time(NULL));
    for(i=1;i<=n;++i)
    {
        R[i]=rand()%99+1;
    }
    R[0]=n;
}

void TestPrint(int R[],int n)
{
    int i;
    for(i=1;i<=n;++i)
    {
        printf("%d ",R[i]);
    }
}

void swap_(int* a,int* b)//��Ȼ�������д�� ��Ȼָ�붼�ò�����
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

void HeapAdjust(int R[],int i,int n)
{
    int lchild=i*2;
    int rchild=i*2+1;
    int max=i;
    if(i<=n/2)
    {
        if(lchild<=n&&R[lchild]>R[max])
        {
            max=lchild;
        }
        if(rchild<=n&&R[rchild]>R[max])
        {
            max=rchild;
        }
        if(max!=i)
        {
            swap_(&R[i],&R[max]);
            HeapAdjust(R,max,n);
        }
    }
}

void HeapSort(int R[],int n)
{
    int i;
    for(i=n/2;i>=1;i--)
    {
        HeapAdjust(R,i,n);
    }
    for(i=n;i>=1;--i)
    {
        //printf("%d ",R[1]);
        swap_(&R[1],&R[i]);
        HeapAdjust(R,1,i-1);
    }
}

int main()
{

    int R[max_s],n;
    printf("������Ҫ��������ĵ�ĸ���n(1<=n<=449)��");
    scanf("%d",&n);
    CreatNumber(R,n);
    printf("�������������Ϊ��");
    TestPrint(R,n);
    printf("\n");

    //int R[7]={-1,16,7,3,20,17,8};
    printf("��������Ϊ��");
    HeapSort(R,n);
    int i;
    for(i=1;i<=n;++i)
        printf("%d ",R[i]);

    return 0;
}
