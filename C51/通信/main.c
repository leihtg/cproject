#include "reg51.h"

typedef unsigned int u16;
typedef unsigned char u8;

void usartInit(){
	TMOD|=0x20;
	TH1=0xF3;//计数器初始值，波特率4800
	TL1=0xF3;
	PCON=0x80;//倍频
	TR1=1;
	SCON=0x50;
	ES=1;//串口中断
	EA=1;
}				
void main(){
	usartInit();
	while(1);
}	  
void usart() interrupt 4{
	u8 receiveData;
	receiveData=SBUF;
	RI=0;
	SBUF=receiveData;
	while(!TI);
	TI=0;
}