#include <STC89C5xRC.H>
#include "Timer0.h"

void Timer_delay(unsigned int ms)
{
	unsigned int count;
	bit flag = 0;
	count = ms; //??????
	flag = 1;
	while(flag);//??????,?????0,??whil??
}

void Timer0_Routine() interrupt 1
{
	unsigned int count;
	bit flag = 0;
	//static unsigned int T0Count;
	TL0 = 0x18;		//??????  //??1 ms????
	TH0 = 0xFC;		//??????
	if(flag)
	{
		if(--count == 0)//?????1,?????????
			flag = 0;       //????0,????
	}
}