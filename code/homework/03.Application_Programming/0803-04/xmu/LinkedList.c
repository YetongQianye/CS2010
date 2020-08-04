#include"LinkedList.h"

/*
 create_linklist:根据用户的输入，创建一个链表
返回值：
	指针，返回链表的头结点的地址
*/

LinkedList* create_linklist()
{
	//创建一个头结点,并且初始化
	LinkedList* head = (LinkedList*)malloc(sizeof(*head));//创建了一个头结点
	//新创建的头结点还没有数据结点
	head->first = NULL;
	head->last = NULL;
	head->nodeNum = 0;
	

	return head;
}

/*
insert_node:往一个带头结点链表(有序)中插入一个结点，
			使插入后的链表任然有序，结点数据通过参数传递
@h:你要插入的带头结点链表的头结点的地址
@a:你要插入的结点的数据
*/
LinkedList *insert_node(LinkedList *head,ElemType *pathname)
{
	struct node *p = NULL;//指向新创建的那个结点的指针
	//.申请新结点需要的空间，保存用户输入的数据，为什么要这么做？？？你们都懂了
	//新申请的结点的每一个成员变量都建议初始化
	p = (struct node *)malloc(sizeof(struct node));//空间已经分配下来了
	strcpy(p->data,pathname);
	p->next = NULL;

	//3.把新结点插入到链表
	if(head->first == NULL)//这个链表中还没有数据结点
	{
		head->first = p;
		head->last = p;
		head->nodeNum++;
	}else
	{
		//"尾插法"--》把新结点放到链表的后面，按照输入顺序建立链表
		head->last->next = p;
		head->last = p;
		head->nodeNum++;
	}	
}


/*
find_x:查找带头结点链表中是否有x这个数据结点，x通过参数传递
@h:你要查找的带头结点链表的第一个结点的地址
@x:你要查找的数据
返回值：
	找到了返回1，没找到返回0
*/

int find_x(LinkedList* h,ElemType *pathname)
{
	struct node *p = h->first;
	while(p)
	{
		if(!strcmp(p->data,pathname))
		{
			return 1;
		}
		p = p->next;
	}
	return 0;
}

/*
delete_x:删除带头结点链表中的第一个x，x通过参数传递
@h:你要删除的带头结点链表的头结点的地址
@x:你要删除的数据
返回值：
	返回删除后的链表的头结点
*/
LinkedList * delete_x(LinkedList *h,ElemType *pathname)
{
	struct node *px = NULL;//指向链表中要删除的那个结点
	struct node *pr = NULL;//指向pk前面那个结点
	//1.遍历整个链表找到x
	px = h->first;
	while(px)
	{
		if(!strcmp(px->data,pathname))//找到了第一个 x
		{
			break;
		}
		//pr = px; 记录px前面那个结点
		px = px->next;
	}
	
	//如果没有记录pr
	pr = h->first;
	while(pr && pr->next != px)
	{
		pr = pr->next;
	}
	
	//2.删除操作
	//如果px为NULL,说明链表中没有x
	if(px == NULL)
	{
		return h;
	}
	
	//px是第一个结点
	if(px == h->first)
	{
		h->first = px->next;
		px->next = NULL;
		free(px);
		h->nodeNum--;
		if(h->first == NULL)//链表中只有一个数据结点。
		{
			h->last = NULL;
		}

	}else if(px == h->last)//px是指向最后的一个数据结点
	{
		pr->next = NULL;
		h->last = pr;
		free(px);
		h->nodeNum--;
	}else
	{
		pr->next = px->next;
		px->next = NULL;
		free(px);
		h->nodeNum--;
	}
	return h;
}



/*
delete_all_x:删除带头结点链表中的所有x，x通过参数传递
@h:你要删除的带头结点链表的头结点的地址
@x:你要删除的数据
返回值：
	返回删除后的链表的头结点
*/
LinkedList * delete_all_x(LinkedList *list,ElemType *pathname)
{
	//自己写
}


/*
delete_list:清空链表，把所有的数据结点都删掉

*/

/*
delete_listwithhead:删除链表，删除所有的数据结点后在删除头结点
@h:你要删除的链表
返回值：
	无
*/
void delete_listwithhead(LinkedList* h)
{
	if(h == NULL)
	{
		return;
	}
	//先删除所有数据结点
	struct node *p = h->first;
	while(p)
	{
		h->first = p->next;
		p->next = NULL;
		free(p);
		h->nodeNum--;
		
		p = h->first;
	}
	
	h->last = NULL;
	
	//把头结点删除
	free(h);
}


/*
print_list:打印一个带头节点的单链表的所有的数据结点
p:需要打印的链表的头结点的地址
返回值：
	无
*/
void print_list(LinkedList *h)
{
	if(h == NULL)
	{
		return;
	}
	struct node *p = h->first;
	while(p)
	{
		printf("%s\n",p->data);
		p = p->next;
	}
	printf("\n");
	printf("nodeNum = %d\n",h->nodeNum);
	return;
}


/*
根据当前结点找到上一个结点
*/
struct node* find_pre(LinkedList *h,struct node *p)
{
	//如果链表为空
	if(h->first == NULL)
	{
		printf("list is NULL\n");
		return NULL;
	}
	//如果链表只有一个结点
	if(h->first == h->last)
	{
		return h->first;
	}
	//如果p为第一个结点，且链表不止一个节点
	if(h->first == p)
	{
		return h->last;
	}
	
	struct node* k = h->first;
	while(k->next != p)
	{
		k = k->next;
	}
	return k;
}










