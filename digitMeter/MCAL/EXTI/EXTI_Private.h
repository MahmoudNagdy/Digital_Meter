#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H

//EXTI Registers
#define EXTI_u8_MCUCR		*((volatile u8 *)0x55)
#define EXTI_u8_MCUCSR		*((volatile u8 *)0x54)
#define EXTI_u8_GICR		*((volatile u8 *)0x5B)
#define EXTI_u8_GIFR		*((volatile u8 *)0x5A)
#define EXTI_u8_SREG		*((volatile u8 *)0x5F)

#define EXTI_u8_ISC00	0
#define EXTI_u8_ISC01	1
#define EXTI_u8_ISC10	2
#define EXTI_u8_ISC11	3
#define EXTI_u8_ISC6			6

#define EXTI_u8_Enable0_Pin		6
#define EXTI_u8_Enable1_Pin		7
#define EXTI_u8_Enable2_Pin		5

#define EXTI_SREG_GIE_PIN		7

#endif
