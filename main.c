#include "config.h"
#include "ssd.h"
#include "keypad.h"
#include "lcd.h"
//#include "pic18f4520.h"

void main(void)	{
	
	int temp, time, valor = 0;

	ssdInit();
	kpInit();
	lcdInit();
	lcdData('E');

	for(;;){

		if (kpRead() != temp){
			temp = kpRead();	
		
		   if (BitTst(kpRead(), 0)){
		   	valor = 1;
			lcdData('Q');
			lcdData('U');
			lcdData('A');
			lcdData('R');
			lcdData('T');
			lcdData('O');
		   }	
		   if (BitTst(kpRead(), 1)){
		   	valor = 2;
			lcdData('S');
			lcdData('A');
			lcdData('L');
			lcdData('A');
		   }
		   if (BitTst(kpRead(), 2)){
		   	valor = 4;
			lcdData('C');
			lcdData('O');
			lcdData('Z');
			lcdData('I');
			lcdData('N');
			lcdData('H');
			lcdData('A');
		   }

		   ssdDigit(valor,0);		

		   for (time = 0; time <100; time++);
		   ssdUpdate();
		   kpDebounce();
		}

	}

}
