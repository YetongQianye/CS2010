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
单链表就地逆置(不能申请新的空间,利用原有结点的空间)
		如链表为 1 3 5 7 9 
		逆置后的链表为:9 7 5 3 1

思路1：	
	把原链表的结点一个一个摘下来,然后按照“头插法”加入新链表中
思路2:
	遍历链表,把链表的每一个结点的值记录下来,反序赋值到结点中
思路3:
	交换数据域,
	把第一个结点的值和最后一个结点的值交换
	把第而个结点的值和最后一个结点的值交换
思路4:
	每一次考虑两个结点......
*/		
struct node *reverse_list(struct node *list)
{
	//指向新创建的链表的第一个结点
	struct node *first = NULL;

	//把原链表的结点一个一个取下来加入新链表
	struct node *p = NULL;//指向取下来的结点
	p = list;
	while(p)
	{
		//先把p指向的结点摘下来
		list = list->next;
		p->next = NULL;
		//把p指向的结点按照头插法加入first表示的链表
		if(first == NULL)
		{
			first = p;
		}else
		{
			p->next = first;
			first = p;
		}
		//取原链表的下一个结点
		p = list;
	}
	return first;

}



		




