/*********************************************************/
/*************** Name 	  : Mahmoud Nagdy 	**************/
/*************** Date 	  : 27/4/2023 		**************/
/*************** SWC  	  : DIO 			**************/
/*************** Version  : 1.0 			**************/
/*********************************************************/

#include "../../LIB/STD_TYPES.h"

#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H

/* Macros For PORTS*/

#define DIO_u8_PORTA 0
#define DIO_u8_PORTB 1
#define DIO_u8_PORTC 2
#define DIO_u8_PORTD 3

/* Macros For PINS*/
#define DIO_u8_PIN0	0
#define DIO_u8_PIN1 1
#define DIO_u8_PIN2 2
#define DIO_u8_PIN3 3
#define DIO_u8_PIN4 4
#define DIO_u8_PIN5 5
#define DIO_u8_PIN6 6
#define DIO_u8_PIN7 7

/* Macros For Pin Direction*/
#define DIO_u8_OUTPUT 			1
#define DIO_u8_INPUT 			0

/* Macros For Pin Value*/

#define DIO_u8_HIGH 								1
#define DIO_u8_LOW 									0


#define NUM_OF_PORTS 			4
#define NUM_OF_PINS_PER_PORT 	8

#define PORTA_ID 				0
#define PORTB_ID 				1
#define PORTC_ID 				2
#define PORTD_ID 				3

#define PIN0_ID 				0
#define PIN1_ID 				1
#define PIN2_ID 				2
#define PIN3_ID 				3
#define PIN4_ID 				4
#define PIN5_ID 				5
#define PIN6_ID 				6
#define PIN7_ID 				7

typedef enum
{
	PIN_INPUT,
	PIN_OUTPUT
} LCD_PinDirectionType;

typedef enum
{
	PORT_INPUT,
	PORT_OUTPUT = 0xFF
} LCD_PortDirectionType;

void DIO_voidInit(void);

u8 DIO_u8SetPinDirection(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8PinDirection);

u8 DIO_u8SetPinValue(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8PinValue);

u8 DIO_u8GetPinValue(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 *Copy_pu8ReturnedPinValue);

u8 DIO_getPinValueWithoutPointer(u8 port_num, u8 pin_num);

u8 DIO_u8SetPortDirection(u8 Copy_u8PortId, u8 Copy_u8PortDirection);

u8 DIO_u8SetPortValue(u8 Copy_u8PortId, u8 Copy_u8PortValue);

u8 DIO_u8GetPortValue(u8 Copy_u8PortId, u8 *Copy_pu8ReturnedPortValue);

u8 DIO_u8SetValueToAllPins(u8 Copy_u8PortId, u8 Copy_u8Pin0, u8 Copy_u8Pin1, u8 Copy_u8Pin2, u8 Copy_u8Pin3, u8 Copy_u8Pin4, u8 Copy_u8Pin5, u8 Copy_u8Pin6, u8 Copy_u8Pin7);

#endif
