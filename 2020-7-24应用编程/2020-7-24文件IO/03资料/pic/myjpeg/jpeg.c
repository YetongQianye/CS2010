#include"jpeg.h"

/*
在指定的位置显示一张指定的JPG图片
picname:JPG文件的路径名
x0:指定位置的横坐标
y0:指定位置的纵坐标
*/
void lcd_draw_jpg(int x0,int y0,char *picname)
{
	/*
	step 1: 分配并初始化一个jpeg解压对象
	*/
	struct jpeg_decompress_struct dinfo; //声明一个解压的对象
	
	struct jpeg_error_mgr jerr; //声明一个出错信息的对象
	
	dinfo.err = jpeg_std_error(&jerr); //初始化这个出错对象
	
	jpeg_create_decompress(&dinfo); //初始化dinfo这个解压对象


	/*
	step 2: 指定要解压缩的图像文件(jpeg)
	*/
	FILE *fp = fopen(picname, "r");
	if (fp == NULL)
	{
		//
		perror("fopen error:");
		return ;
	}

	jpeg_stdio_src(&dinfo, fp);


	/*
	3.	调用jpeg_read_header()获取图像信息
	jpeg_read_header(&dinfo, TRUE);

	*/
	
	jpeg_read_header(&dinfo, TRUE);	

	/*
	4.	用于设置jpeg解压对象dinfo的一些参数。可采用默认参数
	
	*/


	/*
	5. 调用jpeg_start_decompress()启动解压过程
		jpeg_start_decompress(&dinfo);
		
	调用jpeg_start_decompress函数之后，JPEG解压对象dinfo中
	下面这几个字段(成员变量)将会比较有用：
		dinfo.output_width: 	图像输出宽度，一行占多少个像素点
		dinfo.output_height:	图像输出高度，占多少行
		dinfo.output_components:  每个像素点的分量数，每个像素点占多少个字节
								3： R G B
								4：A R G B
				width * height * components

				
		在调用jpeg_start_decompress之后，往往需要为解压后的扫描线上的
		所有像素点分配存储空间： 
			存一行： output_width * output_components

	*/
	jpeg_start_decompress(&dinfo);

	/*
	6. 读取一行或者多行扫描线上数据并处理，通常的代码是这样子的:
	*/
	//分配存储一行数据的空间
	unsigned char *buffer = malloc(dinfo.output_width * dinfo.output_components);

	//dinfo.output_scanline , 表示的意思是，已经扫描了多少行

	int x , y = 0;
	while (dinfo.output_scanline < dinfo.output_height)
	{
		y = dinfo.output_scanline ; //将要扫描第y行;
		
		jpeg_read_scanlines(&dinfo,  //解压对象
							&buffer,//保存解压后数据的二级指针, 
								//此处为什么要用两级指针??
								//你懂的
							1//读取多少行数据来解压
							);	
							//dinfo.output_scanline + 1

							//每个像素点在处理后: (A) R  G B
		/* do something yourself */
		unsigned char *p = buffer;

		unsigned char a, r, g, b;
		int color;
		for (x = 0; x < dinfo.output_width; x++)
		{
			if (dinfo.output_components == 3)
			{
				a = 0;
			}
			else
			{
				a = *p++;
			}
			r = *p++;
			g = *p++;
			b = *p++;

			color = (a<<24) | (r << 16) | (g << 8) | b;

			if (y+y0 < 480 && x +x0<800)
			{
				lcd_draw_point(x+x0,y+y0,color);
			}
			
		}
	}

	/*

	7. 调用jpeg_finish_decompress()完成解压过程
	*/
	jpeg_finish_decompress(&dinfo);
	/*

	8. 调用jpeg_destroy_decompress释放jpeg解压对象dinfo
	*/
	jpeg_destroy_decompress(&dinfo);

	free(buffer);
}

