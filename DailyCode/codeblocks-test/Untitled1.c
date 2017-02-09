/*********************************
 *    日期：2013-3-7
 *    作者：SJF0115
 *    题号: 天勤OJ 题目1485: 二叉链表存储的二叉树
 *    来源：http://acmclub.com/problem.php?id=1485
 *    结果：AC
 *    来源：数据结构算法教学题
 *    总结：
**********************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char array[101];

//二叉树结点
typedef struct BiTNode{
	char data;
	struct BiTNode *lchild,*rchild;
}BiTNode;

//按先序序列创建二叉树
int CreateBiTree(BiTNode *&T,int &index,int &n){
	if(index >= n){
		return 0;
	}
	//按先序次序输入二叉树中结点的值（一个字符），空格表示空树
	if(array[index] == ' '){
		T = NULL;
		index++;
	}
	else{
		T = (BiTNode*)malloc(sizeof(BiTNode));
		//生成根结点
		T->data = array[index];
		index++;
		//构造左子树
		CreateBiTree(T->lchild,index,n);
		//构造右子树
		CreateBiTree(T->rchild,index,n);
	}
	return 0;
}
//输出
void Visit(BiTNode* T){
	printf("%c ",T->data);
}
//先序遍历
void PreOrder(BiTNode* T){
	if(T != NULL){
		//访问根节点
		Visit(T);
		//访问左子结点
		PreOrder(T->lchild);
		//访问右子结点
		PreOrder(T->rchild);
	}
}
//中序遍历
void InOrder(BiTNode* T){
	if(T != NULL){
		//访问左子结点
		InOrder(T->lchild);
		//访问根节点
		Visit(T);
		//访问右子结点
		InOrder(T->rchild);
	}
}
//后序遍历
void PostOrder(BiTNode* T){
	if(T != NULL){
		//访问左子结点
		PostOrder(T->lchild);
		//访问右子结点
		PostOrder(T->rchild);
		//访问根节点
		Visit(T);
	}
}
int main()
{
	int len,index;
	while(gets(array)){
		BiTNode* T;
		len = strlen(array);
		index = 0;
		//创建二叉树
		CreateBiTree(T,index,len);
		//先序遍历
		PreOrder(T);
		printf("\n");
		//中序遍历
		index = 0;
		InOrder(T);
		printf("\n");
		//中序遍历
		index = 0;
		InOrder(T);
		printf("\n");
	}
    return 0;
}

