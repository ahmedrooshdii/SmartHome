 /********************************************************************************************************************
 *  File		: SPI.h
 *	Module		: SPI
 *	Target		: General
 *	Author		: Ahmed
 *  Description	:     
 *********************************************************************************************************************/
 
#ifndef SPI_H_
#define SPI_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "SPI_Cfg.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
typedef enum {
	MASTER,
	SLAVE
	}SPI_Mode;

typedef enum {
	SPI_NOK,
	SPI_OK
	}SPI_Status;
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
 void SPI_Init(SPI_Mode mode);
 void SPI_Transmit(u8 data);
 SPI_Status SPI_Recive(u8* data);
 
#endif  /* SPI_H_ */

/**********************************************************************************************************************
 *  END OF FILE: SPI.h
 *********************************************************************************************************************/
