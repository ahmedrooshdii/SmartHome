/*
 * MASTER.c
 *
 * Created: 3/1/2021 8:32:57 AM
 * Author : ahmed
 */ 

#define F_CPU 16000000
#include <avr/io.h>
#include <avr/delay.h>
#include "UART.h"
#include "SPI.h"
#include "Lcd.h"

int main(void)
{
	//Lcd_Init();
	UART_Init();
	SPI_Init(MASTER);
	
	u8 data = 0 ;

    while (1) 
    {
		
		if(UART_Receive(&data))
		{
			
			PORTB |= ~(1 << 4);
			SPI_Transmit(data);	
			
		}
		
    }
}

