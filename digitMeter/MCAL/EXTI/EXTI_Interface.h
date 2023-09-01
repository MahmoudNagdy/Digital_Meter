#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

#include "../../MCAL/DIO/DIO_Interface.h";

#define EXTI_u8_SREG		*((volatile u8 *)0x5F)
#define EXTI_SREG_GIE_PIN		7

#define EXTI_u8_ISC00			0
#define EXTI_u8_ISC01			1
#define EXTI_u8_ISC10			2
#define EXTI_u8_ISC11			3
#define EXTI_u8_ISC6			6

#define EXTI_u8_INT0_PORT		DIO_u8_PORTD
#define EXTI_u8_INT0_PIN		DIO_u8_PIN2

#define EXTI_u8_INT1_PORT		DIO_u8_PORTD
#define EXTI_u8_INT1_PIN		DIO_u8_PIN3

#define EXTI_u8_Enable0_Pin		6
#define EXTI_u8_Enable1_Pin		7
#define EXTI_u8_Enable2_Pin		5

#define EXTI_INT0_VectorNum		1
#define EXTI_INT1_VectorNum		2
#define EXTI_INT2_VectorNum		3

#define EXTI_INT0									0
#define EXTI_INT1									1
#define EXTI_INT2									2


/* EXTI Modes */
#define Low_Level_Mode								0
#define Falling_Mode								1
#define Any_Logical_Change_Mode						2
#define Rising_Mode									3



void EXTI_voidEXTI0Enable(void);
void EXTI_voidEXTI1Enable(void);
void EXTI_voidINTDisable(u8 Copy_u8_INT_Index);
void EXTI_INTEnable(u8 Copy_u8INTNumber, u8 Copy_u8INTMode);


void setCallBack(void(*ptf)(void), u8 EXTI_Index);

#endif
