#include"lcd.h"

struct lcd_info *lcd = NULL;
/*
init_lcd:初始化屏幕
成功返回初始化后的屏幕的信息(结构体指针)
失败返回NULL
*/
 struct lcd_info *init_lcd()
 {
 	//开辟空间存储lcd的信息
	lcd = (struct lcd_info *)malloc(sizeof(*lcd));
	//打开屏幕
	lcd->fd = open("/dev/fb0",O_RDWR);
	if(lcd->fd == -1) //如果出错
	{
		perror("open lcd error");
		return NULL;
	}
	//映射内存
	lcd->plcd = mmap(NULL, 800*480*4, PROT_WRITE | PROT_READ,MAP_SHARED,lcd->fd, 0);
	if(lcd->plcd == MAP_FAILED)
	{
		perror("map error");
		close(lcd->fd);
		return NULL;
	}

	return lcd;
 }



//关闭屏幕
void close_lcd()
{
	//解映射
	munmap(lcd->plcd,800*480*4);
	//关闭
	close(lcd->fd);
	free(lcd);
}

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
	*(lcd->plcd+800*y+x) = color;
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



