#include <reg51.h>
unsigned char dat_adc;
unsigned char xdata*pad_0808;
void main()
{
  EA=1;
  EX0=1;
  IT0=1;
  pad_0808=0x76FF;
  *pad_0808=0;
  while(1);
}
voidSER_int0( )interrupt 0
{
  dat_adc=*pad_0808;
  P1=dat_adc;
  pad_0808=0x76FF;
  *pad_0808=0;
}