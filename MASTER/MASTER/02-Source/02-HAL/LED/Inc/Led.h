 /********************************************************************************************************************
 *  File		: Led.h
 *	Module		: LED
 *	Target		: General
 *	Author		: Ahmed
 *  Description	: Definitions and prototypes of the LED functions      
 *********************************************************************************************************************/
 
#ifndef LED_H_
#define LED_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

#include "Led_Cfg.h"
#include "Dio.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

typedef enum{
	LED0,
	LED1,
	LED2
	}LED_ID;                                     // Defining the 3 LEDs
	
/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

void Led_TurnON(LED_ID ledID);                   // Turn on LED
void Led_TurnOFF(LED_ID ledID);                  // Turn off LED
void Led_Flip(LED_ID ledID);                     // Flip LED status
void Led_Init(void);                             // Config LED as an output

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
 
#endif  /* LED_H_ */

/**********************************************************************************************************************
 *  END OF FILE: Led.h
 *********************************************************************************************************************/
