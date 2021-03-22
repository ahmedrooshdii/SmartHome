 /********************************************************************************************************************
 *  File		: UART.h
 *	Module		: UART
 *	Target		: Atmega32
 *	Author		: Ahmed
 *  Description	: Definitions and prototypes of the UART functions      
 *********************************************************************************************************************/
 
#ifndef UART_H_
#define UART_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

#include "UART_Private.h"
#include "Bit_Math.h"
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

#define F_CPU 160000						// Defining frequency oscillator
#define BAUDRATE 96							// Defining baud rate

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

typedef enum {
	UART_NOK,
	UART_OK
	}UART_Status;							// Defining the return status
	
/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

void UART_Init(void);
void UART_Transmit(u8 data);
UART_Status UART_Receive (u8* data);
 
#endif  /* UART_H_ */

/**********************************************************************************************************************
 *  END OF FILE: UART.h
 *********************************************************************************************************************/
