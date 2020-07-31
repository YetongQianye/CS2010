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
	int x=0;
	int y=0;
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
			//printf("ABS  event\n");
			//printf("code = %d,value = %d\n",ev.code,ev.value);
			if(ev.code == ABS_X)
			{
				x = ev.value;
			}
			if(ev.code == ABS_Y)
			{
				y = ev.value;
			}
		}
		//手指松开
		if(ev.type == EV_KEY && ev.code == BTN_TOUCH && ev.value == 0)
		{
			break;
		}
	}
	printf("x = %d,y = %d\n",x,y);
	//关闭文件
	close(fd);
	return 0;
}







