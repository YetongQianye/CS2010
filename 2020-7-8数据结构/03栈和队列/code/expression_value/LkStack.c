#include"LkStack.h"


/*
InitStack:初始化一个栈(分配一个栈的空间)
返回值：
	返回一个分配好的并且初始化的链式栈的指针
*/
LkStack *InitStack()
{

	//s只是一个局部变量(大括号内部,作用域和生存期仅仅在定义它的大括号内部)
	/*
	LkStack s;
	s.first = s.last = NULL;
	s.nodeNum = 0;	
	return &s;
	*/
	LkStack *s = malloc(sizeof(LkStack));
	s->first = s->last = NULL;
	s->nodeNum = 0;
	return s;
}

/*
ClearStack:清空一个栈(把栈中的所有用户数据干掉)
@s:指向你要清空的栈
*/
void ClearStack(LkStack *s)
{
	if(s==NULL)
	{
		return;
	}
	Node *p = s->last;
	while(p)
	{
		s->last = p->prev;
		if(s->last)
		{
			s->last->next = NULL;
		}
		p->prev = NULL;
		free(p);
		p = s->last;
	}
	s->first = NULL;
	s->nodeNum = 0;
}

/*
DestroyStack:销毁一个栈,释放s指向的栈的所有空间并且把s指向NULL
@s:指向你要销毁的栈
*/
void DestroyStack(LkStack **s) //保存栈的地址的指针变量本身的地址
{
	if(*s == NULL)
	{
		return;
	}
	ClearStack(*s); //释放所有数据结点
	free(*s);//释放头结点
	*s = NULL;
	
	/*
	if(s == NULL)
	{
		return;
	}
	ClearStack(s); //释放所有数据结点
	free(s);//释放头结点
*/
	
}
/*
int main()
{
	LkStack *s; //实参   &s===>typeof(&s) ===> typeof(s) * ===>LkStack **
	s = InitStack();
	-----
	使用栈
	-----
	不需要这个栈了,应该销毁
	DestroyStack(s); //形不改实
	s=NULL;
	
}

*/




/*
StackIsEmtpy	判断栈是否为空
@s:指向链式栈的指针
返回值:
	如果栈为空返回1
	如果栈不为空返回0
*/

int StackIsEmtpy(LkStack *s)
{
	return s==NULL || s->nodeNum == 0;
}


/*
StackLength		返回栈中的元素的个数(栈的长度)
*/
int StackLength(LkStack *s)
{
	return s==NULL?0:s->nodeNum;
}
/*
GetTop			获取栈顶元素,但是不出栈
	把s指向的栈的栈顶元素存储到e指向的空间
	返回值表示是否获取成功
*/
int GetTop(LkStack *s,ElemType *v)
{
	if(StackIsEmtpy(s))
	{
		return 0;//获取失败
	}

	*v = s->last->data;
	return 1;
}

/*
Push			进栈操作
	把元素e进栈
	返回值表示是否获取成功
*/
int Push(LkStack *s,ElemType e)
{
	if(s == NULL)
	{
		return 0;
	}
	//开辟空间保存e
	Node *p = malloc(sizeof(Node));
	p->data = e;
	p->next = p->prev = NULL;	
	//把结点加入栈
	if(s->first == NULL)
	{
		s->first = s->last = p;
	}else
	{
		//栈顶为链表的尾部
		s->last->next = p;
		p->prev = s->last;
		s->last = p;
	}
	s->nodeNum++;
	return 1;
}

/*
Pop				出栈
	把s指向的栈的栈顶元素出栈到e指向的空间
	返回值表示是否获取成功
*/
int Pop(LkStack *s,ElemType *v)
{
	if(StackIsEmtpy(s))
	{
		return 0;//失败
	}
	*v = s->last->data;
	//把栈顶元素删除
	Node *p = s->last;
	s->last = p->prev;
	p->prev = NULL;
	if(s->last)
	{
		s->last->next = NULL;
	}else
	{
		s->first = NULL;
	}
	free(p);
	s->nodeNum--;
	return 1;
}



















