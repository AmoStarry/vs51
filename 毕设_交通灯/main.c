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
		P2=0x24;             //�����̵������ϱ������
		Timer_delay(3000);
		for(i=0;i<5;i++){
			P2=0x14;           //�����Ƶ������ϱ������
			Timer_delay(500);
			P2=0x04;           //����û�е������ϱ������
			Timer_delay(500);
		}
		P2=0x09;             //������������ϱ��̵���
		Timer_delay(3000);
		for(i=0;i<5;i++){
			P2=0x0a;           //������������ϱ��Ƶ���
			Timer_delay(500);
			P2=0x08;           //������������ϱ�û����
			Timer_delay(500);
		}
	}

}
