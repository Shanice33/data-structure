#include "MGraph.h"
#include "Queue.h"

void main(){
	MGraph G;
	CreateMGraph(&G);
	printf("\n��ȱ�����");
	DFSTraverse(G);
	printf("\n��ȱ�����");
	BFSTraverse(G);
	MiniSpanTree_prim(G);
	MiniSpanTree_Kruskal(G);

	system("pause");
}
