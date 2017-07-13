#include<stdio.h>

#include "stdio.h"    

#include "stdlib.h"   
#include "io.h"  
#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR 0
#define MAXSIZE 20
typedef int Status;
typedef int ElemType;

typedef struct{
	ElemType data[MAXSIZE];
	int length;
}Sqlist;

Status InitList(Sqlist *L){
	L->length=0;
	return OK;
}

Status ListEmpty(Sqlist L){
	if(L.length==0)
		return OK;
	else
		return ERROR;
}

Status ClearList(Sqlist *L){
	L->length=0;
	return OK;
}

Status GetElem(Sqlist L,int i,ElemType *e){
	if(i<1||i>L.length||L.length==0)
		return ERROR;
	*e=L.data[i-1];
	return OK;
}

int LocateElem(Sqlist L ,ElemType e){
	int i;
	for( i=0;i<L.length;i++){
		if(L.data[i]==e)
			return (i+1);
	}
	return 0;
}

Status ListInsert(Sqlist *L,int i,ElemType e){
	int j;
	if(i<1||i>L->length+1)
		return ERROR;
	if(L->length==MAXSIZE)
		return ERROR;
	if(i<=L->length){
	for( j=L->length-1;j>=i-1;j--){
		L->data[j+1]=L->data[j];
	}
	}
	L->data[i-1]=e;
	L->length++;
	return OK;
}

Status ListDelete(Sqlist *L, int i, ElemType* e){
	int j;
	if(i<1||i>L->length)
		return ERROR;
	if(L->length==0)
		return ERROR;
	*e=L->data[i-1];

	for(j=i-1;j<L->length-1;j++){
		L->data[j]=L->data[j+1];
	}
	
	L->length--;
	return OK;
}

int ListLength(Sqlist L){
	return L.length;
}

void ListTraverse(Sqlist L){
	int i;
	for(i=0;i<L.length;i++)
		printf("%d",L.data[i]);
	printf("\n");
}