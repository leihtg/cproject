#include "i2c.h"

void Delay10us(void){
	unsigned char a,b;
	for(b=1;b>0;b--){
		for(a=2;a>0;a--);
	}
}

void I2cStart(){
	SDA=1;
	Delay10us();
	SCL=1;
	Delay10us();
	SDA=0;
	Delay10us();
	SCL=0;
	Delay10us();
}

void I2cStop(){
	SDA=0;
	Delay10us();
	SCL=1;
	Delay10us();
	SDA=1;
	Delay10us();
}

unsigned char I2cSendByte(unsigned char dat){
	unsigned char a=0,b=0;
	for(a=0;a<8;a++){
		SDA=dat>>7;
		dat<<=1;
		Delay10us();
		SCL=1;
		Delay10us();
		SCL=0;
		Delay10us();
	}
	SDA=1;
	Delay10us();
	SCL=1;
	while(SDA){//µÈ´ýÓ¦´ð
		b++;	
		if(b>200){
			SCL=0;
			Delay10us();
			return 0;
		}
	}
	SCL=0;
	Delay10us();
	return 1;
}

unsigned char I2cReadByte(){
	unsigned char dat=0,a=0;
	SDA=1;
	Delay10us();
	for(a=0;a<8;a++){
		SCL=1;
		Delay10us();
		dat<<=1;
		dat|=SDA;
		Delay10us();
		SCL=0;
		Delay10us();
	}
	return dat;
}

void At24c02Write(unsigned char addr,unsigned char dat){
	I2cStart();
	I2cSendByte(0xa0);
	I2cSendByte(addr);
	I2cSendByte(dat);
	I2cStop();
}
	
unsigned char At24c02Read(unsigned char addr){
	unsigned char num=0;
	I2cStart();
	I2cSendByte(0xa0);
	I2cSendByte(addr);
	
	I2cStart();
	I2cSendByte(0xa1);
	I2cSendByte(addr); 
	num=I2cReadByte();
	I2cStop();
	
	return num;	
}