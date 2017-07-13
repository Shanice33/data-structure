#include "stdio.h"    
#include "string.h"
#include "ctype.h"      
#include "stdlib.h"   
#include "io.h"  
#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;
typedef int ElemType;

typedef struct Node{
	ElemType data;
	struct Node *next;
}Node,*LinkList; //Linklist��Node*����һ��������ָ������,//typedef struct Node *LinkList;


Status InitList(LinkList *L){  //L��ָ��ͷָ���ָ�룬��*L��ͷָ�룬ָ������ʼ��λ�ã�������ͷ�������ǵ�һ���ڵ�
	*L=(LinkList)malloc(sizeof(Node));
	if(!(*L)) return ERROR;
	(*L)->next=NULL;
	return OK;
}

Status ListEmpty(LinkList *L){
	if((*L)->next==NULL) return TRUE;
	else return FALSE;
}

Status ClearList(LinkList *L){
	Node* p,*q; //ÿ���ڵ㶼������һ���ڵ�ָ��ָ���ʾ�����ڲ���
	p=(*L)->next;
	while(p){
		q=p->next;
		free(p);
		p=q;
	}
	(*L)->next=NULL;
	return OK;
}

Status GetElem(LinkList *L,int i,ElemType *e){
	Node* p=(*L)->next;
	int j=1;
	while(p && j<i){
		p=p->next;
		j++;
	}
	if(p==NULL||j>i)
		return ERROR;
	*e=p->data;
	return OK;
}

int  LocateElem(LinkList *L,ElemType e){
	Node* p=(*L)->next;
	int i=1;
	while(p){
		if(p->data==e)
			return i;
		p=p->next;
		i++;
	}
	return 0;
}

Status ListInsert(LinkList* L,int i,ElemType e){
	Node* p,*q;
	int j;
	p=*L;
	q=(LinkList)malloc(sizeof(Node));
	q->data=e;
	if(i<1) return ERROR;
	for(j=1;j<i;j++){
		if(!(p->next))
			return ERROR;
		p=p->next;
	}
	q->next=p->next;
	p->next=q;
	return OK;
}

Status ListDelete(LinkList *L,int i,ElemType* e){
	int j;
	Node* p=*L;
	Node *q;
	if(i<1)
		return ERROR;
	for(j=1;j<i;j++){
		p=p->next;
		if(!(p->next))
			return ERROR;
	}
	q=p->next;
	p->next=q->next;
	*e=q->data;
	free(q);
	return OK;
}

int ListLength(LinkList *L){
	int i=0;
	Node* p=(*L)->next;
	while(p){
		p=p->next;
		i++;
	}
	return i;
}

void ListTraverse(Node* L){
	Node* p=L->next;
	while(p){
		printf("%d",p->data);
		p=p->next;
	}
	printf("\n");
}