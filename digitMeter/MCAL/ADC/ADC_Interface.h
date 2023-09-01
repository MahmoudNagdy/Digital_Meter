#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H

#include "../../LIB/STD_TYPES.h";

#define ADC_ADMUX_REFS1		7
#define ADC_ADMUX_REFS0		6
#define ADC_ADMUX_ADLAR		5

#define ADC_ADCSRA_ADATE	5

#define ADC_ADPS2				2
#define ADC_ADPS1				1
#define ADC_ADPS0				0

#define ADC_Enable_PIN			7

#define ADC_Channel_0			0
#define ADC_Channel_1			1
#define ADC_Channel_2			2
#define ADC_Channel_3			3
#define ADC_Channel_4			4
#define ADC_Channel_5			5
#define ADC_Channel_6			6
#define ADC_Channel_7			7

#define ADC_ADCSRA_ADSC			6	// Start Conversion Pin

#define ADC_ADCSRA_ADIF			4

#define AVCC		0
#define AREF		1


#define ADC_DIVSION_FACTOR_BY_2					0
#define ADC_DIVSION_FACTOR_BY_4					1
#define ADC_DIVSION_FACTOR_BY_8					2
#define ADC_DIVSION_FACTOR_BY_16				3
#define ADC_DIVSION_FACTOR_BY_32				4
#define ADC_DIVSION_FACTOR_BY_64				5
#define ADC_DIVSION_FACTOR_BY_128				6

void ADC_void_Init(void);
u8 ADC_u8_Get_Digital_ValueSynchNonBlocking(u8 Copy_u8ChannelNumber, u16 *Copy_Pu16DigitalValue);
u8 ADC_u8_Get_Digital_ValueAsynch(u8 Copy_u8ChannelNumber, void (*Copy_PFNotification)(u16));
u8 ADC_u8GetADCRegValue(u16 *Copy_u16PADCValue);

#endif
