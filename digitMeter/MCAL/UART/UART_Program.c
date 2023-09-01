#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/ERROR_STATE.h"

#include "UART_Config.h"
#include "UART_Private.h"


void UART_Init(void){
	
	/* This Variable To Put 1 In Bit 7 & Select Asynch Mode  */
	u8 Local_u8UCSRCValue = 0x80;
	
	/* Variable To Select Boud Rate */
	u16 Local_u16BoudRate = 103;
	
	/* Select Normal Speed Mode */
	#if Speed_Mode == Normal_Speed
	CLR_BIT(UART_u8_UCSRA_REG, UART_U2X_PIN);
	#elif Speed_Mode == Double_Speed
	SET_BIT(UART_u8_UCSRA_REG, UART_U2X_PIN);
	#endif
	
	/* Disable MPCM */
	CLR_BIT(UART_u8_UCSRA_REG, UART_MPCM_PIN);
	
	/* 8 Bit Data */
	#if BitData_Mode == Five_Data
	CLR_BIT(UART_u8_UCSRB_REG, UART_UCSZ2_PIN);
	CLR_BIT(Local_u8UCSRCValue, UART_UCSZ0);
	CLR_BIT(Local_u8UCSRCValue, UART_UCSZ1);
	
	#elif BitData_Mode == Six_Data
	CLR_BIT(UART_u8_UCSRB_REG, UART_UCSZ2_PIN);
	SET_BIT(Local_u8UCSRCValue, UART_UCSZ0);
	CLR_BIT(Local_u8UCSRCValue, UART_UCSZ1);
	
	#elif BitData_Mode == Seven_Data
	CLR_BIT(UART_u8_UCSRB_REG, UART_UCSZ2_PIN);
	CLR_BIT(Local_u8UCSRCValue, UART_UCSZ0);
	SET_BIT(Local_u8UCSRCValue, UART_UCSZ1);
	
	#elif BitData_Mode == Eight_Data
	CLR_BIT(UART_u8_UCSRB_REG, UART_UCSZ2_PIN);
	SET_BIT(Local_u8UCSRCValue, UART_UCSZ0);
	SET_BIT(Local_u8UCSRCValue, UART_UCSZ1);
	
	#elif BitData_Mode == Nine_Data
	SET_BIT(UART_u8_UCSRB_REG, UART_UCSZ2_PIN);
	SET_BIT(Local_u8UCSRCValue, UART_UCSZ0);
	SET_BIT(Local_u8UCSRCValue, UART_UCSZ1);
	#endif
	
	/* Operation Mode (Asynch / Synch) */
	#if Operation_Mode == ASynch
	CLR_BIT(Local_u8UCSRCValue, UART_UMSEL);
	#elif Operation_Mode == Synch
	SET_BIT(Local_u8UCSRCValue, UART_UMSEL);
	#endif
	
	/* Select Parity Mode (None / Even / Odd) */
	#if Parity_Mode == None
	CLR_BIT(Local_u8UCSRCValue, UART_UPM0);
	CLR_BIT(Local_u8UCSRCValue, UART_UPM1);
	#elif Parity_Mode == Even
	CLR_BIT(Local_u8UCSRCValue, UART_UPM0);
	SET_BIT(Local_u8UCSRCValue, UART_UPM1);
	#elif Parity_Mode == Odd
	SET_BIT(Local_u8UCSRCValue, UART_UPM0);
	SET_BIT(Local_u8UCSRCValue, UART_UPM1);
	#endif
	
	/*  Stop Bits Mode ( 1 / 2) */
	#if StopBits_Mode == One_Bit
	CLR_BIT(Local_u8UCSRCValue, UART_USBS);
	#elif StopBits_Mode == Two_Bits
	SET_BIT(Local_u8UCSRCValue, UART_USBS);
	#endif
	
	/* Update UCSRC Reg Value  */
	UART_u8_UCSRC_REG = Local_u8UCSRCValue;
	
	/* Boud Rate => 9600 */
	UART_u8_UBRRL_REG = (u8)Local_u16BoudRate;
	UART_u8_UBRRH_REG = (u8)(Local_u16BoudRate >> 8);
	
	/* Enable Tx & Rx */
	SET_BIT(UART_u8_UCSRB_REG, UART_TXEN_PIN);
	SET_BIT(UART_u8_UCSRB_REG, UART_RXEN_PIN);
	
}

void UART_Send1ByteData(u8 Copy_u8Sended1ByteData){
	/* UDRE Pin Should be 1 (empty) to be able to write date in it */
	while(!GET_BIT(UART_u8_UCSRA_REG, UART_UDRE_PIN));
	
	/* Send 1 Byte Data */
	UART_u8_UDR_REG = Copy_u8Sended1ByteData;
	
}

void UART_SendString(u8 *Copy_u8SendedString){
	u8 i = 0;
	while(Copy_u8SendedString[i] !=  '\0'){
		UART_Send1ByteData(Copy_u8SendedString[i]);
		i++;
	}
}

void UART_DisplayNumber(u32 num){

    // Convert the number to a string
    u8 buffer[16];
    u8 i = 0;
    u8 isNegative = 0;

    if (num < 0) {
        isNegative = 1;
        num = -num;
    }

    do {
        buffer[i++] = (char)(num % 10) + '0';
        num /= 10;
    } while (num > 0);

    if (isNegative) {
        buffer[i++] = '-';
    }

    // Reverse the string
    u8 j;
    for (j = 0; j < i / 2; j++) {
        char temp = buffer[j];
        buffer[j] = buffer[i - j - 1];
        buffer[i - j - 1] = temp;
    }

    // Null-terminate the string
    buffer[i] = '\0';

    // Write the string to LCD
    UART_SendString(buffer);
}

void UART_displayFloat(f32 number) {
    int integerPart = (int)number;
    int decimalPart = (number - integerPart) * 1000;
    if(integerPart >= 100){
    	integerPart /= 10;
    }
    UART_DisplayNumber(integerPart);
    UART_Send1ByteData('.');
    UART_DisplayNumber(decimalPart);
}

u8 UART_u8Recieve1ByteData(u8 *Copy_Pu8RecievedByteData){
	u8 Local_u8ErrorState = STD_TYPES_OK;
	
	if(Copy_Pu8RecievedByteData != NULL){
		while(!GET_BIT(UART_u8_UCSRA_REG, UART_RXC_PIN));
		*Copy_Pu8RecievedByteData = UART_u8_UDR_REG;
	}
	
	else{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	
	return Local_u8ErrorState;
}


u8 UART_u8RecieveString(u8 *Copy_Pu8RecievedString, u8 Copy_u8StringSize){
	u8 Local_u8ErrorState = STD_TYPES_OK;
	u8 i = 0;
	
	if(Copy_Pu8RecievedString != NULL){
		while(i < Copy_u8StringSize){
			while(!GET_BIT(UART_u8_UCSRA_REG, UART_RXC_PIN));
			Copy_Pu8RecievedString[i] = UART_u8_UDR_REG;
			i++;
		}
		Copy_Pu8RecievedString[i] = '\0';
	}
	
	else{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	
	return Local_u8ErrorState;
}
