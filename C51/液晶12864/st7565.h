#ifndef _ST7565_H
#define _ST7565_H

#include <reg51.h>
#include <intrins.h>

#define CHAR_CODE

#ifndef uchar
#define uchar unsigned char
#endif

#ifndef uint
#define uint unsigned int
#endif

#define DATA_PORT P0
sbit LCD12864_CS=P3^2;
sbit LCD12864_RSET=P3^3;
sbit LCD12864_RS=P2^6;
sbit LCD12864_RW=P2^7;
sbit LCD12864_RD=P2^5;

void Lcd7565_WriteCmd(uchar cmd);
void Lcd7565_WriteData(uchar dat);
void Lcd12864_Init();
void Lcd12864_ClearScreen(void);
uchar Lcd12864_Write16CnCHAR(uchar x,uchar y,uchar *cn);

#endif