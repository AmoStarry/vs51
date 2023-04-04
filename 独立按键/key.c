#include <STC89C5xRC.H>

#include "Delay.h"
#define  AN1 P30
#define  AN2 P31
#define  AN3 P32
#define  AN4 P33
/**
  * @brief  ��ȡ������������
  * @param  ��
  * @retval ���°����ļ���,��Χ:0~4,�ް�������ʱ����ֵΪ0
  */
unsigned char Key()
{
	unsigned char KeyNumber=0;
	
	if(AN1==0){Delay(20);while(AN1==0);Delay(20);KeyNumber=1;}
	if(AN2==0){Delay(20);while(AN2==0);Delay(20);KeyNumber=2;}
	if(AN3==0){Delay(20);while(AN3==0);Delay(20);KeyNumber=3;}
	if(AN4==0){Delay(20);while(AN4==0);Delay(20);KeyNumber=4;}
	
	return KeyNumber;
}