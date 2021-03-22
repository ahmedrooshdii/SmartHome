/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file       Dio.c
 *         \brief      This file contains DIO program instructions
 *
 *         \details    This file has functions (instructions) which is responsible for configurations by calling the (Dio_ConfigChannel) function,
 *                     write on channels by calling the (Dio_WriteChannel) function, reading from channels by calling the (Dio_ReadChannel) function
 *					   and flipping the status of channels by calling the (Dio_FlipChannel) function
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
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
* \Syntax          : void Dio_ConfigChannel(Dio_PortID portID,Dio_ChannelID channelID,Dio_DirectioType channelDir);
        
* \Description     : This function is responsible for determining the channel direction (INPUT or OUTPUT) of PORTx  
                     by taking three parameters the port (portID) ,its channel (channelID) and the channel direction (channelDir)
					 Example:  Dio_ConfigChannel(DIO_PORTA, DIO_CH_3, OUTPUT);                       
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant    
                                         
* \Parameters (in) : portID        :   Refers to DIO_PORTx
				   : channelID     :   Refers to the port channel (DIO_CH_n)
				   : channelDir    :   Refers to channel direction (INPUT or OUTPUT)
				                         
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
void Dio_ConfigChannel(Dio_PortID portID,Dio_ChannelID channelID,Dio_DirectioType channelDir){
	switch(portID)
	{
		case DIO_PORTA:
			if(channelDir == INPUT)
			{
				CLEAR_BIT(DIO_PORTA_DDR,channelID);	
			}
			else
			{
				SET_BIT(DIO_PORTA_DDR,channelID);	
			}
		break;
		
		case DIO_PORTB:
			if(channelDir == INPUT)
			{
				CLEAR_BIT(DIO_PORTB_DDR,channelID);
			}
			else
			{
				SET_BIT(DIO_PORTB_DDR,channelID);
			}
		break;
		
		case DIO_PORTC:
			if(channelDir == INPUT)
			{
				CLEAR_BIT(DIO_PORTC_DDR,channelID);
			}
			else
			{
				SET_BIT(DIO_PORTC_DDR,channelID);
			}
		break;
		
		case DIO_PORTD:
			if(channelDir == INPUT)
			{
				CLEAR_BIT(DIO_PORTD_DDR,channelID);
			}
			else
			{
				SET_BIT(DIO_PORTD_DDR,channelID);
			}
		break;
	}

}

