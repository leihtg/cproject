#include "temp.h"

typedef unsigned char u8;
typedef unsigned int u16;

sbit LSA=P2^2;
sbit LSB=P2^3;
sbit LSC=P2^4;

unsigned char code smg[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,
			0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};	  //共阴
u8 shu[8]={0};
void delay(u16 i){
	while(i--);
}
void dongTaiSmg(){//动态数码管
	u8 i=0,len=8;
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
		P0=shu[i];
		delay(50);
		P0=0;
	}
}

void main(){
	float tp;
	while(1){
		int temp=Ds18b20ReadTemp();
		if(temp<0){
			shu[0]=0x40;
			temp=temp-1;
			temp=~temp;
			tp=temp;
			temp=tp*0.0625*100+0.5;
		}else{
			shu[0]=0x00;
			tp=temp;
			temp=tp*0.0625*100+0.5;			
		}
		shu[1]=smg[temp/10000];
		shu[2]=smg[temp%10000/1000];
		shu[3]=smg[temp%1000/100]|0x80;
		shu[4]=smg[temp%100/10];
		shu[5]=smg[temp%10];
		dongTaiSmg();
	}
}