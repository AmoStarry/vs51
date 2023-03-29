#include <STC89C5xRC.H>
//方法一：直接引脚赋值
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

// 方法2：ox01左移i位取反
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


// //方法3：_crol_循环左移函数
// #include <INTRINS.H>
// int main()
// {
//     while(1)
//     {
//         for(int i = 0;i < 8;i++)
//         {
//             LED =_crol_(oxFE,i);
//             //位移时，舍弃的高位补充到低位
//             Delay(500);
//         }
//     }
// }


// //方法4：把各个LED亮灭情况写入数组
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
