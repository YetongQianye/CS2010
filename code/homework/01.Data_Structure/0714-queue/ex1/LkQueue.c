#include"LkQueue.h"

/*
InitLkQueue:初始化一个队列(分配一个队列的空间)
返回值：
	返回一个分配好的并且初始化的顺序队列的指针
*/
LkQueue *InitLkQueue(int maxLink)
{
	LkQueue *s = malloc(sizeof(*s));
	s->LkQueue = malloc(sizeof(ElemType)*maxLink);
	s->d = 0;
	s->e = 0;

	s->num = 0;//空队列的队列顶元素不存在
	s->max_len = maxLink;//空队列的队列顶元素不存在
	return s;
}

/*
ClearLkQueue:清空一个队列(把队列中的所有用户数据干掉)
@s:指向你要清空的队列
*/
void ClearLkQueue(LkQueue *s)
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
DestroyLkQueue:销毁一个队列,释放s指向的队列的所有空间并且把s指向NULL
@s:指向你要销毁的队列
*/
void DestroyLkQueue(LkQueue *s)
{
	if(s == NULL)
	{
		return;
	}
	ClearLkQueue(s);
	free(s->LkQueue);
	free(s);
}

/*
LkQueueIsEmtpy	判断队列是否为空
@s:指向顺序队列的指针
返回值:
	如果队列为空返回1
	如果队列不为空返回0
*/

int LkQueueIsEmpty(LkQueue *s)
{
	return s==NULL || s->num == 0;
}


/*
LkQueueLength		返回队列中的元素的个数(队列的长度)
*/
int LkQueueLength(LkQueue *s)
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
int GetTop(LkQueue *s,ElemType *v)
{
	if(LkQueueIsEmpty(s))
	{
		return 0;//获取不成功
	}
	*v = s->LkQueue[s->d];
	
	return 1;//获取成功
}

/*
Push			进队列操作
	把元素x进队列
	返回值表示是否获取成功
*/
int Push(LkQueue *s,ElemType e)
{
	if(s==NULL || s->num == s->max_len)
	{
		return 0;
	}
	s->LkQueue[s->e++] = e;
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
int Pop(LkQueue *s,ElemType *v)
{
	if(LkQueueIsEmpty(s))
	{
		return 0;//出队列不成功
	}
	*v = s->LkQueue[s->d++];
	s->d = s->d%s->max_len;
	s->num--;
	return 1;
}

