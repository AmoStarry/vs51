#include<reg51.h>
#define uchar unsigned char
#define uint unsigned int
uchar code table_0[]={0x00,0x7E,0x40,0x20,0x10,0x08,0x04,0x7E,};
uchar code table_a[]={0x00,0x7E,0x10,0x10,0x10,0x12,0x1C,0x00,};
void delay(int msecs)
{
	while(msecs--)
	{
		uchar j;
		for(j=0;j<125;j++);
	}
}
void main(void)
{
	uchar a,i,j;
	while(1)
	{
		for(j=0;j<40;j++)
		{
			a=0x01;
			for(i=0;i<8;i++)
			{
				P2=table_0[i];
				P3=~a;
				delay(1);
				P3=0xff;
				a<<=1;
			}
		}
		for(j=0;j<40;j++)
		{
			a=0x01;
			for(i=0;i<8;i++)
			{
			P2=table_a[i];
			P3=~a;
			delay(1);
			P3=0xff;
			a<<=1;
		}
	}
}
}