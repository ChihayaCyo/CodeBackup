#include <stdio.h>
#include <stdlib.h>

typedef struct TBTNode{
    char data;
    struct TBTNode* lchild;
    struct TBTNode* rchild;
    int ltag;
    int rtag;
}TBTNode;

TBTNode* creatBiTree()
{
    TBTNode* T=(TBTNode*)malloc(sizeof(TBTNode));
    char ch;
    scanf("%c",&ch);
    if(ch=='#') T=NULL;
    else{
        T->data=ch;
        T->lchild=creatBiTree();
        T->rchild=creatBiTree();
    }
    return T;
}

void inOrder(TBTNode* T)
{
    if(T!=NULL)
    {
        printf("%c ",T->data);
        inOrder(T->lchild);
        inOrder(T->rchild);
    }
}

//中序线索化
TBTNode* pre=NULL;
void inThreading(TBTNode* p)
{
    if(p!=NULL)
    {
        inThreading(p->lchild);
        if(p->lchild==NULL){
            p->ltag=1;
            p->lchild=pre;
        }
        if(pre!=NULL&&pre->rchild==NULL){
            pre->rtag=1;
            pre->rchild=p;
        }
        pre=p; //?
        inThreading(p->rchild);

    }
}

void creatInThread(TBTNode* root)
{
    //TBTNode* pre=NULL;
    if(root!=NULL)
    {
        inThreading(root);
        pre->rchild=NULL;
        pre->rtag=1;
    }
}

TBTNode* First(TBTNode* p)
{
    while(p->ltag==0)
        p=p->lchild;
    return p;
}

TBTNode* Next(TBTNode* p)
{
     if(p->rtag==0)
        p=First(p->rchild);
     else
        p=p->rchild;
     return p;
}

void inOrderThread(TBTNode* root)
{
    TBTNode* p;
    for(p=First(root);p!=NULL;p=Next(p))
    {
        printf("%c ",p->data);//visit(p);
    }
}

int main()
{
    TBTNode* T;
    printf("请输入二叉树：\n");
    T=creatBiTree();
    //inOrder(T);

    creatInThread(T);
    inOrderThread(T);

    return 0;
}

/*
二叉树的遍历本质上是将一个复杂的非线性结构转换为线性结构
使每个结点都有了唯一前驱和后继（第一个结点无前驱，最后一个结点无后继）
对于二叉树的一个结点，查找其左右子女是方便的，其前驱后继只有在遍历中得到
线索二叉树的优点是便于在中序下查找前驱结点和后继结点
*/
