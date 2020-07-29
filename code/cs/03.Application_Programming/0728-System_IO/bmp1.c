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
int *plcd = NULL; //全局变量,显存的首地址
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
	*(plcd+800*y+x) = color;
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
	plcd = mmap(NULL, 800*480*4, PROT_WRITE | PROT_READ,MAP_SHARED,fd, 0);
	if(plcd == MAP_FAILED)
	{
		perror("map error");
		close(fd);
		return -1;
	}
	
	//写入颜色数据(直接操作内存)
	//把bmp文件中的像素点信息拿出来,写入到显存
	//打开bmp图片
	int fd_bmp = open("g.bmp",O_RDWR);
	if(fd_bmp == -1)
	{
		perror("open bmp error\n");
		//解映射
		munmap(plcd,800*480*4);
		//关闭
		close(fd);
		close(fd_bmp);
	}
	
	//读取所有的像素点信息
	char buf[666*470*3] = {0};
	lseek(fd_bmp,54,SEEK_SET);
	read(fd_bmp,buf,666*470*3);
	
	//关闭图片
	close(fd_bmp);
	
	//解析所有的像素点且显示
	int x,y;
	char b,g,r; 
	int color;
	int i = 0;
	for(y=469;y>=0;y--) //图片总共有200行
	{
		for(x=0;x<666;x++)//图片每一行有200个点
		{
			//解析一个像素点
			b = buf[i];
			g = buf[i+1];
			r = buf[i+2];
			i+=3;
			color = (r<<16) | (g << 8) | (b);
			Lcd_draw_point(x,y,color);
		}
	}

	
	//解映射
	munmap(plcd,800*480*4);
	//关闭
	close(fd);
	return 0;
}

