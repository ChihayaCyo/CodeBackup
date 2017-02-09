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

//����������
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
    printf("�������������\n");
    T=creatBiTree();
    //inOrder(T);

    creatInThread(T);
    inOrderThread(T);

    return 0;
}

/*
�������ı����������ǽ�һ�����ӵķ����Խṹת��Ϊ���Խṹ
ʹÿ����㶼����Ψһǰ���ͺ�̣���һ�������ǰ�������һ������޺�̣�
���ڶ�������һ����㣬������������Ů�Ƿ���ģ���ǰ�����ֻ���ڱ����еõ�
�������������ŵ��Ǳ����������²���ǰ�����ͺ�̽��
*/
