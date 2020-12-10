#include "keypad.h"
#include "pic18f4520.h"
//#include "so.h"
//#include "io.h"

static unsigned char valor = 0x00;

unsigned int kpRead(void) {
    return valor; //keys
}

void kpInit(void) {
	TRISB = 0xF0;
	BitClr(INTCON2, 7);
	ADCON1 = 0b00001110;
  
#ifdef PIC18F4550
	SPPCFG = 0x00;
#endif
}

char kpReadKey(void){
	int i;
	for(i=0;i<10;i++){
		if (bitTst(keys,0)){
			return charKey[i];
		}
	}
	//nenhuma tecla pressionada
	return 0;
}

void kpDebounce(void) {
	int i, j;
	static unsigned char tempo;
	static unsigned char valorNovo = 0x0000;
	static unsigned char valorAntigo = 0x0000;
	//newRead = 0;
	for(i = 0; i<4; i++){
		
		TRISB = ~((unsigned char)1<<i);
		PORTB = ~((unsigned char)1<<i);

		for(j = 0; j < 2; j++){
			if (!BitTst(PORTB, j + 4)){
				BitSet(valorNovo, (i*2)+j);
			}else{
				BitClr(valorNovo, (i*2)+j);			
			}
			
		}
	}
	if (valorAntigo == valorNovo){
		tempo--;
	} else {
		tempo = 10;
		valorAntigo = valorNovo;
	}
	if (tempo == 0) {
		valor = valorAntigo;
	}
		
}

