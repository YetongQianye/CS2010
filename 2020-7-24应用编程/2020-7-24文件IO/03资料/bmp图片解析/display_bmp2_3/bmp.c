#include"bmp.h"
#include"lcd.h"

//extern struct lcd_info *lcd;
/*
//仅仅是显示一个图片
void lcd_draw_bmp()
{
	//把bmp文件中的像素点信息拿出来,写入到显存
	//打开bmp图片
	int fd_bmp = open("1.bmp",O_RDWR);
	if(fd_bmp == -1)
	{
		perror("open bmp error\n");
		close_lcd();	
	}
	
	//读取所有的像素点信息
	char buf[200*200*3] = {0};
	lseek(fd_bmp,54,SEEK_SET);
	read(fd_bmp,buf,200*200*3);
	
	//关闭图片
	close(fd_bmp);
	
	//解析所有的像素点且显示
	int x,y;
	char b,g,r; 
	int color;
	int i = 0;
	for(y=199;y>=0;y--) //图片总共有200行
	{
		for(x=0;x<200;x++)//图片每一行有200个点
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
*/
/*
//把名字为name的bmp图片显示到(x0,y0)的位置,图片的大小为w*h
void lcd_draw_bmp(int x0,int y0,int w,int h,char *name)
{
	//把bmp文件中的像素点信息拿出来,写入到显存
	//打开bmp图片
	int fd_bmp = open(name,O_RDWR);
	if(fd_bmp == -1)
	{
		perror("open bmp error\n");
		close_lcd();	
	}
	
	//读取所有的像素点信息
	//char buf[w*h*3];
	char *buf = (char *)malloc(sizeof(char)*w*h*3);
	lseek(fd_bmp,54,SEEK_SET);
	read(fd_bmp,buf,w*h*3);
	
	//关闭图片
	close(fd_bmp);
	
	//解析所有的像素点且显示
	int x,y;
	unsigned char b,g,r; 
	unsigned int color;
	int i = 0;
	for(y=h+y0-1;y>=y0;y--) //图片总共有w行
	{
		for(x=x0;x<x0+w;x++)//图片每一行有h个点
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
	free(buf);
}
*/

/*
//把名字为name的bmp图片显示到(x0,y0)的位置
void lcd_draw_bmp(int x0,int y0,char *name)
{
	//把bmp文件中的像素点信息拿出来,写入到显存
	//打开bmp图片
	int fd_bmp = open(name,O_RDWR);
	if(fd_bmp == -1)
	{
		perror("open bmp error\n");
		close_lcd();	
	}
	char buf[4];
	//读取图片的大小
	int w;
	lseek(fd_bmp,0x12,SEEK_SET); //把光标定位到0x12
	read(fd_bmp,buf,4);
	w = (buf[0] & 0xff) |
		((buf[1] & 0xff)<<8) |
		((buf[2] & 0xff)<<16) |
		((buf[3] & 0xff)<<24) ;
	int h;
	lseek(fd_bmp,0x16,SEEK_SET); //把光标定位到0x16
	read(fd_bmp,buf,4);
	h = (buf[0] & 0xff) |
		((buf[1] & 0xff)<<8) |
		((buf[2] & 0xff)<<16) |
		((buf[3] & 0xff)<<24) ;

	int color_depth = 0;
	lseek(fd_bmp,0x1C,SEEK_SET); //把光标定位到0x1C
	read(fd_bmp,buf,2);
	color_depth = (buf[0] & 0xff) |
		((buf[1] & 0xff)<<8);
	printf("size:%d*%d\n",w,h);
	printf("color_depth:%d\n",color_depth);
	char *p = (char *)malloc(sizeof(char)*w*h*color_depth/8);
	//读取所有的像素点信息
	lseek(fd_bmp,54,SEEK_SET);
	read(fd_bmp,p,w*h*color_depth/8);
	
	//关闭图片
	close(fd_bmp);
	
	//解析所有的像素点且显示
	int x,y;
	unsigned char b,g,r; 
	unsigned int color;
	int i = 0;
	for(y=h+y0-1;y>=y0;y--) //图片总共有w行
	{
		for(x=x0;x<x0+w;x++)//图片每一行有h个点
		{
			//解析一个像素点
			b = p[i];
			g = p[i+1];
			r = p[i+2];
			i+=3;
			color = (r<<16) | (g << 8) | (b);
			Lcd_draw_point(x,y,color);
		}
	}
	free(p);
}
*/

//把名字为name的bmp图片显示到(x0,y0)的位置
void lcd_draw_bmp(int x0,int y0,char *name)
{
	//把bmp文件中的像素点信息拿出来,写入到显存
	//打开bmp图片
	int fd_bmp = open(name,O_RDWR);
	if(fd_bmp == -1)
	{
		perror("open bmp error\n");
		close_lcd();	
	}
	char buf[4];
	//读取图片的大小
	int w;
	lseek(fd_bmp,0x12,SEEK_SET); //把光标定位到0x12
	read(fd_bmp,buf,4);
	w = (buf[0] & 0xff) |
		((buf[1] & 0xff)<<8) |
		((buf[2] & 0xff)<<16) |
		((buf[3] & 0xff)<<24) ;
	int h;
	lseek(fd_bmp,0x16,SEEK_SET); //把光标定位到0x16
	read(fd_bmp,buf,4);
	h = (buf[0] & 0xff) |
		((buf[1] & 0xff)<<8) |
		((buf[2] & 0xff)<<16) |
		((buf[3] & 0xff)<<24) ;

	int color_depth = 0;
	lseek(fd_bmp,0x1C,SEEK_SET); //把光标定位到0x1C
	read(fd_bmp,buf,2);
	color_depth = (buf[0] & 0xff) |
		((buf[1] & 0xff)<<8);
	printf("size:%d*%d\n",w,h);
	printf("color_depth:%d\n",color_depth);
	char *p = (char *)malloc(sizeof(char)*w*h*color_depth/8);
	//读取所有的像素点信息
	lseek(fd_bmp,54,SEEK_SET);
	read(fd_bmp,p,w*h*color_depth/8);
	
	//关闭图片
	close(fd_bmp);
	
	//解析所有的像素点且显示
	int x,y;
	unsigned char b,g,r; 
	unsigned int color;
	int i = 0;
	for(y=h+y0-1;y>=y0;y--) //图片总共有w行
	{
		for(x=x0;x<x0+w;x++)//图片每一行有h个点
		{
			//解析一个像素点
			b = p[i];
			g = p[i+1];
			r = p[i+2];
			i+=3;
			color = (r<<16) | (g << 8) | (b);
			Lcd_draw_point(x,y,color);
		}
	}
	free(p);
}


