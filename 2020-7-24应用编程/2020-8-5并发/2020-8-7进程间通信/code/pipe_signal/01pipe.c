#include<stdio.h>
#include<stdlib.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	//创建管道
	int fd[2] = {0};
	int r = pipe(fd);
	if(r == -1)
	{
		perror("create pepe failed");
		return -1;
	}
	//fork创建进程
	pid_t pid = fork();
	if(pid >0) //父进程
	{
		char buf[128] = {0};
		r = read(fd[0],buf,128);		
		printf("read r = %d\n",r);
		printf("buf = %s\n",buf);
		
		wait(NULL);
	}else if(pid == 0) //子进程
	{
		sleep(10);
		char buf[128] = {"nihao,liangzai"};
		r = write(fd[1],buf,20);
		printf("write r = %d\n",r);
	}else
	{
		perror("fork error");
	}
	

	return 0;
}



















