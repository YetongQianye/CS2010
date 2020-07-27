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
insert_elemt:往带头节点单链表中插入一个元素(实现头插法,尾插法,建立有序链表)
@x:你要插入的元素
@h:你要增加元素的链表的头结点地址
返回值:
	无
*/
void insert_elemt(ElemType x,Head *h)
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

//查找元素值为x的结点
Node *find_x(ElemType x,Head *h)
{
	if(h == NULL || h->first == NULL)
	{
		//链表不存在或者没有数据结点
		return NULL;
	}	
	Node *p = h->first;
	while(p)
	{
		if(p->data == x)
		{
			break;
		}
		p = p->next;
	}
	return p;
}

//删除元素值为x的结点
void delete_x(ElemType x,Head *h)
{
	if(h == NULL || h->first == NULL)
	{
		//链表不存在或者没有数据结点
		return ;
	}
	Node *px = NULL; //指向要删除的结点
	Node *pr = NULL; //指向要删除的结点的前一个结点
	
	//先找到要删除的结点
	px = h->first;
	while(px)
	{
		if(px->data == x)
		{
			break;
		}
		pr = px;
		px = px->next;
	}
	//分情况删除
	if(px == NULL) //没找到
	{
		return;
	}

	//删除分三种情况
	//第一个结点 px == h->first
	//最后一个结点 px == h->last
	//删除中间
	if(px == h->first)
	{
		h->first = px->next;
		if(h->first == NULL) //只有一个数据结点
		{
			h->last = NULL;
		}
	}else if(px == h->last)
	{
		pr->next = NULL;
		h->last = pr;
	}else
	{
		pr->next = px->next;
	}
	px->next = NULL;
	h->num --;
	free(px);
}
//删除所有元素值为x的结点
void delete_all_x(ElemType x,Head *h)
{
	if(h == NULL || h->first == NULL)
	{
		//链表不存在或者没有数据结点
		return;
	}
	Node *px = NULL; //指向要删除的结点
	Node *pr = NULL; //指向要删除的结点的前一个结点
	Node *p = h->first;
	while(1)
	{
		//先找到要删除的结点
		px = p;
		while(px)
		{
			if(px->data == x)
			{
				p = px->next;
				break;
			}
			pr = px;
			px = px->next;
		}
		//分情况删除
		if(px == NULL) //没找到
		{
			return;
		}

		//删除分三种情况
		//第一个结点 px == h->first
		//最后一个结点 px == h->last
		//删除中间
		if(px == h->first)
		{
			h->first = px->next;
			if(h->first == NULL) //只有一个数据结点
			{
				h->last = NULL;
			}
		}else if(px == h->last)
		{
			pr->next = NULL;
			h->last = pr;
		}else
		{
			pr->next = px->next;
		}
		px->next = NULL;
		h->num --;
		free(px);
	}
}


//清空链表(释放所有数据结点)
void clear_list(Head *h)
{
	if(h == NULL || h->num == 0)
	{
		//链表不存在或者没有数据结点
		return ;
	}
	//删除所有的数据结点
	Node *p = h->first;
	while(p)
	{
		h->first = p->next;
		p->next = NULL;
		free(p);
		p = h->first;
	}

	h->first = h->last = NULL;
	h->num = 0;
	return ;
	
}
//删除链表(先释放所有数据结点,再释放头结点)
void delete_list(Head *h)
{
	clear_list(h);
	free(h);
}













