#include <STC89C5xRC.H>
//����һ��ֱ�����Ÿ�ֵ
#include "Delay.h"
// sbit LED0 = P0^0;
// sbit LED1 = P0^1;
// sbit LED2 = P0^2;
// sbit LED3 = P0^3;
// sbit LED4 = P0^4;
// sbit LED5 = P0^5;
// sbit LED6 = P0^6;
// sbit LED7 = P0^7;

// int main()
// {
// 	while(1)
// 	{
// 		LED0 = 0;
// 		Delay(500);
// 		LED0 = 1;
// 		LED1 = 0;
// 		Delay(500);
// 		LED1 = 1;
// 		LED2 = 0;
// 		Delay(500);
// 		LED2 = 1;
// 		LED3 = 0;
// 		Delay(500);
// 		LED3 = 1;
// 		LED4 = 0;
// 		Delay(500);
// 		LED4 = 1;
// 		LED5 = 0;
// 		Delay(500);
// 		LED5 = 1;
// 		LED6 = 0;
// 		Delay(500);
// 		LED6 = 1;
// 		LED7 = 0;
// 		Delay(500);
// 		LED7 = 1;
// 	}
// }

// ����2��ox01����iλȡ��
// #define  LED  P0
// int main()
// {
//     while(1)
//     {
//         for(int i = 0;i < 8;i++)
//         {
//             LED = ~(0x01 << i);
//             Delay(500);
//         }
//     }
// }


// //����3��_crol_ѭ�����ƺ���
// #include <INTRINS.H>
// int main()
// {
//     while(1)
//     {
//         for(int i = 0;i < 8;i++)
//         {
//             LED =_crol_(oxFE,i);
//             //λ��ʱ�������ĸ�λ���䵽��λ
//             Delay(500);
//         }
//     }
// }


// //����4���Ѹ���LED�������д������
#define  LED  P0
int main()
{
    while(1)
    {
        
        int i;
        int led[]={0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f};
        for(i = 0;i < 8;i ++)
        {
             LED = led[i];
             Delay(500) ; 
         }      
     }
}
