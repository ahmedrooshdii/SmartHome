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

#include "EXT.h"


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

void Global_INT_Enable(void)
{
	SET_BIT(EXT_SREG,7);
}

void Global_INT_Disable(void)
{
	CLEAR_BIT(EXT_SREG,7);
}

void EXT_INT0_Init(INT_TriggerType trigger)
{
	
	SET_BIT(EXT_GICR,INT0_Enable_BIT_NO);
	Global_INT_Enable();
	
	switch(trigger)
	{
		case LOW_LEVEL:
			EXT_MCUCR |= 0x00;
		break;
		case ANY_LOGICAL_CHANGE:
			EXT_MCUCR |= 0x01;
		break;
		case FALLING_EDGE:
			EXT_MCUCR |= 0x02;
		break;
		case RISING_EDGE:
			EXT_MCUCR |= 0x03;
		break;
	}
	
}

void EXT_INT1_Init(INT_TriggerType trigger)
{
	Global_INT_Enable();
	SET_BIT(EXT_GICR,INT1_Enable_BIT_NO);
	
	switch(trigger)
	{
		case LOW_LEVEL:
			EXT_MCUCR |= 0x00;
		break;
		case ANY_LOGICAL_CHANGE:
			EXT_MCUCR |= 0x04;
		break;
		case FALLING_EDGE:
			EXT_MCUCR |= 0x08;
		break;
		case RISING_EDGE:
			EXT_MCUCR |= 0x0C;
		break;
	}
}

void EXT_INT2_Init(INT_TriggerType trigger)
{
	Global_INT_Enable();
	SET_BIT(EXT_GICR,INT2_Enable_BIT_NO);
	
	switch(trigger)
	{
		case FALLING_EDGE:
			CLEAR_BIT(EXT_MCUCSR,6);
		break;
		case RISING_EDGE:
			SET_BIT(EXT_MCUCSR,6);
		break;
	}
}
/**********************************************************************************************************************
 *  END OF FILE: EXT.c
 *********************************************************************************************************************/
