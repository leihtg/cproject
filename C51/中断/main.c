#include "reg51.h"

typedef unsigned char u8;
typedef unsigned int u16;

unsigned char code smg[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,
			0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};	  //共阴

sbit led=P0^0;
sbit k3=P3^2;
sbit LSA=P2^2;
sbit LSB=P2^3;
sbit LSC=P2^4;

#define JTD P1

void delay(u16 i);
void Int0Init();
void Int0();
void Timer0Init();
void dongTaiSmg(u16 num);
void hor(u8 flag,u8 yell);
void showYellow(u8 flag,u8 yell);

static u8 count=30,flag=0,yf=0;

void main(){
	Timer0Init();
	while(1){
		dongTaiSmg(count);
		hor(flag,yf);
	}
}

void time0Interrupt() interrupt 1{
	static u16 i=0;
	TH0=0xfc;
	TL0=0x18;
	i++;
	if(i==1000){//1秒
		i=0;
		count--;
		if(count==0){
			count=30;
			flag=!flag;

		}
		if(count<=5){
			yf=1;
		}else{
			yf=0;
		}
	}

}
void Timer0Init(){
	TMOD|=0x01;
	TH0=0xfc;
	TL0=0x18;
	ET0=1;
	EA=1;
	TR0=1;
}
void delay(u16 i){
	while(i--);
}

void Int0Init(){
	IT0=1;//中断方式--下降沿有效
	EX0=1;//外部中断0
	EA=1;//总中断
}

void Int0() interrupt 0{
	delay(1000);
	if(k3==0){
		led=~led;
	}
}
void dongTaiSmg(u16 num){//动态数码管
	u8 i=0,len=8,shu[8]={0};
	shu[7]=num%10;
	shu[6]=num/10%10;
	shu[5]=num/100%10;
	shu[4]=num/1000%10;
	shu[3]=num/10000%10;
	shu[2]=num/100000%10;
	shu[1]=num/1000000%10;
	shu[0]=num/10000000%10;
	for(i=0;i<len;i++){
		switch(i+8-len){
			case 0:
				LSA=0;LSB=0;LSC=0;
				break;
			case 1:
				LSA=1;LSB=0;LSC=0;
				break;
			case 2:
				LSA=0;LSB=1;LSC=0;
				break;
			case 3:
				LSA=1;LSB=1;LSC=0;
				break;
			case 4:
				LSA=0;LSB=0;LSC=1;
				break;
			case 5:
				LSA=1;LSB=0;LSC=1;
				break;
			case 6:
				LSA=0;LSB=1;LSC=1;
				break;
			case 7:
				LSA=1;LSB=1;LSC=1;
				break;
		}
		P0=smg[shu[i]];
		delay(50);
		P0=0;
	}
}
void showYellow(u8 flag,u8 show){
	if(!show)return;
	if(flag){
		JTD^=0x10;
	}else{
		JTD^=0x02;			
	}
}
void hor(u8 flag,u8 yell){
	if(flag){
		JTD=0xb3;
	}else{
		JTD=0x5e;
	}
	showYellow(flag,yell);
}
