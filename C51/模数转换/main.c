#include <reg51.h>

typedef unsigned int u16;
typedef unsigned char u8;

sbit PWM=P2^1;
bit DIR;

u16 count,value,timer1;

void Timer1Init(){
	TMOD|=0x10;

	TH1=0xff;
	TL1=0xff; //1us

	ET1=1;
	EA=1;
	TR1=1;
}

void main(){
	Timer1Init();
	while(1){
		if(count>100){
			count=0;
			if(DIR==1){
				value+=10;
			}
			if(DIR==0){
				value-=10;
			}
		}		
		if(value==1000){
			DIR=0;
		}
		if(value==0){
			DIR=1;
		}
		if(timer1>1000){//PWMÖÜÆÚÎª1000*1us
			timer1=0;
		}
		if(timer1<value){
			PWM=1;
		}else{
			PWM=0;
		}
	}
}

void Timera1(void) interrupt 3{
	TH1=0xff;
	TL1=0xff;
	timer1++;
	count++;
}