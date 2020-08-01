#include"qumo.h"
#include"lcd.h"


//把文字的显示写成一个函数的形式?
//x0,y0:起始位置
void Lcd_draw_word(int x0,int y0,char *word,int w,int h,int color)
{
    int i,index;
	for(index=0;index<(w/8)*h;index++)  //有32个byte
	{
		for(i=7;i>=0;i--)	//每一个byte有8bit
		{
			if(word[index]&(1<<i))
			{
				Lcd_draw_point((index%(w/8))*8+(7-i)+x0,index/(w/8)+y0,color);
			}
		}
	}

}

void draw_word2(int x0,int y0,int w,int h,char word[][8*64],int num,int color)
{
	int i;
	for(i=0;i<num;i++)
	{
		Lcd_draw_word(x0+i*80,y0,word[i],w,h,color);
	}
}