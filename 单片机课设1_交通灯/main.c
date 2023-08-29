#include <REGX51.H>
// ����LED�Ƶ�����
sbit RedEastWest = P1^0;    // ��ƣ�������
sbit YellowEastWest = P1^1; // �Ƶƣ�������
sbit GreenEastWest = P1^2;  // �̵ƣ�������

sbit RedNorthSouth = P1^3;    // ��ƣ��ϱ���
sbit YellowNorthSouth = P1^4; // �Ƶƣ��ϱ���
sbit GreenNorthSouth = P1^5;  // �̵ƣ��ϱ���

// �����������ʾ������
sbit SegA = P2^0;
sbit SegB = P2^1;
sbit SegC = P2^2;
sbit SegD = P2^3;
sbit SegE = P2^4;
sbit SegF = P2^5;
sbit SegG = P2^6;

// ���尴��������
sbit EmergencyButton = P3^2; // Ӧ��ͨ�а���

int i =0;
int Key_num =0;

void delay(unsigned int ms) {
    unsigned int i, j;
    for (i = 0; i < ms; i++) {
        for (j = 0; j < 1000; j++);
    }
}

// ����ܵı��룬0~9�Ĺ�������ܱ���
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

// �ⲿ�ж�0���жϷ������
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
    EX0 = 1;   // �����ⲿ�ж�0����λ
    IT0 = 1;   // �����ⲿ�ж�0Ϊ�͵�ƽ����
    EA = 1;    // ����ȫ���ж�����λ
    while (1) {
        // �������̵ƣ��ϱ������
        GreenEastWest = 1;
        YellowEastWest = 0;
        RedEastWest = 0;
        GreenNorthSouth = 0;
        YellowNorthSouth = 0;
        RedNorthSouth = 1;
        // ��ʾʣ��ʱ��
        for ( i = 5; i >= 0; i--) {
            P1 =SevenSegmentDigits[i];
            delay(1000);
        }

        // �Ƶ���˸5��
        for ( i = 0; i < 5; i++) {
            YellowEastWest = ~YellowEastWest;
            P1 =SevenSegmentDigits[8]; // ��ʾ"8"����ʾ�Ƶ�
            delay(500);
        }

        // ������������ϱ����̵�
        GreenEastWest = 0;
        YellowEastWest = 0;
        RedEastWest = 1;
        GreenNorthSouth = 1;
        YellowNorthSouth = 0;
        RedNorthSouth = 0;
        
        // ��ʾʣ��ʱ��
        for ( i = 5; i >= 0; i--) {
            P1 =SevenSegmentDigits[i];
            delay(1000);
        }

        // �Ƶ���˸5��
        for ( i = 0; i < 5; i++) {
            YellowEastWest = ~YellowEastWest;
            P1 =SevenSegmentDigits[8]; // ��ʾ"8"����ʾ�Ƶ�
            delay(500);
        }
    }
}   