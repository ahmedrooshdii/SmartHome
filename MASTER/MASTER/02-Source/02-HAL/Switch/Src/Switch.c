/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*        \file        Switch.c
 *        \brief       Switches instructions 
 *
 *        \details     This file has functions (instructions) which is responsible for initializing Switches as INPUT by calling the (Switch_Init) function
 *					   and reading the status of Switch by calling the (Switch_Read) function
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Switch.h"
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
* \Syntax          : Dio_LevelType Switch_Read(SWITCH_ID switchID);
        
* \Description     : This function is responsible for reading the switch (switchID) status if it is low or high (STD_LOW or STDHIGH)
                     by taking two parameters (switchID)
					 Example:  Switch_Read(PushB0);                       
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant    
                                         
* \Parameters (in) : switchtID        :   Refers to switches
				                         
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/

Dio_LevelType Switch_Read(SWITCH_ID switchID){
	Dio_LevelType reading;
	switch(switchID)
	{
		case PushB0:
			if(Dio_ReadChannel(SWITCH0_PORT,SWITCH0_CHANNEL))
			{
				reading = STD_HIGH;
			}
			else
			{
				reading = STD_LOW;
			}
		break;
		
		case PushB1:
			if(Dio_ReadChannel(SWITCH1_PORT,SWITCH1_CHANNEL))
			{
				reading = STD_HIGH;
			}
			else
			{
				reading = STD_LOW;
			}
		break;
		
		case PushB2:
			if(Dio_ReadChannel(SWITCH2_PORT,SWITCH2_CHANNEL))
			{
				reading = STD_HIGH;
			}
			else
			{
				reading = STD_LOW;
			}
		break;
	}
	return reading;
} 

/******************************************************************************
* \Syntax          : void Switch_Init(void);
*
* \Description     : This function is responsible for determining the channel direction of Switches as input
*					 Example:  Switch_Init();
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
*
* \Parameters (in) : None
* \Parameters (out): None
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*******************************************************************************/

void Switch_Init(void){
	Dio_ConfigChannel(SWITCH0_PORT,SWITCH0_CHANNEL,INPUT);
	Dio_ConfigChannel(SWITCH1_PORT,SWITCH1_CHANNEL,INPUT);
	Dio_ConfigChannel(SWITCH2_PORT,SWITCH2_CHANNEL,INPUT);
}

/**********************************************************************************************************************
 *  END OF FILE: Switch.c
 *********************************************************************************************************************/
