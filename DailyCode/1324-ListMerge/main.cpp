#include <stdio.h>
#define maxsize 202

typedef struct{
    int data[maxsize];
    int length;
}Sqlist;

void Init(Sqlist &L)
{
    L.length=-1;
    for(int i=0;i<=maxsize-1;++i)
        L.data[i]=-1;
}

void Sort(Sqlist &L)//
{
    for(int i=1;i<=L.length-1;++i){
        for(int j=i+1;j<=L.length;++j){//每次循环找到放在这个位置的最小值（与冒泡排序的示意图有出入）
            if(L.data[i]>L.data[j]){
                int temp=L.data[j];
                L.data[j]=L.data[i];
                L.data[i]=temp;
            }
        }
    }

}

void Read(Sqlist &L)
{
    scanf("%d",&L.length);
    for(int i=1;i<=L.length;++i){
        scanf("%d",&L.data[i]);
    }
    Sort(L);
}

void Mergelist(Sqlist La,Sqlist Lb,Sqlist &Lc)
{
    int i=1;int j=1;int k=1;
    while(i<=La.length&&j<=Lb.length){
        if(La.data[i]<Lb.data[j]){
            Lc.data[k]=La.data[i];
            ++k;++i;
        }
        else{
            Lc.data[k]=Lb.data[j];
            ++k;++j;
        }
    }
    if(i<=La.length){
        for(;i<=La.length;++i,++k){
            Lc.data[k]=La.data[i];
        }
    }
    if(j<=Lb.length){
        for(;j<=Lb.length;++j,++k){
            Lc.data[k]=Lb.data[j];
        }
    }
    Lc.length=k-1;
}

void Print(Sqlist Lc)
{
    for(int i=1;i<=Lc.length;++i){
        printf("%d ",Lc.data[i]);
    }
}

int main()
{
    Sqlist La;Sqlist Lb;Sqlist Lc;
    Init(La);Init(Lb);Init(Lc);
    Read(La);Read(Lb);
    Mergelist(La,Lb,Lc);
    Print(Lc);

    return 0;
}
