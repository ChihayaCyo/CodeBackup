#include <stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct BTNode
{
    char data;
    struct BTNode* lchild;
    struct BTNode* rchild;
} BTNode;

char preOrder[101];

void CreatTree(BTNode* &p,int len,int &index)
{
    if(index>len)
        return;
    if(preOrder[index]=='#')
    {
        p=NULL;
        index++;
    }
    else
    {
        p=(BTNode*)malloc(sizeof(BTNode));
        p->data=preOrder[index];
        index++;
        CreatTree(p->lchild,len,index);
        CreatTree(p->rchild,len,index);
    }
}

void InOrderTran(BTNode* p)
{
    if(p!=NULL)
    {
        InOrderTran(p->lchild);
        printf("%c ",p->data);
        InOrderTran(p->rchild);
    }
}

int main()
{
    while(gets(preOrder))
    {
        int index=0;
        int len=strlen(preOrder);
        BTNode* p;
        CreatTree(p,len,index);
        InOrderTran(p);
        printf("\n");
    }


    return 0;
}
