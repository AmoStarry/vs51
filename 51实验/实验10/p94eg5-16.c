#include <reg51.h>
#define uchar unsigned char
#define BEGIN_HOUR 8
#define BRGIN_MINUTE 15
#define BEGIN_SECOND 30
unsigned int count=0;
uchar table[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
uchar dis_table[6]={0,0,0,0,0,0};
unsigned char hour=0,minute=0,second=0;
void delay(int msecs)
{
	uchar j;
	while(msecs--)
	{
		for(j=0;j<125;j++);
	}
}
void LED_Display(uchar*dis_table)
{
	uchar a=0x01,i;
	for(i=0;i<6;i++)
	{
		P0=table[dis_table[i]];
		if(i==2 | i==4)
		{
			P0=P0 | 0x80;
		}
		P1=~a;
		delay(1);
		P1=0xff;
		a<<=1;
	}
}
void INT_T1(void) interrupt 3 using 1
{
	TH1=15536/256;
	TL1=15536%256;
	count++;
	if(count==20)
	{
		count=0;second++;
		if(second==60)
		{
			second=0;
			minute++;
			if(minute==60)
			{
				minute=0;
				hour++;
				if(hour==24)
				{
					hour=0;
				}
			}
		}
	}
}
void initialize_time(void)
{
	hour=BEGIN_HOUR;
	minute=BRGIN_MINUTE;
	second=BEGIN_SECOND;
}
void main(void)
{
	TMOD=0x10;
	TH1=15536/256;
	TL1=15536%256;
	EA=1;
	ET1=1;
	TR1=1;
	initialize_time();
	while(1)
	{
		dis_table[5]=hour/10;
		dis_table[4]=hour%10;
		dis_table[3]=minute/10;
		dis_table[2]=minute%10;
		dis_table[1]=second/10;
		dis_table[0]=second%10;
		LED_Display(dis_table);
	}
}