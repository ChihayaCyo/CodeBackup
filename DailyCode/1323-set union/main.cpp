#include <stdio.h>

#define MAXSIZE 202

typedef struct
{
    int data[MAXSIZE];
    int length;
}Sqlist;

void Intlist(Sqlist &L)
{
    L.length=0;
    for(int i=0;i<=MAXSIZE-1;i++)
        L.data[i]=0;
}

void Read(Sqlist &L)
{
    //scanf("%d",&L.length);
    for(int i=1;i<=L.length;i++)
        scanf("%d",&L.data[i]);
}

void Print(Sqlist L)
{
    printf("%d",L.data[1]);
    for(int k=2;k<=L.length;k++)
    {
        printf(" %d",L.data[k]);
    }
    printf("\n");
}

void Union(Sqlist &A,Sqlist B)
{
    Print(A);
    Print(B);
    int flag=0;//same==1 different==0
    for(int i=1;i<=B.length;i++)
    {
        flag=0;
        for(int j=1;j<=A.length;j++)
        {
            if(A.data[j]==B.data[i])
                flag=1;
        }
        if(flag==0)
        {
            A.data[A.length+1]=B.data[i];
            A.length++;
        }
        Print(A);
    }
}

int main()
{
    Sqlist A,B;
    int m;
    while(scanf("%d",&m)!=EOF){
    Intlist(A);
    Intlist(B);
    //scanf("%d",&A.length);
    A.length=m;
    Read(A);
    scanf("%d",&B.length);
    Read(B);
    Union(A,B);
    }
    return 0;
}
