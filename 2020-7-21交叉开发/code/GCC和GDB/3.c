#include<stdio.h>

void fun()
{
	int x;
	printf("haha\n");
}

int main()
{
	int *num = NULL;
	int x;
	fun();
	fun();
	
	scanf("%d",&x);
	int i;
	for(i=0;i<=x;i++)
	{
		*num += i;
	}

	printf("num = %d\n",*num);
	return 0;
}







