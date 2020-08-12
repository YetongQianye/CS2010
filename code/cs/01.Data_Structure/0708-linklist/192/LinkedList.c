

#include <stdio.h>
#include <stdlib.h>

#include "LinkedList.h"



/*
	Insert_a_Node:在h指向的升序的链表中，增加一个结点p
				使增加后的链表仍然有序
	@h: 指向已有的链表
	@p:　指向待插入的结点
	返回值:
		返回添加后新链表的第一个结点的指针
*/
struct node *Insert_a_Node(struct node *h, struct node *p)
{
	if (h == NULL)
	{
		return p;
	}
	
	if (p == NULL)
	{
		return h;
	}
	
	// 把p指向的结点，插入到h指向的链表中去。 "升序排列"
	// 1. 找插入位置
	//  "遍历"链表，找到第一个值比p->data大的那个结点pk(以及pk前面的那个结点pr)
	//	pk前面就是插入位置
	struct node *pk = h; // 指向链表中第一个比p->data值大的结点
	struct node *pr = NULL; //指向pk前面的那个结点

	while (pk)
	{
		if (pk->data > p->data)
		{
			break;
		}

		pr = pk;
		pk = pk->next;
	}
	
	// 2. 插入操作

	if (pk)
	{
		if (pk == h)
		{
			//头插法
			p->next = h;
			h = p;

		}
		else
		{
			//pk指向的后面的结点，pr指向pk前面的那个结点
			// p放置在pk的前面，pr的后面

			p->next = pk;
			pr->next = p;
		}
	

	}
	else 
	{	
		//没找到,=>现有链表所有结点的值都比p->data要小。
		//  pk == NULL, pr指向链表的最后一个结点
		// "尾插法"
		pr->next = p;
	}
	
	
	return h;
	
}




//根据用户从键盘上的输入来创建一个有序链表
// 用户输入0表示结束
struct node*
create_LinkedList(void)
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
		first = Insert_a_Node(first, p);
		
	}
	
	return first;
}


/*
	delete_x:在h指向的链表中，删除值为x的结点(假设顶多只有一个结点的值为x)
	@h: 指向链表(不一定有序，也可能是空链表)
	@x: 要删除的结点的元素值
	返回值:
		返回删除后的链表的第一个结点的指针
*/
struct node *delete_x(struct node *h, ElemType x)
{
	struct node *px = h; //px指向要删除的结点
	struct node *pr = NULL; //pr指向px前面的那个结点


	//1. 先找到要删除的结点 px (以及它前面的那个结点pr)
	while (px)
	{
		if (px->data == x)
		{
			//呵呵，找到了
			break;
		}

		pr = px;
		px = px->next;
	}



	//2. 删除操作
	//	(1) 先从原链表上把px摘下来
	//	(2) 再 free(px)
	if (px == NULL)
	{
		return h;
	}

	//找到了要删除的结点px
	// 分两种情况来删除:
	//		要删除的结点是第一个结点
	//		要删除的结点是后面的结点

	if (px == h)
	{
		h = px->next;
		px->next = NULL;

		free(px);
	}
	else
	{
		pr->next = px->next;
		px->next = NULL;

		free(px);
	}


	return h;
	
	


}


/*
	delete_all_x:在h指向的链表中，删除值为x的所有结点
	@h: 指向链表(不一定有序，也可能是空链表)
	@x: 要删除的结点的元素值
	返回值:
		返回删除后的链表的第一个结点的指针
*/
struct node *delete_all_x(struct node *h, ElemType x)
{
	struct node *px = h; //px指向要删除的结点
	struct node *pr = NULL; //pr指向px前面的那个结点

	struct node *ps = h; //每次查找的起始结点


	while (1)
	{

		px = ps;

		
		//1. 先找到要删除的结点 px (以及它前面的那个结点pr)
		while (px)
		{
			if (px->data == x)
			{
				//呵呵，找到了
				break;
			}

			pr = px;
			px = px->next;
		}



		//2. 删除操作
		//	(1) 先从原链表上把px摘下来
		//	(2) 再 free(px)
		if (px == NULL)
		{
			return h;
		}



		ps = px->next;// NOTE
		
		//找到了要删除的结点px
		// 分两种情况来删除:
		//		要删除的结点是第一个结点
		//		要删除的结点是后面的结点


		if (px == h)
		{
			h = px->next;
			px->next = NULL;

			free(px);
		}
		else
		{
			pr->next = px->next;
			px->next = NULL;

			free(px);
		}

	}

	return h;
	
	


}

/*
	find_last:在h指向的单链表中，查找最后一个结点
			并把其指针返回
	@h:
	返回值:
		最后一个结点的指针
*/		
struct node* find_last(struct node *h)
{
	struct node *p = h; //p指向最后一个结点

	while (p)
	{

		if (p->next == NULL)
		{
			return p;
		}
		else
		{
			//继续往后面找
			p = p->next;
		}

	}




	return p;

}




void print_list(struct node *p)
{
	while (p)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

struct node *merge(struct node *ha, struct node *hb)
{
	struct node *pc = NULL;//指向合并后的链表的第一个结点
	struct node *pr = NULL;
	if (ha == NULL)
	{
		return hb;
	}
	
	if (hb == NULL)
	{
		return ha;
	}
	
	pc = ha->data < hb->data ? ha : hb;
	
	while (ha && hb)
	{
		if (ha->data < hb->data)
		{
			while (ha && ha->data < hb->data)
			{
				pr = ha;
				ha = ha->next;
			}
			
			pr->next = hb;
		}
		else
		{
			while (hb && hb->data < ha->data)
			{
				pr = hb;
				hb = hb->next;
			}
			
			pr->next = ha;
		}
	
	}
	
	return pc;
	
}


int main()
{
	struct node *ha = create_LinkedList();
	printf("ha: ");
	print_list(ha);
	
	struct node *hb = create_LinkedList();
	printf("hb: ");
	print_list(hb);


	struct node *hc = merge(ha,hb);
	printf("hc: ");
	print_list(hc);
	
	return 0;
}

