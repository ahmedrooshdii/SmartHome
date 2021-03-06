/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*        \file        Led.c
 *        \brief       LEDs instructions
 *
 *        \details     This file has functions (instructions) which is responsible for initializing LEDs as OUTPUT by calling the (Led_Init) function,
 *                     turn on LEDx by calling the (Led_TurnON) function, turn off LEDx by calling the (Led_TurnOFF) function
 *					   and flipping the status of LEDx by calling the (Led_Flip) function
 *
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
* \Syntax          : void Led_TurnON(LED_ID ledID);
*
* \Description     : This function turns LED on by taking one parameter (ledID) and turns it on
*					 Example    :    Led_TurnON(LED0);                                  
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant      
*                                       
* \Parameters (in) : ledID  :   Refers to LEDx
*                   
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
void UART_Init(void)
{
	Dio_ConfigChannel(DIO_PORTD,DIO_CH_0,INPUT);	 /*Pin for Rx defined as input*/
	Dio_ConfigChannel(DIO_PORTD,DIO_CH_0,OUTPUT);	 /*Pin for Tx defined as output*/
		
	UCSRB |= (1 << 4)							 /*Enable receiving data*/
		   | (1 << 3);							 /*Enable transmitting data*/
		  
	UCSRC |= (1 << 7)							 /*Select UCSRC register*/
		   | (1 << 2) | (1 << 1);            /*Enable 8-bit mode*/
	
	u16 UBRR_Val = ((F_CPU)/(16*BAUDRATE)) - 1;      /*Baud rate calculation*/
	UBRRL = UBRR_Val;
	UBRRH = UBRR_Val >> 8;
}
void UART_Transmit(u8 data)
{
	UDR = data;
	while (!(UCSRA & (1 << 6)));
}
UART_Status UART_Recive (u8* data)
{
	while (!(UCSRA & (1 << 7)));
	*data = UDR; 
	return UART_OK;
}

/**********************************************************************************************************************
 *  END OF FILE: Led.c
 *********************************************************************************************************************/
