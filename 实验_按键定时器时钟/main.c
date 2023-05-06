#include <REGX52.H>
#include "Delay.h"
#include "LCD1602.h"
#include "Timer0.h"

unsigned char Sec=55,Min=54,Hour=8;

void main()
{
	LCD_Init();
	
	Timer0Init();
	EA=1;
	EX0=1;
	EX1=1;
	IT0=1;
	IT1=1;
	
	LCD_ShowString(1,2,"2023-05-06 Timer");	//上电显示静态字符串
	LCD_ShowString(2,5,"  :  :");
	
	while(1)
	{
		LCD_ShowNum(2,5,Hour,2);	//显示时分秒
		LCD_ShowNum(2,8,Min,2);
		LCD_ShowNum(2,11,Sec,2);
	}
}

void Min_int0() interrupt 0
{
	Min++;
	if(Min>=60)
	{
		Min=0;	//24小时到，Hour清0
	}
}

void Hour_int1() interrupt 2
{
	Hour++;
	if(Hour>=24)
		{
			Hour=0;	//24小时到，Hour清0
		}
	
}	

void Timer0_Routine() interrupt 1
{
	static unsigned int T0Count;
	TL0 = 0x18;		//设置定时初值
	TH0 = 0xFC;		//设置定时初值
	T0Count++;
	if(T0Count>=1000)	//定时器分频，1s
	{
		T0Count=0;
		Sec++;			//1秒到，Sec自增
		if(Sec>=60)
		{
			Sec=0;		//60秒到，Sec清0，Min自增
			Min++;
			if(Min>=60)
			{
				Min=0;	//60分钟到，Min清0，Hour自增
				Hour++;
				if(Hour>=24)
				{
					Hour=0;	//24小时到，Hour清0
				}
			}
		}
	}
}
