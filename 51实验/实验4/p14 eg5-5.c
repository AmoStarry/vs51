#include<reg51.h>
#define uchar unsigned char
#define uint unsigned int
uchar key_scan(void);
void main(void)
{
	uchar key=0,status=0xff;
	while(1)
	{
		key=key_scan();
		if(key>0)
		{  status=~key;}
		P3=status;
	}
}
void delay10ms(void)
{
	uchar i;
	for(i=0;i<200;i++){;}
}
uchar key_scan(void)
{
	uchar code_h;
	uchar code_l;
	uchar keyval;
	P1=0xf0;
	if((P1&0xf0)!=0xf0)
	{
		delay10ms();
		if((P1&0xf0)!=0xf0)
		{
			code_h=0xfe;
			while(code_h!=0xef)
			{
				P1=code_h;
				if((P1&0xf0)!=0xf0)
				{
					code_l=(P1&0xf0|0x0f);
					keyval=(~ code_h)+(~ code_l);
					while((P1&0xf0)!=0xf0);
					return(keyval);
				}
				else
				{code_h=(code_h<<1)|0x01;}
			 }
			return(0);
		 }
		else return(0);
	 }
	else return(0);
	}