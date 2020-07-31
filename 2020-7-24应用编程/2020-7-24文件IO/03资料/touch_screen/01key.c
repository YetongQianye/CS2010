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
	int fd = open("/dev/input/event1",O_RDWR);
	if(-1 == fd)
	{
		perror("open event1 error");
		return -1;
	}

	struct input_event ev;
	//读取输入事件
	while(1)
	{
		int r = read(fd,&ev,sizeof(ev));
		if(r != sizeof(ev))
		{
			continue;
		}
		//解析输入事件
		if(ev.type == EV_KEY)
		{
			printf("EV_KEY event\n");
			printf("code = %d,value = %d\n",ev.code,ev.value);
		}
	}
	//关闭文件
	close(fd);
	return 0;
}







