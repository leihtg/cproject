#include "reg51.h"

typedef unsigned char u8;
typedef unsigned int u16;

unsigned char code smg[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,
			0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};	  //共阴

sbit LSA=P2^2;
sbit LSB=P2^3;
sbit LSC=P2^4;


void delay(u16 i);
void dongTaiSmg(long num);
void Time0Init();
void Count1Init();

static u16 timeCount=0;
static long sum=0,freq=0;
void main(){
	Time0Init();
	Count1Init();
	while(1){	
		dongTaiSmg(freq);
		if(TR1==0){
			freq=sum+TH1*256+TL1;
			sum=0;

			TH1=0;
			TL1=0;
			TR0=1;
			TR1=1;				
		}				
	}
}
void Time0Init(){//定时器
	TMOD|=0x01;
	TH0=0x3c; //50ms
	TL0=0xb0;
	ET0=1;
	EA=1;
	TR0=1;
} 
void time0() interrupt 1{
	TH0=0x3c;
	TL0=0xb0;
	timeCount++;
	if(timeCount==20){//1秒
		timeCount=0;
		TR1=0;//先暂停
		TR0=0;
	}
	
}
void Count1Init(){//计数器
	TMOD|=0x50;
	TH1=0x00;
	TL1=0x00;
	ET1=1;
	EA=1;
	TR1=1;	
}
void delay(u16 i){
	while(i--);
}

void count() interrupt 3{//计数器1中断
	sum+=65536;
}

void dongTaiSmg(long num){//动态数码管
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
		delay(10);
		P0=0;
	}
}

