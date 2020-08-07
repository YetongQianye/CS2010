#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/types.h>
 #include <sys/wait.h>

int main()
{
	printf("hello\n");
	//创新一个新进程
	pid_t pid  = fork();
	if(pid > 0) //父进程
	{
		printf("-----wait-----\n");
		int status = 0;
		wait(&status); //把子进程的退出状态保存到status中(需要使用特殊的宏取解析)
		//printf("stauts:%d\n",status); //不能直接打印
	}else if(pid == 0) //子进程
	{	
		sleep(5);
		exit(250);		
	}else
	{
		perror("fork error");
	}
	return 0;
}


