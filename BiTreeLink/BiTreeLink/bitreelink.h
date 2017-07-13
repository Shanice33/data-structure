#include "string.h"
#include "stdio.h"    
#include "stdlib.h"   
#include "io.h"  
#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 100 /* �洢�ռ��ʼ������ */

typedef int Status;		/* Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK�� */
typedef char ElemType;
ElemType Nil=' '; /* �ַ����Կո��Ϊ�� */
int index=0;
ElemType str[MAXSIZE];

typedef struct BiTNode{
	ElemType data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

Status InitTree(BiTree *T){
	*T=(BiTree)malloc(sizeof(BiTNode));
	if(!(*T)) return ERROR;
	*T=NULL;
	return OK;
}

Status DestroyTree(BiTree *T){
	if(*T){
		if((*T)->lchild) DestroyTree(&(*T)->lchild);
		if((*T)->rchild) DestroyTree(&(*T)->rchild);
		free(*T);
		*T=NULL;
	}
	return OK;
}

Status CreateTree(BiTree *T){
	ElemType ch;
	//ch=str[index++];
	scanf("%c",&ch);
	if(ch=='#')
		*T=NULL;
	else{
		*T=(BiTree)malloc(sizeof(BiTNode));
		if(!(*T)) exit(OVERFLOW);
		(*T)->data=ch;
		CreateTree(&(*T)->lchild);
		CreateTree(&(*T)->rchild);
	}
	return OK;
}

#define ClearTree DestroyTree;

Status TreeEmpty(BiTree T){
	if(T==NULL) return TRUE;
	return FALSE;
}

int TreeDepth(BiTree T){
	int i,j;
	if(!T) return 0;
	if(T->lchild)
		i=TreeDepth(T->lchild);
	else
		i=0;
	if(T->rchild) 
		j=TreeDepth(T->rchild);
	else
		j=0;
	return (i>j)?i+1:j+1;
}
ElemType Root(BiTree T){
	if(TreeEmpty(T)) return Nil;
	return T->data;
}

ElemType Value(BiTree p){
	return p->data;
}

Status Assign(BiTree p,ElemType value){
	p->data=value;
	return OK;

}

void PreOrderTraverse(BiTree T)
{ 
	if(T==NULL)
		return;
	printf("%c",T->data);/* ��ʾ������ݣ����Ը���Ϊ�����Խ����� */
	PreOrderTraverse(T->lchild); /* ��������������� */
	PreOrderTraverse(T->rchild); /* ���������������� */
}

/* ��ʼ����: ������T���� */
/* �������: ����ݹ����T */
void InOrderTraverse(BiTree T)
{ 
	if(T==NULL)
		return;
	InOrderTraverse(T->lchild); /* ������������� */
	printf("%c",T->data);/* ��ʾ������ݣ����Ը���Ϊ�����Խ����� */
	InOrderTraverse(T->rchild); /* ���������������� */
}

/* ��ʼ����: ������T���� */
/* �������: ����ݹ����T */
void PostOrderTraverse(BiTree T)
{
	if(T==NULL)
		return;
	PostOrderTraverse(T->lchild); /* �Ⱥ������������  */
	PostOrderTraverse(T->rchild); /* �ٺ������������  */
	printf("%c",T->data);/* ��ʾ������ݣ����Ը���Ϊ�����Խ����� */
}
