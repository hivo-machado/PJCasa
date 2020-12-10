#include "lcd.h"
#include "pic18f4520.h"

#define RS 0
#define EN 1
#define RW 2

void Delay40us(void){
	unsigned char i;
	for(i=0; i<25; i++);
}

void Delay2ms(void){
	unsigned char i;
	for(i = 0; i< 50; i++){
		Delay40us();	
	}
}

void lcdCommand(unsigned char cmd){

	BitClr(PORTE,RS);
	BitClr(PORTE,RW);
	PORTD = cmd;

	BitSet(PORTE,EN);
	BitClr(PORTE,EN);
	if((cmd == 0x02) || (cmd == 0x01)){
		Delay2ms();
	} else {
		Delay40us();
	}
}

void lcdData(unsigned char valor){
	
	BitSet(PORTE,RS);
	BitClr(PORTE,RW);

	PORTD = valor;

	BitSet(PORTE,EN);
	BitClr(PORTE,EN);

	BitClr(PORTE,RS);
	Delay40us();
}

void lcdInit(void){

	BitClr(TIRSE,RS);
	BitClr(TRISE,EN);
	BitClr(TRISE,RW);
	TRISD = 0x00;
	ADCON1 = 0b00001110;

	Delay2ms(); Delay2ms(); Delay2ms(); Delay2ms(); Delay2ms();

	lcdCommand(0x38);
	Delay2ms(); Delay2ms();
	lcdCommand(0x38);
	Delay2ms();
	lcdCommand(0x38);

	lcdCommand(0x38);
	lcdCommand(0x06);
	lcdCommand(0x0F);
	lcdCommand(0x01);

}
