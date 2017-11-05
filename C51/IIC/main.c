#include "i2c.h"

typedef unsigned char u8;
typedef unsigned int u16;

sbit k1=P3^1;
sbit k2=P3^0;
sbit k3=P3^2;
sbit k4=P3^3;

sbit LSA=P2^2;
sbit LSB=P2^3;
sbit LSC=P2^4;

u8 code smgduan[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,
			0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};
u8 num=0;

void delay(u16 i){
	while(i--);
}
void dongTaiSmg(long num){//¶¯Ì¬ÊýÂë¹Ü
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
		P0=smgduan[shu[i]];
		delay(10);
		P0=0;
	}
}

void Keypros(){
	if(k1==0){
		delay(1000);
		if(k1==0){
			At24c02Write(1,num);
		}
		while(!k1);
	}
	if(k2==0){
		delay(1000);
		if(k2==0){
			num=At24c02Read(1);
		}
		while(!k2);
	}
	if(k3==0){
		delay(1000);
		if(k3==0){
			num++;
		}
		while(!k3);
	}
	if(k4==0){
		delay(1000);
		if(k4==0){
			num=0;
		}
		while(!k4);
	}
}

void main(){
	while(1){
		Keypros();
		dongTaiSmg(num);
	}
}