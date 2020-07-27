#include"SqStack.h"

/*
InitStack:初始化一个栈(分配一个栈的空间)
返回值：
	返回一个分配好的并且初始化的顺序栈的指针
*/
SqStack *InitStack()
{
	SqStack *s = malloc(sizeof(*s));
	s->top = -1;//空栈的栈顶元素不存在,栈顶元素下标使用-1表示
	return s;
}

/*
ClearStack:清空一个栈(把栈中的所有用户数据干掉)
@s:指向你要清空的栈
*/
void ClearStack(SqStack *s)
{
	if(s == NULL)
	{
		return;
	}
	s->top = -1;
}

/*
DestroyStack:销毁一个栈,释放s指向的栈的所有空间并且把s指向NULL
@s:指向你要销毁的栈
*/
void DestroyStack(SqStack **s)
{
	if(*s == NULL)
	{
		return;
	}
	free(*s);
	*s = NULL;
}

/*
StackIsEmtpy	判断栈是否为空
@s:指向顺序栈的指针
返回值:
	如果栈为空返回1
	如果栈不为空返回0
*/

int StackIsEmtpy(SqStack *s)
{
	return s==NULL || s->top == -1;
}


/*
StackLength		返回栈中的元素的个数(栈的长度)
*/
int StackLength(SqStack *s)
{
	if(s == NULL)
	{
		return 0;
	}
	return s->top+1;

}
/*
GetTop			获取栈顶元素,但是不出栈
	把s指向的栈的栈顶元素存储到e指向的空间
	返回值表示是否获取成功
*/
int GetTop(SqStack *s,ElemType *v)
{
	if(StackIsEmtpy(s))
	{
		return 0;//获取不成功
	}
	*v = s->stack[s->top];
	return 1;//获取成功
}

/*
Push			进栈操作
	把元素e进栈
	返回值表示是否获取成功
*/
int Push(SqStack *s,ElemType e)
{
	if(s == NULL || s->top == MAX_NUM-1)
	{
		return 0;
	}
	s->stack[++s->top] = e;
	return 1;
}

/*
Pop				出栈
	把s指向的栈的栈顶元素出栈到e指向的空间
	返回值表示是否获取成功
*/
int Pop(SqStack *s,ElemType *v)
{
	if(StackIsEmtpy(s))
	{
		return 0;//出栈不成功
	}
	*v = s->stack[s->top--];
	return 1;
}

