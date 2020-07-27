#define _GNU_SOURCE
#include<stdio.h>
#include <unistd.h>
#include<stdlib.h>

int main()
{
	char *p = (char *)get_current_dir_name();
	if(p == NULL)
	{
		perror("get_current_dir_name error");
		return -1;
	}
	printf("PATH = %s\n",p);
	free(p);

	chdir("/home/china");
	p = (char *)get_current_dir_name();
	printf("PATH = %s\n",p);
	free(p);
	return 0;
}





