#include"LinkedList.h"

/*
create_list:创建一个带头节点单链表(只需要开辟一个头结点并且初始化即可)
返回值:
	成功返回创建的带头节点单链表的头结点指针
	失败返回NULL
*/
Head *create_list()
{
	//头结点就表示一个链表
	Head *h = (Head *)malloc(sizeof(Head));
	h->first = h->last = NULL;
	h->num = 0; //暂时还没有数据结点
	
	return h;
}


/*
insert_element:往带头节点单链表中插入一个元素(实现头插法,尾插法,建立有序链表)
@x:你要插入的元素
@h:你要增加元素的链表的头结点地址
返回值:
	无
*/
void insert_element(ElemType x,Head *h)
{
	//为x分配一个结点空间且初始化
	Node *p = (Node *)malloc(sizeof(*p));
	p->next = NULL;
	p->data = x;

	//把p表示的结点加入链表h
	if(h->first == NULL)
	{
		//链表中没有数据结点
		h->first = h->last = p;
	}else
	{
		//头插法
		//p->next = h->first;
		//h->first = p;
		
		//尾插法
		//h->last->next = p;
		//h->last = p;

		//建立有序链表
		//找插入位置
		Node *pk = h->first;//指向链表中第一个比p大的结点
		Node *pr = h->first;//指向pk的前一个结点
		while(pk)
		{
			if(pk->data > p->data)
			{
				break;
			}
			pr = pk;
			pk = pk->next;
		}
		//分情况插入,分三种情况,头插，尾插，中间
		if(pk == h->first)
		{
			p->next = h->first;
			h->first = p;
		}else if(pk == NULL)
		{
			h->last->next = p;
			h->last = p;
		}else
		{
			pr->next = p;
			p->next = pk;
		}
	}	
	h->num++;
}



//根据用户从键盘上的输入来创建一个有序链表
// 用户输入0表示结束
struct node *create_LinkedList(void)
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

#if 0
void print_list(struct node *p)
{
	while (p)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}
#endif
//打印指定的链表
void print_list(Head *h)
{
	if(h == NULL || h->first == NULL)
	{
		//链表不存在或者没有数据结点
		printf("no data node\n");
		return ;
	}
	printf("elem num:%d,data node:",h->num);
	Node *p = h->first;
	while(p)
	{
		printf("%d ",p->data); 
		p = p->next;
	}
	printf("\n");
}
struct node* middle(struct node *h)
{
	struct node *pr = NULL;
	struct node *pk = NULL; 
	
	pr=h;
	pk=h;
  
	while(pk)
	{
		pk=pk->next;
		if(pk)
		{
			pk=pk->next;
			if(pk)
			{
				pr=pr->next;
			}
		}
	}
	return pr;		
		
}







