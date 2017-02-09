#include<stdio.h>
#include<stdlib.h>//给节点分配地址空间
#include<string.h>//使用gets读入字符数组


typedef struct BTNode{
    char data;
    struct BTNode* lchild;
    struct BTNode* rchild;
}BTNode;

int CreatTree(BTNode* &p,int &index,char array[],int &len)
{
    if(index>=len)
        return 0;

    if(array[index]==' '){
        p=NULL;
        index++;
    }
    else{
        p=(BTNode*)malloc(sizeof(BTNode));
        p->data=array[index];
        index++;
        CreatTree(p->lchild,index,array,len);
        CreatTree(p->rchild,index,array,len);
    }
    return 0;
}

void PreOrder(BTNode* p)
{
    if(p!=NULL){
        printf("%c ",p->data);
        PreOrder(p->lchild);
        PreOrder(p->rchild);
    }
}

void InOrder(BTNode* p)
{
    if(p!=NULL){
        InOrder(p->lchild);
        printf("%c ",p->data);
        InOrder(p->rchild);
    }
}

int main()
{
    char array[100];
    int index=0;
    while(gets(array))
    {
        BTNode* p;
        int len=strlen(array);
        CreatTree(p,index,array,len);
        PreOrder(p);
        printf("\n");
        InOrder(p);
        printf("\n");
        InOrder(p);
    }

    return 0;
}
