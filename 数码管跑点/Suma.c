#include <REGX51.H>
#include "Delay.h"
#define LSA P2_2  //三八译码器
#define LSB P2_3
#define LSC P2_4

/**
  * @brief  数码管显示
  * @param  Location 一排数码管上要在第几段显示，范围:1~8
  * @param  Number 要显示的图案 ：开头 中间 结尾
  * @retval 无
  */
  
unsigned char dusuan[]={0x01,0x02,0x40,0x10,0x08};
void Suma(unsigned char Locarion,number)
{
	
    switch(Locarion) //位码输出
    {
		case(1):LSA=0;LSB=0;LSC=0; break;//显示第1位   
		case(2):LSA=1;LSB=0;LSC=0; break;//显示第2位
		case(3):LSA=0;LSB=1;LSC=0; break;//显示第3位
		case(4):LSA=1;LSB=1;LSC=0; break;//显示第4位
		case(5):LSA=0;LSB=0;LSC=1; break;//显示第5位
		case(6):LSA=1;LSB=0;LSC=1; break;//显示第6位
		case(7):LSA=0;LSB=1;LSC=1; break;//显示第7位
		case(8):LSA=1;LSB=1;LSC=1; break;//显示第8位
    }
    P0=dusuan[number];  //段选输出
    Delay(300);           //显示一段时间
    P0=0x00;            //段码清0,消影 
}


