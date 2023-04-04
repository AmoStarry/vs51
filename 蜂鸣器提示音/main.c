#include <STC89C5xRC.H>
#include <REGX52.H>
#include "Delay.h"
#include "Key.h"
#include "Suma.h"
#include "Buzzer.h"

unsigned char KeyNum;

void main()
{
	Suma(1,0);
	while(1)
	{
		KeyNum=Key();
		if(KeyNum)
		{
			Buzzer_Time(100);
			Suma(1,KeyNum);
		}
	}
}
