#include<util/delay.h>
#define F_CPU 16000000UL

#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "SevenSegment_Private.h"

void SevenSegment_Init(u8 Copy_u8PortId){
	DIO_u8SetPortDirection(Copy_u8PortId, DIO_u8_HIGH);
}

void SevenSegment_Display(u8 Copy_u8PortId, u8 Copy_u8Pin0, u8 Copy_u8Pin1, u8 Copy_u8Pin2, u8 Copy_u8Pin3, u8 Copy_u8Pin4, u8 Copy_u8Pin5, u8 Copy_u8Pin6)
{
	switch (Copy_u8PortId)
	{
	case DIO_u8_PORTA:
		if (Copy_u8Pin0 == DIO_u8_HIGH)
		{
			SET_BIT(DIO_u8_PORTA_REG, DIO_u8_PIN0);
		}
		else
		{
			CLR_BIT(DIO_u8_PORTA_REG, DIO_u8_PIN0);
		}

		if (Copy_u8Pin1 == DIO_u8_HIGH)
		{
			SET_BIT(DIO_u8_PORTA_REG, DIO_u8_PIN1);
		}
		else
		{
			CLR_BIT(DIO_u8_PORTA_REG, DIO_u8_PIN1);
		}

		if (Copy_u8Pin2 == DIO_u8_HIGH)
		{
			SET_BIT(DIO_u8_PORTA_REG, DIO_u8_PIN2);
		}
		else
		{
			CLR_BIT(DIO_u8_PORTA_REG, DIO_u8_PIN2);
		}

		if (Copy_u8Pin3 == DIO_u8_HIGH)
		{
			SET_BIT(DIO_u8_PORTA_REG, DIO_u8_PIN3);
		}
		else
		{
			CLR_BIT(DIO_u8_PORTA_REG, DIO_u8_PIN3);
		}

		if (Copy_u8Pin4 == DIO_u8_HIGH)
		{
			SET_BIT(DIO_u8_PORTA_REG, DIO_u8_PIN4);
		}
		else
		{
			CLR_BIT(DIO_u8_PORTA_REG, DIO_u8_PIN4);
		}

		if (Copy_u8Pin5 == DIO_u8_HIGH)
		{
			SET_BIT(DIO_u8_PORTA_REG, DIO_u8_PIN5);
		}
		else
		{
			CLR_BIT(DIO_u8_PORTA_REG, DIO_u8_PIN5);
		}

		if (Copy_u8Pin6 == DIO_u8_HIGH)
		{
			SET_BIT(DIO_u8_PORTA_REG, DIO_u8_PIN6);
		}
		else
		{
			CLR_BIT(DIO_u8_PORTA_REG, DIO_u8_PIN6);
		}
		break;

	case DIO_u8_PORTB:
		if (Copy_u8Pin0 == DIO_u8_HIGH)
		{
			SET_BIT(DIO_u8_PORTB_REG, DIO_u8_PIN0);
		}
		else
		{
			CLR_BIT(DIO_u8_PORTB_REG, DIO_u8_PIN0);
		}

		if (Copy_u8Pin1 == DIO_u8_HIGH)
		{
			SET_BIT(DIO_u8_PORTB_REG, DIO_u8_PIN1);
		}
		else
		{
			CLR_BIT(DIO_u8_PORTB_REG, DIO_u8_PIN1);
		}

		if (Copy_u8Pin2 == DIO_u8_HIGH)
		{
			SET_BIT(DIO_u8_PORTB_REG, DIO_u8_PIN2);
		}
		else
		{
			CLR_BIT(DIO_u8_PORTB_REG, DIO_u8_PIN2);
		}

		if (Copy_u8Pin3 == DIO_u8_HIGH)
		{
			SET_BIT(DIO_u8_PORTB_REG, DIO_u8_PIN3);
		}
		else
		{
			CLR_BIT(DIO_u8_PORTB_REG, DIO_u8_PIN3);
		}

		if (Copy_u8Pin4 == DIO_u8_HIGH)
		{
			SET_BIT(DIO_u8_PORTB_REG, DIO_u8_PIN4);
		}
		else
		{
			CLR_BIT(DIO_u8_PORTB_REG, DIO_u8_PIN4);
		}

		if (Copy_u8Pin5 == DIO_u8_HIGH)
		{
			SET_BIT(DIO_u8_PORTB_REG, DIO_u8_PIN5);
		}
		else
		{
			CLR_BIT(DIO_u8_PORTB_REG, DIO_u8_PIN5);
		}

		if (Copy_u8Pin6 == DIO_u8_HIGH)
		{
			SET_BIT(DIO_u8_PORTB_REG, DIO_u8_PIN6);
		}
		else
		{
			CLR_BIT(DIO_u8_PORTB_REG, DIO_u8_PIN6);
		}
		break;

	case DIO_u8_PORTC:
		if (Copy_u8Pin0 == DIO_u8_HIGH)
		{
			SET_BIT(DIO_u8_PORTC_REG, DIO_u8_PIN0);
		}
		else
		{
			CLR_BIT(DIO_u8_PORTC_REG, DIO_u8_PIN0);
		}

		if (Copy_u8Pin1 == DIO_u8_HIGH)
		{
			SET_BIT(DIO_u8_PORTC_REG, DIO_u8_PIN1);
		}
		else
		{
			CLR_BIT(DIO_u8_PORTC_REG, DIO_u8_PIN1);
		}

		if (Copy_u8Pin2 == DIO_u8_HIGH)
		{
			SET_BIT(DIO_u8_PORTC_REG, DIO_u8_PIN2);
		}
		else
		{
			CLR_BIT(DIO_u8_PORTC_REG, DIO_u8_PIN2);
		}

		if (Copy_u8Pin3 == DIO_u8_HIGH)
		{
			SET_BIT(DIO_u8_PORTC_REG, DIO_u8_PIN3);
		}
		else
		{
			CLR_BIT(DIO_u8_PORTC_REG, DIO_u8_PIN3);
		}

		if (Copy_u8Pin4 == DIO_u8_HIGH)
		{
			SET_BIT(DIO_u8_PORTC_REG, DIO_u8_PIN4);
		}
		else
		{
			CLR_BIT(DIO_u8_PORTC_REG, DIO_u8_PIN4);
		}

		if (Copy_u8Pin5 == DIO_u8_HIGH)
		{
			SET_BIT(DIO_u8_PORTC_REG, DIO_u8_PIN5);
		}
		else
		{
			CLR_BIT(DIO_u8_PORTC_REG, DIO_u8_PIN5);
		}

		if (Copy_u8Pin6 == DIO_u8_HIGH)
		{
			SET_BIT(DIO_u8_PORTC_REG, DIO_u8_PIN6);
		}
		else
		{
			CLR_BIT(DIO_u8_PORTC_REG, DIO_u8_PIN6);
		}
		break;

	case DIO_u8_PORTD:
		if (Copy_u8Pin0 == DIO_u8_HIGH)
		{
			SET_BIT(DIO_u8_PORTD_REG, DIO_u8_PIN0);
		}
		else
		{
			CLR_BIT(DIO_u8_PORTD_REG, DIO_u8_PIN0);
		}

		if (Copy_u8Pin1 == DIO_u8_HIGH)
		{
			SET_BIT(DIO_u8_PORTD_REG, DIO_u8_PIN1);
		}
		else
		{
			CLR_BIT(DIO_u8_PORTD_REG, DIO_u8_PIN1);
		}

		if (Copy_u8Pin2 == DIO_u8_HIGH)
		{
			SET_BIT(DIO_u8_PORTD_REG, DIO_u8_PIN2);
		}
		else
		{
			CLR_BIT(DIO_u8_PORTD_REG, DIO_u8_PIN2);
		}

		if (Copy_u8Pin3 == DIO_u8_HIGH)
		{
			SET_BIT(DIO_u8_PORTD_REG, DIO_u8_PIN3);
		}
		else
		{
			CLR_BIT(DIO_u8_PORTD_REG, DIO_u8_PIN3);
		}

		if (Copy_u8Pin4 == DIO_u8_HIGH)
		{
			SET_BIT(DIO_u8_PORTD_REG, DIO_u8_PIN4);
		}
		else
		{
			CLR_BIT(DIO_u8_PORTD_REG, DIO_u8_PIN4);
		}

		if (Copy_u8Pin5 == DIO_u8_HIGH)
		{
			SET_BIT(DIO_u8_PORTD_REG, DIO_u8_PIN5);
		}
		else
		{
			CLR_BIT(DIO_u8_PORTD_REG, DIO_u8_PIN5);
		}

		if (Copy_u8Pin6 == DIO_u8_HIGH)
		{
			SET_BIT(DIO_u8_PORTD_REG, DIO_u8_PIN6);
		}
		else
		{
			CLR_BIT(DIO_u8_PORTD_REG, DIO_u8_PIN6);
		}
		break;
	}
}

