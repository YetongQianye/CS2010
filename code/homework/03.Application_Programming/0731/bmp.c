#include"bmp.h"
#include"lcd.h"

//extern struct lcd_info *lcd;

 
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
	//char *p = (char *)malloc(sizeof(char)*w*abs(h)*color_depth/8);
	int size = lseek(fd_bmp,0,SEEK_END);
	size-=54;
	char *p = (char *)malloc(sizeof(char)*size);
	//读取所有的像素点信息
	lseek(fd_bmp,54,SEEK_SET);
	read(fd_bmp,p,size);
	
	//关闭图片
	close(fd_bmp);
	
	//解析所有的像素点且显示
	int x,y;
	unsigned char a,b,g,r; 
	unsigned int color;
	int i = 0;
	for(y=0;y<abs(h);y++) //图片总共有h行
	{
		for(x=0;x<w;x++)//图片每一行有w个点
		{
			//解析一个像素点
			b = p[i++];
			g = p[i++];
			r = p[i++];
			a = (color_depth == 32)?p[i++]:0;
			color = (a<<24) | (r<<16) | (g << 8) | (b);
			//根据h的符号决定y坐标
			int dy = h>0?(y0+h-1-y):(y0+y);
			Lcd_draw_point(x+x0,dy,color);
		}
		//根据情况跳过填充字节
		if(((color_depth/8)*w)%4 != 0) 
		{
			i+= 4-((color_depth/8)*w)%4;
		}
	}
	free(p);
}


