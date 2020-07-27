#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{

	int r = truncate("1.txt",100);
	if(r == -1)
	{
		perror("truncate failed");
		return -1;
	}
	return 0;
}
