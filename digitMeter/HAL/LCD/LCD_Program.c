/*********************************************************/
/*************** Name 	  : Mahmoud Nagdy 	**************/
/*************** Date 	  : 1/5/2023 		**************/
/*************** SWC  	  : LCD 			**************/
/*************** Version  : 1.0 			**************/
/*********************************************************/

#include <util/delay.h>
#include "../../HAL/LCD/LCD_Interface.h"

#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/Dio_Interface.h"

void LCD_sendCommand(u8 command)
{

	LCD_setPinValue(LCD_RS_PORT_ID, LCD_RS_PIN_ID, LOGIC_LOW);
	_delay_ms(1);
	LCD_setPinValue(LCD_E_PORT_ID, LCD_E_PIN_ID, LOGIC_HIGH);
	_delay_ms(1);
	LCD_setPortValue(LCD_DATA_PORT_ID, command);
	_delay_ms(1);
	LCD_setPinValue(LCD_E_PORT_ID, LCD_E_PIN_ID, LOGIC_LOW);
	_delay_ms(1);
}

void LCD_displayCharacter(u8 data)
{
	LCD_setPinValue(LCD_RS_PORT_ID, LCD_RS_PIN_ID, LOGIC_HIGH);
	_delay_ms(1);
	LCD_setPinValue(LCD_E_PORT_ID, LCD_E_PIN_ID, LOGIC_HIGH);
	_delay_ms(1);
	LCD_setPortValue(LCD_DATA_PORT_ID, data);
	_delay_ms(1);
	LCD_setPinValue(LCD_E_PORT_ID, LCD_E_PIN_ID, LOGIC_LOW);
	_delay_ms(1);
}

void LCD_DisplayInteger(u32 num) {

    // Convert the number to a string
    u8 buffer[16];
    u8 i = 0;
    u8 isNegative = 0;

    if (num < 0) {
        isNegative = 1;
        num = -num;
    }

    do {
        buffer[i++] = (char)(num % 10) + '0';
        num /= 10;
    } while (num > 0);

    if (isNegative) {
        buffer[i++] = '-';
    }

    // Reverse the string
    u8 j;
    for (j = 0; j < i / 2; j++) {
        char temp = buffer[j];
        buffer[j] = buffer[i - j - 1];
        buffer[i - j - 1] = temp;
    }

    // Null-terminate the string
    buffer[i] = '\0';

    // Write the string to LCD
    LCD_displayString(buffer);
}


void LCD_init(void)
{
	LCD_setPinDirection(LCD_RS_PORT_ID, LCD_RS_PIN_ID, PIN_OUTPUT);
	LCD_setPinDirection(LCD_E_PORT_ID, LCD_E_PIN_ID, PIN_OUTPUT);
	LCD_setPortDirection(LCD_DATA_PORT_ID, PORT_OUTPUT);

	_delay_ms(20);

	LCD_sendCommand(LCD_TWO_LINES_EIGHT_BITS_MODE);
	LCD_sendCommand(LCD_CURSOR_OFF);
	LCD_sendCommand(LCD_CLEAR_COMMAND);
}

void LCD_GoToXY(u8 Copy_u8LineNum, u8 Copy_u8Location)
{
	if (Copy_u8LineNum <= 39)
	{
		switch (Copy_u8LineNum)
		{
		case 0:
			LCD_sendCommand(LCD_Line0 + Copy_u8Location);

			break;
		case 1:
			LCD_sendCommand(LCD_Line1 + Copy_u8Location);
			break;
		}
	}
}

void LCD_displayString(const char *str)
{
	u8 i = 0;
	while (str[i] != '\0')
	{
		LCD_displayCharacter(str[i]);
		i++;
	}
}

void LCD_String_xy(char row, char pos, char *str, u8 *count) /* Send string to LCD with xy position */
{
	u8 i = 0, c = 1;
	if (row == 0 && pos < 16)
		LCD_sendCommand((pos & 0x0F) | 0x80); /* Command of first row and required position<16 */
	else if (row == 1 && pos < 16)
		LCD_sendCommand((pos & 0x0F) | 0xC0); /* Command of first row and required position<16 */

	while (str[i] != '\0')
	{
		LCD_displayCharacter(str[i]);
		i++;

		if (row == 0 && pos > 2 && i == 11)
		{
			LCD_GoToXY(1, 0);
			c++;
		}

		else if (row == 1 && pos > 2 && i == 11)
		{
			LCD_ClearScreen();
		}

		*count = c;
	}
}

void LCD_ClearScreen(void)
{
	LCD_sendCommand(0x01);
	_delay_ms(2);
}

void LCD_ShiftingLeft(void)
{
	LCD_sendCommand(LCD_ShiftLeft);
	_delay_ms(20);
}

void LCD_ShiftingRight(void)
{
	LCD_sendCommand(LCD_ShiftRight);
	_delay_ms(20);
}

void LCD_WriteSpecialChar(u8 Copy_CharNum, u8 *Copy_u8P_Ptr, u8 Copy_u8LineNum, u8 Copy_u8Location, u8 Copy_u8SpecialCharStartBit)
{
	LCD_sendCommand(Copy_u8SpecialCharStartBit);
	for (int i = 0; i < 8; i++)
	{
		LCD_displayCharacter(Copy_u8P_Ptr[i]);
	}
	LCD_GoToXY(Copy_u8LineNum, Copy_u8Location);
	LCD_displayCharacter(Copy_CharNum);

	if (Copy_u8Location > 15)
	{
		LCD_ClearScreen();
		LCD_GoToXY(0, 0);
		LCD_displayCharacter(Copy_CharNum);
	}
}



void displayFloatOnLCD(f32 number) {
    int integerPart = (int)number;
    int decimalPart = (number - integerPart) * 1000;
    if(integerPart >= 100){
    	integerPart /= 10;
    }
    LCD_DisplayInteger(integerPart);
    LCD_displayCharacter('.');
    LCD_DisplayInteger(decimalPart);
    
}

void displayMinusNumbers(f32 number) {
	
	LCD_displayCharacter('-');
	number = -number;
	LCD_DisplayInteger(number);   
}
