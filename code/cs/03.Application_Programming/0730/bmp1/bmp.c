#include"bmp.h"
#include"lcd.h"

//extern struct lcd_info *lcd;

//仅仅是显示一个图片
void lcd_draw_bmp()
{
	//把bmp文件中的像素点信息拿出来,写入到显存
	//打开bmp图片
	int fd_bmp = open("gm.bmp",O_RDWR);
	if(fd_bmp == -1)
	{
		perror("open bmp error\n");
		close_lcd();	
	}
	
	//读取所有的像素点信息
	char buf[600*400*3] = {0};
	lseek(fd_bmp,54,SEEK_SET);
	read(fd_bmp,buf,600*400*3);
	
	//关闭图片
	close(fd_bmp);
	
	//解析所有的像素点且显示
	int x,y;
	char b,g,r; 
	int color;
	int i = 0;
	for(y=399;y>=0;y--) //图片总共有200行
	{
		for(x=0;x<600;x++)//图片每一行有200个点
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
}

