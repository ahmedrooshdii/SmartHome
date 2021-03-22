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

#include "ADC.h"


#define F_CPU 16000000
#include <util/delay.h>
#include "Lcd.h"
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
void ADC_Vref(Vref reference)
{
	switch(reference)
	{
		case AREF:
			ADC_MUX |= 0x00;
		break;
		case AVCC:
			ADC_MUX |= 0x40;
		break;
		case INTERNAL:
			ADC_MUX |= 0xC0;
		break;
	}
}


Adjust_Type adjustType(Adjust_Type adjust)
{
	switch(adjust)
	{
		case RIGHT:
			CLEAR_BIT(ADC_MUX,BIT_5);
			return Status = RIGHT;
		break;
		case LEFT:
			SET_BIT(ADC_MUX,BIT_5);
			return Status = LEFT;
		break;
	}
}


void prescalerSelect(Prescaler_ID divisionFactor)
{
	switch(divisionFactor)
	{
		case Pre_2:
			ADC_SRA |= 0x01;
		break;																	  
		case Pre_4:	
			ADC_SRA |= 0x02;																  
		break;											 
		case Pre_8:	
			ADC_SRA |= 0x03;										 
		break;											 
		case Pre_16:
			ADC_SRA |= 0x04;										 
		break;											 
		case Pre_32:
			ADC_SRA |= 0x05;										 
		break;
		case Pre_64:
			ADC_SRA |= 0x06;
		break;										   
		case Pre_128:	
			ADC_SRA |= 0x07;								   
		break;
	}
}


void ADC_Init(Vref reference,Adjust_Type adjust,u8 divisionFactor)
{
	/*--------- ADC Enable --------*/
	SET_BIT(ADC_SRA,BIT_7);
	
	ADC_Vref(reference);
	adjustType(adjust);
	prescalerSelect(divisionFactor);
		
}


u16 ADC_Read(ADC_ChannelID channelID)
{
	switch(channelID)
	{
		case ADC0:
		ADC_MUX |= 0x00;
		break;
		
		case ADC1:
		ADC_MUX |= 0x01;
		break;
		
		case ADC2:
		ADC_MUX |= 0x02;
		break;
		
		case ADC3:
		ADC_MUX |= 0x03;
		break;
		
		case ADC4:
		ADC_MUX |= 0x04;
		break;
		
		case ADC5:
		ADC_MUX |= 0x05;
		break;
		
		case ADC6:
		ADC_MUX |= 0x06;
		break;
		
		case ADC7:
		ADC_MUX |= 0x07;
		break;
	}
	
	volatile u16 result = 0;
	
	/*----- Start of conversion signal - (SOC) -----*/
	SET_BIT(ADC_SRA,BIT_6); 
	
	/*----- Wait till flag of end of conversion signal - (EOC) set automatically -----*/
	while(ADC_SRA & (1 << BIT_4)){}
		
	switch(Status)
	{
		case RIGHT:
			result = ADC_DATA;
		break;
		
		case LEFT:
		result = ADC_DATA >> 6 ;
		break;
	}
	
	return result;
}

/**********************************************************************************************************************
 *  END OF FILE: ADC.c
 *********************************************************************************************************************/
