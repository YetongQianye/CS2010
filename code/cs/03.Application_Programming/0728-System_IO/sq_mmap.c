//利用内存映射的方法,在屏幕指定的位置显示一个指定大小的矩形。
#include<stdio.h>
#include<errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>

#include <linux/fb.h>
#include <sys/mman.h>

//lcd.c  /lcd.h
int *p_lcd = NULL; //全局变量,显存的首地址
/*
Lcd_draw_point:在指定的像素点显示一个指定的颜色
@x:指定位置的横坐标
@y:指定位置的纵坐标
@color:指定的颜色
*/
void Lcd_draw_point(int x,int y,int color)
{
	if(y >=480 || x >= 800)
	{
		printf("bro,you point out of the lcd!\n");
		return;
	}
	*(p_lcd+800*y+x) = color;
}

//清屏
void Lcd_clear(int color)
{
	int x,y;
	for(y=0;y<480;y++)
	{
		for(x=0;x<800;x++)
		{
			Lcd_draw_point(x,y,color);
		}
	}
}

//在指定的位置显示一个指定大小的矩形
void Lcd_draw_rect(int x0,int y0,int w,int h,int color)
{
	int x,y;
	for(y=y0;y<y0+h;y++)
	{
		for(x=x0;x<x0+w;x++)
		{
			Lcd_draw_point(x,y,color);
		}
	}
	
}

int main()
{
	//打开文件
	int fd = open("/dev/fb0",O_RDWR);
	if(fd == -1) //如果出错
	{
		perror("open lcd error");
		return -1;
	}
	//映射内存
	p_lcd = mmap(NULL, 800*480*4, PROT_WRITE | PROT_READ,MAP_SHARED,fd, 0);
	if(p_lcd == MAP_FAILED)
	{
		perror("map error");
		close(fd);
		return -1;
	}
	//写入颜色数据(直接操作内存)
	Lcd_clear(0x00ffff00);
	Lcd_draw_rect(100,100,500,100,0x000000ff);

	//解映射
	munmap(p_lcd,800*480*4);
	//关闭
	close(fd);
	return 0;
}






























