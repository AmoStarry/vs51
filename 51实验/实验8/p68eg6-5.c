#include"reg51.h"
unsigned char table[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
unsigned char display_num=0;
void SER_INT0() interrupt 0 using 0
{
	display_num++;
	if(display_num>9)
	{
		display_num=0;
	}
}
void main()
{
	EA=1;
	EX0=1;
	IT0=1;
	while(1)
	{
		P1=table[display_num];
	}
}