#include "reg51.h"
#include "string.h"
#include "intrins.h"
#define uchar unsigned char
#define uint unsigned int
#define out P0
char str[]={"2023-04-21"};//???????
char str1[]={"00:00:00"};
sbit RS=P2^0;
sbit RW=P2^1;
sbit E=P2^2;
void lcd_initial(void);
void check_busy(void);
void write_com(uchar com);
void write_data(uchar dat);
void string(uchar ad,uchar*s);
void delay(uint ms);
void main(void)
{
	lcd_initial();
	
	while(1)
	{
		string(0x83,str);
		string(0xC4,str1);
	}
}
void delay(uint ms)
{
	uchar i=250;
	for(;ms>0;ms--)
	{
		while(--i);
		i=249;
		while(--i);
		i=250;
	}
}
void check_busy(void)
{
	uchar dt;
	do
	{
		dt=0xff;
		E=0;RS=0;RW=1;E=1;
		dt=out;
	}while(dt&0x80);
	E=0;
}
void write_com(uchar com)
{
	check_busy();
	E=0;RS=0;RW=0;
	out=com;
	E=1;
	_nop_();
	E=0;
	delay(1);
}
void write_data(uchar dat)
{
  check_busy();	
	E=0;RS=1;RW=0;
	out=dat;
	E=1;
	_nop_();
	E=0;
	delay(1);
}
void lcd_initial (void)
{
	write_com(0x38);
	write_com(0x0c);
	write_com(0x06);
	write_com(0x01);
	delay(1);
}
void string (uchar ad,uchar*s)
{
	write_com(ad);
	while(*s>0)
	{
		write_data(*s++);
		delay(100);
	}
}