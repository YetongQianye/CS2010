
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



/*
delete_list:删除整个链表
@list:你要删除的链表
返回值:
	无
*/
void delete_list(struct node * list);

/*
建立一个链表逆序存储一个整数的各个位上的数字
		如输入:132
		建立链表:2-->3--->1
*/		
struct node *create_list_by_num(char *num);

//使用链表逆序存储两个整数,实现两个超大数的加法,把结果链表返回
		
struct node *add_two_numbers(struct node *la,struct node *lb);


#endif















