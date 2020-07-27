#include"LinkedList.h"

#include <stdlib.h>
#include <stdio.h>

struct node* reciprocal(struct node *h,unsigned int k)
{
	
	struct node *pr = NULL;
	struct node *pk=NULL; 
 
	pk=h;
	pr=h;
	while(k)
	{
		pk=pk->next;
		k--;
	}
	while(pk)
	{
		pk=pk->next;
		pr=pr->next;
		
	}
	return pr;		
		
}

struct node *create_LinkedList(void) //创建链表 
{

	struct node *first = NULL; //指向创建后的链表的第一个结点的指针
	struct node *last = NULL; //指向创建后的链表的最后一个结点的指针
	struct node *p = NULL;  //指向每次创建的那个结点的地址

	int d;

	while (1)
	{
		//1. 从键盘上接收一个用户输入的数据
		scanf("%d", &d);
		if (d == 0)
		{
			break;
		}


		//2. 创建一个结构体来保存这个数据
		p = malloc(sizeof(*p));
		p->data = d;
		p->next = NULL;


		//3. 把创建的这个结构体加入到first指向的链表中去
		if(first==NULL)
		{
			first=p;
			last=p;
		}
		else
            //尾插法
		{
			last->next=p;
			last=p;
		}
		
	}
	return first;
}



void print_list(struct node *p)  //输出链表 
{
	while(p)
	{
		printf("%d",p->data);
		p=p->next;
	}
	printf("\n");
	
}













