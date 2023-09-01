#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#include "../../LIB/std_types.h"

#define NUM_OF_PORTS           4
#define NUM_OF_PINS_PER_PORT   8

#define PORTA_ID               0
#define PORTB_ID               1
#define PORTC_ID               2
#define PORTD_ID               3

#define PIN0_ID                0
#define PIN1_ID                1
#define PIN2_ID                2
#define PIN3_ID                3
#define PIN4_ID                4
#define PIN5_ID                5
#define PIN6_ID                6
#define PIN7_ID                7

/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/
typedef enum
{
	PIN_INPUT,PIN_OUTPUT
}LCD_PinDirectionType;

typedef enum
{
	PORT_INPUT,PORT_OUTPUT=0xFF
}LCD_PortDirectionType;

#define LOGIC_HIGH        (1u)
#define LOGIC_LOW         (0u)

void LCD_setPinDirection(u8 port_num, u8 pin_num, LCD_PinDirectionType direction);

void LCD_setPinValue(u8 port_num, u8 pin_num, u8 value);

u8 LCD_getPinValue(u8 port_num, u8 pin_num);

void LCD_setPortDirection(u8 port_num, u8 direction);

void LCD_setPortValue(u8 port_num, u8 value);

u8 LCD_getPortValue(u8 port_num);

#endif /* DIO_INTERFACE_H_ */
