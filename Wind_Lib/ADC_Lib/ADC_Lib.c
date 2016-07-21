/*
 * ADC_Lib.c
 *
 *  Created on: 19 lip 2016
 *      Author: Jacek
 */


#include <avr/io.h>

void ADC_Init(void){
	ADMUX|=(1<<REFS0); // napiecie odniesienia VCC
	ADCSRA|=(1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);
}

void ADC_Start(void){
	ADCSRA|=(1<<ADSC);
}

uint8_t ADC_Wynik (void){
	if (ADCSRA&ADSC){
		switch(ADCW){
		case 786 ... 790:
		return 1;
		case 460 ... 466:
		return 2;
		default: return ADCW;
		}
	}
		else {
			return 0;
		}
}
