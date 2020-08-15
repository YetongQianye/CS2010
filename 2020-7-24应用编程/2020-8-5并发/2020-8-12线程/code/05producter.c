#include<stdio.h>
#include <pthread.h>

int buffer = 0;//共享资源"缓冲区"
pthread_mutex_t mutex;//定义一个线程互斥锁


//生产者线程函数
void *producter_f(void *arg)
{
	while(1)
	{
		pthread_mutex_lock(&mutex);
		buffer++;
		printf("producter_f:buffer = %d\n",buffer);
		if(buffer >= 1000)
		{
			//唤醒等待条件的线程
		}
		pthread_mutex_unlock(&mutex);
	}
}

//消费者线程函数
void *consumer_f(void *arg)
{
	while(1)
	{
		pthread_mutex_lock(&mutex);
		if(buffer >= 1000) //条件
		{
			buffer -= 1000;
			printf("consumer_f:buffer = %d\n",buffer);
		}else
		{
			printf("data not manzu the yaoqiu\n");
			//等待一个条件(buffer >= 1000),让出CPU
		}
		pthread_mutex_unlock(&mutex);
	}
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
	pthread_t pro_id;//生产者线程ID
	pthread_t con_id;//消费者线程ID
	pthread_create(&pro_id, NULL,producter_f, NULL);
	pthread_create(&con_id, NULL,consumer_f, NULL);
	
	//回收线程资源
	pthread_join(pro_id,NULL); 
	pthread_join(con_id,NULL);

	return 0;
}

















