#include "linkstack.h"
void main(){
	int j;
	LinkStack s;
	int e;
	if(InitStack(&s)==OK)
		for(j=1;j<=10;j++)
			Push(&s,j);
	printf("ջ��Ԫ������Ϊ��");
	StackTraverse(s);
	Pop(&s,&e);
	printf("������ջ��Ԫ�� e=%d\n",e);
	printf("ջ�շ�%d(1:�� 0:��)\n",StackEmpty(s));
	GetTop(s,&e);
	printf("ջ��Ԫ�� e=%d ջ�ĳ���Ϊ%d\n",e,StackLength(s));
	ClearStack(&s);
	printf("���ջ��ջ�շ�%d(1:�� 0:��)\n",StackEmpty(s));
	if(GetTop(s,&e))
	    printf("ջ��Ԫ�� e=%d ջ�ĳ���Ϊ%d\n",e,StackLength(s));
	system("pause");
}