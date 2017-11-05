#include <reg51.h>

typedef unsigned char u8;
typedef unsigned int u16;

sbit LSA=P2^2;
sbit LSB=P2^3;
sbit LSC=P2^4;

sbit IRIN=P3^2;

u8 DisplayData[8];
u8 IrValue[6];
u8 Time;

u8 code smgduan[17]={
0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,
0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71,0X76};

void delay(u16 i){
	while(i--);
}

void DigDisplay()
{
	u8 i;
	for(i=0;i<3;i++)
	{
		switch(i)	 //位选，选择点亮的数码管，
		{
			case(0):
				LSA=0;LSB=0;LSC=0; break;//显示第0位
			case(1):
				LSA=1;LSB=0;LSC=0; break;//显示第1位
			case(2):
				LSA=0;LSB=1;LSC=0; break;//显示第2位	
		}
		P0=DisplayData[i];//发送数据
		delay(100); //间隔一段时间扫描	
		P0=0x00;//消隐
	}		
}

//1号中断初始化
void int0Init(){
	IT0=1; //下降沿有效
	EX0=1;
	EA=1;

	//IRIN=1;
}

void main(){
	int0Init();
	while(1){
		DisplayData[0]=smgduan[IrValue[2]/16];
		DisplayData[1]=smgduan[IrValue[2]%16];
	    DisplayData[2]=smgduan[16];
		DigDisplay();
	}	
}

void intreput() interrupt 0{
	u8 j,k;
	u16 err;
	Time=0;
	delay(700);//7ms
	if(IRIN==0){
		err=1000;
		while(IRIN==0&&err-->0){
			delay(1);
		}
		if(IRIN==1){
			err=500;
			while(IRIN==1&&err-->0){
				delay(1);				
			}
			for(k=0;k<4;k++){
				for(j=0;j<8;j++){
					err=60;
					while(IRIN==0&&err-->0){
						delay(1);
					}
					err=500;
					while(IRIN==1&&err-->0){
						delay(10);
						Time++;
						if(Time>30){
							return;
						}
					}
					IrValue[k]>>=1;
					if(Time>=8){
						IrValue[k]|=0x80;
					}
					Time=0;
				}
			}
		}
		if(IRIN==1){
			if(IrValue[2]!=~IrValue[2]){
				return;
			}
		}
			
	}			
}