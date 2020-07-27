
#include <stdio.h>
#include <stdlib.h>
#include "SqQueue.h"


/*
	alloc_SqQueue:分配/申请一个顺序队列(循环队列)
	@max_len: 指定队列中最大能同时容纳多少个元素
	返回值:
		成功返回一个循环队列指针
		失败返回NULL
*/
SqQueue* alloc_SqQueue(int max_len)
{
	SqQueue* s = malloc(sizeof(*s));

	s->data = malloc(max_len * sizeof(QElemType));

	s->avail_len = 0; //
	s->rear = 0;
	s->front = 0;
	s->max_len = max_len;


	return s;
}

//清空队列
void clear_SqQueue(SqQueue *s)
{
	if (s == NULL)
	{
		return ;
	}

	s->avail_len = 0; //
	s->rear = 0;
	s->front = 0;
	
}


//销毁一个队列
void destroy_SqQueue(SqQueue *s)
{
	clear_SqQueue(s);

	if (s)
	{	
		if (s->data)
		{
			free(s->data);
		}
		free(s);
	}
}


//判断队列是否为空
// 1 -> 为空
// 0 -> 不为空
int SqQueue_is_empty(SqQueue *s)
{
	if (s == NULL)
	{
		return 1;
	}

	return s->avail_len == 0 ? 1 : 0 ;
}


//返回队列的元素个数
int SqQueue_length(SqQueue *s)
{

	if (s == NULL)
	{
		return 0;
	}

	return s->avail_len;
}


//入队
// 1表示成功
// 0表示失败
int EnQueue(SqQueue *s, QElemType e)
{
	if (s == NULL || (s->avail_len == s->max_len))
	{
		return 0;
	}

	s->data[s->rear] = e;
	s->rear ++;

	if (s->rear == s->max_len)
	{
		s->rear = 0;
	}

	s->avail_len++;

	return 1;

}

//出队
//返回1表示成功
//返回0表示失败
int DeQueue(SqQueue *s, QElemType *e)
{
	if (s == NULL || s->avail_len == 0)
	{
		return 0;
	}

	*e = s->data[s->front];
	s->front++;

	if (s->front == s->max_len)
	{
		s->front = 0;
	}

	s->avail_len--;

	return 1;
	
}

//获取队头元素，但不出队
//返回1表示成功
//返回0表示失败
int get_head(SqQueue *s, QElemType *e)
{
	if (s == NULL || s->avail_len == 0)
	{
		return 0;
	}

	*e = s->data[s->front];
	
	return 1;
	
}

