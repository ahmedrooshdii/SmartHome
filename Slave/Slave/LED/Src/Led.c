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

#include "Led.h"

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

void Led_TurnON(LED_ID ledID){
	switch(ledID)
	{
		case LED0:
			Dio_WriteChannel(LED0_PORT,LED0_CHANNEL,STD_HIGH);
		break;
		
		case LED1:
			Dio_WriteChannel(LED1_PORT,LED1_CHANNEL,STD_HIGH);
		break;
		
		case LED2:
			Dio_WriteChannel(LED2_PORT,LED2_CHANNEL,STD_HIGH);
		break;
	}	
}

/******************************************************************************
* \Syntax          : void Led_TurnOFF(LED_ID ledID);
*
* \Description     : This function turns LED off by taking one parameter (ledID) and turns it off
*					 Example    :    Led_TurnOFF(LED0);
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

void Led_TurnOFF(LED_ID ledID){
	switch(ledID)
	{
		case LED0:
			Dio_WriteChannel(LED0_PORT,LED0_CHANNEL,STD_LOW);
		break;
		
		case LED1:
			Dio_WriteChannel(LED1_PORT,LED1_CHANNEL,STD_LOW);
		break;
		
		case LED2:
			Dio_WriteChannel(LED2_PORT,LED2_CHANNEL,STD_LOW);
		break;
	}
}

/******************************************************************************
* \Syntax          : void Led_Flip(LED_ID ledID);
*
* \Description     : This function flips LED OFF if it is ON and flips it ON if it is OFF by taking one parameter (ledID) and flips it
*					 Example    :    Led_Flip(LED0);
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

void Led_Flip(LED_ID ledID){
	switch(ledID)
	{
		case LED0:
			Dio_FlipOutputChannel(LED0_PORT,LED0_CHANNEL);
		break;
		
		case LED1:
			Dio_FlipOutputChannel(LED1_PORT,LED1_CHANNEL);
		break;
		
		case LED2:
			Dio_FlipOutputChannel(LED2_PORT,LED2_CHANNEL);
		break;
	}
}

/******************************************************************************
* \Syntax          : void Led_Init(void);
*        
* \Description     : This function is responsible for determining the channel direction of LEDs as output 
*					 Example:  Led_Init();                       
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant    
*                                         
* \Parameters (in) : None
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/

void Led_Init(void){
	Dio_ConfigChannel(LED0_PORT,LED0_CHANNEL,OUTPUT);
	Dio_ConfigChannel(LED1_PORT,LED1_CHANNEL,OUTPUT);
	Dio_ConfigChannel(LED2_PORT,LED2_CHANNEL,OUTPUT);
}

/**********************************************************************************************************************
 *  END OF FILE: Led.c
 *********************************************************************************************************************/
