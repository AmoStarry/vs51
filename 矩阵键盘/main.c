#include <REGX52.H>
#include "Delay.h"		//包含Delay头文件
#include "MatrixKey.h"	//包含矩阵键盘头文件

int KeyNum;

void main()
{
	
	while(1)
	{
		KeyNum=MatrixKey();				//获取矩阵键盘键码
		P3=KeyNum;
	}
}
