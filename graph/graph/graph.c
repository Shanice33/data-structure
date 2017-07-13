#include "MGraph.h"
#include "GraphAdjList.h"


void main(){
	MGraph G;  
	//GraphAdjList GL;    
	CreateMGraph(&G);
	//CreateALGraph(G,&GL);

	printf("\n深度遍历:");
	DFSTraverse(G);
	printf("\n广度遍历:");
	BFSTraverse(G);

	system("pause");
}