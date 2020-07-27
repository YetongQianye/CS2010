#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

/*
	设计一个算法，判断一个单链表中是否存在环?
		创建一个数组，将每一个结点的地址保存下来，
		每保存一个就进行遍历。看是否有相同的，
		若有相同的则存在环，若没有，则不存在
*/

/*
	row：输入的数，排成链表
	返回值：
			链表的第一个结点的地址
*/

struct node *row()
{
	int a,s=0;
	struct node *p;
	struct node *first=NULL;
	struct node *last=NULL;
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
		p->data = a;
		last->next = p;
		p->next = NULL;
		last = p;
	}
	return first;
}

/*
	row：输入的数，排成链表
	返回值：
			链表的第一个结点的地址
*/

struct node *row1()
{
	int a,s=0;
	struct node *p;
	struct node *first=NULL;
	struct node *last=NULL;
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
		p->data = a;
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

int is_circle(struct node *h)
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
		a[i] = (int)h;
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
	output：循环输出
	@p：指向单链表的第一个的地址
*/

void output(struct node *p)
{
	if (p != NULL)
	{
		while (p)//循环输出
		{
			printf("%d ", p->data);
			p = p->next;
		}
	}
}

/*
	release：循环释放链表的空间
	@p：用来向前递进
	@n：跟着p后进行释放
*/

int release(struct node *p,struct node *n)
{
	
	while (n)
	{
		p = p->next;
		n->next=NULL;
		free(n);
		n=p;
	}
}


//printf("1\n");
