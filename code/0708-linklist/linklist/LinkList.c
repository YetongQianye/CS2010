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
			//last->next = p;
			//last = p;

			//头插法:按照用户的输入逆序建立链表
			//p->next = first;
			//first = p;

			//建立有序链表(升序)
			//a.找一个插入位置,遍历链表,找到链表中第一个比P数据大的结点pk
			struct node *pk = NULL;
			struct node *pr = NULL; //记录pk前面的结点pr
			pk = first;
			while(pk)
			{
				if(pk->data > p->data)//找到了第一个比p大的结点
				{
					break;
				}
				pr = pk; //记录pk的前一个位置
				pk = pk->next;
			}
			//pk就是p的后面的结点
			/*
			pr = first;
			while( pr && pr->next != pk)
			{
				pr = pr->next;
			}
			*/
			//b.分情况插入操作
			//(1).链表中所有结点都比P大(第一个结点就比P大)                  (pk == first) --头插法
			//(2).p的值比链表中所有结点都大(pk == NULL) ---尾插法
			//(3).插入到中间
			if(pk == first)
			{
				p->next = first;
				first = p;
			}else if(pk == NULL)
			{
				last->next = p;
				last = p;
			}else
			{
				pr->next = p;
				p->next = pk;
			}	
			
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
	while(list)
	{
		printf("%d  ",list->data);
		list = list->next;
	}
	printf("\n");
}

/*
insert_node:往一个链表中加入一个结点(头插法,尾插法,有序)
@p:指向你要加入链表的结点
@list:指向你要加入的链表
返回值:
	返回插入后的链表的第一个结点
*/
struct node *insert_node(struct node *p,struct node *list)
{
	
	//找插入位置
	
	//分情况插入
	
	
}

/*
delete_all_x:删除指定链表中的所有的x元素
@x:你要删除的元素
@list:指向你要删除元素的链表的第一个结点
返回值:
	返回删除后的链表的第一个结点
*/
struct node *delete_all_x(ElemType x,struct node *list)
{


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
	//先找到要删除的结点的指针

	//删除操作

}

/*
find_x:在指定的链表中查找值为x的结点
@x:你要查找的元素
@list:指向你要查找元素的链表的第一个结点
返回值
	返回找到的结点的指针
*/
struct node *find_x(ElemType x,struct node *list)
{



}



