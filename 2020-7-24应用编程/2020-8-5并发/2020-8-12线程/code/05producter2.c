#include<stdio.h>
#include <pthread.h>

int buffer = 0;//共享资源"缓冲区"
pthread_mutex_t mutex; //定义一个线程互斥锁
pthread_cond_t cond;   //条件变量,表示数据是否大于1000


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
			pthread_cond_signal(&cond);
		}
		pthread_mutex_unlock(&mutex);
	}
}

//消费者线程函数
void *consumer_f(void *arg)
{
	int *p = (int *)arg;
	while(1)
	{
		pthread_mutex_lock(&mutex);
		if(buffer >= 1000) //条件
		{
			buffer -= 1000;
			printf("consumer_f:%d:buffer = %d\n",*p,buffer);
		}else
		{
			printf("浪费CPU时间 %d\n",*p);
			//等待一个条件(buffer >= 1000),让出CPU
			pthread_cond_wait(&cond,&mutex); //阻塞
		}
		pthread_mutex_unlock(&mutex);
	}
}


int main()
{
	//初始化线程互斥锁
	int r =  pthread_mutex_init(&mutex,NULL);
	if(-1 == r)
	{
		perror("init mutex error");
		return -1;
	}
	//初始化条件变量
	pthread_cond_init(&cond,NULL);
	
	pthread_t pro_id;//生产者线程ID
	pthread_t con_id1;//消费者线程ID
	pthread_t con_id2;//消费者线程ID
	pthread_t con_id3;//消费者线程ID

	int a =1;
	int b = 2;
	int c = 3;
	pthread_create(&pro_id, NULL,producter_f, NULL);
	pthread_create(&con_id1, NULL,consumer_f,(void *)&a);
	pthread_create(&con_id2, NULL,consumer_f,(void *)&b);
	pthread_create(&con_id3, NULL,consumer_f, (void *)&c);
	
	//回收线程资源
	pthread_join(pro_id,NULL); 
	pthread_join(con_id1,NULL);
	pthread_join(con_id2,NULL);
	pthread_join(con_id3,NULL);

	return 0;
}

















