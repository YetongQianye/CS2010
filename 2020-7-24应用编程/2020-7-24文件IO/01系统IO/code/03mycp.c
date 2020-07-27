#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
//argc:参数个数
// ./main 1.txt 2.txt 
int main(int argc,char *argv[])
{
	//打开文件
	int fd1 = open(argv[1],O_RDONLY); //源文件
	int fd2 = open(argv[2],O_WRONLY | O_CREAT | O_TRUNC,0664); //目标文件
	if(fd1 == -1 || fd2 == -1) //如果出错
	{
		perror("open error");
		printf("errno  = %d\n",errno);
		return -1;
	}
	printf("open success\n");

	//把fd1中的数据读取出来,放到fd2中去
	char buf[1024];
	while(1)
	{
		long x = read(fd1,buf,1024);
		if(x == 0)
		{
			break;
		}else if(x == -1)
		{
			perror("read error");
		}
		write(fd2,buf, x);
	}

	//关闭文件
	close(fd1);
	close(fd2);

	return 0;
}

