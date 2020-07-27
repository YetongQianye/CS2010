#include<stdio.h>
#include"SqQueue.h"


int main()
{
	SqQueue * q = InitSqQueue(100);
	
	printf("SqQueueIsEmpty:%d\n",SqQueueIsEmpty(q));
	printf("Length:%d\n",SqQueueLength(q));
	
	Push(q,1);
	Push(q,2);
	Push(q,3);
	printf("SqQueueIsEmpty:%d\n",SqQueueIsEmpty(q));
	printf("Length:%d\n",SqQueueLength(q));
	int x;
	Pop(q,&x);
	printf("x = %d\n",x);
	Pop(q,&x);
	printf("x = %d\n",x);
	Pop(q,&x);
	printf("x = %d\n",x);
	
	printf("SqQueueIsEmpty:%d\n",SqQueueIsEmpty(q));
	printf("Length:%d\n",SqQueueLength(q));
	
	DestroySqQueue(q);

	return 0;
}








