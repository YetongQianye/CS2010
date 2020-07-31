#include"lcd.h"

/*
init_lcd:初始化LCD显示屏返回LCD的文件描述符,显存的首地址
返回值:
	成功结构体指针
	失败返回NULL
*/
struct lcd_fd * init_lcd()
{
	//返回一个结构体指针,结构体必须随进程的持续性(持续到关闭lcd)
	struct lcd_fd *lcd = (struct lcd_fd *)malloc(sizeof(struct lcd_fd));
	
	//1.打开屏幕
	lcd->fd = open("/dev/fb0",O_RDWR);
	if(lcd->fd == -1)
	{
		perror("open error");
		return NULL;
	}	
	//2.把屏幕映射到内存“内存映射”
	//plcd 指向了映射后的内存区域
	
	lcd->plcd = mmap(NULL, 800*480*4, PROT_READ | PROT_WRITE, MAP_SHARED,lcd->fd,0);
	if(lcd->plcd == MAP_FAILED)
	{
		perror("map error");
		close(lcd->fd);
		return NULL;
	}
	//操作plcd指向的内存就相当于操作lcd屏幕
	printf("map success\n");
	return lcd;
}

/*
lcd_draw_point:能在指定的位置的点显示一个指定的颜色
@plcd:操作的显存的首地址
@x:指定的点的横坐标
@y:指定的点的纵坐标
@color:指定的点的颜色
返回值:
	无
*/
void lcd_draw_point(int *plcd,int x,int y,int color)
{
	//保证指定的位置在屏幕的可操作范围内。
	if(x<0 || x>=800 || y<0 || y>= 480)
	{
		printf("sorry,you point out of lcd\n");
		return ;
	}
	*(plcd+800*y+x) = color;
}


/*
uninit_lcd:关闭lcd
lcd:保存要关闭的lcd的信息
*/
void uninit_lcd(struct lcd_fd *lcd)
{
	//解映射
	munmap(lcd->plcd,800*480*4);
	//关闭屏幕
	close(lcd->fd);
	free(lcd);
}