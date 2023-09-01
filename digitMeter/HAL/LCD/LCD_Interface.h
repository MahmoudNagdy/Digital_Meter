/*********************************************************/
/*************** Name 	  : Mahmoud Nagdy 	**************/
/*************** Date 	  : 1/5/2023 		**************/
/*************** SWC  	  : LCD 			**************/
/*************** Version  : 1.0 			**************/
/*********************************************************/

#ifndef LCD_H_
#define LCD_H_
#include "../../LIB/std_types.h"

/* LCD HW Ports and Pins Ids */
#define LCD_RS_PORT_ID 			PORTD_ID
#define LCD_RS_PIN_ID 			PIN4_ID

#define LCD_E_PORT_ID 			PORTD_ID
#define LCD_E_PIN_ID 			PIN5_ID

#define LCD_DATA_PORT_ID 		PORTC_ID

/* LCD Commands */
#define LCD_CLEAR_COMMAND 0x01
#define LCD_GO_TO_HOME 0x02
#define LCD_TWO_LINES_EIGHT_BITS_MODE 0x38
#define LCD_TWO_LINES_FOUR_BITS_MODE 0x28
#define LCD_CURSOR_OFF 0x0C
#define LCD_CURSOR_ON 0x0E
#define LCD_Line0 0x80
#define LCD_Line1 0xC0

#define LCD_CURSOR_OFF 0x0C
#define LCD_CURSOR_ON 0x0E
#define LCD_SET_CURSOR_LOCATION 0x80

#define LCD_ShiftRight 0b00011100
#define LCD_ShiftLeft 0b00011000


#define LOGIC_HIGH        (1u)
#define LOGIC_LOW         (0u)

void LCD_init(void);
void LCD_sendCommand(u8 command);
void LCD_displayCharacter(u8 data);
void LCD_DisplayInteger(u32 num);
void LCD_displayString(const char *str);
void LCD_GoToXY(u8 Copy_u8LineNum, u8 Copy_u8Location);
void LCD_ClearScreen(void);
void LCD_ShiftingLeft(void);
void LCD_ShiftingRight(void);
void LCD_String_xy(char row, char pos, char *str, u8 *count);
void LCD_WriteSpecialChar(u8 Copy_CharNum, u8 *Copy_u8P_Ptr, u8 Copy_u8LineNum, u8 Copy_u8Location, u8 Copy_u8SpecialCharStartBit);
void displayFloatOnLCD(f32 number);
void displayMinusNumbers(f32 number);

#endif /* LCD_H_ */
