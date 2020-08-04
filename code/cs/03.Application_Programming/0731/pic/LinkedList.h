#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__
 
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
 
typedef char ElemType;//定义了一个新的类型名，等同于int

struct node //定义一个结构体类型，作为链表的数据元素
{
	ElemType data[256];//存储数据  数据域(D)
	struct node *next;//存储的是下一个元素的地址  指针域
};

typedef struct LinkList
{
	struct node * first;//指向链表的第一个结点
	struct node * last;//指向链表的最后一个结点
	int nodeNum;//当前结点个数
}LinkedList;

/*
 create_linklist:根据用户的输入，创建一个链表
返回值：
	指针，返回链表的头结点的地址
*/
LinkedList* create_linklist();


/*
insert_node:往一个带头结点链表(有序)中插入一个结点，
			使插入后的链表任然有序，结点数据通过参数传递
@h:你要插入的带头结点链表的头结点的地址
@a:你要插入的结点的数据
*/
LinkedList *insert_node(LinkedList *list,ElemType *pathname);


/*
find_x:查找带头结点链表中是否有x这个数据结点，x通过参数传递
@h:你要查找的带头结点链表的第一个结点的地址
@x:你要查找的数据
返回值：
	找到了返回1，没找到返回0
*/

int find_x(LinkedList* h,ElemType *pathname);


/*
delete_x:删除带头结点链表中的第一个x，x通过参数传递
@h:你要删除的带头结点链表的头结点的地址
@x:你要删除的数据
返回值：
	返回删除后的链表的头结点
*/
LinkedList * delete_x(LinkedList *h,ElemType *pathname);



/*
delete_all_x:删除带头结点链表中的所有x，x通过参数传递
@h:你要删除的带头结点链表的头结点的地址
@x:你要删除的数据
返回值：
	返回删除后的链表的头结点
*/
LinkedList * delete_all_x(LinkedList *list,ElemType *pathname);


/*
delete_listwithhead:删除链表，删除所有的数据结点后在删除头结点
@h:你要删除的链表
返回值：
	无
*/
void delete_listwithhead(LinkedList* h);

/*
print_list:打印一个带头节点的单链表的所有的数据结点
p:需要打印的链表的头结点的地址
返回值：
	无
*/
void print_list(LinkedList *h);


/*
根据当前结点找到上一个结点
*/
struct node* find_pre(LinkedList *h,struct node *p);



#endif










