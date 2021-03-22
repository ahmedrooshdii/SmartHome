 /********************************************************************************************************************
 *  File		: Lcd_Cfg.h
 *	Module		: LCD
 *	Target		: General
 *	Author		: Ahmed
 *  Description	: Definitions and prototypes of the LCD functions      
 *********************************************************************************************************************/
 
#ifndef LCD_CFG_H_
#define LCD_CFG_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

#define LCD_CMD_PORT            DIO_PORTB
#define LCD_DATA_PORT           DIO_PORTA

#define LCD_RS_PORT			    DIO_PORTB
#define LCD_RS_CHANNEL			DIO_CH_1

#define LCD_RW_PORT			    DIO_PORTB
#define LCD_RW_CHANNEL			DIO_CH_2

#define LCD_EN_PORT			    DIO_PORTB
#define LCD_EN_CHANNEL			DIO_CH_3

#define LCD_DATA_GROUP_POS		(4)
#define LCD_MASK				(0xF0)

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
 
#endif  /* LCD_CFG_H_ */

/**********************************************************************************************************************
 *  END OF FILE: Led_Cfg.h
 *********************************************************************************************************************/
