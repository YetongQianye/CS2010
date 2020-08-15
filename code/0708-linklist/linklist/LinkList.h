
#ifndef   __LINKLIST_H__   //if no define 
#define   __LINKLIST_H__   //防止重复包含

#include<stdio.h>
#include<stdlib.h>


//接口文件(类型的定义和函数的声明)
//假设当前的用户数据类型为int
typedef int ElemType;

//结点类型(包含用户数据和一个指针(关系))
struct node 
{
	ElemType data;//数据域
	struct node *next;//指针域,指向下一个结点的地址
};


/*
create_linklist:根据用户的输入建立一个链表
返回值:
	返回创建的链表
	链表的第一个结点的地址
*/
//返回值类型       函数名(参数类型列表);
struct node  *create_linklist();

/*
insert_node:往一个链表中加入一个结点(头插法,尾插法,有序)
@p:指向你要加入链表的结点
@list:指向你要加入的链表
返回值:
	返回插入后的链表的第一个结点
*/
struct node *insert_node(struct node *p,struct node *list);


/*
print_list:打印指定的链表
@list:第一个结点的地址
返回值:
	无
*/
void print_list(struct node *list);


/*
delete_x:删除指定链表中的第一个x元素
@x:你要删除的元素
@list:指向你要删除元素的链表的第一个结点
返回值:
	返回删除后的链表的第一个结点
*/
struct node *delete_x(ElemType x,struct node *list);

/*
delete_all_x:删除指定链表中的所有的x元素
@x:你要删除的元素
@list:指向你要删除元素的链表的第一个结点
返回值:
	返回删除后的链表的第一个结点
*/
struct node *delete_all_x(ElemType x,struct node *list);



/*
find_x:在指定的链表中查找值为x的结点
@x:你要查找的元素
@list:指向你要查找元素的链表的第一个结点
返回值
	返回找到的结点的指针
*/
struct node *find_x(ElemType x,struct node *list);





#endif















