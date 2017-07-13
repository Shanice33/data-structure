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

#define MAXSIZE 100 /* 存储空间初始分配量 */

typedef int Status;		/* Status是函数的类型,其值是函数结果状态代码，如OK等 */
typedef char ElemType;
ElemType Nil=' '; /* 字符型以空格符为空 */
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
	printf("%c",T->data);/* 显示结点数据，可以更改为其它对结点操作 */
	PreOrderTraverse(T->lchild); /* 再先序遍历左子树 */
	PreOrderTraverse(T->rchild); /* 最后先序遍历右子树 */
}

/* 初始条件: 二叉树T存在 */
/* 操作结果: 中序递归遍历T */
void InOrderTraverse(BiTree T)
{ 
	if(T==NULL)
		return;
	InOrderTraverse(T->lchild); /* 中序遍历左子树 */
	printf("%c",T->data);/* 显示结点数据，可以更改为其它对结点操作 */
	InOrderTraverse(T->rchild); /* 最后中序遍历右子树 */
}

/* 初始条件: 二叉树T存在 */
/* 操作结果: 后序递归遍历T */
void PostOrderTraverse(BiTree T)
{
	if(T==NULL)
		return;
	PostOrderTraverse(T->lchild); /* 先后序遍历左子树  */
	PostOrderTraverse(T->rchild); /* 再后序遍历右子树  */
	printf("%c",T->data);/* 显示结点数据，可以更改为其它对结点操作 */
}
