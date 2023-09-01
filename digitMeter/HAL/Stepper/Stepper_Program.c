#include "../../LIB/STD_TYPES.h";
#include "../../MCAL/DIO/DIO_Interface.h";

#include "Stepper_Config.h";
#include "Stepper_Private.h";

#include<util/delay.h>
#define F_CPU 16000000UL


void Stepper_Init(){
	DIO_u8SetPinDirection(Stepper_1B_PORT, Stepper_1B_PIN, DIO_u8_OUTPUT);
	DIO_u8SetPinDirection(Stepper_2B_PORT, Stepper_2B_PIN, DIO_u8_OUTPUT);
	DIO_u8SetPinDirection(Stepper_3B_PORT, Stepper_3B_PIN, DIO_u8_OUTPUT);
	DIO_u8SetPinDirection(Stepper_4B_PORT, Stepper_4B_PIN, DIO_u8_OUTPUT);
}


void ActivatePins1(u8 Copy_u8_1B_Value, u8 Copy_u8_2B_Value, u8 Copy_u8_3B_Value, u8 Copy_u8_4B_Value){
	DIO_u8SetPinValue(Stepper_1B_PORT, Stepper_1B_PIN, Copy_u8_1B_Value);
	DIO_u8SetPinValue(Stepper_2B_PORT, Stepper_2B_PIN, Copy_u8_2B_Value);
	DIO_u8SetPinValue(Stepper_3B_PORT, Stepper_3B_PIN, Copy_u8_3B_Value);
	DIO_u8SetPinValue(Stepper_4B_PORT, Stepper_4B_PIN, Copy_u8_4B_Value);
}

void ActivatePins2(u8 Copy_u8_1B_Value, u8 Copy_u8_2B_Value, u8 Copy_u8_3B_Value, u8 Copy_u8_4B_Value){
	DIO_u8SetPinValue(Stepper_4B_PORT, Stepper_4B_PIN, Copy_u8_4B_Value);
	DIO_u8SetPinValue(Stepper_3B_PORT, Stepper_3B_PIN, Copy_u8_3B_Value);
	DIO_u8SetPinValue(Stepper_2B_PORT, Stepper_2B_PIN, Copy_u8_2B_Value);
	DIO_u8SetPinValue(Stepper_1B_PORT, Stepper_1B_PIN, Copy_u8_1B_Value);
}


void SelectStepAngle(u16 angle, u8 Direction){
	switch(angle){
		case 90:
			switch(Direction){
				case CW:
					ActivatePins1(DIO_u8_LOW, DIO_u8_LOW, DIO_u8_HIGH, DIO_u8_HIGH);
					break;

				case CCW:
					ActivatePins2(DIO_u8_HIGH, DIO_u8_HIGH, DIO_u8_LOW, DIO_u8_LOW);
					break;
			}
			break;

			case 180:
				switch(Direction){
					case CW:
						ActivatePins2(DIO_u8_LOW, DIO_u8_HIGH, DIO_u8_HIGH, DIO_u8_LOW);
						break;

					case CCW:
						ActivatePins1(DIO_u8_LOW, DIO_u8_HIGH, DIO_u8_HIGH, DIO_u8_LOW);
						break;
				}
				break;
	}
}
