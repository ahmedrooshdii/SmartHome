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
u8 customChar[] = {
	0x04,
	0x1F,
	0x11,
	0x11,
	0x1F,
	0x1F,
	0x1F,
	0x1F
};
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
static void enablePulse(void)
{
	Dio_WriteChannel(LCD_EN_PORT,LCD_EN_CHANNEL,STD_HIGH);
	_delay_us(1);	
	Dio_WriteChannel(LCD_EN_PORT,LCD_EN_CHANNEL,STD_LOW);
	_delay_ms(2);
}


static void Lcd_Write(u8 data)
{
	u8 MSB_Nibble = data >> LCD_DATA_GROUP_POS;
	u8 LSB_Nibble = data;
	
	Dio_WriteChannelGroup(LCD_DATA_PORT,LCD_MASK,LCD_DATA_GROUP_POS,MSB_Nibble);
	enablePulse();
	Dio_WriteChannelGroup(LCD_DATA_PORT,LCD_MASK,LCD_DATA_GROUP_POS,LSB_Nibble);
	enablePulse();
}

void Lcd_Cmd(LcdCmdType cmd)
{
	Dio_WriteChannel(LCD_RS_PORT,LCD_RS_CHANNEL,STD_LOW);   /*   write mode    */
	Dio_WriteChannel(LCD_RW_PORT,LCD_RW_CHANNEL,STD_LOW);   /*   cmd mode      */
	Lcd_Write(cmd);
}

void Lcd_DisplayChr(u8 data)
{
	Dio_WriteChannel(LCD_RS_PORT,LCD_RS_CHANNEL,STD_HIGH);   /*   write mode    */
	Dio_WriteChannel(LCD_RW_PORT,LCD_RW_CHANNEL,STD_LOW);   /*   data mode      */
	Lcd_Write(data);
}


void Lcd_DisplayStr(u8 *str)
{
	while (*str != '\0')
	{
		Lcd_DisplayChr(*str);
		str++;
	}
}

void Lcd_GotoRowColumn(u8 row, u8 column)
{
	u8 firstCharAdr[] = {0x80,0xC0};
	Lcd_Cmd(firstCharAdr[row-1]+(column-1));
	
}



void Lcd_WriteCustomChr(void)
{
	u8 indx;
	Lcd_Cmd(0x40);

	for (indx =0;	indx<8;	indx++)
	{
		Lcd_DisplayChr(customChar[indx]);
	}
}


void Lcd_WriteNumber(u32 number)
{
	u8 num[10];
	ltoa(number,(u8*)num,10);
	Lcd_DisplayStr(num);
}


void Lcd_Init(void)
{
	Dio_ConfigChannel(LCD_RS_PORT,LCD_RS_CHANNEL,OUTPUT);
	Dio_ConfigChannel(LCD_RW_PORT,LCD_RW_CHANNEL,OUTPUT);
	Dio_ConfigChannel(LCD_EN_PORT,LCD_EN_CHANNEL,OUTPUT);
	Dio_ConfigChannelGroup(LCD_DATA_PORT,LCD_MASK,OUTPUT);

	/*initialize LCD*/
	_delay_ms(15);
	Lcd_Cmd(0x33);
	_delay_ms(100);
	Lcd_Cmd(0x32);
	_delay_ms(100);
	Lcd_Cmd(_LCD_4BIT_MODE);
	Lcd_Cmd(_LCD_CLEAR);
	
}

/*
void Lcd_Clear(void)
{
	Lcd_WriteCommand(0x01); 
}*/
/**********************************************************************************************************************
 *  END OF FILE: Lcd.c
 *********************************************************************************************************************/
