#include <reg51.h>
unsigned char xdata* pdac0832= 0xFEFF;
unsigned char temp=0;
#define VM 0x80
////调整宏VM定义，可以改变幅度和频率
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
    ////调整延时时间可以改变频率
    temp++;
    if( temp == VM)
    {
      temp= 0;
    }
  }
}
