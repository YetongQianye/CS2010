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
		printf("child pid:%d\n",pid);
		wait(NULL);
		
	}else if(pid == 0) //子进程
	{	
		printf("i am son\n");
		//execl("/home/china/sum", "sum","123","455",NULL);
		//execlp("sum","sum","123","455",NULL);
		char *arg[]={"sum","123","456",NULL};
		//execv("/home/china/sum", arg);
		execvp("sum", arg);
		printf("ni kan bu dao wo\n");
	}else
	{
		perror("fork error");
	}
	return 0;
}


