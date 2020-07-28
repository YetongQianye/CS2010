#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <sys/mman.h>

int main(int argc,char *argv[])
{
	if(argc != 2)
	{
		printf("bro,arg num error\n");
		return -1;
	}
	//打开文件
	int fd = open(argv[1],O_RDWR);
	if(fd == -1) //如果出错
	{
		perror("open error");
		return -1;
	}
	//把文件映射到内存
	//指针的单位决定操作的内存的长度
	int *p = mmap(NULL, 4096, PROT_READ | PROT_WRITE, MAP_SHARED,fd, 0);
	if(p == MAP_FAILED)
	{
		perror("mmap error");
		close(fd);
		return -1;
	}
	//-------------------------------
	//直接通过指针p操作内存去操作文件

	int ch = *p;
	printf("ch = %d\n",ch);

	*(p+1) = 1234;

	
	//--------------------------------

	//解映射
	munmap(p,4096);
	//关闭文件
	close(fd);
	return 0;
}

















