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

typedef struct EdgeNode{
	int adjvex;
	struct EdgeNode *next;
}EdgeNode;

typedef struct VertexNode{
	VertexType data;
	EdgeNode *firstedge;
}VertexNode,AdjList[MAXVEX];

typedef struct GraphAdjList{
	AdjList adjlist;
	int numVertexes,numEdges;
}GraphAdjList;




void CreateALGraph(GraphAdjList *G){
	int i=0,j=0,k;
	EdgeNode *e;
	printf("请输入顶点数和边数:\n");
	scanf("%d%d",&G->numVertexes,&G->numEdges);
	for(i=0;i<G->numVertexes;i++){
		G->adjlist[i].data=i;
		//G->adjlist[i].firstedge=NULL;
		//scanf(&G->adjlist[i].data); 	/* 输入顶点信息 */
		G->adjlist[i].firstedge=NULL;
	}
	
	for(k=0;k<G->numEdges;k++){
		printf("输入边（vi,vj）的顶点序号：\n");
		scanf("%d%d",&i,&j);
		if(i<0||i>=G->numVertexes||j<0||j>=G->numVertexes){
			printf("不存在点(vi=%d,vj=%d)\n",i,j);
			return;
		}

		e=(EdgeNode *)malloc(sizeof(EdgeNode));
		e->adjvex=j;
		e->next=G->adjlist[i].firstedge;
		G->adjlist[i].firstedge=e;

		e=(EdgeNode *)malloc(sizeof(EdgeNode));
		e->adjvex=i;
		e->next=G->adjlist[j].firstedge;
		G->adjlist[j].firstedge=e;

	}

}



void BFSTraverse(GraphAdjList G){
	int i,j,k;
	EdgeNode *p;
	VertexType ch;
	Queue Q;
	InitQueue(&Q);
	for(i=0;i<G.numVertexes;i++)
		visited[i]=FALSE;
	for(i=0;i<G.numVertexes;i++){
		if(!visited[i]){
			visited[i]=TRUE;
			printf("%c",G.adjlist[i].data);
			EnQueue(&Q,G.adjlist[i].data);
			while(!EmptyQueue(Q)){
				DeQueue(&Q,&ch);
				for(j=0;j<G.numVertexes;j++){
					if(G.adjlist[j].data==ch)
						break;
				}
				p=G.adjlist[j].firstedge;
				while(p){
					k=p->adjvex;
					if(!visited[k]){
						visited[k]=TRUE;
						printf("%c",G.adjlist[k].data);
						EnQueue(&Q,G.adjlist[k].data);
					}
					p=p->next;

				}
			}
		}
	}
}

	void DFS(GraphAdjList G,int i){
		EdgeNode *p;
		visited[i]=TRUE;
		printf("%d",G.adjlist[i].data);
		p=G.adjlist[i].firstedge;
		while(p){
			if(!visited[p->adjvex])
				DFS(G,p->adjvex);
			p=p->next;
		}
	}

	void DFSTraverse(GraphAdjList G){
		int i;
		for(i=0;i<G.numVertexes;i++)
			visited[i]=FALSE;
		for(i=0;i<G.numVertexes;i++){
			if(!visited[i])
				DFS(G,i);
		}
	}
