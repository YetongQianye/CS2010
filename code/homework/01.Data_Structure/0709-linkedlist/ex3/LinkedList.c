
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

/*
	zxl：判断一条链表的元素是否为另一条链表的子集
	@pa：指向一条链表的首地址
	@pb：指向一条链表的首地址
*/

int brach(Head *la,Head *lb)
{
	if(la == NULL || la->first == NULL)
	{
		return 1;
	}
	if(lb == NULL || lb->first == NULL)
	{
		return 0;
	}
	Node *pa = la->first; //la链表的第一个数据结点
	Node *pb = lb->first;
	Node *pf = lb->first;

	while(pb)
	{
		//尝试找第一个相同的结点
		if(pb->data != pa->data)
		{
			pb = pb->next;
			continue;
		}
		//记录pb的下一个位置,作为下一次开始查找的位置
		pf = pb->next;
		//pb指向的结点的值和pa指向的结点的值相等
		//pb指向的位置,可能存在子序列,验证(一起往后比较)
		while(pa && pb)
		{
			if(pa->data != pb->data)
			{
				break;
			}
			pa = pa->next;
			pb = pb->next;
		}
		if(pa == NULL)
		{
			return 1;//有子序列
		}else if(pb == NULL)
		{
			return 0;//肯定没有子序列
		}

		//因为break而退出前面的循环，寻找下一个可能存在子序列的位置
		pa = la->first;
		pb = pf;
	}
}









