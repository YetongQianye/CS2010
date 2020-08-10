#include <sys/types.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>


int main()
{
	alarm(5);
	sleep(3);
	int r = alarm(5);
	printf("r = %d\n",r);
	while(1)
	{
		printf("hello\n");
		sleep(1);
	}
	return 0;
}


























