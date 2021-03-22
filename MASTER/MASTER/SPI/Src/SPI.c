/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*         
 *		  \file       SPI.c
 *         \brief      This file contains SPI program instructions
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "SPI.h"
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
* \Syntax          : void SPI_Init(SPI_Mode mode)
* \Description     : This function initializes SPI mode (MASTER or SLAVE) by taking one parameter (mode)
*					 Example:  void SPI_Init(MASTER);
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : mode	:		Refers to SPI mode
* \Return value:   : None
*******************************************************************************/

 void SPI_Init(SPI_Mode mode)
 {
	switch(mode)
	{
		case MASTER:											// SPI mode is master ( Send data )
		
			Dio_ConfigChannel(SPI_PORT,MOZI,OUTPUT);			// Config MOZI channel as output
			Dio_ConfigChannel(SPI_PORT,MIZO,INPUT);				// Config MIZO channel as input
			Dio_ConfigChannel(SPI_PORT,SCK,OUTPUT);				// Config SCK channel as output
			Dio_ConfigChannel(SPI_PORT,SS,OUTPUT);				// Config SS channel as output
			SPI_CR |= 0x53;
			
		break;
		
		case SLAVE :											// SPI mode is slave ( Receiving data )
		
			Dio_ConfigChannel(SPI_PORT,MOZI,INPUT);				// Config MOZI channel as input
			Dio_ConfigChannel(SPI_PORT,MIZO,OUTPUT);			// Config MIZO channel as output
			Dio_ConfigChannel(SPI_PORT,SCK,INPUT);				// Config SCK channel as input
			Dio_ConfigChannel(SPI_PORT,SS,INPUT);				// Config SS channel as input
			SPI_CR |= 0x43;
			
		break;
	} 
 }
 
 /******************************************************************************
 * \Syntax          : void SPI_Transmit(u8 data)
 * \Description     : This function transmit data (passing parameter)
 *					  Example:  SPI_Transmit(data);
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : data	:	Refers to transmitting data
 * \Return value:   : None
 *******************************************************************************/
 
 void SPI_Transmit(u8 data)
 {
	 SPI_DR = data;												// Writing data which will be send in data register
	 while (!(SPI_SR & (1 << 7)));								// Waiting for the SPIF Flag to be set
 }
 
 /******************************************************************************
 * \Syntax          : SPI_Status SPI_Receive(u8* data)
 * \Description     : This function receives data and stores it in the passing address 
 *					  Example:  SPI_Receive(&data);
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : &data	:	Refers to address where data will be stored
 * \Return value:   : SPI_Status (SPI_OK)
 *******************************************************************************/
 
 
 SPI_Status SPI_Receive(u8* data)
 {
	 while (!(SPI_SR & (1 << 7)));								// Writing data which will be send in data register
	 *data = SPI_DR;											// Waiting for the SPIF Flag to be set
	 return SPI_OK;												// Return SPI_OK (1)
 }

/**********************************************************************************************************************
 *  END OF FILE: SPI.c
 *********************************************************************************************************************/
