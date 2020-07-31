#include<stdio.h>
#include<errno.h>
#include<stdlib.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <linux/input.h>


int main()
{
	//打开文件
	int fd = open("/dev/input/event0",O_RDWR);
	if(-1 == fd)
	{
		perror("open event0 error");
		return -1;
	}

	struct input_event ev;
	//读取输入事件
	int x0=-1,y0=-1;//起点
	int x,y; //终点
	
	while(1)
	{
		int r = read(fd,&ev,sizeof(ev));
		if(r != sizeof(ev))
		{
			continue;
		}
		//解析输入事件
		if(ev.type == EV_ABS)
		{
		
			if(ev.code == ABS_X)
			{
				if(x0 == -1)
				{
					x0 = ev.value;
				}
				x = ev.value;
			}
			if(ev.code == ABS_Y)
			{
				if(y0 == -1)
				{
					y0 = ev.value;
				}
				y = ev.value;
			}
		}
		//手指松开
		if(ev.type == EV_KEY && ev.code == BTN_TOUCH && ev.value == 0)
		{
			break;
		}
	}
	//printf("x0 = %d,y0 = %d\n",x0,y0);
	//printf("x = %d,y = %d\n",x,y);

	if(y<y0&&abs(x-x0)<=abs(y-y0))
	{
		printf("up\n");
	}
	else if(y>y0&&abs(x-x0)<=abs(y-y0))
	{
		printf("down\n");
	}
	else if(x<x0&&abs(x-x0)>=abs(y-y0))
	{
		printf("left\n");
	}else if(x>x0&&abs(x-x0)>=abs(y-y0))
	{
		printf("right\n");
	}
	
	//关闭文件
	close(fd);
	return 0;
}







