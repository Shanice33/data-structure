#include "MGraph.h"
#include "GraphAdjList.h"


void main(){
	MGraph G;  
	//GraphAdjList GL;    
	CreateMGraph(&G);
	//CreateALGraph(G,&GL);

	printf("\n��ȱ���:");
	DFSTraverse(G);
	printf("\n��ȱ���:");
	BFSTraverse(G);

	system("pause");
}