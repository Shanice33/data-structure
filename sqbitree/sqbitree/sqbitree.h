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
#define MAX_TREE_SIZE 100 /* ��������������� */

typedef int Status;		/* Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK�� */
typedef int ElemType;  /* �������������ͣ�Ŀǰ�ݶ�Ϊ���� */
//typedef ElemType SqBiTree[MAX_TREE_SIZE]; /* 0�ŵ�Ԫ�洢�����  */

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