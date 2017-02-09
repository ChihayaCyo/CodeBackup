/*********************************
 *    ���ڣ�2013-3-7
 *    ���ߣ�SJF0115
 *    ���: ����OJ ��Ŀ1485: ��������洢�Ķ�����
 *    ��Դ��http://acmclub.com/problem.php?id=1485
 *    �����AC
 *    ��Դ�����ݽṹ�㷨��ѧ��
 *    �ܽ᣺
**********************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char array[101];

//���������
typedef struct BiTNode{
	char data;
	struct BiTNode *lchild,*rchild;
}BiTNode;

//���������д���������
int CreateBiTree(BiTNode *&T,int &index,int &n){
	if(index >= n){
		return 0;
	}
	//�������������������н���ֵ��һ���ַ������ո��ʾ����
	if(array[index] == ' '){
		T = NULL;
		index++;
	}
	else{
		T = (BiTNode*)malloc(sizeof(BiTNode));
		//���ɸ����
		T->data = array[index];
		index++;
		//����������
		CreateBiTree(T->lchild,index,n);
		//����������
		CreateBiTree(T->rchild,index,n);
	}
	return 0;
}
//���
void Visit(BiTNode* T){
	printf("%c ",T->data);
}
//�������
void PreOrder(BiTNode* T){
	if(T != NULL){
		//���ʸ��ڵ�
		Visit(T);
		//�������ӽ��
		PreOrder(T->lchild);
		//�������ӽ��
		PreOrder(T->rchild);
	}
}
//�������
void InOrder(BiTNode* T){
	if(T != NULL){
		//�������ӽ��
		InOrder(T->lchild);
		//���ʸ��ڵ�
		Visit(T);
		//�������ӽ��
		InOrder(T->rchild);
	}
}
//�������
void PostOrder(BiTNode* T){
	if(T != NULL){
		//�������ӽ��
		PostOrder(T->lchild);
		//�������ӽ��
		PostOrder(T->rchild);
		//���ʸ��ڵ�
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
		//����������
		CreateBiTree(T,index,len);
		//�������
		PreOrder(T);
		printf("\n");
		//�������
		index = 0;
		InOrder(T);
		printf("\n");
		//�������
		index = 0;
		InOrder(T);
		printf("\n");
	}
    return 0;
}

