#include <REGX51.H>
#include "Delay.h"
#define LSA P2_2  //����������
#define LSB P2_3
#define LSC P2_4

/**
  * @brief  �������ʾ
  * @param  Location һ���������Ҫ�ڵڼ�����ʾ����Χ:1~8
  * @param  Number Ҫ��ʾ��ͼ�� ����ͷ �м� ��β
  * @retval ��
  */
  
unsigned char dusuan[]={0x01,0x02,0x40,0x10,0x08};
void Suma(unsigned char Locarion,number)
{
	
    switch(Locarion) //λ�����
    {
		case(1):LSA=0;LSB=0;LSC=0; break;//��ʾ��1λ   
		case(2):LSA=1;LSB=0;LSC=0; break;//��ʾ��2λ
		case(3):LSA=0;LSB=1;LSC=0; break;//��ʾ��3λ
		case(4):LSA=1;LSB=1;LSC=0; break;//��ʾ��4λ
		case(5):LSA=0;LSB=0;LSC=1; break;//��ʾ��5λ
		case(6):LSA=1;LSB=0;LSC=1; break;//��ʾ��6λ
		case(7):LSA=0;LSB=1;LSC=1; break;//��ʾ��7λ
		case(8):LSA=1;LSB=1;LSC=1; break;//��ʾ��8λ
    }
    P0=dusuan[number];  //��ѡ���
    Delay(300);           //��ʾһ��ʱ��
    P0=0x00;            //������0,��Ӱ 
}


