 /**********************************************************************************************************************
 *  File		: Lcd.c
 *	Module		: LCD
 *	Target		: General
 *	Author		: Ahmed
 *  Description	:      
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
* \Syntax          : void Button_Init(void)
* \Description     : Describe this service
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : None
* \Return value:   : None
*******************************************************************************/
 void SPI_Init(SPI_Mode mode)
 {
	switch(mode)
	{
		case MASTER:
		
			Dio_ConfigChannel(SPI_PORT,MOZI,OUTPUT);
			Dio_ConfigChannel(SPI_PORT,MIZO,INPUT);
			Dio_ConfigChannel(SPI_PORT,SCK,OUTPUT);
			Dio_ConfigChannel(SPI_PORT,SS,OUTPUT);
			SPI_CR |= 0x53;
			
		break;
		
		case SLAVE :
		
			Dio_ConfigChannel(SPI_PORT,MOZI,INPUT);
			Dio_ConfigChannel(SPI_PORT,MIZO,OUTPUT);
			Dio_ConfigChannel(SPI_PORT,SCK,INPUT);
			Dio_ConfigChannel(SPI_PORT,SS,INPUT);
			SPI_CR |= 0x43;
			
		break;
	} 
 }
 
 void SPI_Transmit(u8 data)
 {
	 SPI_DR = data;
	 while (!(SPI_SR & (1 << 7)));
 }
 
 SPI_Status SPI_Recive(u8* data)
 {
	 while (!(SPI_SR & (1 << 7)));
	 *data = SPI_DR;
	 return SPI_OK;
 }

/**********************************************************************************************************************
 *  END OF FILE: Lcd.c
 *********************************************************************************************************************/
