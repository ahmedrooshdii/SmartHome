/*
 * Slave.c
 *
 * Created: 3/1/2021 8:45:24 AM
 * Author : ahmed
 */ 

#include <avr/io.h>
#include "Std_Types.h"
#include "Led.h"
#include "SPI.h"

int main(void)
{
	SPI_Init(SLAVE);
	Led_Init();
	
	u8 data = 0;
	
    while (1) 
    {
		if(SPI_Receive(&data))
		{
			switch(data)
			{
				case '1':
					Led_TurnON(LED0);
				break;
				case '2':
					Led_TurnON(LED1);
				break;
				case '3':
					Led_TurnON(LED2);
				break;
				case '4':
					Led_TurnOFF(LED0);
					Led_TurnOFF(LED1);
					Led_TurnOFF(LED2);
				break;
			}
		}
		//_delay_ms(250);
		
    }
}

