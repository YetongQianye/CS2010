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

			//头插法:按照用户的输入逆序建立链表
			//p->next = first;
			//first = p;
			
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
delete_x:删除指定无序链表中的第一个x元素
@x:你要删除的元素
@list:指向你要删除元素的链表的第一个结点
返回值:
	返回删除后的链表的第一个结点
*/
struct node *delete_x(ElemType x,struct node *list)
{
	struct node *px = NULL;//指向要删除的结点
	struct node *pr = NULL;//指向要删除的结点前一个
	//先找到要删除的结点的指针
	/*
	px = find_x(x,list);
	pr = list;
	while( pr && pr->next != px)
	{
		pr = pr->next;
	}
	*/
	px = list;
	while(px)
	{
		if(px->data == x)
		{
			break;
		}
		pr = px;
		px = px->next;
	}
	if(px == NULL)
	{
		return list;
	}

	//删除操作,分情况删除
	if(px == list) //如果要删除的结点是第一个结点
	{
		list = list->next;
	}else
	{
		pr->next = px->next;
	}
	px->next = NULL;
	free(px);
	return list;
}



/*
delete_list:删除整个链表
@list:你要删除的链表
返回值:
	无
*/
void delete_list(struct node * list)
{
	if(list == NULL)
	{
		return;
	}
	struct node *p = list;
	while(p)
	{
		list = list->next;
		free(p);
		p = list;
	}
	return;
}



/*
建立一个链表逆序存储一个整数的各个位上的数字
		如输入:13245
		建立链表:5->4->2-->3--->1
*/		
struct node *create_list_by_num(char *num)
{
	struct node *first = NULL; //指向链表的第一个结点
	struct node *p = NULL;

	while(*num && *num >= '0' && *num <= '9') //num指向的字符不为'\0'
	{
		//把num指向的字符用结点保存并且加入first表示的链表
		p = (struct node *)malloc(sizeof(*p));
		p->data = *num-'0';
		p->next = NULL;
		num++;
		//头插法
		if(first == NULL)
		{
			first = p;
		}else
		{
			p->next = first;
			first = p;
		}
	}
	return first;
}



//使用链表逆序存储两个整数,实现两个超大数的加法,把结果链表返回
		
struct node *add_two_numbers(struct node *la,struct node *lb)
{
	struct node *first = NULL; //指向结果链表的第一个结点
	struct node *p = NULL;
	//同时遍历两个链表
	struct node *pa = la;
	struct node *pb = lb;
	int a,b;
	int c = 0;
	int sum;

	while(pa || pb || c)
	{
		//取两个加数
		a = pa?pa->data:0;
		b = pb?pb->data:0;
		//相加,把结果按照头插法存入新链表
		sum = (a+b+c)%10;
		c = (a+b+c)/10;
		
		p = (struct node *)malloc(sizeof(*p));
		p->data = sum;
		p->next = NULL;
		//头插法
		if(first == NULL)
		{
			first = p;
		}else
		{
			p->next = first;
			first = p;
		}
		//取下一个位
		pa = pa?pa->next:NULL;
		pb = pb?pb->next:NULL;

	}

	return first;
}