void SevenSegment_From0To9(u8 Copy_u8PortId){
	while(1){
		SevenSegment_Display(Copy_u8PortId, 1, 1, 1, 1, 1, 1, 0); // 0
		_delay_ms(50);
		SevenSegment_Display(Copy_u8PortId, 0, 1, 1, 0, 0, 0, 0); // 1
		_delay_ms(50);
		SevenSegment_Display(Copy_u8PortId, 1, 1, 0, 1, 1, 0, 1); // 2
		_delay_ms(50);
		SevenSegment_Display(Copy_u8PortId, 1, 1, 1, 1, 0, 0, 1); // 3
		_delay_ms(50);
		SevenSegment_Display(Copy_u8PortId, 0, 1, 1, 0, 0, 1, 1); // 4
		_delay_ms(50);
		SevenSegment_Display(Copy_u8PortId, 1, 0, 1, 1, 0, 1, 1); // 5
		_delay_ms(50);
		SevenSegment_Display(Copy_u8PortId, 1, 0, 1, 1, 1, 1, 1); // 6
		_delay_ms(50);
		SevenSegment_Display(Copy_u8PortId, 1, 1, 1, 0, 0, 0, 0); // 7
		_delay_ms(50);
		SevenSegment_Display(Copy_u8PortId, 1, 1, 1, 1, 1, 1, 1); // 8
		_delay_ms(50);
		SevenSegment_Display(Copy_u8PortId, 1, 1, 1, 1, 0, 1, 1); // 9
		_delay_ms(50);
	}
}

void SevenSegment_FromAToH(u8 Copy_u8PortId){
	while(1){
		SevenSegment_Display(Copy_u8PortId, 1, 1, 1, 0, 1, 1, 1); // A
		_delay_ms(50);
		SevenSegment_Display(Copy_u8PortId, 0, 0, 1, 1, 1, 1, 1); // B
		_delay_ms(50);
		SevenSegment_Display(Copy_u8PortId, 1, 0, 0, 1, 1, 1, 0); // C
		_delay_ms(50);
		SevenSegment_Display(Copy_u8PortId, 0, 1, 1, 1, 1, 0, 1); // D
		_delay_ms(50);
		SevenSegment_Display(Copy_u8PortId, 1, 0, 0, 1, 1, 1, 1); // E
		_delay_ms(50);
		SevenSegment_Display(Copy_u8PortId, 1, 0, 0, 0, 1, 1, 1); // F
		_delay_ms(50);
		SevenSegment_Display(Copy_u8PortId, 1, 0, 1, 1, 1, 1, 0); // G
		_delay_ms(50);
		SevenSegment_Display(Copy_u8PortId, 0, 1, 1, 0, 1, 1, 1); // H
		_delay_ms(50);
	}
}
