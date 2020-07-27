#include"LinkList.h"

/*
create_linklist:根据用户的输入建立一个链表
返回值:
	返回创建的链表
	链表的第一个结点的地址
*/
//返回值类型       函数名(参数类型列表);
struct node  *create_linklist()
{
	//printf("%s:%d\n",__FUNCTION__,__LINE__);
	//保存新创建的结点的地址
	struct node *p =NULL;
	//保存新创建的链表的第一个结点
	struct node *first =NULL;
	//保存新创建的链表的最后一个结点
	struct node *last =NULL;
	int d;
	printf("please input the num\n");
	while(1)
	{
		//接收用户输入
		scanf("%d",&d);
		if(0 == d)
		{
			break;
		}
		//创建一个结点,用于保存刚刚输入的数据
		//新创建的结点的每一个成员都建议初始化
		//struct node p;  不行,生存期仅仅在{}内部
		//p = malloc(sizeof(struct node));
		p = malloc(sizeof(*p));
		p->data = d;
		p->next = NULL;

		//把创建的结点加入链表
		if(first == NULL) //链表还不存在(没有结点)
		{
			first = last = p;
		}else
		{
			//尾插法:按照用户的输入建立链表
			last->next = p;
			last = p;

						
		}
		
	}
	return first;
}

/*
print_list:打印指定的链表
@list:第一个结点的地址
返回值:
	无
*/
void print_list(struct node *list)
{
	if(list == NULL)
	{
		printf("list is no element\n");
		return;
	}
	while(list)
	{
		printf("%d  ",list->data);
		list = list->next;
	}
	printf("\n");
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

