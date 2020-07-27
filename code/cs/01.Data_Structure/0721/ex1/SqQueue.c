#include"SqQueue.h"

/*
InitQueue:初始化一个队列
返回值:返回初始化的队列的首地址
*/
SqQueue *InitQueue(int maxL)
{
	//分配一个队列空间
	SqQueue *s = malloc(sizeof(*s));
	//分配存储队列元素的空间
	s->Queue = malloc(sizeof(ElemType)*maxL);
	s->d = 0;
	s->e = 0;
	s->num = 0;
	s->max_len = maxL;
	return s;
}

//ClearQueue:清空一个队列,删除所有的有效元素
void ClearQueue(SqQueue *q)
{
	if(q == NULL)
	{
		return ;
	}
	q->d = 0;
	q->e = 0;
	q->num = 0;
}

//DestoryQueue:销毁一个队列,释放开辟的内存空间
void DestoryQueue(SqQueue *q)
{
	if(q == NULL)
	{
		return;
	}
	ClearQueue(q);
	free(q->Queue);
	free(q);
	
}

//QueueIsEmpty:判断队列是否为空,为空返回1,否则返回0
int QueueIsEmpty(SqQueue *q)
{
	return q==NULL || q->num == 0;
}

//QueueLength:获取队列的长度
int QueueLength(SqQueue *q)
{
	return q==NULL?0:q->num;
}

//GetFront:获取队头元素,但是不出队列
//获取的元素存储到指针v指向的空间
//返回1表示获取成功,返回0表示获取失败
int GetFront(SqQueue *q,ElemType *v)
{
	if(QueueIsEmpty(q))
	{
		return 0;//获取失败
	}
	*v = q->Queue[q->d];
	return 1;
}

//EnQueue:入队列
//返回1表示入队成功,返回0表示入队失败
int EnQueue(SqQueue *q,ElemType e)
{
	//队列满或者队列不存在
	if(q==NULL || q->num == q->max_len)
	{
		return 0;
	}
	q->Queue[q->e++] = e;
	if(q->e == q->max_len)
	{
		q->e = 0;
	}
	q->num++;
	return 1;
}

//DeQueue:出队列
//出队的元素存储到指针v指向的空间
//返回1表示出队成功,返回0表示出队失败
int DeQueue(SqQueue *q,ElemType *v)
{
	if(QueueIsEmpty(q))
	{
		return 0;//出队失败
	}
	*v = q->Queue[q->d++];

	q->d = q->d%q->max_len;
	
	q->num--;
	return 1;
}

























