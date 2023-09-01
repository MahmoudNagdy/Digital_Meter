#include "../../LIB/ERROR_STATE.h";
#include "../../LIB/BIT_MATH.h";
#include "../../LIB/STD_TYPES.h";
#include "../../MCAL/DIO/DIO_Interface.h";
#include "ADC_Private.h";
#include "ADC_Config.h";

static void (*ADC_PfNotification)(u16) = NULL;

/* ADC Busy Flag */
static u8 ADC_u8BusyFlag = 0;


void ADC_void_Init(void){
	// Select Voltage Referance
	#if ADC_REF_VOLTAGE_MODE == AVCC
	   CLR_BIT(ADC_u8_ADMUX_REG,ADC_ADMUX_REFS1);
	   SET_BIT(ADC_u8_ADMUX_REG,ADC_ADMUX_REFS0);
	   #elif ADC_REF_VOLTAGE_MODE == AREF
	   CLR_BIT(ADC_u8_ADMUX_REG,ADC_ADMUX_REFS1);
	   CLR_BIT(ADC_u8_ADMUX_REG,ADC_ADMUX_REFS0);
	   #elif ADC_REF_VOLTAGE_MODE == INTERNAL_VOLTAGE
	   SET_BIT(ADC_u8_ADMUX_REG,ADC_ADMUX_REFS1);
	   SET_BIT(ADC_u8_ADMUX_REG,ADC_ADMUX_REFS0);
	   #endif

	// Select Presentaion Mode
	#if ADC_PRESENTATION_MODE == Right_Adjust
	   CLR_BIT(ADC_u8_ADMUX_REG, ADC_ADMUX_ADLAR);
   #elif ADC_PRESENTATION_MODE == Left_Adjust
	   SET_BIT(ADC_u8_ADMUX_REG, ADC_ADMUX_ADLAR);
   #endif

	// Disable Auto Trigger
	CLR_BIT(ADC_u8_ADCSRA_REG, ADC_ADCSRA_ADATE);

	// Select Division Factor
	#if DEVISION_FACTOR_MODE == ADC_DIVSION_FACTOR_BY_2
		CLR_BIT(ADC_u8_ADCSRA_REG, ADC_ADPS2);
		CLR_BIT(ADC_u8_ADCSRA_REG, ADC_ADPS1);
		SET_BIT(ADC_u8_ADCSRA_REG, ADC_ADPS0);
   #elif DEVISION_FACTOR_MODE == ADC_DIVSION_FACTOR_BY_4
		CLR_BIT(ADC_u8_ADCSRA_REG, ADC_ADPS2);
		SET_BIT(ADC_u8_ADCSRA_REG, ADC_ADPS1);
		CLR_BIT(ADC_u8_ADCSRA_REG, ADC_ADPS0);
   #elif DEVISION_FACTOR_MODE == ADC_DIVSION_FACTOR_BY_8
		CLR_BIT(ADC_u8_ADCSRA_REG, ADC_ADPS2);
		SET_BIT(ADC_u8_ADCSRA_REG, ADC_ADPS1);
		SET_BIT(ADC_u8_ADCSRA_REG, ADC_ADPS0);
	#elif DEVISION_FACTOR_MODE == ADC_DIVSION_FACTOR_BY_16
		SET_BIT(ADC_u8_ADCSRA_REG, ADC_ADPS2);
		CLR_BIT(ADC_u8_ADCSRA_REG, ADC_ADPS1);
		CLR_BIT(ADC_u8_ADCSRA_REG, ADC_ADPS0);
	#elif DEVISION_FACTOR_MODE == ADC_DIVSION_FACTOR_BY_32
		SET_BIT(ADC_u8_ADCSRA_REG, ADC_ADPS2);
		CLR_BIT(ADC_u8_ADCSRA_REG, ADC_ADPS1);
		SET_BIT(ADC_u8_ADCSRA_REG, ADC_ADPS0);
	#elif DEVISION_FACTOR_MODE == ADC_DIVSION_FACTOR_BY_64
			SET_BIT(ADC_u8_ADCSRA_REG, ADC_ADPS2);
			SET_BIT(ADC_u8_ADCSRA_REG, ADC_ADPS1);
			CLR_BIT(ADC_u8_ADCSRA_REG, ADC_ADPS0);
	#elif DEVISION_FACTOR_MODE == ADC_DIVSION_FACTOR_BY_128
			SET_BIT(ADC_u8_ADCSRA_REG, ADC_ADPS2);
			SET_BIT(ADC_u8_ADCSRA_REG, ADC_ADPS1);
			SET_BIT(ADC_u8_ADCSRA_REG, ADC_ADPS0);
   #endif

	// Enable ADC
	SET_BIT(ADC_u8_ADCSRA_REG, ADC_Enable_PIN);

}



