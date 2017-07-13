#pragma once

#include "Queue.h"
#include <iostream>

using namespace std;
#define INFINITY 65535

typedef struct {
	int numVertexes,numEdges;
	VertexType node[MAXVEX];
	EdgeType edge[MAXVEX][MAXVEX];
	
}MGraph;

typedef struct{
	int begin;
	int end;
	int weight;
}Edge;

void CreateMGraph(MGraph *G){
	int i,j,k,w;
	printf("输入顶点数和边数：\n");
	scanf("%d%d",&G->numVertexes,&G->numEdges);
	//printf("输入%d个顶点序号:\n",G->numVertexes);
	/*for(i=0; i<G->numVertexes; i++){
		//printf("%d: ",i);
		//scanf("%c",&(G->node[i]));
		//getchar();
		cin >> G->node[i];
	}*/
	G->node[0]='v0';
	G->node[1]='v1';
	G->node[2]='v2';
	G->node[3]='v3';
	G->node[4]='v4';
	G->node[5]='v5';
	G->node[6]='v6';
	G->node[7]='v7';
	G->node[8]='v8';

	for(i=0;i<G->numVertexes;i++)
		for(j=0;j<G->numVertexes;j++)
			G->edge[i][j]=INFINITY;
	for(k=0;k<G->numEdges;k++){
		printf("输入边（vi，vj）的下标i，j和边的权值w：\n");
		scanf("%d%d%d",&i,&j,&w);
		if(i<0||i>=G->numVertexes||j<0||j>=G->numVertexes){
			printf("不存在点(i=%d,j=%d)\n",i,j);
			return;
		}
		G->edge[i][j]=w;
		G->edge[j][i]=G->edge[i][j];
	}
	/*G->edge[0][1]=1;
	G->edge[0][5]=1;

	G->edge[1][2]=1; 
	G->edge[1][8]=1; 
	G->edge[1][6]=1; 

	G->edge[2][3]=1; 
	G->edge[2][8]=1; 

	G->edge[3][4]=1;
	G->edge[3][7]=1;
	G->edge[3][6]=1;
	G->edge[3][8]=1;

	G->edge[4][5]=1;
	G->edge[4][7]=1;

	G->edge[5][6]=1; 

	G->edge[6][7]=1; 
	for(i = 0; i < G->numVertexes; i++)
	{
		for(j = i; j < G->numVertexes; j++)
		{
			G->edge[j][i] =G->edge[i][j];
		}
	}*/
}


void BFSTraverse(MGraph G){
	int i,j,k;
	VertexType c;
	Queue1 Q;
	InitQueue(&Q);
	for(i=0;i<G.numVertexes;i++)
		visited[i]=FALSE;
	for(i=0;i<G.numVertexes;i++){
		if(!visited[i]){

			visited[i]=TRUE;
			printf("%c",G.node[i]);
			EnQueue(&Q,G.node[i]);

			while(!EmptyQueue(Q))
			{
				DeQueue(&Q,&c);
				for(k=0;k<G.numVertexes;k++){
					if(G.node[k]==c)
						break;
				}
				
				for(j=0;j<G.numVertexes;j++){
					if(G.edge[k][j]==1 && !visited[j]){
						visited[j]=TRUE;

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

void MiniSpanTree_prim(MGraph G){
	int min,i,j,k;
	int adjvex[MAXVEX];
	int lowcost[MAXVEX];
	lowcost[0]=0;
	adjvex[0]=0;
	printf("最小生成树为：%c",G.node[0]);
	for(i=1;i<G.numVertexes;i++){
		lowcost[i]=G.edge[0][i];
		adjvex[i]=0;
	}
	for(i=1;i<G.numVertexes;i++){
		min=INFINITY;
		k=0;
		for(j=1;j<G.numVertexes;j++){
			if(lowcost[j]<min && lowcost[j]){
				min=lowcost[j];
				k=j;
			}

		}
		lowcost[k]=0;
		printf("%c",G.node[k]);
		for(j=1;j<G.numVertexes;j++){
			if(G.edge[k][j]<lowcost[j]){
				lowcost[j]=G.edge[k][j];
				adjvex[j]=k;
			}
		}
	}
	printf("\n");
}
void sort(Edge e[],MGraph G){
	int i,j,temp;

	for(i=0;i<G.numEdges;i++)
	   for(j+1;j<G.numEdges;j++){

		 if(e[j].weight<e[i].weight){
			 temp=e[j].begin;
			 e[j].begin=e[i].begin;
			 e[i].begin=temp;

			 temp=e[j].end;
			 e[j].end=e[i].end;
			 e[i].end=temp;

			 temp=e[j].weight;
			 e[j].weight=e[i].weight;
			 e[i].weight=temp;
				
		 }
	 }
}

int Find(int *parent,int f){
	while(parent[f]>0)
		f=parent[f];
	return f;
}
void MiniSpanTree_Kruskal(MGraph G){
		int i,j,n,m,k=0;
		Edge edges[MAXVEX];
		int parent[MAXVEX];
		for(i=0;i<G.numVertexes-1;i++)
			for(j=i+1;j<G.numVertexes;j++){
				if(G.edge[i][j]<INFINITY){
					edges[k].begin=i;
					edges[k].end=j;
					edges[k].weight=G.edge[i][j];
					k++;
				}

			}
		sort(edges,G);
		printf("边集数组为：\n");
		for(i=0;i<G.numEdges;i++)
			printf("(%d,%d) %d\n",edges[i].begin,edges[i].end,edges[i].weight);
		for(i=0;i<G.numVertexes;i++)
			parent[i]=0;
		printf("最小生成树的边集即边的权值为：");
		for(i=0;i<G.numEdges;i++){
			n=Find(parent,edges[i].begin);
			m=Find(parent,edges[i].end);
			if(n!=m){
				parent[n]=m;
				printf("(%c,%c) %d",G.node[edges[i].begin],G.node[edges[i].end],edges[i].weight);
			}
		}
		printf("\n");

}