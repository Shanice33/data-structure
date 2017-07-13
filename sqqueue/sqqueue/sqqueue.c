#include "sqqueue.h"

void main(){
	Status j;
	int i=0,l;
	ElemType d;
	SqQueue Q;
	InitQueue(&Q);
	printf("��ʼ�����к󣬶��пշ�%u(1:�� 0:��)\n",QueueEmpty(Q));

	printf("���������Ͷ���Ԫ��(������%d��),-1Ϊ��ǰ������: ",MAXSIZE-1);
	do
	{
		/* scanf("%d",&d); */
		d=i+100;
		if(d==-1)
			break;
		i++;
		EnQueue(&Q,d);
	}while(i<MAXSIZE);
	QueueTraverse(Q);

	printf("���г���Ϊ: %d\n",QueueLength(Q));
	printf("���ڶ��пշ�%d(1:�� 0:��)\n",QueueEmpty(Q));
	printf("����%d���ɶ�ͷɾ��Ԫ��,��β����Ԫ��:\n",MAXSIZE);
	for(l=1;l<=MAXSIZE-2;l++)
	{
		DeQueue(&Q,&d);
		printf("ɾ����Ԫ����%d \n",d);
		
		/* scanf("%d",&d); */
		d=l+1000;
		EnQueue(&Q,d);
		printf("�����Ԫ��Ϊ��%d\n",d);
		
	}
	l=QueueLength(Q);

	printf("���ڶ����е�Ԫ��Ϊ: \n");
	QueueTraverse(Q);
	printf("�����β������%d��Ԫ��\n",i+MAXSIZE);
	
	while(QueueLength(Q)>2)
	{
		DeQueue(&Q,&d);
		printf("ɾ����Ԫ��ֵΪ%d\n",d);
	}

	j=GetHead(Q,&d);
	if(j)
		printf("���ڶ�ͷԪ��Ϊ: %d\n",d);
	ClearQueue(&Q);
	printf("��ն��к�, ���пշ�%u(1:�� 0:��)\n",QueueEmpty(Q));
	system("pause");
}