#define _GNU_SOURCE
#include<stdio.h>
#include<stdlib.h>

#include <unistd.h>

int main()
{
/*
	char buf[12] = {0};
	printf("buf = %p\n",buf);
	//char *p = getwd(buf);
	char *p = getcwd(buf,12);
	if(p == NULL)
	{
		perror("getcwd error:");
		return -1;
	}
	printf("p = %p\n",p);
	printf("PATH = %s\n",buf);
*/
	char *p = (char *)get_current_dir_name();
	if(p == NULL)
	{
		perror("get_current_dir_name error");
		return -1;
	}
	printf("PATH = %s\n",p);
	free(p);
	return 0;
}
