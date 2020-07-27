#ifndef __SQ_STACK_H__
#define __SQ_STACK_H__

#include<stdio.h>
#include<stdlib.h>


//类型的定义和函数的声明
typedef int ElemType;//栈中元素的类型		
#define MAX_NUM 1024  //栈中最多能够存储多少个元素

typedef struct SqStack
{
	ElemType stack[MAX_NUM]; 		//"静态数组"在编译的时候大小已经确定
	//ElemType *stack; 				//“动态数组”
	int top;//栈顶元素在栈中的下标	
}SqStack;

/*
InitStack:初始化一个栈(分配一个栈的空间)
返回值：
	返回一个分配好的并且初始化的顺序栈的指针
*/
SqStack *InitStack();

/*
ClearStack:清空一个栈(把栈中的所有用户数据干掉)
@s:指向你要清空的栈
*/
void ClearStack(SqStack *s);

/*
DestroyStack:销毁一个栈,释放s指向的栈的所有空间并且把s指向NULL
@s:指向你要销毁的栈
*/
void DestroyStack(SqStack **s);

/*
StackIsEmtpy	判断栈是否为空
@s:指向顺序栈的指针
返回值:
	如果栈为空返回1
	如果栈不为空返回0
*/

int StackIsEmtpy(SqStack *s);


/*
StackLength		返回栈中的元素的个数(栈的长度)
*/
int StackLength(SqStack *s);
/*
GetTop			获取栈顶元素,但是不出栈
	把s指向的栈的栈顶元素存储到e指向的空间
	返回值表示是否获取成功
*/
int GetTop(SqStack *s,ElemType *v);

/*
Push			进栈操作
	把元素e进栈
	返回值表示是否获取成功
*/
int Push(SqStack *s,ElemType e);

/*
Pop				出栈
	把s指向的栈的栈顶元素出栈到e指向的空间
	返回值表示是否获取成功
*/
int Pop(SqStack *s,ElemType *v);

/*
InitStack  		初始化一个栈(分配一个栈的空间)
ClearStack 		清空一个栈(把栈中的所有用户数据干掉)
DestroyStack 	销毁一个栈
StackIsEmtpy	判断栈是否为空
StackLength		返回栈中的元素的个数(栈的长度)
GetTop			获取栈顶元素,但是不出栈
Push			进栈操作
Pop				出栈
*/



#endif 


















