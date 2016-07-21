/*
 * main.c
 *
 *  Created on: 7 lip 2016
 *      Author: Jacek
 */


#include <stdio.h>
#include <stdlib.h>
#include <avr/io.h>
#include <stdint.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "UART/uart.h"
#include "Wind_Lib/Wind_Lib.h"
uint8_t wynik;
int main(void)
{

    USART_Init(__UBRR);
    ADC_Init();
    sei();
    uart_puts("******* Start ***********\r\n");
    ADC_Start();
	while (1)
	{
		wynik=ADC_Wynik();
		if (wynik){
			uart_putint(wynik,10);
			uart_puts("\r\n");
		    ADC_Start();
		    _delay_ms(500);
		}
	}
}
