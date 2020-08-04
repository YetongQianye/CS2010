#include"touch.h"


//获取手指滑动方向
enum drec get_touch()
{
	//1.打开设备文件(/dev/input/event0)
	int fd = open("/dev/input/event0",O_RDWR | O_NONBLOCK);
	if(-1 == fd)
	{
		perror("open error");
		return ;
	}
	struct input_event ev;
	//2.从文件中读(获取)  struct input_event
	int x0 = -1,y0 = -1; //起点
	int x1 = 0,y1 = 0; //终点
	int x  = 100000;
	while(x--)
	{
		//3.解析 读到的结构体，打印获取到的坐标点
		int res = read(fd,&ev,sizeof(ev));
		if(res != sizeof(ev))
		{
			continue;
		}
		if(ev.type == EV_ABS)
		{
			if(ev.code == ABS_X)
			{
				if(x0 == -1)
				{
					x0 = ev.value;	
				}
				x1 = ev.value;
			}else if(ev.code == ABS_Y)
			{
				if(y0 == -1)
				{
					y0 = ev.value;	
				}
				y1 = ev.value;
			}
		}
		//当手指松开的时候结束循环
		if(ev.type == EV_KEY && ev.code == BTN_TOUCH && ev.value == 0)
		{
			break;
		}
	}
#ifdef DEBUG	
	printf("x0 = %d,y0 = %d\n",x0,y0);
	printf("x1 = %d,y1 = %d\n",x1,y1);
#endif 
	enum drec DEC;
	if(abs(x1-x0) < abs(y0-y1) && y0 > y1)
	{
		//printf("up\n");
		DEC = UP;
	}else if(abs(x1-x0) < abs(y0-y1) && y0 < y1)
	{
		//printf("down\n");
		DEC = DOWN;
	}else if(abs(x1-x0) > abs(y0-y1) && x0 > x1)
	{
		//printf("left\n");
		DEC = LEFT;
	}else if(abs(x1-x0) > abs(y0-y1) && x0 < x1)
	{
		//printf("right\n");
		DEC = RIGHT;
	}else if(x0 == -1 && y0 == -1)
	{
		//printf("no touch\n");
		DEC = NOT;
	}
	
	//4.关闭文件
	close(fd);
	return DEC;
}