#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__


typedef int ElemType; //数据元素类型

//"数据结点"
struct node
{
	ElemType data; //"数据域"：保存数据元素的


	struct node *next ; //“指针域”：保存下一个数据元素的地址的
						//如果下一个为空，则 NULL
};




#endif
