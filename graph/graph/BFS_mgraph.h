//#include "MGraph.h"

/*typedef struct Queue{
	VertexType data[MAXVEX];
	int front,rear;
}Queue;

Status InitQueue(Queue *Q){
	(*Q)->front=(*Q)->rear=0;
	return OK;
}

Status EmptyQueue(Queue Q){
	if(Q.front==Q.rear)
		return TRUE;
	return FALSE;
}

Status EnQueue(Queue *Q,VertexType e){
	if(((*Q)->rear+1)%MAXVEX==(*Q)->front) return ERROR;
	(*Q)->data[(*Q)->rear]=e;
	(*Q)->rear++;
	return OK;
}

Status DeQueue(Queue *Q,VertexType *e){
	if(EmptyQueue(*Q)) return ERROR;
	*e=(*Q)->data[(*Q)->front];
	(*Q)->front=((*Q)->front+1)%MAXVEX;
	return OK;
}

void BFSTraverse(MGraph G){
	int i,j,k;
	VertexType c;
	Queue Q;
	InitQueue(&Q);
	for(i=0;i<G.numVertexes;i++)
		visited[i]=FALSE;
	for(i=0;i<G.numVertexes;i++){
		if(!visited[i]){
			visited[i]=TRUE;
			printf("%c",G.node[i]);
			EnQueue(&Q,G.node[i]);
			while(!EmptyQueue(Q)){
				DeQueue(&Q,&c);
				for(k=0;k<G.numVertexes;k++){
					if(G.node[k]==c)
						break;
				}
				for(j=0;j<G.numVertexes;j++){
					if(G.edge[k][j]==1&&!visited[j]){
						printf("%c",G.node[j]);
						EnQueue(&Q,G.node[j]);
					}
				}

			}
		}
	}
}*/
