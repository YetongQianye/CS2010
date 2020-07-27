#include<stdio.h>
#include"LkStack.h"


int main()
{
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
	return 0;
}








