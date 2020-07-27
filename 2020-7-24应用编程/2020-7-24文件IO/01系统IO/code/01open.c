#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

int main()
{
	//打开文件
	int fd = open("1.txt",O_RDWR | O_CREAT,0664);
	//"1.txt"------>当前工作路径/1.txt
	printf("fd = %d\n",fd);
	if(fd == -1) //如果出错
	{
		perror("open 1.txt error");
		printf("errno  = %d\n",errno);
		return -1;
	}
	printf("open success\n");
	//读写文件
	/*
	char buf[128] = {0};
	ssize_t  x = read(fd,buf,20);
	printf("x = %ld\n",x);
	printf("buf = %s\n",buf);
	*/
	char buf[128] = {0};
	fgets(buf,128, stdin);  //abcdefg

	ssize_t x = write(fd,buf, 5);
	printf("x = %ld\n",x);   //5

	x = read(fd,buf,20);
	printf("x = %ld\n",x);  //11
	printf("buf = %s\n",buf); //
	
	//关闭文件
	close(fd);

	return 0;
}
















