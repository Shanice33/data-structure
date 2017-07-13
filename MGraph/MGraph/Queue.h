#pragma once

#include "stdio.h"    
#include "stdlib.h"   
#include "io.h"  
#include "math.h"  
#include "time.h"


#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXVEX 100 /* ��󶥵�����Ӧ���û����� */
#define INFINITY 65535

typedef int Status;	/* Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK�� */
typedef char VertexType; /* ��������Ӧ���û�����  */
typedef int EdgeType; /* ���ϵ�Ȩֵ����Ӧ���û����� */
typedef int BOOLEAN;
BOOLEAN visited[MAXVEX];


typedef struct{
	VertexType data[MAXVEX];
	int front;
	int rear;
}Queue1;

Status InitQueue(Queue1 *Q){
	Q->front=Q->rear=0;
	return OK;
}

Status EmptyQueue(Queue1 Q){
	if(Q.front==Q.rear) return TRUE;
	return FALSE;
}

Status EnQueue(Queue1 *Q,VertexType e){
	if((Q->rear+1)%MAXVEX==Q->front) return ERROR;
	Q->data[Q->rear]=e;
	Q->rear++;
	return OK;
}

Status DeQueue(Queue1 *Q,VertexType *e){
	if(Q->front == Q->rear) return ERROR;
	*e=Q->data[Q->front];
	Q->front=(Q->front+1)%MAXVEX;
	return OK;
}