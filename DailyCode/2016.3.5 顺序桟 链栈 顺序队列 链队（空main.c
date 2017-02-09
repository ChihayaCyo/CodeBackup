#include<stdio.h>
#include<stdlib.h>

#define max_s 450

//˳��C
typedef struct{
    int data[max_s];
    int top;
}SqStack;

//���C
typedef struct LNode{
    int data;
    struct LNode* next;
}LNode;

//˳�����
typedef struct{
    int data[max_s];
    int front;
    int rear;
}SqQueue;

//����
typedef struct QNode{
    int data;
    struct QNode* next;
}QNode;
typedef struct{
    QNode* front;
    QNode* rear;
}LiQueue;

//˳��C�Ļ�������
void initSqStack(SqStack* s)
{
    s->top=-1;
}
int isSqStackEmpty(SqStack s)
{
    if(s.top==-1)
        return 1;
    else
        return 0;
}
int pushSq(SqStack* s,int x)
{
    if(s->top==max_s-1)
        return 0;
    ++(s->top);
    s->data[s->top]=x;
    return 1;
}
int popSq(SqStack* s,int* x)
{
    if(s->top==-1)
        return 0;
    //return s.data[(s.top)--];
    *x=s->data[s->top];
    --(s->top);
    return 1;
}

//���C�Ļ�������
void initLinkStack(LNode** ls)
{
    *ls=(LNode*)malloc(sizeof(LNode));
    (*ls)->next=NULL;
}
int isLinkStackEmpty(LNode* ls)
{
    if(ls->next==NULL)
        return 1;
    else
        return 0;
}
void pushLink(LNode** ls,int x)
{
    LNode* s;
    s=(LNode*)malloc(sizeof(LNode));

    s->data=x;
    s->next=(*ls)->next;
    (*ls)->next=s;

}
int popLink(LNode** ls,int* x)
{
    if((*ls)->next==NULL)
        return 0;
    *x=(*ls)->next->data;

    LNode* p;
    p=(*ls)->next;
    (*ls)->next=p->next;
    free(p);
    return 1;
}

//ѭ��˳����еĻ�������
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
int enSqQueue(SqQueue* qu,int x)
{
    if((qu->rear+1)%max_s==qu->front)//����
        return 0;
    qu->rear=(qu->rear+1)%max_s;
    qu->data[qu->rear]=x;
    return 0;
}
int deSqQueue(SqQueue* qu,int* x)
{
    if(qu->front==qu->rear)
        return 0;
    qu->front=(qu->front+1)%max_s;//���еĵ�һ��Ԫ��Ҳ����ֵ
    *x=qu->data[qu->front];
    return 1;
}

//���ӵĻ�������
void initLinkQueue(LiQueue** lqu)
{
    *lqu=(LiQueue*)malloc(sizeof(LiQueue));
    (*lqu)->front=(*lqu)->rear=NULL;
}
int isLinkQueueEmpty(LiQueue* lqu)
{
    if(lqu->front==NULL||lqu->rear==NULL)
        return 1;
    else
        return 0;
}
void enLinkQueue(LiQueue** lqu,int x)
{
    QNode* p;
    p=(QNode*)malloc(sizeof(QNode));
    p->data=x;
    p->next=NULL;
    if((*lqu)->front==NULL)
        (*lqu)->front=(*lqu)->rear=p;
    else{
        (*lqu)->rear->next=p;
        (*lqu)->rear=p;
    }
}
int deLinkQueue(LiQueue** lqu,int *x)
{
    if((*lqu)->rear==NULL)  return 0;
    *x=(*lqu)->front->data;
    QNode* p;
    p=(*lqu)->front;
    if((*lqu)->front==(*lqu)->rear)
        (*lqu)->front=(*lqu)->rear=NULL;
    else
        (*lqu)->front=(*lqu)->front->next;
    free(p);
    return 1;
}

int main()
{


    return 0;
}







