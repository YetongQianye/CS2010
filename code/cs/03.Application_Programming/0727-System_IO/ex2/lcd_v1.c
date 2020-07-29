#include<stdio.h>
#include<errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
	//1.打开文件
	int fd = open("/dev/fb0",O_RDWR);
	if(fd == -1) //如果出错
	{
		perror("open lcd error");
		return -1;
	}
	//2.写入颜色数据
	//800*480
	int color[480][800] = {0};
	int i,j;
	for(i=0;i<480;i++)
	{
		for(j=0;j<800;j++)
		{
			color[i][j] = 0x006633ff;
		}
	}

	write(fd,color,800*480*4);

	
	//3.关闭
	close(fd);
	return 0;
}












