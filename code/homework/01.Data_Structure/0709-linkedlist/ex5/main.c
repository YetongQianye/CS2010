#include<stdio.h>   //<>""的区别是查找路径不同 
#include"LinkedList.h" //在当前路径下查找 


int main()
{
	int h;
	printf("是否成环，成环输入1，否则为0\n");
	scanf("%d",&h);
	struct node *n;
	if(h == 0)
	{
		n = row();//定义n接收链表的第一个地址
	}
	else if(h == 1)
	{
		n = row1();
	}
	else 
	{
		n = NULL;
	}
	int a = is_circle(n);
	
	printf("%d\n",a);
	
	struct node *p;
	p=n;
	release(n,p);
	
	printf("\n");
	return 0;
}









