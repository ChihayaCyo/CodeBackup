#include <stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct BTNode{
    char data;
    struct BTNode* lchild,* rchild;
}BTNode;

void CreatTree(BTNode* &p,char* InOrder,char* PreOrder,int length)
{
    if(length==0)
        return;
    p=(BTNode*)malloc(sizeof(BTNode));
    p->data=*PreOrder;
    int rootIndex=0;
    for(;rootIndex<length;rootIndex++)
    {
        if(InOrder[rootIndex]==*PreOrder){
            break;
        }
    }
    //left
    CreatTree(p->lchild,InOrder,PreOrder+1,rootIndex);//??
    //right
    CreatTree(p->rchild,InOrder+rootIndex+1,PreOrder+rootIndex+1,length-(rootIndex+1));//?
}



void PostOrder(BTNode* p)
{
    if(p!=NULL){
        PostOrder(p->lchild);
        PostOrder(p->rchild);
        printf("%c ",p->data);
    }
}

int main()
{
    char PreOrder[26];
    char InOrder[26];
    int length;
    while((gets(PreOrder)!=NULL)&&(gets(InOrder)!=NULL))
    {
        length=strlen(PreOrder);
        BTNode* p;
        CreatTree(p,InOrder,PreOrder,length);
        PostOrder(p);
    }


    return 0;
}
