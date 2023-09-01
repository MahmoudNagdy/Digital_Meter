#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/ERROR_STATE.h"

#include "../../MCAL/DIO/DIO_Interface.h"
#include<util/delay.h>

#include "../KEYPAD/Keypad_Config.h"
#define F_CPU 16000000UL

/* KPD Arrays */

const u8 KPD_Au8Keys[4][4] = KPD_Key;

const u8 KPD_Au8RowsPins[4] = {KPD_R1_PIN, KPD_R2_PIN, KPD_R3_PIN, KPD_R4_PIN};
const u8 KPD_Au8ColsPins[4] = {KPD_C1_PIN, KPD_C2_PIN, KPD_C3_PIN, KPD_C4_PIN};

/******************************************************************************************/

void KPD_voidInit(void){
	for(int i = 0; i <= 3; i++){
		/* Rows */
		DIO_u8SetPinDirection(KPD_PORT, KPD_Au8RowsPins[i], DIO_u8_OUTPUT);
		DIO_u8SetPinValue(KPD_PORT, KPD_Au8RowsPins[i], DIO_u8_OUTPUT_HIGH);
		
		/* Cols */
		DIO_u8SetPinDirection(KPD_PORT, KPD_Au8ColsPins[i], DIO_u8_INPUT);
		DIO_u8SetPinValue(KPD_PORT, KPD_Au8ColsPins[i], DIO_u8_INPUT_PULLUP);
	}
}



u8 KPD_u8GetKeyState(u8 *Copy_pu8ReturnedKey){
	
	u8 Local_u8ErrorState = STD_TYPES_OK;
	u8 Local_u8RowsCounter, Local_u8ColsCounter, Local_u8PinValue, Local_u8Flag = 0;
	
	if(Copy_pu8ReturnedKey != NULL){
		*Copy_pu8ReturnedKey = KPD_UnPressed;
		for(Local_u8RowsCounter = 0; Local_u8RowsCounter <= 3; Local_u8RowsCounter++){
			/* Activate Each Row */
			DIO_u8SetPinValue(KPD_PORT, KPD_Au8RowsPins[Local_u8RowsCounter], DIO_u8_LOW);
			/* Check which pin is zero */
			for(Local_u8ColsCounter = 0; Local_u8ColsCounter <= 3; Local_u8ColsCounter++){
				DIO_u8GetPinValue(KPD_PORT, KPD_Au8ColsPins[Local_u8ColsCounter], &Local_u8PinValue);
				if(Local_u8PinValue == DIO_u8_LOW){ // Switch Is Pressed
					/* Debouncing */
					_delay_ms(20);
					DIO_u8GetPinValue(KPD_PORT, KPD_Au8ColsPins[Local_u8ColsCounter], &Local_u8PinValue);
					/* Check If the Pin Equal Low */
					while(Local_u8PinValue == DIO_u8_LOW){
						DIO_u8GetPinValue(KPD_PORT, KPD_Au8ColsPins[Local_u8ColsCounter], &Local_u8PinValue);
					}
					
					*Copy_pu8ReturnedKey = KPD_Au8Keys[Local_u8RowsCounter][Local_u8ColsCounter];
					Local_u8Flag = 1;
					break;
				}
			}
			/* Deactivate Row */
			DIO_u8SetPinValue(KPD_PORT, KPD_Au8RowsPins[Local_u8RowsCounter], DIO_u8_HIGH);
			if(Local_u8Flag){
				break;
			}
		}
	}
	else{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	
	return Local_u8ErrorState;
}
