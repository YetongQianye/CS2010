#ifndef __SQ_QUEUE_H__
#define __SQ_QUEUE_H__

#include<stdio.h>
#include<stdlib.h>

typedef struct BiTNode * ElemType;//假设队列中的元素类型为BiTNode *
#define QUEUE_MAX_NUM 1024  //队列中最大的元素个数
typedef struct SqQueue
{
	//ElemType Queue[QUEUE_MAX_NUM];//一段内存空间,用来保存队列的元素
	ElemType *Queue;//指针,可以为这个指针分配一段内存空间保存队列的元素
	int d;//下一个出队元素的下标,初始为0
	int e;//下一个入队元素的下标,初始为0
	int num;//表示当前队列(数组)中有效的元素(队列元素)的个数,初始为0
	int avail_len; //表示当前队列中有多少个元素
	int max_len;//表示当前队列能够存储的最大元素个数	
}SqQueue;

/*
InitQueue:初始化一个队列
返回值:返回初始化的队列的首地址
*/
SqQueue *InitQueue(int maxL);

//ClearQueue:清空一个队列,删除所有的有效元素
void ClearQueue(SqQueue *q);

//DestoryQueue:销毁一个队列,释放开辟的内存空间
void DestoryQueue(SqQueue *q);

//QueueIsEmpty:判断队列是否为空,为空返回1,否则返回0
int QueueIsEmpty(SqQueue *q);

//QueueLength:获取队列的长度
int QueueLength(SqQueue *q);

//GetFront:获取队头元素,但是不出队列
//获取的元素存储到指针v指向的空间
//返回1表示获取成功,返回0表示获取失败
int GetFront(SqQueue *q,ElemType *v);

//EnQueue:入队列
//返回1表示入队成功,返回0表示入队失败
int EnQueue(SqQueue *q,ElemType e);

//DeQueue:出队列
//出队的元素存储到指针v指向的空间
//返回1表示出队成功,返回0表示出队失败
int DeQueue(SqQueue *q,ElemType *v);

/*
InitQueue:初始化一个队列
ClearQueue:清空一个队列
DestoryQueue:销毁一个队列
QueueIsEmpty:判断队列是否为空
QueueLength:获取队列的长度
GetFront:获取队头元素,但是不出队列
EnQueue:入队列
DeQueue:出队列
*/


#endif