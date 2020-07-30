#ifndef __LCD_H__
#define __LCD_H__

#include<stdio.h>
#include<errno.h>
#include<stdlib.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>

#include <linux/fb.h>
#include <sys/mman.h>




//保存打开的屏幕的信息
struct lcd_info
{
	int *plcd;
	int fd;
};


//初始化屏幕
 struct lcd_info *init_lcd();



//关闭屏幕
//void close_lcd( struct lcd_info *lcd);	
void close_lcd();


/*
Lcd_draw_point:在指定的像素点显示一个指定的颜色
@x:指定位置的横坐标
@y:指定位置的纵坐标
@color:指定的颜色
*/
void Lcd_draw_point(int x,int y,int color);

//清屏
void Lcd_clear(int color);

//在指定的位置显示一个指定大小的矩形
void Lcd_draw_rect(int x0,int y0,int w,int h,int color);

#endif




