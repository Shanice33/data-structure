#include "stdio.h"    
#include "stdlib.h"   
#include "io.h"  
#include "math.h"  
#include "time.h"
#include "Queue.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXVEX 100 /* 最大顶点数，应由用户定义 */
#define INFINITY 65535

typedef int Status;	/* Status是函数的类型,其值是函数结果状态代码，如OK等 */
typedef char VertexType; /* 顶点类型应由用户定义  */
typedef int EdgeType; /* 边上的权值类型应由用户定义 */
typedef int BOOLEAN;
BOOLEAN visited[MAXVEX];

typedef struct {
	VertexType node[MAXVEX];
	EdgeType edge[MAXVEX][MAXVEX];
	int numVertexes,numEdges;
}MGraph;



void CreateMGraph(MGraph *G){
	int i=0 ,j=0,k;
	printf("输入顶点数和边数：\n");
	scanf("%d%d",&G->numVertexes,&G->numEdges);
	printf("输入%d个顶点序号:",G->numVertexes);
	for(i=0;i<G->numVertexes;i++){
		printf("%d",i);
		scanf("%c",&G->node[i]);
	}
	//G->node[i]=i;
	for(i=0;i<G->numVertexes;i++)
		for(j=0;j<G->numVertexes;j++)
			G->edge[i][j]=INFINITY;
	for(k=0;k<G->numEdges;k++){
		printf("输入边（vi，vj）的下标i，j：\n");
		scanf("%d%d",&i,&j);
		if(i<0||i>=G->numVertexes||j<0||j>=G->numVertexes){
			printf("不存在点(i=%d,j=%d)\n",i,j);
			return;
		}
		G->edge[i][j]=1;
		G->edge[j][i]=G->edge[i][j];
	}
}


void BFSTraverse(MGraph G){
	int i,j,k;
	VertexType c;
	Queue Q;
	InitQueue(&Q);
	for(i=0;i<G.numVertexes;i++)
		visited[i]=FALSE;
	for(i=0;i<G.numVertexes;i++){
		if(!visited[i]){
			visited[i]=TRUE;
			printf("%c",G.node[i]);
			EnQueue(&Q,G.node[i]);
			while(!EmptyQueue(Q)){
				DeQueue(&Q,&c);
				for(k=0;k<G.numVertexes;k++){
					if(G.node[k]==c)
						break;
				}
				for(j=0;j<G.numVertexes;j++){
					if(G.edge[k][j]==1&&!visited[j]){
						printf("%c",G.node[j]);
						EnQueue(&Q,G.node[j]);
					}
				}

			}
		}
	}
}



void DFS(MGraph G,int i){
	int j;
	visited[i]=TRUE;
	printf("%c",G.node[i]);
	for(j=0;j<G.numVertexes;j++){
		if(G.edge[i][j]==1&&!visited[j])
			DFS(G,j);
	}
}

void DFSTraverse(MGraph G){
	int i;
	for(i=0;i<G.numVertexes;i++){
		visited[i]==FALSE;
	}
	for(i=0;i<G.numVertexes;i++){
		if(!visited[i])
			DFS(G,i);
	}
}