/******************************************************************************
* \Syntax          : void Dio_WriteChannel(Dio_PortID portID,Dio_ChannelID channelID,Dio_LevelType level);
        
* \Description     : This function is responsible for writing the channel status of PORTx low or high (STD_LOW or STDHIGH)
                     by taking three parameters the port (portID) ,its channel (channelID) and the channel status (level)
					 Example:  Dio_WriteChannel(DIO_PORTC, DIO_CH_2, STD_HIGH);                       
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant    
                                         
* \Parameters (in) : portID        :   Refers to DIO_PORTx
				   : channelID     :   Refers to the port channel (DIO_CH_n)
				   : level         :   Refers to channel status (STD_LOW or STD_HIGH)
				                         
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
void Dio_WriteChannel(Dio_PortID portID,Dio_ChannelID channelID,Dio_LevelType level){
	switch(portID)
	{
		case DIO_PORTA:
			if(level == STD_HIGH)
			{
				SET_BIT(DIO_PORTA_DATA_OUT,channelID);
			}
			else
			{
				CLEAR_BIT(DIO_PORTA_DATA_OUT,channelID);
			}
		break;
		
		case DIO_PORTB:
			if(level == STD_HIGH)
			{
				SET_BIT(DIO_PORTB_DATA_OUT,channelID);
			}
			else
			{
				CLEAR_BIT(DIO_PORTB_DATA_OUT,channelID);
			}
		break;
		
		case DIO_PORTC:
			if(level == STD_HIGH)
			{
				SET_BIT(DIO_PORTC_DATA_OUT,channelID);
			}
			else
			{
				CLEAR_BIT(DIO_PORTC_DATA_OUT,channelID);
			}
		break;
		
		case DIO_PORTD:
			if(level == STD_HIGH)
			{
				SET_BIT(DIO_PORTD_DATA_OUT,channelID);
			}
			else
			{
				CLEAR_BIT(DIO_PORTD_DATA_OUT,channelID);
			}
		break;
	}
}

/******************************************************************************
* \Syntax          : Dio_LevelType Dio_ReadChannel(Dio_PortID portID,Dio_ChannelID channelID);
        
* \Description     : This function is responsible for reading the channel status of PORTx if it is low or high (STD_LOW or STDHIGH)
                     by taking two parameters the port (portID) ,its channel (channelID)
					 Example:  Dio_ReadChannel(DIO_PORTB, DIO_CH_0);                       
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant    
                                         
* \Parameters (in) : portID        :   Refers to DIO_PORTx
				   : channelID     :   Refers to the port channel (DIO_CH_n)
				                         
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/

Dio_LevelType Dio_ReadChannel(Dio_PortID portID,Dio_ChannelID channelID){
	Dio_LevelType state;
	switch(portID)
	{
		case DIO_PORTA:
		if(CHECK_BIT(DIO_PORTA_DATA_IN,channelID))
			{
				state = STD_HIGH;
			}
			else
			{
				state = STD_LOW;
			}
		break;
		
		case DIO_PORTB:
			if(CHECK_BIT(DIO_PORTB_DATA_IN,channelID))
			{
				state = STD_HIGH;
			}
			else
			{
				state = STD_LOW;
			}
		break;
		
		case DIO_PORTC:
			if(CHECK_BIT(DIO_PORTC_DATA_IN,channelID))
			{
				state = STD_HIGH;
			}
			else
			{
				state = STD_LOW;
			}
		break;
		
		case DIO_PORTD:
			if(CHECK_BIT(DIO_PORTD_DATA_IN,channelID))
			{
				state = STD_HIGH;
			}
			else
			{
				state = STD_LOW;
			}
		break;
		
	}
	return state;
}

/******************************************************************************
* \Syntax          : void Dio_FlipOutputChannel(Dio_PortID portID,Dio_ChannelID channelID);
        
* \Description     : This function is responsible for flipping the channel status of PORTx (if it is low (STD_LOW), makes if high (STDHIGH))
                     by taking two parameters the port (portID) ,its channel (channelID)
					 Example:  Dio_ReadChannel(DIO_PORTB, DIO_CH_0);                       
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant    
                                         
* \Parameters (in) : portID        :   Refers to DIO_PORTx
				   : channelID     :   Refers to the port channel (DIO_CH_n)
				                         
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/


void Dio_FlipOutputChannel(Dio_PortID portID,Dio_ChannelID channelID){
	switch(portID)
	{
		case DIO_PORTA:
			FLIP_BIT(DIO_PORTA_DATA_OUT,channelID);
		break;
		
		case DIO_PORTB:
			FLIP_BIT(DIO_PORTB_DATA_OUT,channelID);
		break;
		
		case DIO_PORTC:
			FLIP_BIT(DIO_PORTC_DATA_OUT,channelID);
		break;
		
		case DIO_PORTD:
			FLIP_BIT(DIO_PORTD_DATA_OUT,channelID);
		break;
	}
}
		

void Dio_ConfigChannelGroup(Dio_PortID portID,u8 mask, Dio_DirectioType channedDir){
	switch(portID)
	{
		case DIO_PORTA:
			if(channedDir == OUTPUT)
			{
				DIO_PORTA_DDR |= mask;
			}
			else
			{
				DIO_PORTA_DDR &= ~mask;
			}
		break;
		case DIO_PORTB:
			if(channedDir == OUTPUT)
			{
				DIO_PORTB_DDR |= mask;
			}
			else
			{
				DIO_PORTB_DDR &= ~mask;
			}
		break;
		case DIO_PORTC:
			if(channedDir == OUTPUT)
			{
				DIO_PORTC_DDR |= mask;
			}
			else
			{
				DIO_PORTC_DDR &= ~mask;
			}
		break;
		case DIO_PORTD:
			if(channedDir == OUTPUT)
			{
				DIO_PORTD_DDR |= mask;
			}
			else
			{
				DIO_PORTD_DDR &= ~mask;
			}
		break;
	}
}



void Dio_WriteChannelGroup(Dio_PortID portID,u8 mask,u8 positio,u8 data)
{
	switch(portID)
	{
		case DIO_PORTA:
			DIO_PORTA_DATA_OUT &= ~mask;
			DIO_PORTA_DATA_OUT |= (data<<positio);
		break;
		case DIO_PORTB:
			DIO_PORTB_DATA_OUT &= ~mask;
			DIO_PORTB_DATA_OUT |= (data<<positio);
		break;
		case DIO_PORTC:
			DIO_PORTC_DATA_OUT &= ~mask;
			DIO_PORTC_DATA_OUT |= (data<<positio);
		break;
		case DIO_PORTD:
			DIO_PORTD_DATA_OUT &= ~mask;
			DIO_PORTD_DATA_OUT |= (data<<positio);
		break;
	}
}

/**********************************************************************************************************************
 *  END OF FILE: Dio.c
 *********************************************************************************************************************/
