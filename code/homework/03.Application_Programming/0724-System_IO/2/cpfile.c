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
    int fd1 = open("1.txt",O_RDWR | O_CREAT,0664);
    int fd2 = open("2.txt",O_RDWR | O_CREAT,0664);
    printf("fd1 = %d\n",fd1);
    printf("fd2 = %d\n",fd2);
	if(fd1 == -1) //如果出错
	{
		perror("open 1.txt error");
		printf("errno  = %d\n",errno);
		return -1;
	}
	printf("open success\n");

    if(fd2 == -1) //如果出错
	{
		perror("open 2.txt error");
		printf("errno  = %d\n",errno);
		return -1;
	}
	printf("open success\n");

	//读写文件
	//使用read函数
	char buf_read[MAXLENGTH]="you are so beautiful";
	ssize_t  x1 = read(fd1,buf_read,20);
	printf("x1 = %ld\n",x1);
	printf("buf_read = %s\n",buf_read);

	//使用write函数
	//char buf_write[MAXLENGTH]="you are so beautiful";
	ssize_t x2 = write(fd2,buf_read, 20);
	printf("x2 = %ld\n",x2);
	printf("buf_write = %s\n",buf_read);



	//关闭文件
	close(fd1);
    close(fd2);

	
}
















