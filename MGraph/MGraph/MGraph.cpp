#include "MGraph.h"
#include "Queue.h"

void main(){
	MGraph G;
	CreateMGraph(&G);
	printf("\n深度遍历：");
	DFSTraverse(G);
	printf("\n广度遍历：");
	BFSTraverse(G);
	MiniSpanTree_prim(G);
	MiniSpanTree_Kruskal(G);

	system("pause");
}
