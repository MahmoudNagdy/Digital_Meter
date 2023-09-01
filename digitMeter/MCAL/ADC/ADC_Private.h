#ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H

#include "../../LIB/STD_TYPES.h";

#define ADC_u8_ADMUX_REG		*((volatile u8 *)0x27)
#define ADC_u8_ADCSRA_REG		*((volatile u8 *)0x26)
#define ADC_u8_ADCH_REG			*((volatile u8 *)0x25)
#define ADC_u8_ADCL_REG			*((volatile u8 *)0x24)
#define ADC_u8_SFIOR_REG		*((volatile u8 *)0x50)


#define ADC_u16_ADC_REG			*((volatile u16 *) 0x24) // 10 Bits



#define ADC_ADMUX_REFS1					7
#define ADC_ADMUX_REFS0					6
#define ADC_ADMUX_ADLAR					5

#define ADC_ADCSRA_ADATE				5

#define ADC_ADPS2						2
#define ADC_ADPS1						1
#define ADC_ADPS0						0

#define ADC_Enable_PIN					7

#define ADC_ADCSRA_ADSC					6		// Start Conversion Pin

#define ADC_ADCSRA_ADIF					4		// Interrupt Flag

#define ADC_Interrupt_Enable_PIN		3



/****************************************************************/

#define AVCC					0
#define AREF					1
#define INTERNAL_VOLTAGE		2

#define Right_Adjust			0
#define Left_Adjust				1

#define ADC_DIVSION_FACTOR_BY_2					0
#define ADC_DIVSION_FACTOR_BY_4					1
#define ADC_DIVSION_FACTOR_BY_8					2
#define ADC_DIVSION_FACTOR_BY_16				3
#define ADC_DIVSION_FACTOR_BY_32				4
#define ADC_DIVSION_FACTOR_BY_64				5
#define ADC_DIVSION_FACTOR_BY_128				6

#endif
