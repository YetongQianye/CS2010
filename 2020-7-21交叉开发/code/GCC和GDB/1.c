#include<stdio.h>

void fun()
{
	printf("xxx");
	
}

int main()
{
	int a;
	int *p = &a;
	printf("p = %p\n",p);
	printf("sizeof(p) = %ld\n",sizeof(p));
	printf("sizeof(fun) = %ld\n",sizeof(&fun));
	return 0;
}