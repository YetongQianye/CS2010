#include<stdio.h>
#include"LkStack.h"



//利用栈写一个函数,可以把十进制的数字转换成任意进制(2,8,16)的数字
		
void conversion(int Num,int k)
{
	char a[16] = "0123456789ABCDEF";

	LkStack *s = InitStack();
	printf("转换前:%d\n",Num);

	while(Num)
	{
		Push(s,Num%k);
		Num = Num/k;
	}
	
	printf("转换后:");
	while(!StackIsEmtpy(s))
	{
		int e;
		Pop(s,&e);
		
		//printf("%d",e);
		printf("%c",a[e]);
	}
	printf("\n");
	
}











int main()
{
/*
	LkStack *s = InitStack();

	int r = StackIsEmtpy(s);
	if(r == 1)
	{
		printf("空栈\n");
	}else
	{
		printf("非空\n");
	}
	Push(s,1);
	Push(s,2);
	Push(s,3);
	Push(s,4);
	r = StackIsEmtpy(s);
	if(r == 1)
	{
		printf("空栈\n");
	}else
	{
		printf("非空\n");
	}
	int x;
	GetTop(s,&x);
	printf("x = %d\n",x); //4

	Pop(s,&x);
	printf("x = %d\n",x); //4
	Pop(s,&x);
	printf("x = %d\n",x); //3

	DestroyStack(&s);
*/
	int num,k;
	scanf("%d%d",&num,&k);
	conversion(num,k);
	return 0;
}

