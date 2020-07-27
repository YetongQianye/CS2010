#ifndef __ZY2_H__
#define __ZY2_H__


typedef int ElemType ; //数据元素的类型


//数据结点
typedef struct node
{
	ElemType data; //数据域

	struct node *next; //指针域
} Node;


//头结点
typedef struct LinkedList
{
	struct node *first; //指向链表中的第一个结点
	struct node *last ; //指向链表中的最后一个结点

	// ...
	
} LinkedList;



#endif


