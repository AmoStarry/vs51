#include<reg51.h>
void delay(unsigned int msecs)
{
	while(msecs--)
	{
		unsigned char j;
		for(j=0;j<125;j++);
	}
}
unsigned char keyscan(void)
{
	unsigned char keyvalue=0xff;
	P3=0xff;
	 keyvalue=P3;
	if(keyvalue!=0xFF)
	{
		delay(15);
		keyvalue=P3;
		if(keyvalue!=0xFF)
			keyvalue=~keyvalue;
	}
	return keyvalue;
}
void main()
{
	unsigned char keyval;
	while(1)
	{
		keyval=keyscan();
		switch(keyval)
		{
			case 1:{P1=0xAA;delay(1000);P1=0xFF;}break;
			case 2:{P1=0x55;delay(1000);P1=0xFF;}break;
			case 4:{P1=0xFC;delay(1000);P1=0xFF;}break;
			case 8:{P1=0xF3;delay(1000);P1=0xFF;}break;
			case 16:{P1=0xCF;delay(1000);P1=0xFF;}break;
			case 32:{P1=0x3F;delay(1000);P1=0xFF;}break;
			case 64:{P1=0xC3;delay(1000);P1=0xFF;}break;
			case 128:{P1=0x3C;delay(1000);P1=0xFF;}break;
			default:break;
		}
	}
}
