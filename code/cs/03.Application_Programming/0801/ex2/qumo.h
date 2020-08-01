#ifndef __QUMO_H__
#define __QUMO_H__

void Lcd_draw_word(int x0,int y0,char *word,int w,int h,int color);
void draw_word2(int x0,int y0,int w,int h,char word[][8*64],int num,int color);
#endif