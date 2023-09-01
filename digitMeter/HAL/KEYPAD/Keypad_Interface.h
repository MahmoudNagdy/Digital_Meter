#ifndef KEYPAD_INTERFACE_H
#define KEYPAD_INTERFACE_H

#include "../../LIB/STD_TYPES.h"

#define KPD_UnPressed				0xFF

void KPD_voidInit(void);
u8 KPD_u8GetKeyState(u8 *Copy_pu8ReturnedKey);

#endif
