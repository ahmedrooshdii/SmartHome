/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*         
 *		   \file       UART.c
 *         \brief      This file contains UART program instructions
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "UART.h"
#include "Dio.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : void UART_Init(void)
* \Description     : This function initializes UART
*					 Example:  UART_Init();
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : None
* \Return value:   : None
*******************************************************************************/

void UART_Init(void)
{
	Dio_ConfigChannel(DIO_PORTD,DIO_CH_0,INPUT);			// Pin for RX defined as input
	Dio_ConfigChannel(DIO_PORTD,DIO_CH_0,OUTPUT);			// Pin for TX defined as output
															  
	UCSRB |= (1 << 4)									    // Enable receiving data
		   | (1 << 3);									    // Enable transmitting data
		  													 
	UCSRC |= (1 << 7)									    // Select UCSRC register
		   | (1 << 2) | (1 << 1);						    // Enable 8-bit mode
															 
	u16 UBRR_Val = ((F_CPU)/(16*BAUDRATE)) - 1;			    // Baud rate calculation
	UBRRL = UBRR_Val;
	UBRRH = UBRR_Val >> 8;
}

 /******************************************************************************
 * \Syntax          : void UART_Transmit(u8 data)
 * \Description     : This function transmit data (passing parameter)
 *					  Example:  UART_Transmit(data);
 *
 * \Sync\Async      : Asynchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : data	:	Refers to transmitting data
 * \Return value:   : None
 *******************************************************************************/

void UART_Transmit(u8 data)
{
	UDR = data;
	while (!(UCSRA & (1 << 6)));
}

 /******************************************************************************
 * \Syntax          : UART_Status UART_Receive (u8* data)
 * \Description     : This function receives data and stores it in the passing address 
 *					  Example:  UART_Receive(&data);
 *
 * \Sync\Async      : Asynchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : &data	:	Refers to address where data will be stored
 * \Return value:   : SPI_Status (SPI_OK)
 *******************************************************************************/

UART_Status UART_Receive (u8* data)
{
	while (!(UCSRA & (1 << 7)));
	*data = UDR; 
	return UART_OK;
}

/**********************************************************************************************************************
 *  END OF FILE: UART.c
 *********************************************************************************************************************/
