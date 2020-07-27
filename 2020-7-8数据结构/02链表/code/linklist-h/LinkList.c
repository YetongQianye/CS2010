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
#if 0
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
#endif			
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
insert_node:往一个链表中加入一个结点(头插法,尾插法,有序)
@p:指向你要加入链表的结点
@list:指向你要加入的链表
返回值:
	返回插入后的链表的第一个结点
*/
struct node *insert_node(struct node *p,struct node *list)
{
	//头插法
	//p->next = list;
	//list = p;
	if(list == NULL)
	{
		return p;
	}else
	{
		//先找到最后一个结点
		struct node *last = list;
		while(last && last->next != NULL)
		{
			last = last->next;
		}
		//尾插法
		//last->next = p;
		//last = p;

		//建立有序链表(升序)
		//a.找插入位置.第一个比p数据大的结点pk,记录pk的前一个结点pr
		struct node *pk = NULL;
		struct node *pr = NULL;
		pk = list;
		while(pk)
		{
			if(pk->data > p->data)
			{
				break; //pk就指向第一个比p数据大的结点
			}
			pr = pk;
			pk = pk->next;
		}
		
		//b.分情况插入
		if(pk == list) //第一个结点就比p大
		{
			p->next = list;
			list = p;
		}else if(pk == NULL) //最后一个结点都比p小
		{
			pr->next = p;
			pr = p;
		}else
		{
			pr->next = p;
			p->next = pk;
		}
	}
	return list;
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
	struct node *px = NULL;//指向要删除的结点
	struct node *pr = NULL;//指向要删除的结点前一个
	struct node *p = NULL;//指向要删除的结点下一个
	p = list;
	while(1)
	{
		//先找到要删除的结点的指针
		px = p;
		while(px)
		{
			//printf("%s:%d\n",__FUNCTION__,__LINE__);
			if(px->data == x)
			{
				p = px->next;//记录下一次开始查找的位置
				break;
			}
			//printf("%s:%d\n",__FUNCTION__,__LINE__);
			pr = px;
			px = px->next;
		}
		
		if(px == NULL)
		{
			break;
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
		
	}
	return list;
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
find_x:在指定的链表中查找值为x的结点
@x:你要查找的元素
@list:指向你要查找元素的链表的第一个结点
返回值
	返回找到的结点的指针
	如果没找到返回NULL
*/
struct node *find_x(ElemType x,struct node *list)
{
	struct node *p = list;
	while(p)
	{
		if(p->data == x)//找到了
		{
			break;
		}
		p = p->next;
	}
	return p;
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
写一个函数反序输出单链表各个结点的值(不能改变原链表的内容和结构)
		如:链表为 		1 3 5 7 9 
		输出为:		9 7 5 3 1	
思路1:
	遍历链表,把每一个结点的值(指针)保存到数组
	再反序输出
*/	

void print_reverse_list1(struct node *list)
{
	
	//把所有的结点遍历一遍,把指针存储到一个数组中
	//逆序打印数组
	printf("print_reverse_list:");
	struct node *np[1024] = {0}; //指针数组
	int i = 0;
	//保存每一个结点的指针
	while(list)
	{
		np[i++]=list;
		list = list->next;
	}

	while(i)
	{
		printf("%d ",np[--i]->data);
	}
	printf("\n");

}


void print_reverse_list2(struct node *list)
{
	//递归实现
	if(list == NULL)
	{
		return;
	}
	print_reverse_list2(list->next);
	printf("%d  ",list->data);
	
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

struct node *reverse_list2(struct node *list)
{
	//记录每一个结点的值
	ElemType d[1024] = {0};
	struct node *p = list;
	int i = 0;
	
	while(p)
	{
		d[i++] = p->data;
		p = p->next;
	}
	//反序赋值
	p = list;
	while(i)
	{
		p->data = d[--i];
		p = p->next;
	}
	return list;
}


struct node *reverse_list3(struct node *list)
{
	if(list == NULL)
	{
		return list;
	}
	struct node *p;//从前往后走
	struct node *q;//从后往前走
	struct node *t;//从后往前走
	p = list;
	//找最后一个结点
	q = list;
	while(q && q->next != NULL)
	{
		q = q->next;
	}

	int tmp;
	while(1)
	{
		//交换数据域
		tmp = p->data;
		p->data = q->data;
		q->data = tmp;
		
		if(p==q || p->next == q)
		{
			break;
		}
		
		p = p->next;
		//找q的前一个位置
		t = q;
		q = list;
		while(q && q->next != t)
		{
			q = q->next;
		}
	}
	return list;
}


struct node *reverse_list4(struct node *list)
{
	if(list == NULL || list->next == NULL)
	{
		return list;
	}
	struct node *left = list;
	struct node *right = list->next;
	struct node *px = right->next;
	left->next = NULL;
	while(1)
	{
		right->next = left;
		if(px == NULL)
		{
			break;
		}
		left = right;
		right = px;
		px = px->next;
	}

	return right;
}


struct node *reverse_list5(struct node *list)	
{
	if(list == NULL  || list->next==NULL)
		return list;
		
	struct node* first = reverse_list5(list->next);

	//找到最后一个结点
	struct node* temp=first;
	while(temp->next)
	{
		temp=temp->next;
	}
	//把最后一个结点放到前面
	temp->next = list;
	list->next =NULL;
	
	return first;
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











