#include<reg51.h>
#include< intrins.h>
void delay(unsigned int i)
{
	unsigned char t;
	while(i--)
	{
		for(t=0;t<125;t++);
		}
}
void main()
{
	P1=0xfe;
	while(1)
	{
		delay(500);
		P1=_crol_(P1,1);
	}
}