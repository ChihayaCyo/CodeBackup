#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define max_s 450

void createNum(int R[],int n)
{
    int i;
    srand(time(NULL));
    for(i=0;i<n;++i)
    {
        R[i]=rand()%99+0;
    }
}

void print(int R[],int n)
{
    int i;
    for(i=0;i<n;++i)
    {
        printf("%d ",R[i]);
    }
    printf("\n");
}

int Bsearch(int R[],int low,int high,int k)
{
    int mid;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(R[mid]==k)
            return mid;
        else if(R[mid]<k)
            low=mid+1;
        else
            high=mid-1;
    }
    return -1;
}

void QuickSort(int R[],int l,int r)
{

}

int main()
{
    int R[max_s],n;
    printf("请输入要生成的随机数个数：");
    scanf("%d",&n);
    createNum(R,n);
    print(R,n);

    QuickSort(R,n);
    print(R,n);

    int k;
    printf("请输入要查找的数：");
    scanf("%d",&k);
    int ret;
    ret=Bsearch(R,0,n-1,k);
    printf("%d",ret);

    return 0;
}
