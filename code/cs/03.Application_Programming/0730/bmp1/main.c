#include<stdio.h>
#include"lcd.h"
#include"bmp.h"


int main(int argc,char *argv[])
{
	if(argc != 2)
	{
		printf("bro,arg num error\n");
		return -1;
	}
	//初始化屏幕
	struct lcd_info *lcd = init_lcd();

	//操作屏幕
	Lcd_clear(0x00ffffff);
	sleep(2);
	Lcd_draw_rect(100,100,200,300,0x00ff0000);
	sleep(2);
	lcd_draw_bmp();
	//关闭屏幕
	close_lcd();

	
	return 0;
}



