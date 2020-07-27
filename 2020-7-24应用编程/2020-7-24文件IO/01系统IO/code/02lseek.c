#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

int main(int argc,char *argv[])
{
	//打开文件
	int fd = open(argv[1],O_RDWR | O_CREAT,0664);
	printf("fd = %d\n",fd);
	if(fd == -1) //如果出错
	{
		perror("open error");
		printf("errno  = %d\n",errno);
		return -1;
	}
	printf("open success\n");
	//基于文件末尾定位光标
	off_t s = lseek(fd, 500, SEEK_END);
	if(s == -1)
	{
		perror("lseek failed");
		return -1;
	}
	
	printf("s = %d\n",s);
	
	//从键盘获取字符串写入到文件
	char buf[128] = {0};
	fgets(buf,128, stdin);  //12345677654321
	ssize_t x = write(fd,buf, 1);
	printf("x = %ld\n",x);   //
	
	//关闭文件
	close(fd);

	return 0;
}
















