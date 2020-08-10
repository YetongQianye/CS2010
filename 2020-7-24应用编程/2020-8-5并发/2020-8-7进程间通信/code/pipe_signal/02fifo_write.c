#include<stdio.h>
#include<errno.h>

#include<unistd.h>
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
    int fd = open(FIFO,O_WRONLY);
    if(fd == -1)
    {
		perror("open error");
		return -1;
    }
	printf("fd = %d,write open success\n",fd);

	//从stdin中获取数据写入管道
	char buf[BUFSIZE] = {0};
	fgets(buf,BUFSIZE,stdin);
	r = write(fd,buf,20);
	printf("write r = %d\n",r);

	//再一次写入数据
	fgets(buf,BUFSIZE,stdin);
	r = write(fd,buf,20);//???程序收到了一个信号 SIGPIPE
	printf("我死了ma?\n"); 
						//管道破裂 pipe     broken 
	printf("write r = %d\n",r); //????
	
	close(fd);
	
	return 0;
}
