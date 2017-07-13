#include "stdio.h"    
#include "stdlib.h"   
#include "io.h"  
#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXVEX 100 /* 最大顶点数，应由用户定义 */
#define INFINITY 65535

typedef int Status;	/* Status是函数的类型,其值是函数结果状态代码，如OK等 */
typedef char VertexType; /* 顶点类型应由用户定义  */
typedef int EdgeType; /* 边上的权值类型应由用户定义 */



typedef struct{
	VertexType data[MAXVEX];
	int front;
	int rear;
}Queue;

Status InitQueue(Queue *Q){
	Q->front=Q->rear=0;
	return OK;
}

Status EmptyQueue(Queue Q){
	if(Q.front==Q.rear) return TRUE;
	return FALSE;
}

Status EnQueue(Queue *Q,VertexType e){
	if((Q->rear+1)%MAXVEX==Q->front) return ERROR;
	Q->data[Q->rear]=e;
	Q->rear++;
	return OK;
}

Status DeQueue(Queue *Q,VertexType *e){
	if(EmptyQueue(*Q)) return ERROR;
	*e=Q->data[Q->front];
	Q->front=(Q->front+1)%MAXVEX;
	return OK;
}