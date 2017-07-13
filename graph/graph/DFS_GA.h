//#include "GraphAdjList.h"

/*typedef int BOOLEAN;
BOOLEAN visited[i];

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
}*/