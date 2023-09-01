#ifndef UART_INTERFACE_H
#define UART_INTERFACE_H

#include "../../LIB/STD_TYPES.h"

#define UART_NewLine			'\n\r'

void UART_Init(void);

void UART_Send1ByteData(u8 Copy_u8Sended1ByteData);
void UART_SendString(u8 *Copy_u8SendedString);
void UART_DisplayNumber(u32 num);
void UART_displayFloat(f32 number);

u8 UART_u8Recieve1ByteData(u8 *Copy_Pu8RecievedByteData);
u8 UART_u8RecieveString(u8 *Copy_Pu8RecievedString, u8 Copy_u8StringSize);

#endif
