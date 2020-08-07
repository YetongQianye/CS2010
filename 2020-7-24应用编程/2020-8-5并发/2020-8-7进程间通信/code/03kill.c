#include <sys/types.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>


int main()
{
	sleep(3);
	//kill(getpid(),11);
	raise(11);
	/*
	while(1)
	{
		printf("hello \n");
		sleep(1);
	}
	*/
	return 0;
}


























