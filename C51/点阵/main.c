#include "reg51.h"
#include "intrins.h"
#include "string.h"

typedef unsigned char u8;
typedef unsigned int u16;

sbit SRCLK=P3^6;
sbit RCLK=P3^5;
sbit SER=P3^4;

void delay(u16 i);
void Hc595SendByte(u8 dat1,u8 dat2,u8 dat3,u8 dat4);
void showOneWord(u8 w[]);
u8* moveLeft(u8 word[],u8 num);


u8 code ledduan[]={
				
	/*--  文字:  陈  --*/
	/*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
	0x00,0xFE,0x22,0x5A,0x86,0x08,0x88,0x68,0x18,0x0F,0xE8,0x08,0x08,0x08,0x08,0x00,
	0x00,0xFF,0x04,0x08,0x07,0x20,0x11,0x0D,0x41,0x81,0x7F,0x01,0x05,0x09,0x30,0x00,
	
	/*--  文字:  金  --*/
	/*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
	0x80,0x80,0x40,0x20,0x50,0x48,0x44,0xC3,0x44,0x48,0x50,0x20,0x40,0x80,0x80,0x00,
	0x40,0x40,0x42,0x4A,0x72,0x42,0x42,0x7F,0x42,0x42,0x62,0x5A,0x42,0x40,0x40,0x00,
	
	/*--  文字:  平  --*/
	/*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
	0x00,0x02,0x02,0x12,0x62,0x02,0x02,0xFE,0x02,0x02,0x42,0x32,0x02,0x02,0x00,0x00,
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0xFF,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x00,
	
	/*--  文字:  我  --*/
	/*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
	0x20,0x24,0x24,0x24,0xFE,0x23,0x22,0x20,0x20,0xFF,0x20,0x22,0x2C,0xA0,0x20,0x00,
	0x00,0x08,0x48,0x84,0x7F,0x02,0x41,0x40,0x20,0x13,0x0C,0x14,0x22,0x41,0xF8,0x00,
	
	/*--  文字:  爱  --*/
	/*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
	0x80,0x64,0x2C,0x34,0x24,0x24,0xEC,0x32,0x22,0x22,0x32,0x2E,0x23,0xA2,0x60,0x00,
	0x00,0x41,0x21,0x91,0x89,0x87,0x4D,0x55,0x25,0x25,0x55,0x4D,0x81,0x80,0x80,0x00,
	
	/*--  文字:  你  --*/
	/*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
	0x00,0x80,0x60,0xF8,0x07,0x40,0x20,0x18,0x0F,0x08,0xC8,0x08,0x08,0x28,0x18,0x00,
	0x01,0x00,0x00,0xFF,0x00,0x10,0x0C,0x03,0x40,0x80,0x7F,0x00,0x01,0x06,0x18,0x00,
	
	
	/*--  调入了一幅图像：C:\Users\Thinkpad\Desktop\timg (1).bmp  --*/
	/*--  宽度x高度=16x16  --*/
	0x00,0x40,0x00,0x00,0x00,0x80,0x80,0x80,0x80,0xC0,0xC0,0xC0,0xC0,0xE0,0x30,0x20,
	0x03,0x03,0x01,0x01,0x07,0x0D,0x18,0x1F,0x3F,0x3F,0x7F,0x3F,0x0F,0x07,0x00,0x00,
	/*--  调入了一幅图像：C:\Users\Thinkpad\Desktop\timg.bmp  --*/
	/*--  宽度x高度=16x16  --*/
	0x00,0xF8,0xFC,0xFC,0xFC,0xFC,0xFC,0xFC,0xFE,0xFF,0xFF,0xFE,0xFE,0x7C,0x00,0x00,
	0x00,0x60,0xE1,0xE3,0xE3,0xE7,0xEF,0xEF,0xFF,0xFF,0xEF,0xE7,0xE1,0xE0,0xE0,0x40,
	/*--  调入了一幅图像：C:\Users\Thinkpad\Desktop\timg (1).bmp  --*/
	/*--  宽度x高度=16x16  --*/
	0x00,0x00,0xE0,0x20,0x60,0x7F,0x7F,0x7F,0x7F,0x7F,0x62,0x60,0x20,0xE0,0x00,0x00,
	0xC0,0xE0,0xA6,0xFE,0x7C,0xFE,0xFF,0xFE,0xFE,0xFC,0xFF,0xFE,0x7C,0x47,0x80,0xC0
	

};
u8 code ledwei[]={
	0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80
};
void main(){
	u8 word[32];
	u16 i=0;
	u8 len=sizeof(ledduan)/sizeof(u8)/2;
	while(1){
		i%=len;
		showOneWord(moveLeft(word,i++));
		delay(3000);
	}	
}
u8* moveLeft(u8 word[],u8 num){
	u8 seq,m,n,i;
	u8 len=sizeof(ledduan)/sizeof(u8)/2;
	num=num%len;
	seq=num/16;
	m=seq*16+num;
	n=m+16;
	i=16-(num%16);
	memcpy(word,ledduan+m,i);
	memcpy(word+16,ledduan+n,i);
	if(num+16<=len){
		memcpy(word+i,ledduan+16+m+i,16-i);
		memcpy(word+16+i,ledduan+16+n+i,16-i);
	}else{
		memcpy(word+i,ledduan,16-i);
		memcpy(word+16+i,ledduan+16,16-i);		
	}
	
	return word;	
}
void showOneWord(u8 w[]){
	u8 i;
	for(i=0;i<16;i++){
		Hc595SendByte(~ledwei[i+16],~ledwei[i],w[i+16],w[i]);	
	}
}
void delay(u16 i){
	while(i--);
}

void Hc595SendByte(u8 dat1,u8 dat2,u8 dat3,u8 dat4){
	u8 a;
	SRCLK=1;
	RCLK=1;

	for(a=0;a<8;a++){
		SER=dat1>>7;
		dat1<<=1;
		SRCLK=0;
		_nop_();
		_nop_();
		SRCLK=1;
	}
	for(a=0;a<8;a++){
		SER=dat2>>7;
		dat2<<=1;
		SRCLK=0;
		_nop_();
		_nop_();
		SRCLK=1;
	}
	for(a=0;a<8;a++){
		SER=dat3>>7;
		dat3<<=1;
		SRCLK=0;
		_nop_();
		_nop_();
		SRCLK=1;
	}
	for(a=0;a<8;a++){
		SER=dat4>>7;
		dat4<<=1;
		SRCLK=0;
		_nop_();
		_nop_();
		SRCLK=1;
	}

	RCLK=0;
	_nop_();
	_nop_();
	RCLK=1;
}

