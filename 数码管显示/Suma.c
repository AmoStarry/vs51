#include <STC89C5xRC.H>
#include "Delay.h"
#define LSA P22
#define LSB P23
#define LSC P24
unsigned char dusuan[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
void Suma(unsigned char Locarion,number)
{
	
    switch(Locarion)
    {
		case(0):LSA=0;LSB=0;LSC=0; break;//��ʾ��0λ
		case(1):LSA=1;LSB=0;LSC=0; break;//��ʾ��1λ
		case(2):LSA=0;LSB=1;LSC=0; break;//��ʾ��2λ
		case(3):LSA=1;LSB=1;LSC=0; break;//��ʾ��3λ
		case(4):LSA=0;LSB=0;LSC=1; break;//��ʾ��4λ
		case(5):LSA=1;LSB=0;LSC=1; break;//��ʾ��5λ
		case(6):LSA=0;LSB=1;LSC=1; break;//��ʾ��6λ
		case(7):LSA=1;LSB=1;LSC=1; break;//��ʾ��7λ
    }
    P0=dusuan[number];
    Delay(1);
    P0=0x00;
}