/*
 * LCD.h
 *
 *  Created on: Nov 21, 2021
 *      Author: Ahmed Nasser
 */

#ifndef HAL_LCD_LCD_H_
#define HAL_LCD_LCD_H_

/******************************************************************************
*									INCLUDES				                  *
*******************************************************************************/

#include "LCD_config.h"

/******************************************************************************
*									MACROS				                      *
*******************************************************************************/

#if (MODE == 8)
#define EIGHT_BIT_MODE
#define Data_shift 0
#endif

#if (MODE == 4)
#define FOUR_BIT_MODE
#define Data_shift 4
#endif

#define LCD_FIRST_LINE				(0)
#define LCD_SECOND_LINE				(1)

/******************************************************************************
*									COMMANDS				                  *
*******************************************************************************/

#define LCD_CLEAR_SCREEN			(0x01)
#define LCD_RETURN_HOME				(0x02)
#define LCD_ENTRY_DEC				(0x04)
#define LCD_ENTRY_DEC_SHIFT			(0x05)
#define LCD_ENTRY_MODE				(0x06)
#define LCD_ENTRY_INC				(0x06)
#define LCD_ENTRY_INC_SHIFT			(0x07)
#define LCD_DISP_OFF				(0x08)
#define LCD_DISP_ON					(0x0C)
#define LCD_DISP_ON_BLINK			(0x0D)
#define LCD_DISP_ON_CURSOR			(0x0E)
#define LCD_DISP_ON_CURSOR_BLINK	(0x0F)
#define LCD_MOVE_CURSOR_LEFT		(0x10)
#define LCD_MOVE_CURSOR_RIGHT		(0x14)
#define LCD_MOVE_DISP_LEFT			(0x18)
#define LCD_MOVE_DISP_RIGHT			(0x1C)
#define LCD_FUNCTION_4BIT_1LINE		(0x20)
#define LCD_FUNCTION_4BIT_2LINES	(0x28)
#define LCD_FUNCTION_8BIT_1LINE	    (0x30)
#define LCD_FUNCTION_8BIT_2LINES	(0x38)
#define LCD_BEGIN_AT_FIRST_ROW		(0x80)
#define LCD_BEGIN_AT_SECOND_ROW		(0xC0)


/******************************************************************************
*									APIS				                      *
*******************************************************************************/
/**======================================================================
 * @Function 	 :	-LCD_Init
 * @brief   	 :	-Initializes LCD
 	 	 	 	 	 	 configure LCD_PORT and LCD_CTRL_PORT
 	 	 	 	 	 	 Send Commands to setup the working Mode (4bit_mode or 8bit_mode)
 	 	 	 	 	 	 send Commands to setup Cursor settings
 * @parameter[in]:  -None
 * @return value :	-None
 * Note 		 :	-
 */
void LCD_Init(void);

/**======================================================================
 * @Function 	 :	-LCD_Isbusy
 * @brief   	 :	-Make sure that LCD is not busy in any another process
 * @parameter[in]:  -None
 * @return value :	-None
 * Note 		 :	-
 */
void LCD_Isbusy(void);
/**======================================================================
 * @Function 	 :	-LCD_Kick
 * @brief   	 :	-disable EN pin to give LCD time to perform current command then enable it
 * 						-disable enable pin
 * 						-wait
 * 						-enable enable pin
 * @parameter[in]:  -None
 * @return value :	-None
 * Note 		 :	-
 */
void LCD_Kick(void);

/**======================================================================
 * @Function 	 :	-LCD_CMD
 * @brief   	 :	-Send given Command to LCD
 * @parameter[in]:  -Command (one of the above commands)
 * @return value :	-None
 * Note 		 :	-
 */
void LCD_CMD(unsigned char cmd);

/**======================================================================
 * @Function 	 :	-LCD_Send_char
 * @brief   	 :	-Send given Character to LCD and Display it on LCD
 * @parameter[in]:  -Character
 * @return value :	-None
 * Note 		 :	-
 */
void LCD_Send_char(unsigned char ch);

/**======================================================================
 * @Function 	 :	-LCD_Send_str
 * @brief   	 :	-Send given String to LCD and Display it on LCD
 * @parameter[in]:  -str: pointer to first character in the string
 * @return value :	-None
 * Note 		 :	-
 */
void LCD_Send_str(char* str);

/**======================================================================
 * @Function 	 :	-LCD_Clear_Screen
 * @brief   	 :	-Clear the Screen
 * @parameter[in]:  -None
 * @return value :	-None
 * Note 		 :	-
 */
void LCD_Clear_Screen(void);

/**======================================================================
 * @Function 	 :	-LCD_GotoXY
 * @brief   	 :	-Move the Cursor to the given position-X_axis-(1st parameter) and given Line(2nd parameter )
 * @parameter[in]:  -pos : position of cursor on x_axis it's options (From 0 To 15)
 * @parameter[in]:  -line : position of cursor on y_axis it's options (0 OR 1)
 * @return value :	-None
 * Note 		 :	-
 */
void LCD_GotoXY(unsigned char pos , unsigned char line);

/**======================================================================
 * @Function 	 :	-LCD_Send_Num
 * @brief   	 :	-Send given Integer Number to LCD and Display it on LCD
 * @parameter[in]:  -num : from type integer which need to display
 * @return value :	-None
 * Note 		 :	-
 */
void LCD_Send_Num(int num);

/**======================================================================
 * @Function 	 :	-LCD_Send_RealNum
 * @brief   	 :	-Send given Double Number to LCD and Display it on LCD
 * @parameter[in]:  -num : from type double which need to display
 * @return value :	-None
 * Note 		 :	-
 */
void LCD_Send_RealNum(double num);



#endif /* HAL_LCD_LCD_H_ */

