#include<stdio.h>
#include"LkStack.h"

void conversion(int Num,int k)
{
	char a[16] = "0123456789ABCDEF";
	LkStack *s = InitStack();	/* 对栈进行初始化 */
	printf("转换前：%d\n",Num);
	while (Num)
	{
		Push(s,Num%k);
		Num = Num/k;

	}
	printf("转换后:");
	while (!StackIsEmtpy(s))
	{
		int e;
		Pop(s,&e);
		printf("%c",a[e]);
	}
	printf("\n");
		
}

int main()
{
	int num,k;
	scanf("%d%d",&num,&k);
	conversion(num,k);
	return 0;
}

