#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define max_s 450

typedef struct BTNode{
    int key;
    struct BTNode* lchlid;
    struct BTNode* rchild;
}BTNode;

void CreatNumber(int key[],int n)
{
    int i;
    srand(time(NULL));
    for(i=0;i<n;++i)
    {
        key[i]=rand()%99+1;
    }
}

void TestPrint(int key[],int n)
{
    int i;
    for(i=0;i<n;++i)
    {
        printf("%d ",key[i]);
    }
}

BTNode* BSTSearch(BTNode* bst,int key)
{
    if(bst==NULL){
        bst=(BTNode*)malloc(sizeof(BTNode));
        bst->key=-1;
        return bst;
    }
    else
    {
        if(bst->key==key)
            return bst;
        else if(key<bst->key)
            return BSTSearch(bst->lchild,key);
        else
            return BSTSearch(bst->rchild,key);
    }
}

void BSTInsert(BTNode** bst,int key)
{
    if(bst==NULL)
    {
        *bst=(BTNode*)malloc(sizeof(BTNode));
        (*bst)->key=key;
        (*bst)->lchlid=(*bst)->rchild=NULL;
    }
    else
    {
        if((*bst)->key==key)
            return;
        else if(key<(*bst)->key)
            BSTInsert((&(*bst)->lchlid),key);
        else
            BSTInsert(&((*bst)->rchild),key);
    }
}

void CreatBST(BTNode** bst,int key[],int n)
{
    int i;
    bst=NULL;
    for(i=0;i<n;++i)
        BSTInsert(bst,key[i]);
}

int main()
{
    int key[max_s],n;
    printf("请输入要二叉排序的点的个数n(1<=n<=99)：");
    scanf("%d",&n);
    CreatNumber(key,n);
    TestPrint(key,n);

    BTNode* bst;
    CreatBST(&bst,key,n);
    BTNode* retnode;
    int xkey;
    printf("请输入要查找的数(1-99)：");
    scanf("%d",&xkey);
    retnode=BSTSearch(bst,xkey);
    printf("二叉搜索树搜索结果：retnode->key=%d",retnode->key);

    return 0;
}
