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
	int top;
}SqStack;

Status InitStack(SqStack *S){
	S->top=-1;
	return OK;
}

Status ClearStack(SqStack *S){
	S->top=-1;
	return OK;
}

Status StackEmpty(SqStack S){
	if(S.top==-1)
		return TRUE;
	else
		return FALSE;
}

Status GetTop(SqStack S,ElemType *e){
	if(S.top==-1)
		return FALSE;
	*e=S.data[S.top];
	return TRUE;
}

Status Push(SqStack *S,ElemType e){
	if(S->top==MAXSIZE-1)
		return ERROR;
	S->top++;
	S->data[S->top]=e;
	return OK;
}

Status Pop(SqStack *S,ElemType *e){
	if(S->top==-1){
		return ERROR;
	}
	*e=S->data[S->top];
	S->top--;
	return OK;

}

int StackLength(SqStack S){
	return (S.top+1);
}

void StackTraverse(SqStack S){
	while(S.top+1){
		printf("%d",S.data[S.top]);
		S.top--;
	}
	printf("\n");
}