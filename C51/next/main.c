#include "reg51.h"

typedef unsigned char u8;
typedef unsigned int u16;

#define SPEED 200

sbit moto=P1^0;
sbit motoa=P1^0;
sbit motob=P1^1;
sbit motoc=P1^2;
sbit motod=P1^3;

void delay(u16 i);
void mada();
void bujindianji();

void main(){
	bujindianji();	
}

void bujindianji(){
	P1=0x00;
	while(1){
		//A+
		motoa=1;
		motob=0;
		motoc=1;
		motod=1;
		delay(SPEED);
		//A-
		motoa=0;
		motob=1;
		motoc=1;
		motod=1;
		delay(SPEED);
		//
		motoa=1;
		motob=1;
		motoc=1;
		motod=0;
		delay(SPEED);
		//
		motoa=1;
		motob=1;
		motoc=0;
		motod=1;
		delay(SPEED);
	}	
}	

void delay(u16 i){
	while(i--);
}

void mada(){
	u8 i=0;
	for(i=0;i<100;i++){
		moto=1;
		delay(5000);
	}
	moto=0;
	while(1);
}
