#include<stdio.h>
#include<unistd.h>
#include<errno.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define FIFO "/home/china/2010"
#define BUFSIZE 128
int main()
{
	//创建一个有名管道
	int r = mkfifo(FIFO, 0664);
	if(r == -1 && errno != EEXIST)
	{
		perror("mkfifo error");
		return -1;
	}
	//打开管道的读端
    int fd = open(FIFO,O_RDONLY);
    if(fd == -1)
    {
		perror("open error");
		return -1;
    }
	printf("fd = %d,open success\n",fd);

	//从管道中获取数据
	char buf[BUFSIZE] = {0};
	r = read(fd,buf,BUFSIZE);
	printf("read r = %d\n",r);
	printf("buf = %s\n",buf);
	close(fd);
	
	return 0;
}















