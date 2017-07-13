#include "stdio.h"    
#include "stdlib.h"   
#include "io.h"  
#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXEDGE 20
#define MAXVEX 14
#define INFINITY 65535

typedef int Status;	/* Status是函数的类型,其值是函数结果状态代码，如OK等 */

typedef struct EdgeNode{
	int adjvex;
	int weight;
	struct EdgeNode *next;
}EdgeNode;

typedef struct VertexNode{
	int in;
	int data;
	EdgeNode *firstedge;
}VertexNode,AdjList[MAXVEX];

typedef struct{
	AdjList adjList;
	int numVertexes;
	int numEdges;
}graphAdjList,*GraphAdjList;

Status CreateALGraph(GraphAdjList G){
	int i,j,k;
	EdgeNode *e;
	G->numEdges=20;
	G->numVertexes=14;
	
	for(i=0;i<G->numVertexes;i++){
		G->adjList[i].in=0;
		G->adjList[i].data=i;
		G->adjList[i].firstedge=NULL;
	}
	for(k=0;k<G->numEdges;k++){
		printf("输入边（vi，vj）上的顶点序号：\n");
		scanf("%d%d",&i,&j);;
		e=(EdgeNode *)malloc(sizeof(EdgeNode));

		e->adjvex=j;
	    e->weight=1;
		e->next=G->adjList[i].firstedge;
		G->adjList[i].firstedge=e;
		G->adjList[j].in++;
	}
}

Status TopologicalSort(GraphAdjList G){
	EdgeNode *e;
	int *stack,top=0;
	int gettop;
	int i,j;
	int count=0;
	stack=(int *)malloc(G->numVertexes*sizeof(int));
	for(i=0;i<G->numVertexes;i++){
		if(!G->adjList[i].in)
			stack[++top]=i;
	}
	while(top!=0){
		gettop=stack[top--];
		printf("%d  ->",G->adjList[gettop].data);
		count++;
		for(e=G->adjList[gettop].firstedge;e;e=e->next){

			if(!(--G->adjList[e->adjvex].in))
				stack[++top]=e->adjvex;
		}
	}
	if(count==G->numVertexes)
		return OK;
	else
		return ERROR;
}