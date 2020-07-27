
#ifndef  __LK_STACK_H__
#define  __LK_STACK_H__

#include<stdio.h>
#include<stdlib.h>


//类型的定义和函数的申明
//链式栈实际上是在“带头节点双向链表”上面加上栈的限定条件“仅在一端操作”
typedef int ElemType;
//栈元素数据结点
typedef struct node
{
	ElemType data;//保存栈的元素数据
	struct node *next,*prev;
}Node;

//栈的头结点
typedef struct LkStack
{
	Node *first; //指向栈底元素
	Node *last; //指向栈顶元素
	int nodeNum; //栈中的元素个数
}LkStack;

//LkStack ===> struct LkStack

/*
InitStack:初始化一个栈(分配一个栈的空间)
返回值：
	返回一个分配好的并且初始化的链式栈的指针
*/
LkStack *InitStack();

/*
ClearStack:清空一个栈(把栈中的所有用户数据干掉)
@s:指向你要清空的栈
*/
void ClearStack(LkStack *s);

/*
DestroyStack:销毁一个栈,释放s指向的栈的所有空间并且把s指向NULL
@s:指向你要销毁的栈
*/
void DestroyStack(LkStack **s);

/*
StackIsEmtpy	判断栈是否为空
@s:指向链式栈的指针
返回值:
	如果栈为空返回1
	如果栈不为空返回0
*/

int StackIsEmpty(LkStack *s);


/*
StackLength		返回栈中的元素的个数(栈的长度)
*/
int StackLength(LkStack *s);
/*
GetTop			获取栈顶元素,但是不出栈
	把s指向的栈的栈顶元素存储到e指向的空间
	返回值表示是否获取成功
*/
int GetTop(LkStack *s,ElemType *v);

/*
Push			进栈操作
	把元素e进栈
	返回值表示是否获取成功
*/
int Push(LkStack *s,ElemType e);

/*
Pop				出栈
	把s指向的栈的栈顶元素出栈到e指向的空间
	返回值表示是否获取成功
*/
int Pop(LkStack *s,ElemType *v);

#endif



