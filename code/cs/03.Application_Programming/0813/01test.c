#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <pthread.h>

int x = 0;
//线程函数
void *func1(void *arg)
{	
	int i = 100000000;
	 
	while(i--)
	{
		x++;
	}
    printf("pthread x = %d\n",x);
}

 

int main()
{
	 
	pthread_t tid;
    pthread_t tid1;
    //thread1
	int r = pthread_create(&tid,NULL,func1, NULL);
    int r1 = pthread_create(&tid1,NULL,func1, NULL);
	if(r == -1 ||r1 == -1)
	{
		perror("pthread_create error");
		return -1;
	}
    pthread_join(tid,NULL);
    pthread_join(tid1,NULL);
	 
    
	return 0;
}

