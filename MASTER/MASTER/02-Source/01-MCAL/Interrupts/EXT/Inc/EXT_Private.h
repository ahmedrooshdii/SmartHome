 /********************************************************************************************************************
 *  File		: EXT_Private.h
 *	Module		: Interrupt
 *	Target		: Atmega32
 *	Author		: Ahmed
 *  Description	: This header file defines names of registers addresses     
 *********************************************************************************************************************/
#ifndef EXT_PRIVATE_H_
#define EXT_PRIVATE_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

#define EXT_SREG               (*(volatile u8*)0x5F)
#define EXT_MCUCR              (*(volatile u8*)0x55)
#define EXT_MCUCSR             (*(volatile u8*)0x54)
#define EXT_GICR			   (*(volatile u8*)0x5B)
#define EXT_GIFR			   (*(volatile u8*)0x5A)
#define INT0_Enable_BIT_NO	   (6u)
#define INT1_Enable_BIT_NO	   (7u)
#define INT2_Enable_BIT_NO	   (5u)
							   
/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

 
#endif  /* EXT_PRIVATE_H_ */

/**********************************************************************************************************************
 *  END OF FILE: EXT_Private.h
 *********************************************************************************************************************/
