#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{

	int r = stat("1.txt",stat);
	if(r == -1)
	{
		perror("stat failed");
		return -1;
	}
	return 0;
}

struct stat 
{
    
};