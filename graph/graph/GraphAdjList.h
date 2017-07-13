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
#define MAXVEX 100 /* ��󶥵�����Ӧ���û����� */
#define INFINITY 65535

typedef int Status;	/* Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK�� */
typedef char VertexType; /* ��������Ӧ���û�����  */
typedef int EdgeType; /* ���ϵ�Ȩֵ����Ӧ���û����� */

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
	printf("�����붥�����ͱ���:\n");
	scanf("%d%d",&G->numVertexes,&G->numEdges);
	for(i=0;i<G->numVertexes;i++){
		G->adjlist[i].data=i;
		//G->adjlist[i].firstedge=NULL;
		//scanf(&G->adjlist[i].data); 	/* ���붥����Ϣ */
		G->adjlist[i].firstedge=NULL;
	}
	
	for(k=0;k<G->numEdges;k++){
		printf("����ߣ�vi,vj���Ķ�����ţ�\n");
		scanf("%d%d",&i,&j);
		if(i<0||i>=G->numVertexes||j<0||j>=G->numVertexes){
			printf("�����ڵ�(vi=%d,vj=%d)\n",i,j);
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
