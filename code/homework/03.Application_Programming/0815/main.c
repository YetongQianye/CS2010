#include<stdio.h>
#include"copyfile.h"
#include"pthread_pool.h"

//把srcdir执行的目录复制为destdir指向的目录
//./main srcdir  destdir
int main(int argc,char *argv[])
{
	if(argc != 3)
	{
		printf("arg num not yes\n");
		return -1;
	}
	//定义并且初始化一个线程池
	Pthread_pool pool;
	init_pool(&pool,10);

	add_threads(&pool,10);
	remove_threads(&pool,8); 
	
	//判断是否为目录
	copydir(&pool,argv[1],argv[2]);
	
	destory_pool(&pool);
	return 0;
}



