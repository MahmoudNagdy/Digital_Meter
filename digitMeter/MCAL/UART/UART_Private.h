#ifndef UART_PRIVATE_H
#define UART_PRIVATE_H
	
#define UART_u8_UBRRH_REG					*((volatile u8*)0x40)
#define UART_u8_UCSRC_REG					*((volatile u8*)0x40)

#define UART_u8_UDR_REG						*((volatile u8*)0x2C)
#define UART_u8_UCSRA_REG					*((volatile u8*)0x2B)
#define UART_u8_UCSRB_REG					*((volatile u8*)0x2A)

#define UART_u8_UBRRL_REG					*((volatile u8*)0x29)




/***************************************************************/

// UCSRA PINS

#define UART_MPCM_PIN						0
#define UART_U2X_PIN						1
#define UART_UDRE_PIN						5
#define UART_RXC_PIN						7

// UCSRB PINS

#define UART_UCSZ2_PIN						2
#define UART_TXEN_PIN						3
#define UART_RXEN_PIN						4


// UCSRC PINS

#define UART_UCSZ0							1
#define UART_UCSZ1							2
#define UART_UMSEL							6

#define UART_USBS							3
#define UART_UPM0							4
#define UART_UPM1							5


#endif
