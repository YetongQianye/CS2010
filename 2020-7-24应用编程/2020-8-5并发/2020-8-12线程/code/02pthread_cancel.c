#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <pthread.h>


//线程函数
void *func(void *arg)
{	
	//pthread_detach(pthread_self());
	pthread_t tid = pthread_self();
	int *p = (int *)malloc(sizeof(int));
	*p = 250;
	while(1)
	{
		printf("tid = %lu\n",tid);
		sleep(1);
		//pthread_exit((void *)p);
	}
}

int main()
{
	printf("线程创建前\n");
	pthread_t tid;
	int r = pthread_create(&tid,NULL,func, NULL);
	if(r == -1)
	{
		perror("pthread_create error");
		return -1;
	}
	printf("线程创建后\n");
	sleep(2);
	pthread_cancel(tid);

	
	while(1)
	{
		printf("i am main,tid = %lu\n",tid);
		sleep(1);
	}
	
	return 0;
}




















