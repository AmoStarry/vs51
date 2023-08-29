#include <REGX51.H>
// 定义LED灯的引脚
sbit RedEastWest = P1^0;    // 红灯（东西向）
sbit YellowEastWest = P1^1; // 黄灯（东西向）
sbit GreenEastWest = P1^2;  // 绿灯（东西向）

sbit RedNorthSouth = P1^3;    // 红灯（南北向）
sbit YellowNorthSouth = P1^4; // 黄灯（南北向）
sbit GreenNorthSouth = P1^5;  // 绿灯（南北向）

// 定义数码管显示的引脚
sbit SegA = P2^0;
sbit SegB = P2^1;
sbit SegC = P2^2;
sbit SegD = P2^3;
sbit SegE = P2^4;
sbit SegF = P2^5;
sbit SegG = P2^6;

// 定义按键的引脚
sbit EmergencyButton = P3^2; // 应急通行按键

int i =0;
int Key_num =0;

void delay(unsigned int ms) {
    unsigned int i, j;
    for (i = 0; i < ms; i++) {
        for (j = 0; j < 1000; j++);
    }
}

// 数码管的编码，0~9的共阴数码管编码
unsigned char code SevenSegmentDigits[] = {
    0x3F, // 0
    0x06, // 1
    0x5B, // 2
    0x4F, // 3
    0x66, // 4
    0x6D, // 5
    0x7D, // 6
    0x07, // 7
    0x7F, // 8
    0x6F  // 9
};

// 外部中断0的中断服务程序
void external_interrupt() interrupt 0 {
     while(1){     
          GreenEastWest = 0;
          YellowEastWest = 0;
          RedEastWest = 1;
          GreenNorthSouth = 0;
          YellowNorthSouth = 0;
          RedNorthSouth = 1;
          if (EmergencyButton == 0){
               Key_num++;
          }
          while(Key_num ==2){break;}
     }
    
}


void main() {
    EmergencyButton = 1; 
    EX0 = 1;   // 启用外部中断0允许位
    IT0 = 1;   // 设置外部中断0为低电平触发
    EA = 1;    // 启用全局中断允许位
    while (1) {
        // 东西亮绿灯，南北亮红灯
        GreenEastWest = 1;
        YellowEastWest = 0;
        RedEastWest = 0;
        GreenNorthSouth = 0;
        YellowNorthSouth = 0;
        RedNorthSouth = 1;
        // 显示剩余时间
        for ( i = 5; i >= 0; i--) {
            P1 =SevenSegmentDigits[i];
            delay(1000);
        }

        // 黄灯闪烁5次
        for ( i = 0; i < 5; i++) {
            YellowEastWest = ~YellowEastWest;
            P1 =SevenSegmentDigits[8]; // 显示"8"，表示黄灯
            delay(500);
        }

        // 东西红灯亮，南北亮绿灯
        GreenEastWest = 0;
        YellowEastWest = 0;
        RedEastWest = 1;
        GreenNorthSouth = 1;
        YellowNorthSouth = 0;
        RedNorthSouth = 0;
        
        // 显示剩余时间
        for ( i = 5; i >= 0; i--) {
            P1 =SevenSegmentDigits[i];
            delay(1000);
        }

        // 黄灯闪烁5次
        for ( i = 0; i < 5; i++) {
            YellowEastWest = ~YellowEastWest;
            P1 =SevenSegmentDigits[8]; // 显示"8"，表示黄灯
            delay(500);
        }
    }
}   