#include"lcd.h"
#include"dir.h"
#include"LinkedList.h"
#include"jpeg.h"
#include"touch.h"

//#define DEBUG

void auto_play(LinkedList *LPIC,struct node *p)
{
	printf("-------auto play ---------\n");
	enum drec DEC;
	while(1)
	{	
		DEC = get_touch();
		if(DEC == UP)
		{
			break;
		}
		p = p->next;
		if(p==NULL)
		{
			p = LPIC->first;
		}
		//判断一个文件是否为BMP图片
		//如果是 返回 1，否则 返回0
		if(isBMP(p->data))
		{
			printf("bmp  %s\n",p->data);
			lcd_draw_bmp(0,0,p->data);
		}
		//判断一个文件是否为JPG图片
		//如果是 返回 1，否则 返回0
		if(isJPG(p->data))
		{
			printf("jpg  %s\n",p->data);
			lcd_draw_jpg(0,0,p->data);
		}	
		sleep(1);
	}
}

int main(int argc,char *argv[])
{
	//初始化屏幕
	lcd_init();
	//清屏
	lcd_clear(0x0000ff00);
	//lcd_draw_bmp(50,50,"1.bmp");
	//创建链表且找到指定目录中所有图片保存到链表中
	LinkedList* LPIC = create_linklist();
	LPIC = fun_dir_bmp("/home/hmw/pic",LPIC);
	
	struct node *p = LPIC->first;
	if(p == NULL) //整个目录都没有图片文件
	{
		printf("dir no pic\n");
		//关闭
		lcd_uninit();
		return -1;
	}
	enum drec DEC;
	
	//显示一张起始图片(链表的第一张图片)
	if(isBMP(p->data))
	{
		lcd_draw_bmp(0,0,p->data);
	}
	//判断一个文件是否为JPG图片
	//如果是 返回 1，否则 返回0
	if(isJPG(p->data))
	{
		lcd_draw_jpg(0,0,p->data);
	}

	
	while(1)
	{
#ifdef DEBUG		
		printf("%s\n",p->data);
#endif
		DEC = get_touch();
		if(DEC == NOT) //没有触摸，不作处理
		{
			continue;
		}
		else if(DEC == LEFT)
		{
			//显示上一张
			p = find_pre(LPIC,p);
			
		}else if(DEC == RIGHT)
		{
			//显示上一张
			p = p->next;
			if(p==NULL)
			{
				p = LPIC->first;
			}
		}else if(DEC == DOWN)
		{
			//进入自动播放
			auto_play(LPIC,p);
		}
		printf("-------shou dong play ---------\n");
		//判断一个文件是否为BMP图片
		//如果是 返回 1，否则 返回0
		if(isBMP(p->data))
		{
			printf("bmp  %s\n",p->data);
			lcd_draw_bmp(0,0,p->data);
		}
		//判断一个文件是否为JPG图片
		//如果是 返回 1，否则 返回0
		if(isJPG(p->data))
		{
			printf("jpg  %s\n",p->data);
			lcd_draw_jpg(0,0,p->data);
		}	
	}
	
	print_list(LPIC);
	delete_listwithhead(LPIC);
	
	//关闭
	lcd_uninit();
	
	return 0;
}