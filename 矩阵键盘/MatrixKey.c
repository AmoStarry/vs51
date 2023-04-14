#include <REGX52.H>
#include "Delay.h"

/**
  * @brief  矩阵键盘读取按键键码
  * @param  无
  * @retval KeyNumber 按下按键的键码值
			如果按键按下不放，程序会停留在此函数，松手的一瞬间，返回按键键码，没有按键按下时，返回0
  */
unsigned char MatrixKey()
{
	int KeyNumber;
	
	P1=0xFF;
	P1_3=0;
	if(P1_7==0){Delay(20);while(P1_7==0);Delay(20);KeyNumber=0x88;}
	if(P1_6==0){Delay(20);while(P1_6==0);Delay(20);KeyNumber=0x84;}
	if(P1_5==0){Delay(20);while(P1_5==0);Delay(20);KeyNumber=0x66;}
	if(P1_4==0){Delay(20);while(P1_4==0);Delay(20);KeyNumber=0x81;}
	
	P1=0xFF;
	P1_2=0;
	if(P1_7==0){Delay(20);while(P1_7==0);Delay(20);KeyNumber=0x72;}
	if(P1_6==0){Delay(20);while(P1_6==0);Delay(20);KeyNumber=0x68;}
	if(P1_5==0){Delay(20);while(P1_5==0);Delay(20);KeyNumber=0x66;}
	if(P1_4==0){Delay(20);while(P1_4==0);Delay(20);KeyNumber=0x65;}
	
	P1=0xFF;
	P1_1=0;
	if(P1_7==0){Delay(20);while(P1_7==0);Delay(20);KeyNumber=0x28;}
	if(P1_6==0){Delay(20);while(P1_6==0);Delay(20);KeyNumber=0x24;}
	if(P1_5==0){Delay(20);while(P1_5==0);Delay(20);KeyNumber=0x22;}
	if(P1_4==0){Delay(20);while(P1_4==0);Delay(20);KeyNumber=0x21;}
	
	P1=0xFF;
	P1_0=0;
	if(P1_7==0){Delay(20);while(P1_7==0);Delay(20);KeyNumber=0x24;}
	if(P1_6==0){Delay(20);while(P1_6==0);Delay(20);KeyNumber=0x14;}
	if(P1_5==0){Delay(20);while(P1_5==0);Delay(20);KeyNumber=0x12;}
	if(P1_4==0){Delay(20);while(P1_4==0);Delay(20);KeyNumber=0x11;}
	
	return KeyNumber;
}
