#include <reg51.h>
unsigned char xdata* pdac0832= 0xFEFF;
unsigned char temp=0;
#define VM 0x80
////������VM���壬���Ըı���Ⱥ�Ƶ��
void delay(unsigned int ms)
{
unsigned char i;
for(;ms> 0; ms--)
for(i= 0; i< 125; i++);
}
void main()
{
  while(1)
  {
    * pdac0832= temp;
    delay(20);
    ////������ʱʱ����Ըı�Ƶ��
    temp++;
    if( temp == VM)
    {
      temp= 0;
    }
  }
}
