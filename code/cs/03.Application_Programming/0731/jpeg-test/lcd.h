#ifndef __LCD_H__
#define __LCD_H__

#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/mman.h>

struct lcd_fd
{
	int fd;//保存lcd的文件描述符
	int *plcd;//保存lcd的显存的首地址
};

/*
init_lcd:初始化LCD显示屏返回LCD的文件描述符,显存的首地址
返回值:
	成功结构体指针
	失败返回NULL
*/
struct lcd_fd * init_lcd();



/*
lcd_draw_point:能在指定的位置的点显示一个指定的颜色
@plcd:操作的显存的首地址
@x:指定的点的横坐标
@y:指定的点的纵坐标
@color:指定的点的颜色
返回值:
	无
*/
void lcd_draw_point(int *plcd,int x,int y,int color);




/*
uninit_lcd:关闭lcd
lcd:保存要关闭的lcd的信息
*/
void uninit_lcd(struct lcd_fd *lcd);




#endif