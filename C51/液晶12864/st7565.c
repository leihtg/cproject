#include "st7565.h"

void Lcd7565_WriteCmd(uchar cmd){
	LCD12864_CS=0;
	LCD12864_RD=1;
	LCD12864_RS=0;
	LCD12864_RW=0;
	_nop_();
	_nop_();

	DATA_PORT=cmd;
	_nop_();
	_nop_();
	LCD12864_RW=1;
}

void Lcd7565_WriteData(uchar dat){
	LCD12864_CS=0;
	LCD12864_RD=1;
	LCD12864_RS=1;
	LCD12864_RW=0;
	_nop_();
	_nop_();

	DATA_PORT=dat;
	_nop_();
	_nop_();

	LCD12864_RW=1;
}

void Lcd12864_Init(){
	uchar i;
	LCD12864_RSET=0;
	for(i=0;i<100;i++);
	LCD12864_CS=0;
	LCD12864_RSET=1;

	Lcd7565_WriteCmd(0xE2);
	for(i=0;i<100;i++);
	
	Lcd7565_WriteCmd(0xa1);
	Lcd7565_WriteCmd(0xc8);
	Lcd7565_WriteCmd(0xa6);
	Lcd7565_WriteCmd(0xa4);
	Lcd7565_WriteCmd(0xa2);
	Lcd7565_WriteCmd(0xf8);
	Lcd7565_WriteCmd(0x01);
	Lcd7565_WriteCmd(0x81);
	Lcd7565_WriteCmd(0x23);
	Lcd7565_WriteCmd(0x25);
	Lcd7565_WriteCmd(0x2f);
	for(i=0;i<100;i++);
	Lcd7565_WriteCmd(0x40);
	Lcd7565_WriteCmd(0xaf);
	for(i=0;i<100;i++);
}

void Lcd12864_ClearScreen(void){
	uchar i,j;
	for(i=0;i<8;i++){
		Lcd7565_WriteCmd(0xb0+i);
		Lcd7565_WriteCmd(0x10);
		Lcd7565_WriteCmd(0x04);

		for(j=0;j<128;j++){
			Lcd7565_WriteData(0x00);
		}

	}
}

#ifdef CHAR_CODE
#include "charcode.h"
uchar Lcd12864_Write16CnCHAR(uchar x,uchar y,uchar *cn){
	uchar j,x1,x2,wordNum;
	if(y>7)return 0;
	if(x>128)return 0;
	y+=0xB0;
	Lcd7565_WriteCmd(y);
	while(*cn!='\0'){
		Lcd7565_WriteCmd(y);
		x1=(x>>4)&0x0f;
		x2=x&0x0f;
		Lcd7565_WriteCmd(0x10+x1);
		Lcd7565_WriteCmd(0x04+x2);
		
		for(wordNum=0;wordNum<50;wordNum++){
			if((CN16CHAR[wordNum].Index[0]==*cn)&&(CN16CHAR[wordNum].Index[1]==*(cn+1))){
				for(j=0;j<32;j++){
					if(j==16){
						Lcd7565_WriteCmd(y+1);
						Lcd7565_WriteCmd(0x10+x1);
						Lcd7565_WriteCmd(0x04+x2);
					}
					Lcd7565_WriteData(CN16CHAR[wordNum].Msk[j]);
				}
				x+=16;
			}
		}
		cn+=2;
	}
	return 1;
}
#endif