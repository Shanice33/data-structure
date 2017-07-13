#include "bitreelink.h"

void main(){
	int i;
	BiTree T;
	ElemType e1;
	InitTree(&T);


	//str[MAXSIZE]="ABDH#K###E##CFI###G#J##";

	CreateTree(&T);

	printf("����ն�������,���շ�%d(1:�� 0:��) �������=%d\n",TreeEmpty(T),TreeDepth(T));
	e1=Root(T);
	printf("�������ĸ�Ϊ: %c\n",e1);

	printf("\nǰ�����������:");
	PreOrderTraverse(T);
	printf("\n�������������:");
	InOrderTraverse(T);
	printf("\n�������������:");
	PostOrderTraverse(T);
	DestroyTree(&T);
	printf("\n�����������,���շ�%d(1:�� 0:��) �������=%d\n",TreeEmpty(T),TreeDepth(T));
	i=Root(T);
	if(!i)
		printf("���գ��޸�\n");

	system("pause");
}