#include "st7565.h"
#include "pic.h"

typedef unsigned int u16;
typedef unsigned char u8;

void Delay10ms(u16 c);
void shuaping();
void showChar();

void main(){
	u8 i,j;
	u16 n;
	Lcd12864_Init();
	Lcd12864_ClearScreen();
	for(i=0;i<8;i++){
		Lcd7565_WriteCmd(0x40);
		Lcd7565_WriteCmd(0xb0+i);
		Lcd7565_WriteCmd(0x10);
		Lcd7565_WriteCmd(0x04);

		for(j=0;j<128;j++){
			Lcd7565_WriteData(pic[n]);
			n=n+1;
		}
	}
	while(1);
}

void Delay10ms(u16 c){
	u8 a,b;
	for(;c>0;c--){
		for(b=38;b>0;b--){
			for(a=130;a>0;a--);
		}
	}
}

void shuaping(){
	uchar i,j;
	Lcd12864_Init();
	Lcd12864_ClearScreen();
	while(1){
		for(i=0;i<8;i++){
			Lcd7565_WriteCmd(0xb0+i);
			Lcd7565_WriteCmd(0x10);
			Lcd7565_WriteCmd(0x04);
			for(j=0;j<128;j++){
				Lcd7565_WriteData(0xff);
				Delay10ms(1);
			}
		}
		for(i=0;i<8;i++){
			Lcd7565_WriteCmd(0xb0+i);
			Lcd7565_WriteCmd(0x10);
			Lcd7565_WriteCmd(0x04);
			for(j=0;j<128;j++){
				Lcd7565_WriteData(0x00);
				Delay10ms(1);
			}
		}
	}
}
void showChar(){
	uchar i;
	Lcd12864_Init();
	Lcd12864_ClearScreen();
	while(1){
		for (i=0; i<8; i += 1)
		{
			Lcd12864_ClearScreen();

			//--由于这个函数显示方向正好相反--//
			Lcd12864_Write16CnCHAR(0, i, "陈金平我爱你！");
			Delay10ms(100);
		}
	}
}