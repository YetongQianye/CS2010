#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	printf("hello\n"); //只打印一次
	int a;
	pid_t pid = fork();
	//下面的代码就有两个进程在执行
	if(pid > 0)
	{
		printf("i am father\n");
		//&a
	}else if(pid == 0)
	{
		printf("i am son\n");
		//&a
	}
	return 0;
}

