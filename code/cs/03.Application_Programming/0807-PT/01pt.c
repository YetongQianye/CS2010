#include<stdio.h>
#include<stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
 
int main()
{
    pid_t pid;
    int ret;
    // 创建一个子进程
    if((pid = fork()) < 0)
    {
        printf("Fork error\n");
        exit(1);

    }
    if(pid == 0)
    {
        printf("Child(pid : %d) is wating for ny signal\n",getpid());
        raise(SIGSTOP);
        exit(0);

    }
    else
    {
        if((waitpid(pid,NULL,WNOHANG)) == 0)
        {
            if((ret = kill(pid,SIGKILL)) == 0)
            {
                printf("Parent kill %d\n",pid);
            }
        }
        waitpid(pid,NULL,0);
        exit(0);
    }
      	
	return 0;
}
