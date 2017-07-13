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
#define MAX_TREE_SIZE 100 /* 二叉树的最大结点数 */

typedef int Status;		/* Status是函数的类型,其值是函数结果状态代码，如OK等 */
typedef int ElemType;  /* 树结点的数据类型，目前暂定为整型 */
//typedef ElemType SqBiTree[MAX_TREE_SIZE]; /* 0号单元存储根结点  */

typedef struct {
	ElemType data[MAXSIZE];
	int length;
}SqBiTree;

Status InitTree(SqBiTree *T){
	T->length=0;
	return OK;
}

Status ClearTree(SqBiTree *T){
	T->length=0;
	return OK;
}

Status CreateTree(SqBiTree *T){
	int i;
	for()
}