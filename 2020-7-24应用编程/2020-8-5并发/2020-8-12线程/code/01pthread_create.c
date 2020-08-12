#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <pthread.h>
struct arg_test
{
	int a;
	char b;
};


//线程函数
void *func(void *arg)
{
	//printf("arg = %p\n",arg);
	//int *p = (int *)arg;
	//printf("p = %d\n",*p);

	
	//char *p = (char *)arg;
	//printf("p = %d\n",*p);
	//*p = 66; //'B'	

	int x = 250;
	int *q = (int *)malloc(sizeof(int));
	*q = 250;
	struct arg_test *p = (struct arg_test *)arg;
	printf("a = %d\n",p->a);
	printf("b = %c\n",p->b);

	
	pthread_t tid = pthread_self();
	while(1)
	{
		printf("tid = %lu\n",tid);
		sleep(1);
		//pthread_exit(NULL);
		//pthread_exit((void *)&x);//不应该返回一个局部变量的地址
		pthread_exit((void *)q);
	}
}

int main()
{
	printf("线程创建前\n");
	//int a = 1024;
	//char ch = 'A';
	//printf("ch = %p\n",&ch);
	struct arg_test at;
	at.a = 1024;
	at.b = 'X';

	
	pthread_t tid;
	int r = pthread_create(&tid,NULL,func, (void *)&at);
	if(r == -1)
	{
		perror("pthread_create error");
		return -1;
	}
	sleep(1);
	printf("线程创建后\n");
	//printf("ch = %d\n",ch);
	while(1)
	{
		printf("i am main,tid = %lu\n",tid);
		sleep(1);
	}
	
	return 0;
}




















