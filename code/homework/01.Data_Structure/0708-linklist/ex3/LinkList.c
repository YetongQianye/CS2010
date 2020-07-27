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
create_list_by_digital:建立一个链表逆序存储一个整数的各个位上的数字
list:指向链表的第一个结点
*/
struct node * create_list_by_digital(char *num)
{
	struct node *first = NULL; //指向链表第一个节点
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






