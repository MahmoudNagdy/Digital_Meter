#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/DIO/DIO_Interface.h"

#include "DC_Motor_Config.h"
#include "DC_Motor_Private.h"

u8 DC_Motor_Init(u8 Copy_u8_Motor1, u8 Copy_u8_Motor2){
	u8 Local_u8_Error_State = State_OK;

	if(Copy_u8_Motor1 == MOTOR_Connected){
		DIO_u8SetPinDirection(MOTOR_EN1_PORT, MOTOR_EN1_PIN, DIO_u8_OUTPUT);
		DIO_u8SetPinDirection(MOTOR_IN1_PORT, MOTOR_IN1_PIN, DIO_u8_OUTPUT);
		DIO_u8SetPinDirection(MOTOR_IN2_PORT, MOTOR_IN2_PIN, DIO_u8_OUTPUT);
	}

	if(Copy_u8_Motor2 == MOTOR_Connected){
		DIO_u8SetPinDirection(MOTOR_EN2_PORT, MOTOR_EN2_PIN, DIO_u8_OUTPUT);
		DIO_u8SetPinDirection(MOTOR_IN3_PORT, MOTOR_IN3_PIN, DIO_u8_OUTPUT);
		DIO_u8SetPinDirection(MOTOR_IN4_PORT, MOTOR_IN4_PIN, DIO_u8_OUTPUT);
	}

	else{
		Local_u8_Error_State = State_NOT_OK;
	}
	return Local_u8_Error_State;
}


u8 DC_Motor_Rotate(u8 Copy_u8_Motor, u8 Copy_u8_Motor_Dirction){
	u8 Local_u8_Error_State = State_OK;

	switch(Copy_u8_Motor){
		case Motor1:
			switch(Copy_u8_Motor_Dirction){
				case ClockWise:
					DIO_u8SetPinValue(MOTOR_EN1_PORT ,MOTOR_EN1_PIN, DIO_u8_HIGH);
					DIO_u8SetPinValue(MOTOR_IN1_PORT ,MOTOR_IN1_PIN, DIO_u8_HIGH);
					DIO_u8SetPinValue(MOTOR_IN2_PORT ,MOTOR_IN2_PIN, DIO_u8_LOW);
					break;

				case CounterClockWise:
					DIO_u8SetPinValue(MOTOR_EN1_PORT ,MOTOR_EN1_PIN, DIO_u8_HIGH);
					DIO_u8SetPinValue(MOTOR_IN1_PORT ,MOTOR_IN1_PIN, DIO_u8_LOW);
					DIO_u8SetPinValue(MOTOR_IN2_PORT ,MOTOR_IN2_PIN, DIO_u8_HIGH);
					break;

				default:
					Local_u8_Error_State = State_NOT_OK;
					break;
			}
			break;

		case Motor2:
			switch(Copy_u8_Motor_Dirction){
				case ClockWise:
					DIO_u8SetPinValue(MOTOR_EN2_PORT ,MOTOR_EN2_PIN, DIO_u8_HIGH);
					DIO_u8SetPinValue(MOTOR_IN3_PORT ,MOTOR_IN3_PIN, DIO_u8_HIGH);
					DIO_u8SetPinValue(MOTOR_IN4_PORT ,MOTOR_IN4_PIN, DIO_u8_LOW);
					break;

				case CounterClockWise:
					DIO_u8SetPinValue(MOTOR_EN2_PORT ,MOTOR_EN2_PIN, DIO_u8_HIGH);
					DIO_u8SetPinValue(MOTOR_IN3_PORT ,MOTOR_IN3_PIN, DIO_u8_LOW);
					DIO_u8SetPinValue(MOTOR_IN4_PORT ,MOTOR_IN4_PIN, DIO_u8_HIGH);
					break;

				default:
					Local_u8_Error_State = State_NOT_OK;
					break;
			}
			break;

		default:
			Local_u8_Error_State = State_NOT_OK;
			break;
	}

	return Local_u8_Error_State;
}


u8 DC_Motor_Stop(u8 Copy_u8_Motor){
	u8 Local_u8_Error_State = State_OK;

	if(Copy_u8_Motor == Motor1){
		DIO_u8SetPinValue(MOTOR_EN1_PORT ,MOTOR_EN1_PIN, DIO_u8_LOW);
	}

	else if(Copy_u8_Motor == Motor2){
		DIO_u8SetPinValue(MOTOR_EN2_PORT ,MOTOR_EN2_PIN, DIO_u8_LOW);
	}

	else{
		Local_u8_Error_State = State_NOT_OK;
	}
	return Local_u8_Error_State;
}
