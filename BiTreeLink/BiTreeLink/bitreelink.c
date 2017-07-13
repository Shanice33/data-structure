#include "bitreelink.h"

void main(){
	int i;
	BiTree T;
	ElemType e1;
	InitTree(&T);


	//str[MAXSIZE]="ABDH#K###E##CFI###G#J##";

	CreateTree(&T);

	printf("构造空二叉树后,树空否？%d(1:是 0:否) 树的深度=%d\n",TreeEmpty(T),TreeDepth(T));
	e1=Root(T);
	printf("二叉树的根为: %c\n",e1);

	printf("\n前序遍历二叉树:");
	PreOrderTraverse(T);
	printf("\n中序遍历二叉树:");
	InOrderTraverse(T);
	printf("\n后序遍历二叉树:");
	PostOrderTraverse(T);
	DestroyTree(&T);
	printf("\n清除二叉树后,树空否？%d(1:是 0:否) 树的深度=%d\n",TreeEmpty(T),TreeDepth(T));
	i=Root(T);
	if(!i)
		printf("树空，无根\n");

	system("pause");
}