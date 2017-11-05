#include "lcd.h"

typedef unsigned int u16;
typedef unsigned char u8;

u8 Disp[]="Hello World Good";

void main(){
	u8 i=0,j=0;

	while(1){
		LcdInit();
	//	LcdWriteCom(0x01);
	//	LcdWriteCom(0x80+0x40); 
		for(i=j;i<16;i++){
			LcdWriteData(Disp[i]);
		}
		j++;
		if(j%16==0){
			j=0;
		}
		Lcd1602_Delay1ms(500);
	}
}