u8 ADC_u8_Get_Digital_ValueSynchNonBlocking(u8 Copy_u8ChannelNumber, u16 *Copy_Pu16DigitalValue){
	u8 Local_u8ErrorState = STD_TYPES_OK;
	u32 Local_u32TimeOutCounter = 0;
	if((Copy_u8ChannelNumber < 32) && (Copy_Pu16DigitalValue != NULL)){

		/* Clear MUX4 */
		ADC_u8_ADMUX_REG &= 0b11100000;
		/* Select Channel */
		ADC_u8_ADMUX_REG |= Copy_u8ChannelNumber;
		/* Start Conversion */
		SET_BIT(ADC_u8_ADCSRA_REG, ADC_ADCSRA_ADSC);
		/* Wait Flag = 1 */
		while((GET_BIT(ADC_u8_ADCSRA_REG, ADC_ADCSRA_ADIF) == 0) && (Local_u32TimeOutCounter < ADC_u32_TIME_OUT_MAX_VALUE)){
			Local_u32TimeOutCounter++;
		}
		if(GET_BIT(ADC_u8_ADCSRA_REG, ADC_ADCSRA_ADIF) != 0){ //(Local_u32TimeOutCounter < ADC_u32_TIME_OUT_MAX_VALUE)
			/* Clear Flag = 1 */
			SET_BIT(ADC_u8_ADCSRA_REG, ADC_ADCSRA_ADIF);
			/* Read Digital Value */
			*Copy_Pu16DigitalValue = ADC_u16_ADC_REG;
		}
		else{
			Local_u8ErrorState = STD_TYPES_NOK;
		}
	}

	else{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	return Local_u8ErrorState;
}



u8 ADC_u8_Get_Digital_ValueAsynch(u8 Copy_u8ChannelNumber, void (*Copy_PFNotification)(u16)){
	u8 Local_u8ErrorState = STD_TYPES_OK;
	if((Copy_u8ChannelNumber < 32) && (Copy_PFNotification != NULL) && (ADC_u8BusyFlag == 0)){
		/* Set Flag To Make ADC Busy */
		ADC_u8BusyFlag = 1;
		/* Update Global Pointer To a Function */
		ADC_PfNotification = Copy_PFNotification;
		/* Enable ADC Interrupt */
		SET_BIT(ADC_u8_ADCSRA_REG, ADC_Interrupt_Enable_PIN);
		/* Clear MUX4 */
		ADC_u8_ADMUX_REG &= 0b11100000;
		/* Select Channel */
		ADC_u8_ADMUX_REG |= Copy_u8ChannelNumber;
		/* Start Conversion */
		SET_BIT(ADC_u8_ADCSRA_REG, ADC_ADCSRA_ADSC);
	}
	else{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	return Local_u8ErrorState;
}

u8 ADC_u8GetADCRegValue(u16 *Copy_u16PADCValue){
	u8 Local_u8ErrorState = STD_TYPES_OK;
	if(Copy_u16PADCValue != NULL){
		/* Read ADC Register */
		Copy_u16PADCValue = ADC_u16_ADC_REG;
	}
	else{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	return Local_u8ErrorState;
}


void __vector_16(void)		__attribute__((signal));

void __vector_16(void){
	if(ADC_PfNotification != NULL){
		ADC_u8BusyFlag = 0;
		CLR_BIT(ADC_u8_ADCSRA_REG, ADC_Interrupt_Enable_PIN);
		ADC_PfNotification(ADC_u16_ADC_REG);
	}
}
