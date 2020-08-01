#include"lcd.h"

//全局变量，表示显存的首地址
int *plcd = NULL;
int fd_lcd;//全局变量，lcd的文件描述符
//初始化屏幕，映射内存
void lcd_init()
{
	//打开屏幕
	fd_lcd = open("/dev/fb0",O_RDWR);
	if(-1 == fd_lcd)
	{
		perror("open error");
		return;
	}
	
	struct fb_var_screeninfo info;	
	int x = ioctl(fd_lcd,FBIOGET_VSCREENINFO,&info);
#ifdef DEBUG	
	//屏幕的宽度,屏幕的高度
	printf("resolution:%d * %d\n",info.xres,info.yres);

	//像素点的大小
	printf("fbinfo.bits_per_pixel:%d\n",info.bits_per_pixel);
	//像素点的RGB信息
	//R
	printf("R.offset:%d\n",info.red.offset);
	printf("R.length:%d\n",info.red.length);
	printf("R.msb_right:%d\n",info.red.msb_right);
	//G
	printf("G.offset:%d\n",info.green.offset);
	printf("G.length:%d\n",info.green.length);
	printf("G.msb_right:%d\n",info.green.msb_right);
	//B 
	printf("B.offset:%d\n",info.blue.offset);
	printf("B.length:%d\n",info.blue.length);
	printf("B.msb_right:%d\n",info.blue.msb_right);
	//A
	printf("A.offset:%d\n",info.transp.offset);
	printf("A.length:%d\n",info.transp.length);
	printf("A.msb_right:%d\n",info.transp.msb_right);
#endif	
	//映射内存
	plcd = mmap(NULL, 800*480*4, PROT_READ | PROT_WRITE , MAP_SHARED,
                  fd_lcd, 0);
	if(plcd == MAP_FAILED)
	{
		perror("mmap error");
		return;
	}		
	
	printf("mmap success\n");
}

//在LCD指定的坐标显示一个指定的颜色
/*
x：指定的点的横坐标
y:指定的点的纵坐标
color:指定的颜色
*/
void lcd_draw_point(int x,int y,int color)
{
	if(x >= 800 || y >= 480)
	{
		printf("bro,you point out of you lcd\n");
		return;
	}
	*(plcd + 800*y + x) = color;
}

/*
在指定的位置显示一张指定的BMP图片
picname:BMP文件的路径名
x0:指定位置的横坐标
y0:指定位置的纵坐标
*/
void lcd_draw_bmp(int x0,int y0,char *picname)
{		
	//打开BMP文件
	int fd_bmp = open(picname,O_RDWR);
	if(fd_bmp == -1)
	{
		perror("open error");
		return;
	}
	//获取图片本身的信息 像素点数组大小，宽度，高度，位深
	
	//把文件的偏移量定位到离文件开头的 0x12的地方
	lseek(fd_bmp,0x12,SEEK_SET);
	char buf[4];
	//把文件光标处的4个字节读到数组 buf中去
	read(fd_bmp,buf,4);
	
	int width = (buf[0] & 0xff) | ((buf[1] & 0xff)<<8) |
			((buf[2] & 0xff) << 16 ) | ((buf[3] & 0xff) <<24);
#ifdef DEBUG			
	printf("width = %d\n",width);
#endif	
	
	//把文件的偏移量定位到离文件开头的 0x16的地方
	lseek(fd_bmp,0x16,SEEK_SET);
	//把文件光标处的4个字节读到数组 buf中去
	read(fd_bmp,buf,4);
	int height = (buf[0] & 0xff) | ((buf[1] & 0xff)<<8) |
			((buf[2] & 0xff) << 16 ) | ((buf[3] & 0xff) <<24);
	
#ifdef DEBUG			
	printf("height = %d\n",height);
#endif	
	//这个bmp文件的像素点占用多少个字节？
	//把文件的偏移量定位到离文件开头的 0x1c的地方
	lseek(fd_bmp,0x1c,SEEK_SET);
	//把文件光标处的2个字节读到数组 buf中去
	read(fd_bmp,buf,2);
	int color_depth = (buf[0] & 0xff) | ((buf[1] & 0xff)<<8);
	
#ifdef DEBUG			
	printf("color_depth = %d\n",color_depth);
#endif		
	
	
	//这个bmp文件的像素点数组大小是多少？
	int size = abs(width*height*(color_depth/8));
	
	//读取像素点信息
	char pixel[size];
	//unsigned char *pixel = malloc(size);
	//把文件的偏移量定位到离文件开头的 0x36的地方
	lseek(fd_bmp,54,SEEK_SET);
	read(fd_bmp,pixel,size);
	//关闭BMP文件
	close(fd_bmp);
	//解析像素点信息
	int x,y;
	int color;
	char a,b,g,r;
	int i = 0;
	for(y=0;y<height;y++) //图片有hight行
	{
		for(x = 0;x<abs(width);x++) //图片有width列
		{
			//把 BGR 			int dy = height>0?(y0+height-1-y):y0+y;
			lcd_draw_point(x+x0,dy,color);
		}=====》 ARGB
			//把像素点显示到屏幕上面去
			//如果是 32位。。。如果是24 位 。。。
			b = pixel[i++];
			g = pixel[i++];
			r = pixel[i++];
			a = (color_depth == 32)?pixel[i++]:0;
			color = (a<<24) | (r<<16) | (g<<8) | b;

		//如果图片一行的大小不是4的倍数
		if( (x*(color_depth/8)) % 4 != 0)
		{
			i+= 4 - x*(color_depth/8)%4;
		}
	}	
	
}



/*
把屏幕是显示成指定的颜色
color:你要显示的颜色
*/
void lcd_clear(int color)
{
	int x,y;
	//每一个像素点都显示为指定的颜色
	for(y=0;y<480;y++) //遍历每一行
	{
		for(x=0;x<800;x++) //遍历每一列
		{
			lcd_draw_point(x,y,color);	
		}
	}
}


//解除映射，关闭lcd
void lcd_uninit()
{
	munmap(plcd, 800*480*4);
	close(fd_lcd);
}
       