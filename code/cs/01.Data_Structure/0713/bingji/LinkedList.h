#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__

#include<stdlib.h>
#include<stdio.h>
#include<string.h>

typedef int ElemType;//假设链表的用户数据类型为int
	
//数据结点
typedef struct node 
{
	ElemType data;//数据域,存放用户数据
	struct node *next;//指针域,存放数据元素之间的关系
}Node,*PNode;

//管理者结点,"头结点",一个头结点就表示一个链表
typedef struct head
{
	Node *first; //指向链表的第一个数据结点
	Node *last; //指向链表的最后一个数据结点
	int num; //链表中的数据结点的个数
}Head;	


/*
create_list:创建一个带头节点单链表(只需要开辟一个头结点并且初始化即可)
返回值:
	成功返回创建的带头节点单链表的头结点指针
	失败返回NULL
*/
Head *create_list();

/*
insert_element:往带头节点单链表中插入一个元素(实现头插法,尾插法,建立有序链表)
@x:你要插入的元素
@h:你要增加元素的链表的头结点地址
返回值:
	无
*/
void insert_element(ElemType x,Head *h);

//打印指定的链表
void print_list(Head *h);
//查找元素值为x的结点
Node *find_x(ElemType x,Head *h);
//删除元素值为x的结点
void delete_x(ElemType x,Head *h);
//删除所有元素值为x的结点
void delete_all_x(ElemType x,Head *h);

//清空链表(释放所有数据结点)
void clear_list(Head *h);
//删除链表(先释放所有数据结点,再释放头结点)
void delete_list(Head *h);
/*
归并两个有序链表(利用原有空间),并且使归并后的链表任然有序
		la:1 3 5 7 9
		lb:1 2 3 4 5 6 7 8 9 
		结果链表:1 1 2 3 3 4 5 5 6 7 7 8 9 9
*/
Head *Merge(Head *la,Head *lb);
Head *Merge2(Head *la,Head *lb);
Head *Merge3(Head *la,Head *lb);

/*
无序链表head有正有负,写一个函数,把负数放到正数前面,原有顺序保持不变
	如:
	head: 1 -4 -7 2 5 -8  6
	处理后的链表:-4 -7 -8 1 2 5 6
*/
void change_list(Head *h);

/*
有两个链表la,lb,写一个函数,判断la是否为lb的子序列
		如果是子序列返回1,否则返回0
		la:4 5 7
		lb:1 4 5 7 2 9
		la是lb的子序列
*/
int La_is_son_of_lb(Head *la,Head *lb);

//返回一个链表中,倒数第k个结点的指针
Node *reverse_K(Head *h,int k);

/*
有一个链表La,判断la中是否存在环？
	环:最后一个数据结点的指针指向前面数据结点构成环
*/
int have_loop(Head *h);


//找一个链表的中间结点(只允许遍历一次链表)
Node *middle(Head *h);

/*
有两个链表A,B,求A,B的交集,A,B,升序,要求C升序
不管A,B中是否存在重复元素,C中不允许存在重复元素。
如:
	la:1 2 2 3 3 4 4 4 5 6 8
	lb:2 2 2 6 6 6 7 8 8 8 9 
	lc:2 6 8 
*/		
Head *Intersection(Head *la,Head *lb);

Head *Intersection2(Head *la,Head *lb);
Head *Searchbin(Head *la,Head *lb);


#endif




















