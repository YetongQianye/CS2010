#include<stdio.h>
#include<stdlib.h>

#include"lcd.h"
#include"bmp.h"
char wordNum[11][3*48] = 
{
{
/*--  文字:  0  --*/
/*--  宋体36;  此字体下对应的点阵为：宽x高=24x48   --*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7E,0x00,0x01,0xE7,0x80,0x03,0xC3,
0xC0,0x07,0x81,0xE0,0x0F,0x80,0xF0,0x0F,0x00,0xF0,0x1F,0x00,0xF8,0x1E,0x00,0xF8,
0x3E,0x00,0x78,0x3E,0x00,0x7C,0x3E,0x00,0x7C,0x3E,0x00,0x7C,0x3E,0x00,0x7C,0x3E,
0x00,0x7C,0x3E,0x00,0x7C,0x3E,0x00,0x7C,0x3E,0x00,0x7C,0x3E,0x00,0x7C,0x3E,0x00,
0x7C,0x3E,0x00,0x7C,0x3E,0x00,0x7C,0x3E,0x00,0x7C,0x3E,0x00,0x7C,0x3E,0x00,0x78,
0x1E,0x00,0xF8,0x1F,0x00,0xF8,0x0F,0x00,0xF0,0x0F,0x81,0xF0,0x07,0x81,0xE0,0x03,
0xC3,0xC0,0x01,0xE7,0x80,0x00,0x7E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
},{
/*--  文字:  1  --*/
/*--  宋体36;  此字体下对应的点阵为：宽x高=24x48   --*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0C,0x00,0x00,0x1C,0x00,0x00,0x7C,
0x00,0x07,0xFC,0x00,0x00,0x3C,0x00,0x00,0x3C,0x00,0x00,0x3C,0x00,0x00,0x3C,0x00,
0x00,0x3C,0x00,0x00,0x3C,0x00,0x00,0x3C,0x00,0x00,0x3C,0x00,0x00,0x3C,0x00,0x00,
0x3C,0x00,0x00,0x3C,0x00,0x00,0x3C,0x00,0x00,0x3C,0x00,0x00,0x3C,0x00,0x00,0x3C,
0x00,0x00,0x3C,0x00,0x00,0x3C,0x00,0x00,0x3C,0x00,0x00,0x3C,0x00,0x00,0x3C,0x00,
0x00,0x3C,0x00,0x00,0x3C,0x00,0x00,0x3C,0x00,0x00,0x3C,0x00,0x00,0x3C,0x00,0x00,
0x3E,0x00,0x00,0x7F,0x00,0x07,0xFF,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
},{

/*--  文字:  2  --*/
/*--  宋体36;  此字体下对应的点阵为：宽x高=24x48   --*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0x00,0x03,0xC7,0xC0,0x07,0x01,
0xE0,0x0E,0x00,0xF0,0x1E,0x00,0xF8,0x1E,0x00,0xF8,0x3E,0x00,0x78,0x3E,0x00,0x78,
0x3F,0x00,0x78,0x3F,0x00,0x78,0x1F,0x00,0xF8,0x00,0x00,0xF8,0x00,0x00,0xF0,0x00,
0x01,0xF0,0x00,0x03,0xE0,0x00,0x03,0xC0,0x00,0x07,0x80,0x00,0x0F,0x00,0x00,0x1E,
0x00,0x00,0x3C,0x00,0x00,0x78,0x00,0x00,0xF0,0x00,0x01,0xE0,0x00,0x03,0xC0,0x00,
0x07,0x80,0x1C,0x07,0x00,0x1C,0x0E,0x00,0x38,0x1C,0x00,0x38,0x3C,0x00,0x78,0x3F,
0xFF,0xF8,0x3F,0xFF,0xF8,0x3F,0xFF,0xF8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
},{

/*--  文字:  3  --*/
/*--  宋体36;  此字体下对应的点阵为：宽x高=24x48   --*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFE,0x00,0x07,0x87,0x80,0x0F,0x03,
0xC0,0x1E,0x01,0xE0,0x1E,0x01,0xF0,0x1E,0x01,0xF0,0x1F,0x00,0xF0,0x1F,0x00,0xF0,
0x1E,0x00,0xF0,0x00,0x00,0xF0,0x00,0x01,0xF0,0x00,0x01,0xF0,0x00,0x03,0xE0,0x00,
0x03,0xC0,0x00,0x0F,0x00,0x00,0xFE,0x00,0x00,0x07,0x80,0x00,0x01,0xE0,0x00,0x00,
0xF0,0x00,0x00,0xF8,0x00,0x00,0xF8,0x00,0x00,0x78,0x00,0x00,0x7C,0x1E,0x00,0x7C,
0x3F,0x00,0x7C,0x3F,0x00,0x7C,0x3F,0x00,0x78,0x3E,0x00,0xF8,0x1E,0x00,0xF0,0x0F,
0x01,0xE0,0x07,0x87,0xC0,0x01,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
},{

/*--  文字:  4  --*/
/*--  宋体36;  此字体下对应的点阵为：宽x高=24x48   --*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0xC0,0x00,0x03,0xC0,0x00,0x07,
0xC0,0x00,0x0F,0xC0,0x00,0x0F,0xC0,0x00,0x1F,0xC0,0x00,0x3F,0xC0,0x00,0x3F,0xC0,
0x00,0x77,0xC0,0x00,0x77,0xC0,0x00,0xE7,0xC0,0x01,0xC7,0xC0,0x01,0xC7,0xC0,0x03,
0x87,0xC0,0x07,0x07,0xC0,0x07,0x07,0xC0,0x0E,0x07,0xC0,0x1E,0x07,0xC0,0x1C,0x07,
0xC0,0x38,0x07,0xC0,0x38,0x07,0xC0,0x7F,0xFF,0xFE,0x7F,0xFF,0xFE,0x00,0x07,0xC0,
0x00,0x07,0xC0,0x00,0x07,0xC0,0x00,0x07,0xC0,0x00,0x07,0xC0,0x00,0x07,0xC0,0x00,
0x07,0xC0,0x00,0x07,0xE0,0x00,0x7F,0xFE,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
},{

/*--  文字:  5  --*/
/*--  宋体36;  此字体下对应的点阵为：宽x高=24x48   --*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0xFF,0xF8,0x0F,0xFF,0xF8,0x0F,0xFF,
0xF8,0x0E,0x00,0x00,0x0E,0x00,0x00,0x0E,0x00,0x00,0x0E,0x00,0x00,0x0E,0x00,0x00,
0x0E,0x00,0x00,0x0E,0x00,0x00,0x0E,0x00,0x00,0x0E,0x7F,0x00,0x0D,0xFF,0xC0,0x0F,
0xC3,0xE0,0x1F,0x01,0xF0,0x1E,0x00,0xF8,0x1E,0x00,0xF8,0x00,0x00,0x78,0x00,0x00,
0x7C,0x00,0x00,0x7C,0x00,0x00,0x7C,0x00,0x00,0x7C,0x1E,0x00,0x7C,0x3F,0x00,0x7C,
0x3F,0x00,0x78,0x3F,0x00,0x78,0x3E,0x00,0xF8,0x1E,0x00,0xF0,0x1E,0x01,0xF0,0x0E,
0x01,0xE0,0x07,0x87,0xC0,0x00,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
},{

/*--  文字:  6  --*/
/*--  宋体36;  此字体下对应的点阵为：宽x高=24x48   --*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0xC0,0x00,0xF1,0xE0,0x03,0xC1,
0xF0,0x07,0x81,0xF8,0x07,0x01,0xF8,0x0F,0x00,0xF0,0x1F,0x00,0x00,0x1E,0x00,0x00,
0x1E,0x00,0x00,0x3E,0x00,0x00,0x3E,0x00,0x00,0x3E,0x00,0x00,0x3E,0x3F,0x80,0x3E,
0xFF,0xE0,0x3F,0xE3,0xF0,0x3F,0x80,0xF8,0x3F,0x00,0xF8,0x3F,0x00,0x7C,0x3E,0x00,
0x7C,0x3E,0x00,0x7C,0x3E,0x00,0x3C,0x3E,0x00,0x3C,0x3E,0x00,0x3C,0x3E,0x00,0x3C,
0x3E,0x00,0x7C,0x1E,0x00,0x7C,0x1F,0x00,0x78,0x0F,0x00,0x78,0x0F,0x80,0xF0,0x07,
0xC0,0xE0,0x03,0xE3,0xC0,0x00,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
},{

/*--  文字:  7  --*/
/*--  宋体36;  此字体下对应的点阵为：宽x高=24x48   --*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1F,0xFF,0xFC,0x1F,0xFF,0xFC,0x1F,0xFF,
0xF8,0x1F,0x00,0x38,0x1C,0x00,0x70,0x1C,0x00,0xE0,0x38,0x00,0xE0,0x38,0x01,0xC0,
0x00,0x01,0xC0,0x00,0x03,0x80,0x00,0x03,0x80,0x00,0x07,0x80,0x00,0x07,0x00,0x00,
0x0F,0x00,0x00,0x0E,0x00,0x00,0x1E,0x00,0x00,0x1E,0x00,0x00,0x3C,0x00,0x00,0x3C,
0x00,0x00,0x3C,0x00,0x00,0x7C,0x00,0x00,0x78,0x00,0x00,0x78,0x00,0x00,0xF8,0x00,
0x00,0xF8,0x00,0x00,0xF8,0x00,0x00,0xF8,0x00,0x00,0xF8,0x00,0x00,0xF8,0x00,0x00,
0xF8,0x00,0x00,0xF8,0x00,0x00,0x78,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
},{

/*--  文字:  8  --*/
/*--  宋体36;  此字体下对应的点阵为：宽x高=24x48   --*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0x00,0x07,0xC3,0xC0,0x0F,0x00,
0xE0,0x1E,0x00,0xF0,0x1E,0x00,0x78,0x3C,0x00,0x78,0x3C,0x00,0x78,0x3C,0x00,0x7C,
0x3E,0x00,0x78,0x3E,0x00,0x78,0x1F,0x00,0x78,0x1F,0x80,0xF0,0x0F,0xE1,0xE0,0x07,
0xFB,0xC0,0x01,0xFF,0x80,0x01,0xFF,0x80,0x07,0xBF,0xC0,0x0F,0x0F,0xE0,0x1E,0x03,
0xF0,0x3E,0x01,0xF8,0x3C,0x00,0xF8,0x3C,0x00,0x7C,0x7C,0x00,0x7C,0x78,0x00,0x3C,
0x78,0x00,0x3C,0x7C,0x00,0x3C,0x3C,0x00,0x78,0x3C,0x00,0x78,0x1E,0x00,0x70,0x0F,
0x00,0xE0,0x07,0xC3,0xC0,0x01,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
},{

/*--  文字:  9  --*/
/*--  宋体36;  此字体下对应的点阵为：宽x高=24x48   --*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0xFE,0x00,0x07,0xC7,0x80,0x0F,0x01,
0xE0,0x1E,0x01,0xE0,0x1E,0x00,0xF0,0x3E,0x00,0xF8,0x3C,0x00,0x78,0x3C,0x00,0x78,
0x7C,0x00,0x7C,0x7C,0x00,0x7C,0x7C,0x00,0x7C,0x7C,0x00,0x7C,0x7C,0x00,0x7C,0x3C,
0x00,0xFC,0x3E,0x00,0xFC,0x3E,0x01,0xFC,0x1F,0x03,0xFC,0x1F,0x8F,0xFC,0x0F,0xFF,
0x7C,0x03,0xFC,0x7C,0x00,0x00,0x7C,0x00,0x00,0xF8,0x00,0x00,0xF8,0x00,0x00,0xF8,
0x00,0x00,0xF0,0x00,0x01,0xF0,0x0F,0x01,0xE0,0x1F,0x01,0xE0,0x1F,0x03,0xC0,0x1F,
0x07,0x80,0x0F,0x9F,0x00,0x03,0xFC,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
},{
/*--  文字:  :  --*/
/*--  宋体36;  此字体下对应的点阵为：宽x高=24x48   --*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7C,0x00,0x00,0xFE,0x00,0x00,0xFE,0x00,0x00,
0xFE,0x00,0x00,0x7C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7C,0x00,0x00,
0xFE,0x00,0x00,0xFE,0x00,0x00,0xFE,0x00,0x00,0x7C,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
}
};

char wordNum1[2][6*48] = 
{
{
/*--  文字:  星  --*/
/*--  宋体36;  此字体下对应的点阵为：宽x高=48x48   --*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x30,0x00,0x00,0x1C,0x00,0x00,0x3F,0xFF,0xFF,0xFE,0x00,0x00,0x3F,
0xFF,0xFF,0xFF,0x00,0x00,0x3C,0x00,0x00,0x3E,0x00,0x00,0x3C,0x00,0x00,0x3C,0x00,
0x00,0x3C,0x00,0x00,0x3C,0x00,0x00,0x3C,0x00,0x00,0x3C,0x00,0x00,0x3F,0xFF,0xFF,
0xFC,0x00,0x00,0x3F,0xFF,0xFF,0xFC,0x00,0x00,0x3C,0x00,0x00,0x3C,0x00,0x00,0x3C,
0x00,0x00,0x3C,0x00,0x00,0x3C,0x00,0x00,0x3C,0x00,0x00,0x3C,0x00,0x00,0x3E,0x00,
0x00,0x3C,0x00,0x00,0x3E,0x00,0x00,0x3F,0xFF,0xFF,0xFE,0x00,0x00,0x3F,0xFF,0xFF,
0xFE,0x00,0x00,0x3C,0x03,0x00,0x3E,0x00,0x00,0x38,0x03,0xC0,0x3C,0x00,0x00,0x1C,
0x03,0xF0,0x00,0x00,0x00,0x3F,0x03,0xC0,0x00,0x00,0x00,0x3E,0x03,0xC0,0x0E,0x00,
0x00,0x3C,0x03,0xC0,0x1F,0x00,0x00,0x7F,0xFF,0xFF,0xFF,0x80,0x00,0x7F,0xFF,0xFF,
0xFF,0xC0,0x00,0xF0,0x03,0xC0,0x00,0x00,0x00,0xF0,0x03,0xC0,0x00,0x00,0x01,0xE0,
0x03,0xC0,0x00,0x00,0x01,0xC0,0x03,0xC0,0x00,0x00,0x03,0xC0,0x03,0xC0,0x30,0x00,
0x07,0x80,0x03,0xC0,0x78,0x00,0x0F,0x3F,0xFF,0xFF,0xFC,0x00,0x0E,0x3F,0xFF,0xFF,
0xFE,0x00,0x1C,0x18,0x03,0xC0,0x00,0x00,0x00,0x00,0x03,0xC0,0x00,0x00,0x00,0x00,
0x03,0xC0,0x00,0x00,0x00,0x00,0x03,0xC0,0x00,0x00,0x00,0x00,0x03,0xC0,0x00,0xE0,
0x00,0x00,0x03,0xC0,0x01,0xF0,0x3F,0xFF,0xFF,0xFF,0xFF,0xF8,0x3F,0xFF,0xFF,0xFF,
0xFF,0xFC,0x1E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
},
{
/*--  文字:  期  --*/
/*--  宋体36;  此字体下对应的点阵为：宽x高=48x48   --*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0x18,0x00,
0x00,0x00,0x00,0xF8,0x1E,0x00,0x00,0x00,0x00,0xFC,0x1F,0x0C,0x00,0x60,0x00,0xF8,
0x1E,0x0F,0xFF,0xF8,0x00,0xF8,0x1E,0x0F,0xFF,0xF8,0x00,0xF8,0x1E,0x0F,0x00,0xF0,
0x00,0xF8,0x1F,0xCF,0x00,0xF0,0x1F,0xFF,0xFF,0xEF,0x00,0xF0,0x1F,0xFF,0xFF,0xFF,
0x00,0xF0,0x0E,0xF8,0x1E,0x0F,0x00,0xF0,0x00,0xF8,0x1E,0x0F,0x00,0xF0,0x00,0xF8,
0x1E,0x0F,0x00,0xF0,0x00,0xF8,0x1E,0x0F,0x00,0xF0,0x00,0xFF,0xFE,0x0F,0xFF,0xF0,
0x00,0xFF,0xFE,0x0F,0xFF,0xF0,0x00,0xF8,0x1E,0x0F,0x00,0xF0,0x00,0xF8,0x1E,0x0F,
0x00,0xF0,0x00,0xF8,0x1E,0x0F,0x00,0xF0,0x00,0xF8,0x1E,0x0F,0x00,0xF0,0x00,0xF8,
0x1E,0x0F,0x00,0xF0,0x00,0xFF,0xFE,0x0F,0x00,0xF0,0x00,0xFF,0xFE,0x0F,0x00,0xF0,
0x00,0xF8,0x1E,0x0F,0x00,0xF0,0x00,0xF8,0x1E,0x0F,0x00,0xF0,0x00,0xF8,0x1E,0x0F,
0xFF,0xF0,0x00,0xF8,0x1E,0x0F,0xFF,0xF0,0x00,0xF8,0x1F,0xCF,0x00,0xF0,0x1F,0xFF,
0xFF,0xEF,0x00,0xF0,0x1F,0xFF,0xFF,0xFF,0x00,0xF0,0x0E,0x00,0x00,0x0F,0x00,0xF0,
0x00,0x18,0x60,0x1F,0x00,0xF0,0x00,0x3C,0x78,0x1E,0x00,0xF0,0x00,0x3E,0x3C,0x1E,
0x00,0xF0,0x00,0x7C,0x1E,0x3E,0x00,0xF0,0x00,0xF8,0x1F,0x3C,0x00,0xF0,0x00,0xF0,
0x0F,0xBC,0x00,0xF0,0x01,0xE0,0x0F,0x78,0x00,0xF0,0x03,0xC0,0x07,0xF0,0x00,0xF0,
0x07,0x80,0x06,0xF0,0x00,0xF0,0x0F,0x00,0x01,0xE0,0x7F,0xF0,0x1E,0x00,0x03,0xC0,
0x1F,0xF0,0x3C,0x00,0x07,0x80,0x07,0xE0,0x30,0x00,0x0E,0x00,0x03,0xC0,0x00,0x00,
0x1C,0x00,0x01,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
},
};

char wordNum2[3][4*33] = 
{
{
/*--  文字:  年  --*/
/*--  宋体24;  此字体下对应的点阵为：宽x高=32x33   --*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0x00,0x00,0x00,0xF0,0x00,0x00,
0x01,0xE0,0x00,0x00,0x01,0xE0,0x00,0x30,0x01,0xC0,0x00,0x78,0x03,0xFF,0xFF,0xFC,
0x07,0x81,0xE0,0x00,0x07,0x01,0xE0,0x00,0x0E,0x01,0xE0,0x00,0x1C,0x01,0xE0,0x00,
0x1C,0x01,0xE0,0xC0,0x3B,0x81,0xE1,0xE0,0x63,0xFF,0xFF,0xF0,0x03,0xC1,0xE0,0x00,
0x03,0xC1,0xE0,0x00,0x03,0xC1,0xE0,0x00,0x03,0xC1,0xE0,0x00,0x03,0xC1,0xE0,0x18,
0x03,0xC1,0xE0,0x3C,0x7F,0xFF,0xFF,0xFE,0x30,0x01,0xE0,0x00,0x00,0x01,0xE0,0x00,
0x00,0x01,0xE0,0x00,0x00,0x01,0xE0,0x00,0x00,0x01,0xE0,0x00,0x00,0x01,0xE0,0x00,
0x00,0x01,0xE0,0x00,0x00,0x01,0xE0,0x00,0x00,0x01,0xE0,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00
},
{
/*--  文字:  月  --*/
/*--  宋体24;  此字体下对应的点阵为：宽x高=32x33   --*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x03,0x80,
0x00,0xFF,0xFF,0xC0,0x00,0xE0,0x03,0x80,0x00,0xE0,0x03,0x80,0x00,0xE0,0x03,0x80,
0x00,0xE0,0x03,0x80,0x00,0xE0,0x03,0x80,0x00,0xE0,0x03,0x80,0x00,0xFF,0xFF,0x80,
0x00,0xE0,0x03,0x80,0x00,0xE0,0x03,0x80,0x00,0xE0,0x03,0x80,0x00,0xE0,0x03,0x80,
0x00,0xE0,0x03,0x80,0x00,0xE0,0x03,0x80,0x00,0xFF,0xFF,0x80,0x00,0xE0,0x03,0x80,
0x00,0xE0,0x03,0x80,0x01,0xE0,0x03,0x80,0x01,0xE0,0x03,0x80,0x01,0xC0,0x03,0x80,
0x03,0xC0,0x03,0x80,0x03,0x80,0x03,0x80,0x07,0x00,0x03,0x80,0x07,0x00,0xFF,0x80,
0x0E,0x00,0x7F,0x80,0x3C,0x00,0x0F,0x00,0x70,0x00,0x0E,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00
},
{
/*--  文字:  日  --*/
/*--  宋体24;  此字体下对应的点阵为：宽x高=32x33   --*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x80,0x01,0xC0,
0x03,0xFF,0xFF,0xE0,0x03,0x80,0x01,0xC0,0x03,0x80,0x01,0xC0,0x03,0x80,0x01,0xC0,
0x03,0x80,0x01,0xC0,0x03,0x80,0x01,0xC0,0x03,0x80,0x01,0xC0,0x03,0x80,0x01,0xC0,
0x03,0x80,0x01,0xC0,0x03,0x80,0x01,0xC0,0x03,0xFF,0xFF,0xC0,0x03,0x80,0x01,0xC0,
0x03,0x80,0x01,0xC0,0x03,0x80,0x01,0xC0,0x03,0x80,0x01,0xC0,0x03,0x80,0x01,0xC0,
0x03,0x80,0x01,0xC0,0x03,0x80,0x01,0xC0,0x03,0x80,0x01,0xC0,0x03,0x80,0x01,0xC0,
0x03,0x80,0x01,0xC0,0x03,0x80,0x01,0xC0,0x03,0xFF,0xFF,0xC0,0x03,0x80,0x01,0xC0,
0x03,0x80,0x01,0xC0,0x03,0x80,0x01,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00
}
};


//把文字的显示写成一个函数的形式?
//x0,y0:起始位置
//w*h:文字的大小
void Lcd_draw_word(int x0,int y0,char *word,int w,int h,int color)
{
	int i,index;
	for(index=0;index<(w/8)*h;index++)  //有w*h/8个byte
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

//能不能写一个函数,在指定的位置显示一个六位数以内的数字呢？
void Lcd_draw_num1(int x0,int y0,int num,int color)
{
	if(num == -1)
	{
		Lcd_draw_word(x0,y0,wordNum[10],24,48,color);
		return;
	}
	int a,b;
	a = num/10;
	b = num%10;
	if(a!=0)
	{
		Lcd_draw_word(x0,y0,wordNum[a],24,48,color);
		Lcd_draw_word(x0+24,y0,wordNum[b],24,48,color);	
	}else
	{
		Lcd_draw_word(x0,y0,wordNum[b],24,48,color);	
	}
	
	 
#if 0
	if(a != 0)
	{
		Lcd_draw_word(x0,y0,wordNum[a],24,48,color);
		Lcd_draw_word(x0+24,y0,wordNum[b],24,48,color);
		Lcd_draw_word(x0+60,y0,wordNum[c],24,48,color);
		Lcd_draw_word(x0+84,y0,wordNum[d],24,48,color);	
		Lcd_draw_word(x0+120,y0,wordNum[e],24,48,color);	
		Lcd_draw_word(x0+124,y0,wordNum[f],24,48,color);	
	}else if(b!=0)
	{
		Lcd_draw_word(x0,y0,wordNum[b],24,48,color);
		Lcd_draw_word(x0+36,y0,wordNum[c],24,48,color);
		Lcd_draw_word(x0+60,y0,wordNum[d],24,48,color);	
		Lcd_draw_word(x0+96,y0,wordNum[e],24,48,color);	
		Lcd_draw_word(x0+120,y0,wordNum[f],24,48,color);	
	}else if(c!=0)
	{
		Lcd_draw_word(x0,y0,wordNum[c],24,48,color);
		Lcd_draw_word(x0+24,y0,wordNum[d],24,48,color);	
		Lcd_draw_word(x0+60,y0,wordNum[e],24,48,color);	
		Lcd_draw_word(x0+84,y0,wordNum[f],24,48,color);	
	}else if(d!=0)
	{
		Lcd_draw_word(x0,y0,wordNum[d],24,48,color);
		Lcd_draw_word(x0+36,y0,wordNum[e],24,48,color);	
		Lcd_draw_word(x0+50,y0,wordNum[f],24,48,color);	 
	}else if(e!=0)
	{
		Lcd_draw_word(x0,y0,wordNum[e],24,48,color);
		Lcd_draw_word(x0+24,y0,wordNum[f],24,48,color);	
	}else
	{
		Lcd_draw_word(x0,y0,wordNum[f],24,48,color);	
	}
#endif	
	
}

void Lcd_draw_num2(int x0,int y0,int num,int color)
{
	if(num == -1)
	{
		Lcd_draw_word(x0,y0,wordNum[10],24,48,color);
		return;
	}
	int a,b,c,d;
	a = num/1000;  //1
	b = (num%1000)/100;
	c = (num%100)/10;
	d = num%10;
	if(a!=0)
	{
		Lcd_draw_word(x0,y0,wordNum[a],24,48,color);
		Lcd_draw_word(x0+24,y0,wordNum[b],24,48,color);	
		Lcd_draw_word(x0+60,y0,wordNum[c],24,48,color);	
		Lcd_draw_word(x0+84,y0,wordNum[d],24,48,color);	
	}else if(b!=0)
	{
		Lcd_draw_word(x0,y0,wordNum[b],24,48,color);
		Lcd_draw_word(x0+36,y0,wordNum[c],24,48,color);	
		Lcd_draw_word(x0+50,y0,wordNum[d],24,48,color);	 
	}else if(c!=0)
	{
		Lcd_draw_word(x0,y0,wordNum[c],24,48,color);
		Lcd_draw_word(x0+24,y0,wordNum[d],24,48,color);	
	}else
	{
		Lcd_draw_word(x0,y0,wordNum[d],24,48,color);	
	}

}

int main(int argc,char *argv[])
{

	//初始化屏幕
	struct lcd_info *lcd = init_lcd();
	//操作屏幕
	Lcd_clear(0x00ffffff);

	lcd_draw_bmp(0,0,argv[1]);

	/* int i;
	for(i=0;i<=999999;i++)
	{
		Lcd_draw_num(200,200,i,0x00ff0000);
		sleep(1);
		Lcd_draw_rect(200,200,6*24,48,0x00ffffff);
	} */
	//星期
	Lcd_draw_word(600,90,wordNum1[0],48,48,0x00fe30bd);
	Lcd_draw_word(650,90,wordNum1[1],48,48,0x00fe30bd);
	Lcd_draw_word(700,90,wordNum[2],24,48,0x00fe30bd);
	//年月日
	Lcd_draw_word(560,30,wordNum2[0],32,33,0x00fe30bd);
	Lcd_draw_word(650,30,wordNum2[1],32,33,0x00fe30bd);
	Lcd_draw_word(750,30,wordNum2[2],32,33,0x00fe30bd);
#if 0	 
	int sec = 0,min = 0,hour = 0;
	for(sec=0;sec<=60;sec++)
	{

		Lcd_draw_rect(600,100,2*24,48,0x00ffffff);
		Lcd_draw_num1(600,100,-1,0x00ff0000);

		Lcd_draw_rect(690,100,2*24,48,0x00ffffff);
		Lcd_draw_num1(690,100,-1,0x00ff0000);		

		Lcd_draw_rect(730,100,2*24,48,0x00ffffff);
		Lcd_draw_num1(730,100,sec,0x00ff0000);		
		
		Lcd_draw_rect(640,100,2*24,48,0x00ffffff);
		Lcd_draw_num1(640,100,min,0x00ff0000);	
		 
	 	Lcd_draw_rect(550,100,2*24,48,0x00ffffff);
		Lcd_draw_num1(550,100,hour,0x00ff0000);		 
	 
		sleep(0.5);
		if(sec==59)
		{			
			sec = 0;
			min++;
		 
			if(min==59)
			{
				min = 0;
				hour++;
			}
			if(hour==23)
			{
				hour= 0;
			}
		}		
	}
#endif		
		
	int sec = 0,min = 0,hour = 0;
	int year = 2020,month = 8, day = 4;
	for(sec=0;sec<=60;sec++)
	{

		Lcd_draw_rect(600,180,2*24,48,0x00125D7F);
		Lcd_draw_num1(600,180,-1,0x00ff0000);

		Lcd_draw_rect(690,180,2*24,48,0x00125D7F);
		Lcd_draw_num1(690,180,-1,0x00ff0000);		

		Lcd_draw_rect(730,180,2*24,48,0x00125D7F);
		Lcd_draw_num1(730,180,sec,0x00ff0000);		
		
		Lcd_draw_rect(640,180,2*24,48,0x00125D7F);
		Lcd_draw_num1(640,180,min,0x00ff0000);	
		 
	 	Lcd_draw_rect(550,180,2*24,48,0x00125D7F);
		Lcd_draw_num1(550,180,hour,0x00ff0000);		

		//年月日
		Lcd_draw_rect(700,20,2*24,48,0x00125D7F);
		Lcd_draw_num1(700,20,day,0x00ff0000);		
		
		Lcd_draw_rect(600,20,2*24,48,0x00125D7F);
		Lcd_draw_num1(600,20,month,0x00ff0000);	
		 
	 	Lcd_draw_rect(450,20,4*24,48,0x00125D7F);
		Lcd_draw_num2(450,20,year,0x00ff0000);		  
	 
		sleep(1);
		if(sec==59)
		{			
			sec = 0;
			min++;
		 
			if(min==59)
			{
				min = 0;
				hour++;
			}
			if(hour==23)
			{
				hour= 0;
				day++;
			}
			if(day==30)
			{
				day = 1;
				month++;
			}
			if(month==12)
			{
				month = 1;
				year++;
			}


		}		
	}
	
	 
	/* 	Lcd_draw_num(300,200,sec,0x00ff0000);
		Lcd_draw_rect(300,200,2*24,48,0x00ffffff);

		Lcd_draw_num(250,200,min,0x00ff0000);
		Lcd_draw_rect(250,200,2*24,48,0x00ffffff);

		Lcd_draw_num(150,200,hour,0x00ff0000);
		Lcd_draw_rect(150,200,2*24,48,0x00ffffff); */
	

	//关闭屏幕
	close_lcd();
	return 0;
}



