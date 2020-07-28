#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

int main(int argc,char *argv[])
{
	if(argc != 2)
	{
		printf("bro,arg num error\n");
		return -1;
	}
	//打开文件
	int fd = open(argv[1],O_RDONLY);
	if(fd == -1) //如果出错
	{
		perror("open error");
		return -1;
	}
	printf("open success\n");
	//读写文件
	
	char buf[128] = {0};
	ssize_t  x = read(fd,buf,20);
	if(x == -1) //如果出错
	{
		perror("read error");
		return -1;
	}
	printf("x = %ld\n",x);
	printf("buf = %s\n",buf);
	
	//关闭文件
	close(fd);

	return 0;
}
