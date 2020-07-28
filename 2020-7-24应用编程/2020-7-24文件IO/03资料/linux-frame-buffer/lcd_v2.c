#include<stdio.h>
#include<errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>

#include <linux/fb.h>
int fd = 0;
void Lcd_draw_rect(int x,int y,int w,int h,int color)
{
	int lcd[480][800] = {0};
	int i,j;
	for(i=0;i<480;i++)
	{
		for(j=0;j<800;j++)
		{
			lcd[i][j] = 0x00ffffff;
		}
	}
	
	for(i=y;i<y+h;i++)
	{
		for(j=x;j<x+w;j++)
		{
			lcd[i][j] = color;
		}
	}
	write(fd,lcd,800*480*4);
}


void Lcd_draw_r(int x,int y,int r,int color)
{
	int lcd[480][800] = {0};
	int i,j;
	for(i=0;i<480;i++)
	{
		for(j=0;j<800;j++)
		{
			lcd[i][j] = 0x00ffffff;
		}
	}
	
	for(i=y-r;i<y+r;i++)
	{
		for(j=x-r;j<x+r;j++)
		{
			if((j-x)*(j-x)+(i-y)*(i-y) <= r*r)
			{
				lcd[i][j] = color;
			}
		}
	}
	write(fd,lcd,800*480*4);
}



int main()
{
	//1.打开文件
	fd = open("/dev/fb0",O_RDWR);
	if(fd == -1) //如果出错
	{
		perror("open lcd error");
		return -1;
	}
	//2.写入颜色数据
	Lcd_draw_rect(100,100,200,40,0x0000ff00);
	sleep(2);
	lseek(fd,0,SEEK_SET);
	Lcd_draw_r(400,240,200,0x00ffff00);
	//3.关闭
	close(fd);
	return 0;
}












