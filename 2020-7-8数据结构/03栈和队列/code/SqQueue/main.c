#include<stdio.h>
#include"SqQueue.h"
int main()
{
	SqQueue * q = InitQueue(100);
	
	printf("QueueIsEmpty:%d\n",QueueIsEmpty(q));
	printf("Length:%d\n",QueueLength(q));
	
	EnQueue(q,1);
	EnQueue(q,2);
	EnQueue(q,3);
	printf("QueueIsEmpty:%d\n",QueueIsEmpty(q));
	printf("Length:%d\n",QueueLength(q));
	int x;
	DeQueue(q,&x);
	printf("x = %d\n",x);
	DeQueue(q,&x);
	printf("x = %d\n",x);
	DeQueue(q,&x);
	printf("x = %d\n",x);
	
	printf("QueueIsEmpty:%d\n",QueueIsEmpty(q));
	printf("Length:%d\n",QueueLength(q));
	
	DestoryQueue(q);
	return 0;
}

