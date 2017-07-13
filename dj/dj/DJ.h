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
#define MAXVEX 20
#define INFINITY 65535

typedef int Status;	/* Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK�� */ 


typedef struct
{
	int vexs[MAXVEX];
	int arc[MAXVEX][MAXVEX];
	int numVertexes, numEdges;
}MGraph;

typedef int Patharc[MAXVEX];    /* ���ڴ洢���·���±������ */
typedef int ShortPathTable[MAXVEX];/* ���ڴ洢���������·����Ȩֵ�� */

Status CreateMGraph(MGraph *G){
	int i,j;
	G->numEdges=16;
	G->numVertexes=9;
	for(i=0;i<G->numVertexes;i++)
		G->vexs[i]=i;
	for(i=0;i<G->numVertexes;i++)
		for(j=0;j<G->numVertexes;j++){
			if(i==j)
				G->arc[i][j]=0;
			else
			    G->arc[i][j]=INFINITY;
		}
		G->arc[0][1]=1;
		G->arc[0][2]=5; 
		G->arc[1][2]=3; 
		G->arc[1][3]=7; 
		G->arc[1][4]=5; 

		G->arc[2][4]=1; 
		G->arc[2][5]=7; 
		G->arc[3][4]=2; 
		G->arc[3][6]=3; 
		G->arc[4][5]=3;

		G->arc[4][6]=6;
		G->arc[4][7]=9; 
		G->arc[5][7]=5; 
		G->arc[6][7]=2; 
		G->arc[6][8]=7;

		G->arc[7][8]=4;
	for(i=0;i<G->numVertexes;i++)
		for(j=i+1;j<G->numVertexes;j++){
			G->arc[j][i]=G->arc[i][j];
		}

}

void ShortestPath_Dijistra(MGraph G,int v0,Patharc *P,ShortPathTable *D){
	int final[MAXVEX];
	int i,j,k,min;
	for(i=0;i<G.numVertexes;i++){
		final[i]=0;
		(*P)[i]=v0;
		(*D)[i]=G.arc[v0][i];
	}
	final[v0]=1;
	for(i=1;i<G.numVertexes;i++){
		min=INFINITY;
		for(j=0;j<G.numVertexes;j++){
			if(!final[j]&&(*D)[j]<min){
				min=(*D)[j];
				k=j;
			}
		}
		final[k]=1;
		for(j=0;j<G.numVertexes;j++){
			if(!final[j]&&(min+G.arc[k][j]<(*D)[j])){
				(*D)[j]=min+G.arc[k][j];
				(*P)[j]=k;
			}
		}
	}
}
