#include "DoubleList.h"

//创建一个双向链表,返回一个头结点指针
HNODE *create_list()
{
	HNODE *l = (HNODE *)malloc(sizeof(HNODE));
	//if(l == NULL)
	l->first = NULL;
	l->tail = NULL;
	l->len = 0;
	return l;
}

//把数据信息加入链表
void tail_insert(HNODE* list,CLI_INFO node)
{
	if(list == NULL)
	{
		return ;
	}
	//创建一个结点,并且初始化
	
	
	
	NODE *new = (NODE *)malloc(sizeof(NODE));
	new->prev =NULL;
	new->next =NULL;
	
	new->data.fd = node.fd;
	new->data.fp= node.fp;
	new->data.port = node.port;
	memset(new->data.ip,0,sizeof(new->data.ip));
	strcpy(new->data.ip,node.ip);
	
	//把结点加入链表
	//1.如果链表为空
	if(list->len ==0)
	{
		list->first = new;
		list->tail = new;
		list->len++;
	}else
	{
		//2.如果不为空，尾插法
		list->tail->next = new;
		new->prev = list->tail;
		list->tail = new;
		list->len++;
	}
}

//根据fd找到链表中的结点
//没找到返回NULL
NODE *find_node(HNODE* list,int fd)
{
	if(list == NULL)
	{
		return NULL;
	}
	
	NODE *tmp = list->first;
	while(tmp)
	{
		if(tmp->data.fd == fd)
		{
			break;
		}
		tmp = tmp->next;
	}
	
	return tmp;
}


//根据fd找到结点并删除结点
/*
结点的删除分为：
删除的是第一个结点
删除的是最后一个结点
删除的是中间的结点
*/
void del_node(HNODE* list,NODE *node)
{
	if(list == NULL)
	{
		return ;
	}
	
	NODE *tmp = node;
	
	//删除node结点
	if(tmp == list->first && tmp == list->tail)
	{
		list->first = NULL;
		list->tail = NULL;
		list->len = 0;
		free(tmp);
		return ;
	}
	
	if(tmp == list->first)
	{
		list->first = tmp->next;
		tmp  = tmp->next;
		tmp->prev = NULL;
		free(node);
		list->len--;
		return ;	
	}
	
	if(tmp == list->tail)
	{
		list->tail = tmp->prev;
		list->tail->next = NULL;
		
		free(node);
		list->len--;
		return ;	
	}
	
	tmp->prev->next = tmp->next;
	tmp->next->prev = tmp->prev;
	free(tmp);
	list->len--;
	
}



//打印链表,打印IP和端口号
void print_list(HNODE* list)
{
	if(list == NULL)
	{
		return ;
	}
	
	NODE *tmp = list->first;
	while(tmp)
	{
		printf("list ip:%s,port:%d\n",tmp->data.ip,tmp->data.port);
		tmp = tmp->next;
	}

}

