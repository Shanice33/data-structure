//#include "GraphAdjList.h"

/*typedef struct{
	VertexType data[MAXVEX];
	int front;
	int rear;
}Queue;

Status InitQueue(Queue *Q){
	(*Q)->front=(*Q)->rear=0;
	return OK;
}

Status EmptyQueue(Queue Q){
	if(Q->front==Q->rear) return TRUE;
	return FALSE;
}

Status EnQueue(Queue *Q,VertexType e){
	if(((*Q)->rear+1)%MAXVEX==(*Q)->front) return ERROR;
	(*Q)->data[(*Q)->rear]=e;
	(*Q)->rear++;
	return OK;
}

Status DeQueue(Queue *Q,VertexType *e){
	if(EmptyQueue(Q)) return ERROR;
	*e=(*Q)->data[(*Q)->front];
	(*Q)->front=((*Q)->front+1)%MAXVEX;
	return OK;
}

void BFSTraverse(GraphAdjList G){
	int i,j,k;
	EdgeNode *p;
	VertexType ch;
	Queue Q;
	InitQueue(&Q);
	for(i=0;i<G.numVertexes;i++)
		visited[i]=FALSE;
	for(i=0;i<G.numVertexes;i++){
		if(!visited[i]){
			visited[i]=TRUE;
			printf("%c",G.adjlist[i].data);
			EnQueue(&Q,G.adjlist[i].data);
			while(!EmptyQueue(Q)){
				DeQueue(&Q,&ch);
				for(j=0;j<G.numVertexes;j++){
					if(G.adjlist[j].data==ch)
						break;
				}
				p=G.adjlist[j].firstedge;
				while(p){
					k=p->adjvex;
					if(!visited[k]){
						visited[k]=TRUE;
						printf("%c",G.adjlist[k].data);
						EnQueue(&Q,G.adjlist[k].data);
				}
					p=p->next;

			}
		}
	}
}*/