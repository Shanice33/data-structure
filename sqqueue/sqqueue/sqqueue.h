#include "stdio.h"    
#include "stdlib.h"   
#include "io.h"  
#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 5 /* 存储空间初始分配量 */

typedef int Status; 
typedef int ElemType;

typedef struct{
	ElemType data[MAXSIZE];
	int front;
	int rear;
}SqQueue;

Status InitQueue(SqQueue *Q){
	Q->front=Q->rear=0;
	return OK;
}

Status ClearQueue(SqQueue *Q){
	Q->front=Q->rear=0;
	return OK;
}

Status QueueEmpty(SqQueue Q){
	if(Q.front==Q.rear) return TRUE;
	return FALSE;
}

Status GetHead(SqQueue Q,ElemType *e){
	if(QueueEmpty(Q)) return ERROR;
	*e=Q.data[Q.front];
	return OK;
}

Status EnQueue(SqQueue *Q,ElemType e){
	if((Q->rear+1)%MAXSIZE==Q->front)  return ERROR;
	Q->data[Q->rear]=e;
	Q->rear=(Q->rear+1)%MAXSIZE;
	return OK;
}

Status DeQueue(SqQueue *Q,ElemType *e){
	if(QueueEmpty(*Q)) return ERROR;
	*e=Q->data[Q->front];
	Q->front=(Q->front+1)%MAXSIZE;
	return OK;
}

int QueueLength(SqQueue Q){
	return (Q.rear+MAXSIZE-Q.front)%MAXSIZE;
}

void QueueTraverse(SqQueue Q){
	int i=Q.front,j;
	for(j=0;j<QueueLength(Q);j++){
		printf("%d  ",Q.data[i]);
		i=(i+1)%MAXSIZE;
	}
	printf("\n");
}
	