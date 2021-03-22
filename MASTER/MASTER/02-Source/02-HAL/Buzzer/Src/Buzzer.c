/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*        \file        Buzzer.c
 *        \brief       Buzzer instructions
 *
 *        \details     This file has functions (instructions) which is responsible for initializing Buzzer as OUTPUT by calling the (Buzzer_Init) function,
 *                     turn on Buzzer by calling the (Buzzer_TurnON) function, turn off Buzzer by calling the (Buzzer_TurnOFF) function
 *					   and flipping the status of Buzzer by calling the (Buzzer_Flip) function
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "Buzzer.h"

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
* \Syntax          : void Buzzer_TurnON(void);
*
* \Description     : This function turns Buzzer on
*					 Example    :    Buzzer_TurnON();
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
*
* \Parameters (in) : None
* \Parameters (out): None
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*******************************************************************************/

void Buzzer_TurnON(void){
	Dio_WriteChannel(BUZZER_PORT,BUZZER_CHANNEL,STD_HIGH);
}

/******************************************************************************
* \Syntax          : void Buzzer_TurnOFF(void);
*
* \Description     : This function turns Buzzer off
*					 Example    :    Buzzer_TurnOFF();
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
*
* \Parameters (in) : None
* \Parameters (out): None
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*******************************************************************************/

void Buzzer_TurnOFF(void){
	Dio_WriteChannel(BUZZER_PORT,BUZZER_CHANNEL,STD_LOW);
}

/******************************************************************************
* \Syntax          : void Buzzer_Flip(void);
*
* \Description     : This function flips Buzzer OFF if it is ON and flips it ON if it is OFF
*					 Example    :    Buzzer_Flip();
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
*
* \Parameters (in) : None
* \Parameters (out): None
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*******************************************************************************/

void Buzzer_Flip(void){
	Dio_FlipOutputChannel(BUZZER_PORT,BUZZER_CHANNEL);
}

/******************************************************************************
* \Syntax          : void Buzzer_Init(void);
*
* \Description     : This function is responsible for determining the channel direction of Buzzer as output 
*					 Example    :    Buzzer_Init();
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
*
* \Parameters (in) : None
* \Parameters (out): None
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*******************************************************************************/

void Buzzer_Init(void){
	Dio_ConfigChannel(BUZZER_PORT,BUZZER_CHANNEL,OUTPUT);
}

/**********************************************************************************************************************
 *  END OF FILE: Buzzer.c
 *********************************************************************************************************************/
