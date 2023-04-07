#include <STC89C5xRC.H>
#include "Timer0.h"
#include "Timer_delay.h"

#define uchar unsigned char
#define uint unsigned int
 
int main()
{
	uint i;
	Timer0Init();
	while(1){
		P2=0x24;             //东西绿灯亮，南北红灯亮
		Timer_delay(3000);
		for(i=0;i<5;i++){
			P2=0x14;           //东西黄灯亮，南北红灯亮
			Timer_delay(500);
			P2=0x04;           //东西没有灯亮，南北红灯亮
			Timer_delay(500);
		}
		P2=0x09;             //东西红灯亮，南北绿灯亮
		Timer_delay(3000);
		for(i=0;i<5;i++){
			P2=0x0a;           //东西红灯亮，南北黄灯亮
			Timer_delay(500);
			P2=0x08;           //东西红灯亮，南北没灯亮
			Timer_delay(500);
		}
	}

}
