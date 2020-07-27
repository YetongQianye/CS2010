#ifndef __ZY3_H__
#define __ZY3_H__


typedef int ElemType ; //数据元素的类型


//数据结点
typedef struct node
{
	ElemType data; //数据域

	struct node *next; //指针域
} Node;



#endif


