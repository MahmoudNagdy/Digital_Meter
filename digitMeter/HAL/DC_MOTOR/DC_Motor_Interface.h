#ifndef DC_MOTOR_INTERFACE_H
#define DC_MOTOR_INTERFACE_H

#include "../../LIB/STD_TYPES.h";

#define ClockWise	1
#define CounterClockWise	0
#define Motor1		0
#define Motor2		1



u8 DC_Motor_Init(u8 Copy_u8_Motor1, u8 Copy_u8_Motor2);

u8 DC_Motor_Rotate(u8 Copy_u8_Motor, u8 Copy_u8_Motor_Dirction);

u8 DC_Motor_Stop(u8 Copy_u8_Motor);


#endif
