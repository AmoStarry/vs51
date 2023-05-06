#include<reg51.h>
sbit P10=P1^0;
unsigned int count=0;
unsigned char state=0x01;
void SER_T1(void)interrupt 3 using 1
{
	count++;
	if(count==2500)
		P10=!P10;
	if(count==10000)
	{
		P10=!P10;
		count=0;
	}
}
void main(void)
{
	P10=1;
	TMOD=0x20;
	TH1=TL1=256-200;
	EA=1; ET1=1;
	TR1=1;
	while(1);
}