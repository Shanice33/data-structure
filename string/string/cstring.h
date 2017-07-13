#include "stdlib.h"   
#include "io.h"  
#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 40 /* 存储空间初始分配量 */

typedef int Status;		/* Status是函数的类型,其值是函数结果状态代码，如OK等 */
typedef int ElemType;	/* ElemType类型根据实际情况而定，这里假设为int */

typedef char String[MAXSIZE+1];  /* 定义了一种类型，类型的名字叫String，这种类型的结构是长度为MAXSIZE+1的char数组 */

Status StrAssign(String T,char *chars){
	int i;
	if(strlen(chars)>MAXSIZE) return ERROR;
	T[0]=strlen(chars);
	for(i=1;i<=T[0];i++){
		T[i]=*(chars+i-1);
	}
	return OK;
}

int StrLength(String S){
	return S[0];
}

Status StrCopy(String T,String S){
	int i;
	if(S==NULL) return ERROR;
	for(i=0;i<=S[0];i++){
		T[i]=S[i];
	}
	return OK;
}

Status ClearString(String S){
	if(!S) return ERROR;
	S[0]=0;
	return OK;
}

Status StringEmpty(String S){
	if(S[0]==0) return TRUE;
	return FALSE;
}

int StrCompare(String S,String T){
	int i;
	if(S[0]>T[0]) return 1;
	if(S[0]<T[0]) return -1;
	for(i=0;i<S[0];i++){
		if(S[i]>T[i]) return 1;
		if(S[i]<T[i]) return -1;
	}
	return 0;
}

Status Concat(String T,String S1,String S2){
	int i;
	if(StrLength(S1)+StrLength(S2)>MAXSIZE){
		T[0]=MAXSIZE;	
		for(i=1;i<=S1[0];i++){
			T[i]=S1[i];
		}
		for(i=1;i<=MAXSIZE-S1[0];i++){
			T[i+S1[0]]=S2[i];
		}
		return ERROR;
	}
	else{
	T[0]=S1[0]+S2[0];
	
	for(i=1;i<=S1[0];i++){
		T[i]=S1[i];
	}
	for(i=1;i<=S2[0];i++){
		T[i+S1[0]]=S2[i];
	}
	return OK;
	}
}

Status SubString(String Sub,String S,int pos,int len){
	int i;
	if(pos>MAXSIZE|| len>S[0]) return ERROR;
	if((len+pos-1)>MAXSIZE){
		Sub[0]=MAXSIZE-pos+1;
		for(i=1;i<=Sub[0];i++){
			Sub[i]=S[pos++];
		}
		return ERROR;
	}
	Sub[0]=len;
	for( i=1;i<=len;i++){
		Sub[i]=S[pos++];
	}
	return OK;
}

int Index(String S,String T,int pos){
	String Sub;
	int i;
	for(i=1;i<=S[0]-T[0]+1;i++){
		SubString(Sub,S,i,T[0]);
		if(StrCompare(Sub,T)==0) return i;
	}
	return 0;
}

void StrPrint(String S){
	int i;
	for(i=1;i<=S[0];i++){
		printf("%c",S[i]);
	}
	printf("\n");
}

Status StrInsert(String S,int pos,String T){
	int i,j,k=T[0];
	if(pos<1||pos>S[0]+1||S[0]+T[0]>MAXSIZE) return ERROR;
	for(j=S[0]+T[0];j>=pos;j--){
		S[j]=S[j-k];
	}
	for(i=1;i<=T[0];i++){
		S[pos++]=T[i];
	}
	S[0]=S[0]+T[0];
	return OK;
}

Status StrDelete(String S,int pos,int len){
	int i;
	if(pos<1||pos>MAXSIZE-len+1) return ERROR;

	for(i=pos;i<=S[0]-len;i++){
		S[i]=S[i+len];
	}
	S[0]=S[0]-len;
	return OK;
}

Status Replace(String S,String T,String V){
		int i,j;
		String s;
		if(T[0]==0) return ERROR;
		
		for(i=1;i<=S[0]-T[0]+1;){
			j=Index(S,T,i);
			if(j){
				StrDelete(S,j,T[0]);
				//StrPrint(S);
				StrInsert(S,j,V);
				//StrPrint(S);
				i=i+V[0];
			}
			else
				i++;
		}
		return OK;
}