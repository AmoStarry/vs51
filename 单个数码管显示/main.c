#include <REGX51.H>
#include "Delay.h"
#define LE P1

unsigned int table[] = {0xef, 0xdf, 0xfe, 0xfd, 0xfb, 0xf7};

void main() {
	int i = 0;
	while(1) {
		for(i = 0; i < 6; i++) {
	  		LE = table[i];
	  		Delay(10);
			LE =0x00;
		}
	}
}