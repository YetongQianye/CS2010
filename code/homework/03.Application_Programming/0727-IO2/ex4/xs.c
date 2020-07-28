//4.运行程序,在屏幕上显示一个矩形,2s后,在屏幕上显示一个圆形	

#include<stdio.h>
#include<errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>

#include <linux/fb.h>

int main()
{
	//1.打开文件
	int fd = open("/dev/fb0",O_RDWR);
	if(fd == -1) //如果出错
	{
		perror("open lcd error");
		return -1;
	}
	//获取可视屏幕的信息
	struct fb_var_screeninfo fbinfo;
	ioctl(fd,FBIOGET_VSCREENINFO, &fbinfo); 
	
	//打印可视屏幕的尺寸
	printf("resolution size:%d * %d\n",fbinfo.xres,fbinfo.yres);
	//每一个像素点的大小
	printf("bits_per_pixel:%d\n",fbinfo.bits_per_pixel);
	//每一个颜色的分量
	//透明度
	printf("fbinfo.transp.offset = %d,fbinfo.transp.length = %d\n",
			fbinfo.transp.offset,fbinfo.transp.length);
	//red
	printf("fbinfo.red.offset = %d,fbinfo.red.length = %d\n",
			fbinfo.red.offset,fbinfo.red.length);
	//green
	printf("fbinfo.green.offset = %d,fbinfo.green.length = %d\n",
			fbinfo.green.offset,fbinfo.green.length);
	//blue
	printf("fbinfo.blue.offset = %d,fbinfo.blue.length = %d\n",
			fbinfo.blue.offset,fbinfo.blue.length);
	//2.写入颜色数据
	//800*480

	int color[480][800] = {0};
	int i,j;
	//显示矩形
	for(i=0;i<480;i++)
	{
		for(j=0;j<800;j++)
		{
            if((200<i&&i<280)&&(200<j&&j<600))
            {
                color[i][j] = 0x00FF0000;
            }
            else
            {
                color[i][j] = 0x000000CC;
            }
            			
		}
	}
    write(fd,color,800*480*4);
    sleep(2);	//延时2秒
	fd = open("/dev/fb0",O_RDWR);
   
   //显示圆形
	for(i=0;i<480;i++)
	{
		for(j=0;j<800;j++)
		{
            if((i-240)*(i-240)+(j-400)*(j-400)<=40000)
            {
                color[i][j] = 0x00FF0000;
            }
            else
            {
                color[i][j] = 0x000000CC;
            }
            			
		}
	}

	write(fd,color,800*480*4);

	
	//3.关闭
	close(fd);
	return 0;
}












