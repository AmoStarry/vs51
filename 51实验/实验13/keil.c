#include<reg51.h>
sbit ADDA=P2^0;
sbit ADDB=P2^1;
sbit ADDC=P2^2;
sbit OE=P2^3;
sbit START=P2^4;
sbit ALE=P2^5;
sbit EOC=P2^6;
unsigned char num=0;
unsigned char code table[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x00};
unsigned char distable[4]={0,1,2,3};
unsigned char dispcount;
void delay(unsigned int ms)
{
	unsigned char i;
	for(;ms>0;ms--)
	for(i=0;i<125;i++);
}
void LED_display()
{
	unsigned char i,a=0x01;
	for(i=0;i<4;i++)
	{
		P1=~table[distable[i]];
		if(i==0)
		P1=~table[distable[i]] & 0x7F;
		P3=~a;
		delay(1);
		P3=0xFF;
		a<<=1;
	}
}
void calculate(unsigned char num)
{
	long int i;
	i=num*196;
	distable[0]=i/10000;
	i=i%10000;
	distable[1]=i/1000;
	i=i%1000;
	distable[2]=i/100;
	i=i%100;
	distable[3]=i/10;
}
void main(void)
{
	P0=0xff;
	P2=0x00;
	EOC=1;
	ADDA=1;
	ADDB=1;
	ADDC=0;
	ALE=1;
	while(1)
	{
		START=0;
		START=1;
		START=0;
		delay(1);
		OE=1;
		delay(1);
		num=P0;
		OE=0;
		calculate(num);
		LED_display();
	}
}