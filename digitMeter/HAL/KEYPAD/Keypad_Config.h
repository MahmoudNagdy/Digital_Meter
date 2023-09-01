#ifndef KEYPAD_CONFIG_H
#define KEYPAD_CONFIG_H

/* Macros For PORTS*/

#define DIO_u8_PORTA 				0
#define DIO_u8_PORTB 				1
#define DIO_u8_PORTC 				2
#define DIO_u8_PORTD 				3

/* Macros For PINS*/
#define DIO_u8_PIN0					0
#define DIO_u8_PIN1 				1
#define DIO_u8_PIN2 				2
#define DIO_u8_PIN3 				3
#define DIO_u8_PIN4 				4
#define DIO_u8_PIN5 				5
#define DIO_u8_PIN6 				6
#define DIO_u8_PIN7 				7

/* Macros For Pin Direction*/
#define DIO_u8_OUTPUT 			1
#define DIO_u8_INPUT 			0

/* Macros For Pin Value*/
#define DIO_u8_OUTPUT_HIGH 							1
#define DIO_u8_OUTPUT_LOW 							0
#define DIO_u8_HIGH 								1
#define DIO_u8_LOW 									0
#define DIO_u8_INPUT_FLOATING						0
#define DIO_u8_INPUT_PULLUP 						1


/******************** KPD Macros *******************/


#define KPD_Key						 {{'7', '8', '9', '/'},   \
									 {'4', '5', '6', '*'},   \
									 {'1', '2', '3', '-'},   \
									 {'C', '0', '=', '+'}}




#define KPD_PORT					DIO_u8_PORTA

#define KPD_R1_PIN					DIO_u8_PIN0
#define KPD_R2_PIN					DIO_u8_PIN1
#define KPD_R3_PIN					DIO_u8_PIN2
#define KPD_R4_PIN					DIO_u8_PIN3



#define KPD_C1_PIN					DIO_u8_PIN4
#define KPD_C2_PIN					DIO_u8_PIN5
#define KPD_C3_PIN					DIO_u8_PIN6
#define KPD_C4_PIN					DIO_u8_PIN7

#define KPD_UnPressed				0xFF


#endif
