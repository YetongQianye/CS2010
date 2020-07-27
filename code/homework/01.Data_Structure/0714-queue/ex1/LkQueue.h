#ifndef __LK_Queue_H__
#define __LK_Queue_H__

#include<stdio.h>
#include<stdlib.h>

//类型的定义和函数的声明
typedef int ElemType;//假设队列的元素类型为int
#define MAX_NUM 1024

typedef struct LkQueue
{
	//ElemType LkQueue[MAX_NUM]; //连续的地址空间
	ElemType *LkQueue;
	int d;//下一个出队元素的下标
	int e;//下一个入队元素的下标
	int num;//队列中的元素个数
	int max_len;//LkQueue指向的空间能够存储的最大的元素个数
}LkQueue;

/*
InitLkQueue:初始化一个队列(分配一个队列的空间)
返回值：
	返回一个分配好的并且初始化的顺序队列的指针
*/
LkQueue *InitLkQueue();

/*
ClearLkQueue:清空一个队列(把队列中的所有用户数据干掉)
@s:指向你要清空的队列
*/
void ClearLkQueue(LkQueue *s);

/*
DestroyLkQueue:销毁一个队列,释放s指向的队列的所有空间并且把s指向NULL
@s:指向你要销毁的队列
*/
void DestroyLkQueue(LkQueue *s);

/*
LkQueueIsEmtpy	判断队列是否为空
@s:指向顺序队列的指针
返回值:
	如果队列为空返回1
	如果队列不为空返回0
*/

int LkQueueIsEmpty(LkQueue *s);


/*
LkQueueLength		返回队列中的元素的个数(队列的长度)
*/
int LkQueueLength(LkQueue *s);
/*
GetTop			获取队列顶元素,但是不出队列
	把s指向的队列的队列顶元素存储到e指向的空间
	返回值表示是否获取成功
*/
int GetTop(LkQueue *s,ElemType *e);

/*
Push			进队列操作
	把元素e进队列
	返回值表示是否获取成功
*/
int Push(LkQueue *s,ElemType e);

/*
Pop				出队列
	把s指向的队列的队列顶元素出队列到e指向的空间
	返回值表示是否获取成功
*/
int Pop(LkQueue *s,ElemType *v);

/*
InitLkQueue  		初始化一个队列(分配一个队列的空间)
ClearLkQueue 		清空一个队列(把队列中的所有用户数据干掉)
DestroyLkQueue 	销毁一个队列
LkQueueIsEmtpy	判断队列是否为空
LkQueueLength		返回队列中的元素的个数(队列的长度)
GetTop			获取队列顶元素,但是不出队列
Push			进队列操作
Pop				出队列
*/



#endif 


















