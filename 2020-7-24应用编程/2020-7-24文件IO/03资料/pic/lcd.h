#ifndef __LCD__H__
#define __LCD__H__

#include<stdio.h>
#include <sys/types.h> //for open
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h> //for close
#include <sys/mman.h> //mmap
#include <sys/ioctl.h> //ioctl

#include <linux/fb.h> // fb的结构体
       
//初始化LCD显示屏
//返回值：返回LCD的文件描述符
void lcd_init();
void lcd_uninit();
//在LCD指定的坐标显示一个指定的颜色
/*
x：指定的点的横坐标
y:指定的点的纵坐标
color:指定的颜色
*/
void lcd_draw_point(int x,int y,int color);
/*
把屏幕是显示成指定的颜色
color:你要显示的颜色
*/
void lcd_clear(int color);


/*
在指定的位置显示一张指定的BMP图片
picname:BMP文件的路径名
x:指定位置的横坐标
y:指定位置的纵坐标
*/
void lcd_draw_bmp(int x,int y,char *picname);


#endif