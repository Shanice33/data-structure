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

typedef struct Node{
	ElemType data;
	struct Node *next;
}Node,*LinkQueueptr;

typedef struct LinkQueue{
	LinkQueueptr front;
	LinkQueueptr rear;
}LinkQueue;

Status InitQueue(LinkQueue *Q){
	LinkQueueptr p;
	p=(LinkQueueptr)malloc(sizeof(Node));
	if(!p) return ERROR;
	Q->front=Q->rear=p;
	Q->rear->next=NULL;
	return OK;
}

Status ClearQueue(LinkQueue *Q){
	LinkQueueptr p,q;
	Q->rear=Q->front;
	p=Q->front->next;
	Q->front->next=NULL;
	while(p){
		q=p;
		p=p->next;
		free(q);	
	}
}

Status QueueEmpty(LinkQueue Q){
	if(Q.front==Q.rear) return TRUE;
	return FALSE;
}

Status GetHead(LinkQueue Q,ElemType *e){
	if(QueueEmpty(Q)) return ERROR;
	*e=Q.front->next->data;
	return OK;
}

Status EnQueue(LinkQueue *Q,ElemType e){
	LinkQueueptr p;
	p=(LinkQueueptr)malloc(sizeof(Node));
	p->data=e;
	p->next=NULL;
	Q->rear->next=p;
	Q->rear=p;
	return OK;
}

Status DeQueue(LinkQueue *Q,ElemType *e){
	LinkQueueptr p;
	if(QueueEmpty(*Q)) return ERROR;
	p=Q->front->next;
	*e=p->data;
	Q->front->next=p->next;
	free(p);
	return OK;
}

int QueueLength(LinkQueue Q){
	int count=0;
	LinkQueueptr p=Q.front->next;
	while(p){
		p=p->next;
		count++;
	}
	return count;
}

void QueueTraverse(LinkQueue Q){
	LinkQueueptr p=Q.front->next;
	while(p){
		printf("%d",p->data);
		p=p->next;
	}
}
