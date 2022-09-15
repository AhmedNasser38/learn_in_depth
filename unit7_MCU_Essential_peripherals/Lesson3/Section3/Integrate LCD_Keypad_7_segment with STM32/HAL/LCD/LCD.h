/*
 * LCD.h
 *
 * Created: 11/3/2021 10:47:40 AM
 *  Author: Ahmed Nasser
 */ 


#ifndef LCD_H_
#define LCD_H_

//-----------------------------
//Includes
//-----------------------------
#include <stdio.h>
#include "../stm32f103c6_Drivers/Inc/stm32f103c6.h"
#include "../stm32f103c6_Drivers/Inc/stm32f103c6_GPIO_Driver.h"





// configuration section
#define LCD_PORT GPIOA  //enter the port you connect d0:d7
#define LCD_CTRL_PORT GPIOA  // enter the port you connect RS , RW , EN

//#define MODE 8   // 8 >> 8bit_mode or 4 >> 4bit mode

#define LCD_D0			 GPIO_PIN_0
#define LCD_D1			 GPIO_PIN_1
#define LCD_D2			 GPIO_PIN_2
#define LCD_D3			 GPIO_PIN_3
#define LCD_D4			 GPIO_PIN_4
#define LCD_D5			 GPIO_PIN_5
#define LCD_D6			 GPIO_PIN_6
#define LCD_D7			 GPIO_PIN_7

#define RS				 GPIO_PIN_8
#define RW				 GPIO_PIN_9
#define EN				 GPIO_PIN_10


// END configuration section


//#if (MODE == 8)
//#define EIGHT_BIT_MODE
//#define Data_shift 0
//#endif
//
//#if (MODE == 4)
//#define FOUR_BIT_MODE
//#define Data_shift 4
//#endif
//

#define LCD_REG_Select_PIN			(0)
#define LCD_READ_WRITE_PIN			(1)
#define LCD_ENABLE_PIN				(2)

#define LCD_REG_Select_ENABLE		(1)
#define LCD_REG_Select_DISABLE		(0)

#define LCD_READ					(1)
#define LCD_WRITE					(0)

#define LCD_ENABLE					(1)
#define LCD_DISABLE					(0)

#define LCD_FIRST_LINE				(0)  
#define LCD_SECOND_LINE				(1)

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


// CG_RAM
#define Custom_Char1_Address        (0x40)
#define Custom_Char2_Address        (0x48)
#define Custom_Char3_Address        (0x50)
#define Custom_Char4_Address        (0x58)
#define Custom_Char5_Address        (0x60)
#define Custom_Char6_Address        (0x68)
#define Custom_Char7_Address        (0x70)
#define Custom_Char8_Address        (0x78)

#define DISP_Custom_Char1           (0)
#define DISP_Custom_Char2           (1)
#define DISP_Custom_Char3           (2)
#define DISP_Custom_Char4           (3)
#define DISP_Custom_Char5           (4)
#define DISP_Custom_Char6           (5)
#define DISP_Custom_Char7           (6)
#define DISP_Custom_Char8           (7)





//-----------------------------
//Delay Function (May be updated)
//-----------------------------

void Delay_ms(uint32_t milles);

//-----------------------------
//		LCD APIs
//-----------------------------

//void LCD_SetUp(DIO_PIN_ID D0 ,DIO_PIN_ID D1 , DIO_PIN_ID D2 , DIO_PIN_ID D3 , DIO_PIN_ID RS ,DIO_PIN_ID RW ,DIO_PIN_ID EN);//need to be written
void HAL_LCD_Init(void);
void HAL_LCD_Isbusy(void);
void HAL_LCD_Kick(void);
void HAL_LCD_CMD(unsigned char cmd);
void HAL_LCD_Send_char(unsigned char ch);
void HAL_LCD_Send_str(char* str);
void HAL_LCD_Clear_Screen(void);
void HAL_LCD_GotoXY(unsigned char pos , unsigned char line);
void HAL_LCD_Send_Num(int num);
void HAL_LCD_Send_RealNum(double num);

#endif /* LCD_H_ */
