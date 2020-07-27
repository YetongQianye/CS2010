#include<stdio.h>
#include"maxnum.h"

#define MAX 1024
int main()
{
	int a[MAX];
	
	int num;
	printf("please input you elem num\n");
	scanf("%d",&num);
	if(num <=0 || num >= 1024)
	{
		printf("sorry,i cant do it\n");
		return -1;
	}
	printf("please input you  nums\n");
	int i;
	for(i=0;i<num;i++)
	{
		scanf("%d",&a[i]);
	}
	maxnum(a,num);
	printf("The max num is:\n");
	printf("%d  ",a[num-1]);
	
	printf("\n");
	return 0;
}
