//写一个程序,能够扫描一个指定目录中的所有图片文件,并且能够手动滑动显示
#include<stdio.h>
#include"LinkList.h" //在当前路径下查找 
#include "lcd.h"
int main( )
{
	//初始化LCD
    struct lcd_info *init_lcd();	
    //测试BMP显示是否成功

    //测试jpg显示是否成功
    //创建一个链表
	struct node *list = create_linklist();
    //搜索目录图片文件

    //测试是否成功
	
	return 0;
}



