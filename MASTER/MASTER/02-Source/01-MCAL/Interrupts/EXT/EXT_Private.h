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


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

#define EXT_REG               (*(volatile u8*)0x5F)
#define EXT_MCUCR             (*(volatile u8*)0x55)
#define EXT_MCUCSR            (*(volatile u8*)0x54)
#define EXT_GICR			  (*(volatile u8*)0x5B)
#define EXT_GIFR			  (*(volatile u8*)0x5A)

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
