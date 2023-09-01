#ifndef SWITCH_CONFIG_H
#define SWITCH_CONFIG_H

#include "../../MCAL/DIO/DIO_Interface.h";
#include "Switch_Private.h";

#define SWITCH_PORT		DIO_u8_PORTD
#define SWITCH_PIN		DIO_u8_PIN2
#define SWITCH_STATE	SWITCH_PULL_UP

#define Switch_Num		1

typedef struct{
	u8 Switch_Port;
	u8 Switch_Pin;
	u8 Switch_State;
}Switch;


#endif
