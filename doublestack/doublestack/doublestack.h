#include "stdio.h"    
#include "stdlib.h"   
#include "io.h"  
#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20 /* 存储空间初始分配量 */

typedef int Status; 
typedef int ElemType; 

typedef struct{
	ElemType data[MAXSIZE];
	int top1;
	int top2;
}DoubleStack;

Status InitStack(DoubleStack *S){
	S->top1=-1;
	S->top2=MAXSIZE;
	return OK;
}

Status ClearStack(DoubleStack *S){
	S->top1=-1;
	S->top2=MAXSIZE;
	return OK;
}

Status StackEmpty(DoubleStack S){
	if(S.top1==-1 && S.top2==MAXSIZE)
		return TRUE;
	return FALSE;
}

Status GetTop(DoubleStack S,ElemType *e,int t){
	if(StackEmpty(S)||(t!=1 && t!=2)) return ERROR;
	if(t==1)
		*e=S.data[S.top1];
	if(t==2)
		*e=S.data[S.top2];
	return OK;
}

Status Push(DoubleStack *S,ElemType e,int t){
	if(S->top1+1==S->top2 || (t!=1 && t!=2)) return ERROR;
	if(t==1){
		S->top1++;
		S->data[S->top1]=e;
	}
	if(t==2){
		S->top2--;
		S->data[S->top2]=e;
	}
	return OK;
	
}

Status Pop(DoubleStack *S,ElemType *e,int t){
	if(t!=1 && t!=2) return ERROR;
	if(t==1){
		if(S->top1==-1) return ERROR;
		*e=S->data[S->top1];
		S->top1--;
	}
	if(t==2){
		if(S->top2==MAXSIZE) return ERROR;
		*e=S->data[S->top2];
		S->top2++;
	}
	return OK;
}

int StackLength(DoubleStack S){
	return (MAXSIZE+1+S.top1-S.top2);
}

void StackTraverse(DoubleStack S){
	printf("栈1的元素为：\n");
	while(S.top1!=-1)
		printf("%d",S.data[S.top1--]);
	printf("\n");
	printf("栈2的元素为：\n");
	while(S.top2!=MAXSIZE)
		printf("%d",S.data[S.top2++]);
	printf("\n");

}