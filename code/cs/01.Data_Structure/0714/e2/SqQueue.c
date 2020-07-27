#include"SqQueue.h"

/*
InitSqQueue:初始化一个队列(分配一个队列的空间)
返回值：
	返回一个分配好的并且初始化的顺序队列的指针
*/
SqQueue *InitSqQueue(int maxLink)
{
	SqQueue *s = malloc(sizeof(*s));
	s->SqQueue = malloc(sizeof(ElemType)*maxLink);
	s->d = 0;
	s->e = 0;

	s->num = 0;//空队列的队列顶元素不存在
	s->max_len = maxLink;//空队列的队列顶元素不存在
	return s;
}

/*
ClearSqQueue:清空一个队列(把队列中的所有用户数据干掉)
@s:指向你要清空的队列
*/
void ClearSqQueue(SqQueue *s)
{
	if(s == NULL)
	{
		return;
	}
	s->d = 0;
	s->e = 0;
	s->num = 0;
}

/*
DestroySqQueue:销毁一个队列,释放s指向的队列的所有空间并且把s指向NULL
@s:指向你要销毁的队列
*/
void DestroySqQueue(SqQueue *s)
{
	if(s == NULL)
	{
		return;
	}
	ClearSqQueue(s);
	free(s->SqQueue);
	free(s);
}

/*
SqQueueIsEmtpy	判断队列是否为空
@s:指向顺序队列的指针
返回值:
	如果队列为空返回1
	如果队列不为空返回0
*/

int SqQueueIsEmpty(SqQueue *s)
{
	return s==NULL || s->num == 0;
}


/*
SqQueueLength		返回队列中的元素的个数(队列的长度)
*/
int SqQueueLength(SqQueue *s)
{
	if(s == NULL)
	{
		return 0;
	}
	return s->num;

}
/*
GetTop			获取队列顶元素,但是不出队列
	把s指向的队列的队列顶元素存储到e指向的空间
	返回值表示是否获取成功
*/
int GetTop(SqQueue *s,ElemType *v)
{
	if(SqQueueIsEmpty(s))
	{
		return 0;//获取不成功
	}
	*v = s->SqQueue[s->d];
	
	return 1;//获取成功
}

/*
Push			进队列操作
	把元素x进队列
	返回值表示是否获取成功
*/
int Push(SqQueue *s,ElemType e)
{
	if(s==NULL || s->num == s->max_len)
	{
		return 0;
	}
	s->SqQueue[s->e++] = e;
	if(s->e ==s->max_len)
	{
		s->e = 0;
	}
	s->num++;
	return 1;
}

/*
Pop				出队列
	把s指向的队列的队列顶元素出队列到e指向的空间
	返回值表示是否获取成功
*/
int Pop(SqQueue *s,ElemType *v)
{
	if(SqQueueIsEmpty(s))
	{
		return 0;//出队列不成功
	}
	*v = s->SqQueue[s->d++];
	s->d = s->d%s->max_len;
	s->num--;
	return 1;
}

