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
		sleep(4);
		pthread_exit((void *)p);
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
	int *x = NULL; //执行pthread_join后,x指向malloc的地址
	pthread_join(tid,(void **)&x);
	printf("你终于死了,%d\n",*x);
	free(x);
	return 0;
}




















