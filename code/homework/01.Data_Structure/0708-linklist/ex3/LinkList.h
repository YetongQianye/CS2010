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
print_list:打印指定的链表
@list:第一个结点的地址
返回值:
	无
*/
void print_list(struct node *list);

struct node * create_list_by_digital(char * num);
#endif















