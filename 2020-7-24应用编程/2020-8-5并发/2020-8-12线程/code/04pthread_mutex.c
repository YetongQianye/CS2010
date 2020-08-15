#include<stdio.h>
#include <pthread.h>

int x = 0;//共享资源
//pthread_mutex_t mutex;//定义一个线程互斥锁

void *func(void *arg)
{
	pthread_mutex_t *pmutex = (pthread_mutex_t *)arg;
	int i=100000000; //数字需要足够大,否则一个第一个线程已经over
					//第二个线程还没有开始
	//lock
	pthread_mutex_lock(pmutex);
	while(i--)
	{
		//lock
		//pthread_mutex_lock(&mutex);
		x+=2;
		//printf("hahaha\n");
		x-=1;
		//unlcok
		//pthread_mutex_unlock(&mutex);
	}
	//unlcok
	pthread_mutex_unlock(pmutex);
	printf("pthread x = %d\n",x);
}

int main()
{
	pthread_mutex_t mutex;//定义一个线程互斥锁
	int r =  pthread_mutex_init(&mutex,NULL);
	if(-1 == r)
	{
		perror("init mutex error");
		return -1;
	}
	pthread_t tid;
	pthread_t tid1;
	//创建线程
	r = pthread_create(&tid, NULL,func,(void *)&mutex);
	int r2 = pthread_create(&tid1, NULL,func,(void *)&mutex);
	if(r==-1 || r2==-1)
	{
		perror("create thread error");
		return -1;
	}
	pthread_join(tid,NULL);
	pthread_join(tid1,NULL);
	return 0;
}













































