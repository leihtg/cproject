#include "XPT2046.h"

typedef unsigned int u16;
typedef unsigned char u8;

sbit LSA=P2^2;
sbit LSB=P2^3;
sbit LSC=P2^4;

u8 disp[4];
u8 code smgduan[10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};

void delay(u16 i){
	while(i--);
}

void datapros(){
	u16 temp;
	static u8 i;
	if(i==50){
		i=0;
		//temp=Read_AD_Data(0x94);  //电位器
		//temp=Read_AD_Data(0xA4);//光敏电阻
		temp=Read_AD_Data(0xD4);  //热敏电阻
	}
	i++;
	disp[0]=smgduan[temp/1000];//千位
	disp[1]=smgduan[temp%1000/100];//百位
	disp[2]=smgduan[temp%1000%100/10];//个位
	disp[3]=smgduan[temp%1000%100%10];		
}

void DigDisplay(){
	u8 i;
	for(i=0;i<4;i++){
		switch(i){
			case(0):
				LSA=0;LSB=0;LSC=0; break;//显示第0位
			case(1):
				LSA=1;LSB=0;LSC=0; break;//显示第1位
			case(2):
				LSA=0;LSB=1;LSC=0; break;//显示第2位
			case(3):
				LSA=1;LSB=1;LSC=0; break;//显示第3位	
		}
		P0=disp[i];
		delay(100);
		P0=0x00;
	}
}

void main(){
	while(1){
		datapros();
		DigDisplay();
	}
}