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
print_reverse_list:反序输出单链表各个结点的值
list:指向链表的第一个结点
*/
void print_reverse_list(struct node *list)
{
	printf("逆序输出为\n");
	struct node* a[100];	//定义一个指针数组
	int i = 0;
			
	while (list)
	{
		a[i++] = list;
		list = list->next;
	}
			
	i--;
	while (i >= 0)
	{
		printf("%d ", a[i]->data);
		i--;
	}
	printf("\n");
}






