
#include <stdlib.h>
#include <stdio.h>

#include "LinkedListWithHead.h"


LinkedList* Create_LinkedList(void)
{
	LinkedList* l = malloc(sizeof(*l));

	l->first = NULL;
	l->last = NULL;

	return l;
}


/*
	Add_a_Node:在l指向的带头结点的单链表中，添加一个
			Node.
	@l: l指向单链表升序
	@p: 指向结点
*/
void Add_a_Node(LinkedList *l, Node *p)
{

	if (l == NULL || p == NULL)
	{
		return ;
	}


	Node *pk = l->first; //pk指向链表中第一个值比p->data大的结点
	Node *pr = NULL; //pr指向pk前面的那个结点

	if (l->first == NULL)
	{
		l->first = p;
		l->last = p;

		return ;
	}


	//1.  找插入位置: 遍历链表
	while (pk)
	{
		if (pk->data > p->data)
		{
			break;
		}

		pr = pk;
		pk = pk->next;
	}


	//2. 插入操作
	if (pk == NULL)
	{
		//链表中所有结点的值都比p->data要小。“尾插法”
		l->last->next = p;
		l->last = p;
	}
	else
	{
		if (pk == l->first)
		{
			//链表中第一个结点就比p->data要大。“头插法”
			p->next = l->first;
			l->first = p;
		}
		else
		{
			p->next = pk;
			pr->next = p;
		}
	}



}



//根据用户的输入，按升序建立一个带头结点的链表
LinkedList* creat_list(void)
{
	int d;
	
	LinkedList* l = Create_LinkedList();


	while (1)
	{
		scanf("%d", &d);
		if (d == 0)
		{
			break;
		}

		Node *p = malloc(sizeof(*p));
		p->data = d;
		p->next = NULL;

		Add_a_Node(l, p);

	}

	return l;
}



/*
	delete_all_x:在l指向的带头结点的单链表中，删除
		所有值为x的结点。
	@l: 指向头结点
	@x: 要删除的结点的元素值
	返回值:
		无
*/
void delete_all_x(LinkedList *l, ElemType x)
{
	if (l == NULL || l->first == NULL)
	{
		return ;
	}

	Node *px = l->first; //指向要删除的结点
	Node *pr = NULL; //pr指向px前面的那个结点

	Node *ps = l->first ; //每次查找的起始结点


	while (1)
	{
		px = ps;
		//1. 要找到要删除的结点px
		while (px)
		{
			if (px->data == x)
			{
				break;
			}

			pr = px;
			px = px->next;
		}

		//2. 删除操作
		if (px == NULL)
		{
			return ;
		}


		//下次查找，只需要从px的下一个开始即可，Do you understand ? 你懂的。
		ps = px->next;

		if (px == l->first)
		{
			l->first = px->next;
			px->next = NULL;
			free(px);

			if (l->first == NULL)
			{
				l->last = NULL;
			}
		}
		else if (px == l->last)
		{
			pr->next = NULL;
			l->last = pr;

			free(px);
		}
		else
		{
			pr->next = px->next;
			px->next = NULL;
			free(px);
		}
	}

}


void print_LinkedList(LinkedList *l)
{
	if (l == NULL || l->first == NULL)
	{
		return ;
	}

	Node *p = l->first;

	while (p)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
	
}

int main()
{

	LinkedList *l = creat_list();
	
	print_LinkedList(l);


	int x;
	scanf("%d", &x);

		delete_all_x(l, x);

	print_LinkedList(l);

	return 0;
}
