#include "DJ.h"

void main(){
	int i,j,v0;
	MGraph G;    
	Patharc P;    
	ShortPathTable D; /* 求某点到其余各点的最短路径 */   
	v0=1;
    CreateMGraph(&G);

	ShortestPath_Dijistra(G, v0, &P, &D); 

	for(i=0;i<G.numVertexes;i++)
		printf("%d  ",P[i]);
	printf("\n");

	printf("最短路径倒序输出如下：\n");
	for(i=0;i<G.numVertexes;i++){
		printf("v%d--v%d:\n",v0,i);
		j=i;
		printf("v%d\t",j);
		while(P[j]!=v0){
			printf("v%d\t",P[j]);
			j=P[j];
		}
		printf("v%d\n",v0);
	}

	printf("源点到各顶点的最短路径长度为:\n");
	for(i=0;i<G.numVertexes;i++){
		printf("v%d--v%d:%d\n",v0,i,D[i]);

	}

	system("pause");
}