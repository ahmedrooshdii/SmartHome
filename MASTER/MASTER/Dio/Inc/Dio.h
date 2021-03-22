 /********************************************************************************************************************
 *  File		: Dio.h
 *	Module		: DIO
 *	Target		: Atmega32
 *	Author		: Ahmed
 *  Description	: This header file contains definitions and prototypes of the DIO functions     
 *********************************************************************************************************************/
 
#ifndef DIO_H_
#define DIO_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

#include "Std_Types.h"       
#include "Bit_Math.h"
#include "Dio_Private.h"

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
	DIO_CH_0,
	DIO_CH_1,
	DIO_CH_2,
	DIO_CH_3,
	DIO_CH_4,
	DIO_CH_5,
	DIO_CH_6,
	DIO_CH_7
	}Dio_ChannelID;                                 // Defining the 8-Channels of PORTx

typedef enum{
	DIO_PORTA,
	DIO_PORTB,
	DIO_PORTC,
	DIO_PORTD
	}Dio_PortID;                                    // Defining the 4 Ports
	
typedef enum{
	STD_LOW,
	STD_HIGH
	}Dio_LevelType;                                 // Defining the status of Bits
	
typedef enum{
	INPUT,
	OUTPUT
	}Dio_DirectioType;                              // Defining the directions 
	
/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

void Dio_ConfigChannel(Dio_PortID portID,Dio_ChannelID channelID,Dio_DirectioType channelDir);     // Config channel 
void Dio_WriteChannel(Dio_PortID portID,Dio_ChannelID channelID,Dio_LevelType level);              // Write channel
Dio_LevelType Dio_ReadChannel(Dio_PortID portID,Dio_ChannelID channelID);                          // Read channel
void Dio_FlipOutputChannel(Dio_PortID portID,Dio_ChannelID channelID);                             // Flip channel
void Dio_ConfigChannelGroup(Dio_PortID portID,u8 mask, Dio_DirectioType channedDir);
void Dio_WriteChannelGroup(Dio_PortID portID,u8 mask,u8 positio,u8 data);

         
#endif  /* DIO_H_ */

/**********************************************************************************************************************
 *  END OF FILE: Dio.h
 *********************************************************************************************************************/
