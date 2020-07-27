
// 9.链表A,B,判断A是否为B的子序列(子序列：连续的一部分)

#include <stdio.h>
#include <stdlib.h>
#include "zy9.h"

struct note *list()
{
	int a,s=0;
	note *p;
	note *first=NULL;
	note *last=NULL;
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
	zxl：判断一条链表的元素是否为另一条链表的子集
	@pa：指向一条链表的首地址
	@pb：指向一条链表的首地址
*/

int brach(note *pa,note *pb)
{
	note *a;
	note *b;
	while (1)
	{
		if(pa->num == pb->num)
		{
			a = pa;
			b = pb;
			while(a)
			{
				a = a->next;
				b = b->next;
				if(a == NULL)
				{
					return 1;
				}
				else if(b == NULL)
				{
					return 0;
				}
				if(a->num != b->num)
				{
					break;
				}
			}
		}
		pb = pb->next;
		if(pb == NULL)
		{
			return 0;
		}
	}
}

/*
	output：循环输出
	@p：指向单链表的第一个的地址
*/

void output(note *p)
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
	release：循环释放链表的空间
	@p：用来向前递进
	@n：跟着p后进行释放
*/

int release(note *p,note *n)
{
	
	while (n)
	{
		p = p->next;
		free(n);
		n=p;
	}
}

int main()
{
	printf("输入一个数组\n");
	note *n = list();//定义n接收链表的第一个地址
	
	printf("输入一个数组\n");
	note *m = list();//定义n接收链表的第一个地址

	int a = brach(n,m);
	
	printf("%d",a);
	
	note *p;
	p = n;
	release(n,p);
	p = m;
	release(m,p);
	
	printf("\n");
	return 0;
}

