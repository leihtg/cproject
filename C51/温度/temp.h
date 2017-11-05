#ifndef _TEMP_H
#define _TEMP_H

#include <reg51.h>

#ifndef uchar
#define uchar unsigned char
#endif

#ifndef uint
#define uint unsigned int
#endif

sbit DSPORT=P3^7;
	
int Ds18b20ReadTemp();

#endif