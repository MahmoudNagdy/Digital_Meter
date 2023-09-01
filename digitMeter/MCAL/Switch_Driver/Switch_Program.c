#include "../../LIB/STD_TYPES.h";
#include "../../MCAL/DIO/DIO_Interface.h";
#include "Switch_Private.h";
#include "Switch_Config.h";


void Switch_Init(Switch * Arr, u8 Switchf_Num){

	for(int i = 0; i < Switchf_Num; i++){
		DIO_u8SetPinDirection(Arr[i].Switch_Port, Arr[i].Switch_Pin, DIO_u8_INPUT);
		DIO_u8SetPinValue(Arr[i].Switch_Port, Arr[i].Switch_Pin, Arr[i].Switch_State);
	}

}


void Switch_GetValue(Switch *Arr ,u8 *ptr_Value){
	DIO_u8GetPinValue(Arr->Switch_Port, Arr->Switch_Pin, ptr_Value);
}
