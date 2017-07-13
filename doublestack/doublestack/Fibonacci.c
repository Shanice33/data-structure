#include "stdio.h"

int Fibonacci(int n){
	if(n==0 || n==1) return n;
	return Fibonacci(n-1)+Fibonacci(n-2);
}

void main(){
	int i=0;
	printf("F函数的输出为：\n");
	for(;i<10;i++){
		printf("%d",Fibonacci(i));
	}
	system("pause");
}