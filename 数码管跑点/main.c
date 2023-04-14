#include <REGX51.H>
#include "Delay.h"
#include "Suma.h"
int main()
{
    while(1)
    {
        int i;
		for(i=8;i>=1;i--)
		{
			Suma(i,0);
		}
		Suma(1,1);
		for(i=1;i<=8;i++)
		{
			Suma(i,2);
		}
		Suma(8,3);
		for(i=8;i>=1;i--)
		{
			Suma(i,4);
		}
		
    }
}
