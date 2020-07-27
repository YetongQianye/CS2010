#ifndef __DOUBLELINKLIST_H__
#define __DOUBLELINKLIST_H__

#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;	//ElemType相当于int
//普通结点的类型
typedef struct node 
{		
	ElemType data;  //数据域,保存用户的数据
	struct node *next,*prev; //指针域,保存数据元素之间的关系
}Node;

//头结点的类型,一个头结点就表示一个链表
typedef struct LinkedList
{
	Node *first;//指向链表的第一个结点
	Node *last;//指向链表的最后一个结点
	int num;
}Head;

/*
create_list:创建一个带头节点的双向链表
返回值:返回头结点的指针
*/
Head *create_list();


//往带头节点双向链表中插入元素(头插法,尾插法,有序)
void add_Elem_to_list(Head *l,ElemType x);


//打印一个带头节点的双向链表
void print_list(Head *l);

//清空链表(释放所有数据结点)
void clear_list(Head *l);

//删除链表(先释放所有数据结点,再释放头结点)
void delete_list(Head *l);

//删除指定的x
void delete_x(Head *l,ElemType x);

//删除所有的x
void delete_all_x(Head *l,ElemType x);

//查找x
//返回找到的结点的指针,如果不存在,返回NULL
Node *find_x(Head *l,ElemType x);

#endif 