#include <stdio.h>
#include <stdlib.h>
#include "jpeglib.h"
#include "jerror.h"

#include "lcd.h"

int main(int argc,char *argv[])
{
	//初始化lcd屏幕
	struct lcd_fd *lcd =  init_lcd();
	
	//解压一张指定的jpeg图片并且显示到lcd上面
	
//1.分配并初始化一个jpeg解压对象
	//声明一个解压对象
	struct jpeg_decompress_struct  dinfo;
	//声明一个结构体jerr保存出错信息
	struct jpeg_error_mgr jerr;
	//初始化这个出错对象
	dinfo.err = jpeg_std_error(&jerr);
	//初始化dinfo这个解压对象	
	jpeg_create_decompress(&dinfo); 
	
//2.指定要解压缩的图像文件	
	FILE *fp;
	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		perror("fopen error");
		jpeg_destroy_decompress(&dinfo);
		return;
	}
	//把jpeg文件和解压对象向关联
	jpeg_stdio_src(&dinfo,fp);
	
//3.调用jpeg_read_header()获取图像信息
	jpeg_read_header(&dinfo,TRUE);	
	
//4.	用于设置jpeg解压对象dinfo的一些参数。可采用默认参数	

//5. 调用jpeg_start_decompress()启动解压过程
	jpeg_start_decompress(&dinfo);
	/*
	下面这几个字段(成员变量)将会比较有用：
	dinfo.output_width: 	图像输出宽度，一行占多少个像素点
	dinfo.output_height:	图像输出高度，占多少行
	dinfo.output_components:  每个像素点的分量数，每个像素点占多少个字节
	*/
	//printf("picsize:%d*%d\n",dinfo.output_width,dinfo.output_height);
	//printf("dinfo.output_components:%d\n",dinfo.output_components);
	
	//开辟合适的空间,存储读取的一行像素点的信息。
	//jpeg图片是一行一行解压的
	
	unsigned char *buffer = (unsigned char *)malloc(dinfo.output_width*dinfo.output_components);
	
	//dinfo.output_scanline , 表示的意思是,已经读取了多少行,有dinfo结构体自动维护
	int x,y;
	int i=0;
	unsigned char a,r,g,b;
	int color;
	while(dinfo.output_scanline < dinfo.output_height)
	{
		y = dinfo.output_scanline;
		//printf("y = %d\n",y);
		jpeg_read_scanlines(&dinfo,  //解压对象
							&buffer,//保存解压后数据的二级指针, 
							1 //读取多少行数据来解压
							);					
		//读取一行就处理一行,每一个像素点:RGB
		//一行的像素点数据存储在buffer数组中
		i=0;
		for(x=0;x<dinfo.output_width;x++)
		{
			//每一个点的处理
			if(dinfo.output_components == 3)
			{
				a=0;
			}else
			{
				a = buffer[i++];
			}
			r = buffer[i++];
			g = buffer[i++];
			b = buffer[i++];
			color = (a<<24)	| (r<<16) |(g<<8) | b;
			lcd_draw_point(lcd->plcd,x,y,color);
		}	
	}
	
//7. 调用jpeg_finish_decompress()完成解压过程
	jpeg_finish_decompress(&dinfo);

//8. 调用jpeg_destroy_decompress释放jpeg解压对象dinfo
	jpeg_destroy_decompress(&dinfo);
	
	free(buffer);
	//关闭jpeg图片
	fclose(fp);
	
	//关闭lcd
	uninit_lcd(lcd);
	return 0;
}