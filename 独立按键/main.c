#include <STC89C5xRC.H>
#include "key.h"
#include "Delay.h"
#include <stdio.h>
int main()
{
	unsigned char KeyNum=0;
	KeyNum = key();
	printf("%d",KeyNum);
	
}