 #include <stdio.h>
#include <stdlib.h>
#include "zy6.h"

/*
	设计一个算法，判断一个单链表中是否存在环?
		创建一个数组，将每一个结点的地址保存下来，
		每保存一个就进行遍历。看是否有相同的，
		若有相同的则存在环，若没有，则不存在
*/

/*
	lbpx：输入的数，排成链表
	返回值：
			链表的第一个结点的地址
*/

struct student *lbpx()
{
	int a,s=0;
	student *p;
	student *first=NULL;
	student *last=NULL;
	printf("输入一个数组\n");
	while (1)
	{
		scanf("%d",&a);
		if(a == 0)
		{
			break;
		}
		p = malloc(sizeof(*p));
		if(s == 0)
		{
			first = p;
			last = p;
			s++;
		}
		p->num = a;
		last->next = p;
		p->next = NULL;
		last = p;
	}
	return first;
}

/*
	lbpx：输入的数，排成链表
	返回值：
			链表的第一个结点的地址
*/

struct student *lbpx1()
{
	int a,s=0;
	student *p;
	student *first=NULL;
	student *last=NULL;
	printf("输入一个数组\n");
	while (1)
	{
		scanf("%d",&a);
		if(a == 0)
		{
			break;
		}
		p = malloc(sizeof(*p));
		if(s == 0)
		{
			first = p;
			last = p;
			s++;
		}
		p->num = a;
		last->next = p;
		p->next = NULL;
		last = p;
	}
	last->next = first;
	return first;
}

/*
	is_circle：判断是否存在环
	@h：指向链表首地址
	返回值
		1：存在
		0：不存在
*/

int is_circle(struct student *h)
{
	if(h == NULL)
	{
		return -1;
	}
	int a[100];
	int i=0;
	int n;
	while(h)
	{
		a[i]=(int)h;
		h = h->next;
		for(n=0;n<i;n++)
		{
			if(a[i] == a[n])
			{
				return 1;
			}
		}
		i++;
	}
	return 0;
}

/*
	shuchu：循环输出
	@p：指向单链表的第一个的地址
*/

void shuchu(student *p)
{
	if (p != NULL)
	{
		while (p)//循环输出
		{
			printf("%d ", p->num);
			p = p->next;
		}
	}
}

/*
	shifan：循环释放链表的空间
	@p：用来向前递进
	@n：跟着p后进行释放
*/

int shifan(student *p,student *n)
{
	
	while (n)
	{
		p = p->next;
		n->next=NULL;
		free(n);
		n=p;
	}
}

int main()
{
	int h;
	printf("是否成环，成环输入1，否则为0\n");
	scanf("%d",&h);
	student *n;
	if(h == 0)
	{
		n = lbpx();//定义n接收链表的第一个地址
	}
	else if(h == 1)
	{
		n = lbpx1();
	}
	else 
	{
		n = NULL;
	}
	int a = is_circle(n);
	
	printf("%d\n",a);
	
	student *p;
	p=n;
	shifan(n,p);
	
	printf("\n");
	return 0;
}
//printf("1\n");
