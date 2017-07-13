#include "topo.h"

void main(){
	graphAdjList GL; 
	int result;   
	CreateALGraph(&GL);
	result=TopologicalSort(&GL);
	printf("result:%d",result);
	system("pause");
}