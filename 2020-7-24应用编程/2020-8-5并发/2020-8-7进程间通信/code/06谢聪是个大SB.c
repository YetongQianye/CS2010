#include <sys/types.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void my_handler(int sig)
{
	printf("sig = %d\n",sig);
	switch(sig)
	{
		case SIGALRM:
			printf("received SIGALRM\n");
			break;
		case SIGINT:
			printf("received SIGINT\n");
			break;		
		case SIGKILL:
			printf("received SIGKILL\n");
			break;	
	}
	
}

int main()
{
	//捕捉信号
	//signal(SIGINT,SIG_IGN);
	signal(SIGINT,my_handler);
	signal(SIGALRM,my_handler);
	signal(SIGKILL,my_handler);
	alarm(5);
	while(1)
	{
		printf("hello\n");
		sleep(1);
	}
	return 0;
}














