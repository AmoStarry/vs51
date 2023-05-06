#include <REGX52.H>
#define ws P1 
#define ds P3 

//数码管段码表
unsigned char NixieTable[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};

//延时子函数
void Delay(unsigned int xms)
{
	unsigned char i, j;
	while(xms--)
	{
		i = 2;
		j = 239;
		do
		{
			while (--j);
		} while (--i);
	}
}

//数码管显示子函数
void Nixie(unsigned char Location,Number)
{
	switch(Location)		//位码输出
	{
		case 1:P1_0 = 1;break;
		case 2:P1_1 = 1;break;
		case 3:P1_2 = 1;break;
		case 4:P1_3 = 1;break;
		case 5:P1_4 = 1;break;
		case 6:P1_5 = 1;break;
		case 7:P1_6 = 1;break;
		case 8:P1_7 = 1;break;
	}
	ds=NixieTable[Number];	//段码输出
	Delay(1000);				//显示一段时间
	ds=0xff;				//段码清0，消影
}

void main()
{
	while(1)
	{
		Nixie(1,2);		//在数码管的第1位置显示1
		Delay(200);
		Nixie(2,0);		//在数码管的第2位置显示2
		Delay(200);
		Nixie(3,0);		//在数码管的第3位置显示3
		Nixie(4,1);
		Nixie(5,1);
		Nixie(6,2);
		Nixie(7,2);
		Nixie(8,9);	
//		Delay(20);
	}
}
