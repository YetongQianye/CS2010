
#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#define MAXLENGTH 100
int main()
{
	//打开文件
	int fd = open("1.txt",O_RDWR | O_CREAT,0664);
	printf("fd = %d\n",fd);
	if(fd == -1) //如果出错
	{
		perror("open 1.txt error");
		printf("errno  = %d\n",errno);
		return -1;
	}
	printf("open success\n");
	//读写文件
	//使用read函数
	/* char buf[128] = {0};
	ssize_t  x = read(fd,buf,20);
	printf("x = %ld\n",x);
	printf("buf = %s\n",buf); */

	//使用write函数
	char buf[MAXLENGTH]="you are so beautiful";
	ssize_t x = write(fd, buf, 10);
	printf("x = %ld\n",x);
	printf("buf = %s\n",buf);

	//使用lseek函数
	

	//关闭文件
	close(fd);

	
}
















