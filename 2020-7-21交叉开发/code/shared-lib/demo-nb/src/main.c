#include<stdio.h>
#include"nb.h"

int main()
{
	int a;
	int b;
	printf("please input two num\n");
	scanf("%d%d",&a,&b);
	int sum = my_nb(a,b);
	printf("%d + %d = %d\n",a,b,sum);
	return 0;
}








