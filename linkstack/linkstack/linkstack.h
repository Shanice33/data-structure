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
}Node;
typedef struct Node* LinkstackPtr;

typedef struct LinkStack{
	LinkstackPtr top;
	int count;
}LinkStack;

Status InitStack(LinkStack *S){
	S->top=(LinkstackPtr)malloc(sizeof(Node));
	if(!S->top)
		return ERROR;
	S->count=0;
	S->top==NULL;
	return OK;
}

Status ClearStack(LinkStack *S){
	LinkstackPtr p,q;
	int i;
	p=S->top;
	for(i=0;i<S->count;i++){
		q=p->next;
		free(p);
		p=q;
	}
	/*while(p)     
	{  
		q=p;
		p=p->next;
		free(q);
	} */
	S->count=0;
	return OK;
}

Status StackEmpty(LinkStack S){
	if(S.count==0)
		return TRUE;
	return FALSE;
}

Status GetTop(LinkStack S,ElemType *e){
	if(S.count==0)
		return ERROR;
	*e=(S.top)->data;
	return OK;
}

Status Push(LinkStack *S,ElemType e){
	LinkstackPtr s=(LinkstackPtr)malloc(sizeof(Node));
	if(!s)
		return ERROR;
	s->data=e;
	s->next=S->top;
	S->top=s;
	S->count++;
	return OK;
}

Status Pop(LinkStack *S,ElemType *e){
	LinkstackPtr p=S->top;
	if(S->count==0)
		return ERROR;
	*e=p->data;
	S->top=p->next;
	free(p);
	S->count--;
	return OK;
	
}

int StackLength(LinkStack S){
	return S.count;
}

void StackTraverse(LinkStack S){
   int i;
	for(i=0;i<S.count;i++){
		printf("%d",(S.top)->data);
		S.top=(S.top)->next;
	}
	printf("\n");
}