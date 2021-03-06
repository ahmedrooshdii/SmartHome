 /********************************************************************************************************************
 *  File		: EXT.h
 *	Module		: Interrupt
 *	Target		: Atmega32
 *	Author		: Ahmed
 *  Description	: DIO configurations       
 *********************************************************************************************************************/
#ifndef ADC_H_
#define ADC_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "ADC_Private.h"
#include "ADC_Cfg.h"
#include "Std_Types.h"
#include "Bit_Math.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define	BIT_0	0
#define	BIT_1	1
#define	BIT_2	2
#define	BIT_3	3
#define	BIT_4	4
#define	BIT_5	5
#define	BIT_6	6
#define	BIT_7	7

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum {
	ADC0,
	ADC1,
	ADC2,
	ADC3,
	ADC4,
	ADC5,
	ADC6,
	ADC7
	}ADC_ChannelID;
	
typedef enum {
	Pre_2   = 2,
	Pre_4   = 4,
	Pre_8   = 8,
	Pre_16  = 16,
	Pre_32  = 32,
	Pre_64  = 64,
	Pre_128 = 128
	}Prescaler_ID;

typedef enum {
	AVCC,
	AREF,
	INTERNAL
	}Vref;
	
typedef enum {
	RIGHT,
	LEFT
	}Adjust_Type;
	
static Adjust_Type Status = RIGHT;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void ADC_Vref(Vref reference);
Adjust_Type adjustType(Adjust_Type adjust);
void prescalerSelect(u8 divisionFactor);
void ADC_Init(Vref reference,Adjust_Type adjust,u8 divisionFactor);
u16 ADC_Read(ADC_ChannelID channelID); 
#endif  /* EXT_H_ */

/**********************************************************************************************************************
 *  END OF FILE: EXT.h
 *********************************************************************************************************************/
