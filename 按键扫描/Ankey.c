#include <Delay.h>
#define u_char   unsigned char
#define IO  P2
#define  IO_0   P1^0
#define  IO_0   P1^0
#define  IO_0   P1^0
#define  IO_0   P1^0
#define  IO_0   P1^0
#define  IO_0   P1^0
#define  IO_0   P1^0
#define  IO_0   P1^0

u_char AnKey()
{
    u_char keyNumber=0;
    IO=oxff;
    IO_0=0;
    if(IO_7==0){Delay(20);while(IO_7==0);Delay(20);keyNumber=1;}
    if(IO_6==0){Delay(20);while(IO_6==0);Delay(20);keyNumber=1;}
    if(IO_5==0){Delay(20);while(IO_5==0);Delay(20);keyNumber=1;}
	if(IO_4==0){Delay(20);while(IO_4==0);Delay(20);keyNumber=1;}
	
	IO_1=0;
    if(IO_7==0){Delay(20);while(IO_7==0);Delay(20);keyNumber=1;}
    if(IO_6==0){Delay(20);while(IO_6==0);Delay(20);keyNumber=1;}
    if(IO_5==0){Delay(20);while(IO_5==0);Delay(20);keyNumber=1;}
	if(IO_4==0){Delay(20);while(IO_4==0);Delay(20);keyNumber=1;}
	
}