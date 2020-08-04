#ifndef __MY_JPEG_H__
#define __MY_JPEG_H__


#include <stdio.h>
#include <stdlib.h>
#include "lcd.h"

/*
在指定的位置显示一张指定的JPG图片
picname:JPG文件的路径名
x0:指定位置的横坐标
y0:指定位置的纵坐标
*/
void lcd_draw_jpg(int x0,int y0,char *picname);



#endif