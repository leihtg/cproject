#include "reg51.h"
#include "intrins.h"

#define led P0
#define btn P1

sbit beep=P1^5;
sbit relay=P1^4;
sbit LSA=P2^2;
sbit LSB=P2^3;
sbit LSC=P2^4;
sbit IN_PL=P1^6;
sbit IN_DATA=P1^7;
sbit SCK=P3^6;
sbit RCLK=P3^5;
sbit SER=P3^4;


unsigned char code smg[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,
			0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};	  //共阴

void liushuideng();
void delay(int m);
void didi();
void relayFunc();
void staticSmg();
void dongTaiSmg();
void keypros();
void rectKeyBoard();
void useHC165();
void useHC595();

void main(){
	useHC595();
}
void sendData(unsigned char dat){
	unsigned char a;
	for(a=0;a<8;a++){
		SER=dat>>7;
		dat<<=1;
		SCK=0;
		delay(1);
		SCK=1;
	}
	RCLK=0;
	delay(1);
	RCLK=1;
}
void useHC595(){
	unsigned char ledNum=0x01;
	while(1){
		sendData(ledNum);
		ledNum=_crol_(ledNum,1);
		delay(200);
	}	
}
unsigned char readData(){
	unsigned char indata=0;
	unsigned char i=0;

	IN_PL=0;
	delay(1);
	IN_PL=1;
	for(i=0;i<8;i++){
		indata=indata<<1;
		SCK=0;
		delay(1);
		indata|=IN_DATA;
		SCK=1;
	}
	return indata;
}
void useHC165(){//使用74hc165
	 unsigned char h165Value;
	 led=0x00;
	 while(1){
	 	h165Value=readData();
		if(h165Value!=0xff){
			led=~h165Value;
		}
	 }
}
void rectKeyBoard(){//矩阵按键
	unsigned char r=0,c=0;
	while(1){
		btn=0x0f;
		if(btn!=0x0f){
			delay(50);
			if(btn!=0x0f)
			switch(btn&0x0f){
				case 0x07:
					c=0;
				break;
				case 0x0b:
					c=1;
					break;
				case 0x0d:
					c=2;
					break;
				case 0x0e:
					c=3;
					break;
			}
			btn=0xf0;
			if(btn!=0xf0){
				delay(50);//消抖
				if(btn!=0xf0)  //确认被按下
				switch((btn&0xf0)>>4){
					case 0x07:
						r=0;
					break;
					case 0x0b:
						r=1;
						break;
					case 0x0d:
						r=2;
						break;
					case 0x0e:
						r=3;
						break;				
				}
				led=~smg[r*4+c];
			}
		}

	}
}
void keypros(){//独立按键
	unsigned char _btn;
	led=0xff;//全不亮
	while(1){	
		_btn=btn&0xff;
		if(btn!=0xff){
			delay(100);
			led=(~led)^_btn;
			while(btn!=0xff);	
		}
	}
}
void dongTaiSmg(){//动态数码管
	unsigned char i,j=0;
	while(1){
		for(i=0;i<8;i++){
			switch(i){
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
			P0=smg[j++%16];
			delay(200);
			//P0=0x00;
		}
	}
}
void staticSmg(){//静态数码管
	unsigned char i=0;
	while(1){
		P0=~smg[i++%16];
		delay(100);
	}
}
void relayFunc(){//继电器
	relay=0;
	while(1);
}

void didi(){//蜂鸣器
	while(1){
		//beep=~beep;
		beep=1;
		delay(50);
		beep=0;
		delay(100);
	}
}
void liushuideng(){
	int i=1;
	led=0x01;	
	while(1){
	   delay(1000);
	      led=led<<1;
	   if((i++%8)==0){
	   		led=1;
	   }
	}
}
void delay(int m){
	while(m-->0){
		int i=110;
		while(i-->0){
		}
	}
}
