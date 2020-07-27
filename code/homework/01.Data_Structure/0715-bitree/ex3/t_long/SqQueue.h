#ifndef __SQQUEUE_H__
#define __SQQUEUE_H__



typedef void* QElemType; //队列元素的类型
			
typedef struct SqQueue
{
	//QElemType data[1024];
	QElemType *data; // 指向一段连续的存储单元
					//用来存储队列中的元素
	
	int max_len; //表示data指向的存储空间最大的元素个数
	
	int rear; //队尾下标，下一个入队元素的下标　
	int front; //队头下标，下一个出队元素的下标
			
	int avail_len; //表示当前队列中有多少个元素
				//avail_len == 0, 表示队列为空
				//avail_len == max_len , 表示队列满的。

}SqQueue;


/*
	alloc_SqQueue:分配/申请一个顺序队列(循环队列)
	@max_len: 指定队列中最大能同时容纳多少个元素
	返回值:
		成功返回一个循环队列指针
		失败返回NULL
*/
SqQueue* alloc_SqQueue(int max_len);



//清空队列
void clear_SqQueue(SqQueue *s);

//销毁一个队列
void destroy_SqQueue(SqQueue *s);

//判断队列是否为空
// 1 -> 为空
// 0 -> 不为空
int SqQueue_is_empty(SqQueue *s);


//返回队列的元素个数
int SqQueue_length(SqQueue *s);


//入队
// 1表示成功
// 0表示失败
int EnQueue(SqQueue *s, QElemType e);



//出队
//返回1表示成功
//返回0表示失败
int DeQueue(SqQueue *s, QElemType *e);

//获取队头元素，但不出队
//返回1表示成功
//返回0表示失败
int get_head(SqQueue *s, QElemType *e);


#endif
