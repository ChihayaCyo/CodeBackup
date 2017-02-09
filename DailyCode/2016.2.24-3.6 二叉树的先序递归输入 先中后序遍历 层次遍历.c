#include <stdio.h>
#include <stdlib.h>

#define max_s 450

typedef struct BiTNode{
    char data;
    struct BiTNode* lchild;
    struct BiTNode* rchild;
}BiTNode,*BiTree;

typedef struct{
    BiTNode* node[max_s];
    int front;
    int rear;
}SqQueue;
void initSqQueue(SqQueue* qu)
{
    qu->front=qu->rear=0;
}
int isSqQueueEmpty(SqQueue qu)
{
    if(qu.front==qu.rear)
        return 1;
    else
        return 0;
}
int enSqQueue(SqQueue* qu,BiTNode* q)
{
    if((qu->rear+1)%max_s==qu->front)
        return 0;
    qu->rear=(qu->rear+1)%max_s;
    qu->node[qu->rear]=q;
    return 1;
}
int deSqQueue(SqQueue* qu,BiTNode** q)
{
    if(qu->front==qu->rear)
        return 0;
    qu->front=(qu->front+1)%max_s;
    *q=qu->node[qu->front];
    return 1;
}

/*
void creatBiTree(BiTNode* T)
{
    char c;
    scanf("%c",&c);
    if(c=='#')  T=NULL;
    else{
        T=(BiTNode*)malloc(sizeof(BiTNode));
        T->data=c;
        creatBiTree(T->lchild);
        creatBiTree(T->rchild);
    }
}
*/

BiTNode* creatBiTree()
{
    BiTNode* T;
    char ch;
    scanf("%c",&ch);
    if(ch=='#') T=NULL;
    else{
        T=(BiTNode*)malloc(sizeof(BiTNode));
        T->data=ch;
        T->lchild=creatBiTree();
        T->rchild=creatBiTree();
    }
    return T;
}

void preOrder(BiTNode* T)
{
    if(T!=NULL)
    {
        printf("%c ",T->data);
        preOrder(T->lchild);
        preOrder(T->rchild);
    }
}

void inOrder(BiTNode* T)
{
    if(T!=NULL)
    {
        preOrder(T->lchild);
        printf("%c ",T->data);
        preOrder(T->rchild);
    }
}

void postOrder(BiTNode* T)
{
    if(T!=NULL)
    {
        preOrder(T->lchild);
        preOrder(T->rchild);
        printf("%c ",T->data);
    }
}

void levelOrder(BiTNode* T)//使用顺序循环队列  
{
    SqQueue qu;
    initSqQueue(&qu);
    BiTNode* q;
    if(T!=NULL)
    {
        enSqQueue(&qu,T);//其实不用函数才更简单 入队出队都两句话而已 C的函数传参太难 
        while(isSqQueueEmpty(qu)!=1)
        {
            deSqQueue(&qu,&q);
            printf("%c ",q->data);
            if(q->lchild!=NULL)
                enSqQueue(&qu,q->lchild);
            if(q->rchild!=NULL)
                enSqQueue(&qu,q->rchild);
        }
    }
}

int main()
{
    BiTNode* T;
    //BiTree T;
    printf("请先序输入二叉树（用#将其填充成完全二叉树再先序输入）：\n");
    T=creatBiTree();

    preOrder(T);
    printf("\n");
    inOrder(T);
    printf("\n");
    postOrder(T);
    printf("\n");

    levelOrder(T);

    return 0;
}

/*
                    a
            b                   c
        #        d          #       e
              #     #             #    #

在输入的时候，需要输入: ab#d##c#e##
*/
