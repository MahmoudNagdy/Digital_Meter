/*
 * Timer.c
 *
 *  Created on: Aug 3, 2023
 *      Author: Abdallah
 */


#include "Timer.h"

#define F_CPU 16000000UL


#define NULLPTR   ((void*)0)

static void (*Timer0_OVF_Fptr)(void) = NULLPTR;
static void (*Timer0_OCM_Fptr)(void) = NULLPTR;
static void (*Timer1_ICU_Fptr)(void) = NULLPTR;


u8 Delay_Flag=0;

TIMER0_Config_t Global_Timer0_Cfg;

TIMER1_Config_t Global_Timer1_Cfg;


volatile u32 OVF_Number = 0;
//volatile u16 OVF_Num_Delay;
volatile u8 Global_Delay_Status=0;







u8 TIMER0_Init(TIMER0_Config_t *TIME0_Cfg)
{
	u8 RetValue = STD_TYPES_NOK;
	if(TIME0_Cfg == NULLPTR){
		RetValue = STD_TYPES_NOK;
	}else
	{
		// Copy the configuration in a global structure in case of
		// usage inside othe functions
		Global_Timer0_Cfg = *TIME0_Cfg;


		// Timer0 mode Configurations
		if((TIME0_Cfg->mode >= TIMER0_NORMAL_MODE) && (TIME0_Cfg->mode <= TIMER0_FAST_PWM_MODE))
		{
			RetValue = STD_TYPES_OK;
			switch(TIME0_Cfg->mode)
			{
			case TIMER0_NORMAL_MODE:
				CLR_BIT(TCCR0,WGM00);
				CLR_BIT(TCCR0,WGM01);
				break;
			case TIMER0_PHASE_CORRECT_MODE:
				SET_BIT(TCCR0,WGM00);
				CLR_BIT(TCCR0,WGM01);
				break;
			case TIMER0_CTC_MODE:
				CLR_BIT(TCCR0,WGM00);
				SET_BIT(TCCR0,WGM01);
				break;
			case TIMER0_FAST_PWM_MODE:
				SET_BIT(TCCR0,WGM00);
				SET_BIT(TCCR0,WGM01);
				break;
			}
		}else{
			RetValue = STD_TYPES_OK;
		}

		// Timer_0 Prescalar Configuration
		if((TIME0_Cfg->prescalar >= TIMER0_STOP) && (TIME0_Cfg->prescalar <= EXTERNAL_RISING))
		{
			TCCR0 |= TIME0_Cfg->prescalar;
		}else{
			RetValue = STD_TYPES_OK;
		}


		// Timer_0 OC0 Pin
		TCCR0 |= (TIME0_Cfg->oc0_mode << COM00);


		// Timer_0 Interrupts
		TIMSK |= (TIME0_Cfg->OVF_Interrupt) | (TIME0_Cfg->OCM_Interrupt);



	}

	return RetValue;

}
u8 TIMER0_Stop(void)
{
	// No clock source
	CLR_BIT(TCCR0,CS00);
	CLR_BIT(TCCR0,CS01);
	CLR_BIT(TCCR0,CS02);
	return STD_TYPES_OK;
}

u8 TIMER0_GetCompareValue(u8 *CM_Value)
{
	*CM_Value = OCR0;

	return STD_TYPES_OK;

}
u8 TIMER0_SetCompareValue(u8 CM_Value)
{
	OCR0 = CM_Value;

	return STD_TYPES_OK;

}

u8 TIMER0_GetCounterValue(u8 *TCNT_Value)
{

	*TCNT_Value = TCNT0;


	return STD_TYPES_OK;
}


u8 TIMER0_SetCounterValue(u8 TCNT_Value)
{
	TCNT0 = TCNT_Value;

	return STD_TYPES_OK;

}

// In case of larger than 255
u8 TIMER0_GetOVF_Flag(u8 *OVF_Value)
{

	*OVF_Value = OVF_Number;
	return STD_TYPES_OK;

}



u8 PWM_Set_DutyCycle(float dutyCycle)
{
	u8 RetValue;

	if((Global_Timer0_Cfg.mode == TIMER0_FAST_PWM_MODE) || (Global_Timer0_Cfg.mode == TIMER0_PHASE_CORRECT_MODE))
	{
		if(Global_Timer0_Cfg.oc0_mode == OC0_NON_INVERTING)
		{
			OCR0 = (u8)((dutyCycle/100.0)*256) - 1;

		}else if(Global_Timer0_Cfg.oc0_mode == OC0_INVERTING)
		{
			OCR0 = (u8)(256-((256*dutyCycle)/100.0)) - 1;
		}
		RetValue = STD_TYPES_OK;
	}else{
		RetValue = STD_TYPES_NOK;
	}
	return RetValue;
}



void Timer0_Set_Delay_ms(u32 delay_ms)
{
	TIMER0_Config_t Timer0Cfg = {TIMER0_NORMAL_MODE, TIMER0_PRESCALAR_1024, OC0_DISCONNECTED, TOIE0_ENABLE, OCIE0_DISABLE};
	TIMER0_Init(&Timer0Cfg);

	u16 prescalar = 0;
	switch(Timer0Cfg.prescalar){
	case TIMER0_PRESCALAR_1024:
		prescalar = 1024;
		break;
	case TIMER0_PRESCALAR_256:
		prescalar = 256;
		break;
	case TIMER0_PRESCALAR_64:
		prescalar = 64;
		break;
	case TIMER0_PRESCALAR_8:
		prescalar = 8;
		break;
	case TIMER0_PRESCALAR_1:
		prescalar = 1;
		break;
	case EXTERNAL_FALLING:
	case EXTERNAL_RISING:
		break;
	case TIMER0_STOP:
		prescalar = 0;
		break;
	}

	u32 CountsNum = (u32)((F_CPU / (prescalar * 1000UL)) * (delay_ms));
	OVF_Number = (u32)(CountsNum / 256);
	u8 RestCounts = CountsNum % 256;



	TIMER0_SetCounterValue(0);

	while(OVF_Number > 0);

	while(TCNT0 < RestCounts);

	TIMER0_Stop();

	// Disable Timer0 overflow interrupt
	TIMSK &= ~(1 << TOIE0);
}


void Timer0_OVF_SetCallBack(void (*Local_ptr_toFunc))
{
	Timer0_OVF_Fptr = Local_ptr_toFunc;


}
void Timer0_OCM_SetCallBack(void (*Local_ptr_toFunc))
{
	Timer0_OCM_Fptr = Local_ptr_toFunc;
}


void Timer1_ICU_SetCallBack(void (*Local_ptr_toFunc))
{
	Timer1_ICU_Fptr = Local_ptr_toFunc;
}


void Timer1_ICU_InterruptEnable(void)
{
	// Enable ICU interrupt
	SET_BIT(TIMSK,TICIE1);
}

void Timer1_ICU_InterruptDisable(void)
{
	// Enable ICU interrupt
	CLR_BIT(TIMSK,TICIE1);
}


// ===========================================================


u8 TIMER1_Init(TIMER1_Config_t *TIME1_Cfg)
{
	u8 RetValue = STD_TYPES_NOK;
	if(TIME1_Cfg == NULLPTR){
		RetValue = STD_TYPES_NOK;
	}else
	{
		// Copy the configuration in a global structure in case of
		// usage inside othe functions
		Global_Timer1_Cfg = *TIME1_Cfg;


		// Timer0 mode Configurations
		if((TIME1_Cfg->mode >= TIMER1_NORMAL_MODE) && (TIME1_Cfg->mode <= TIMER1_FAST_PWM_OCR1A_TOP))
		{
			RetValue = STD_TYPES_OK;
			switch(TIME1_Cfg->mode)
			{
			case TIMER1_NORMAL_MODE:
				CLR_BIT(TCCR1A,WGM10);
				CLR_BIT(TCCR1A,WGM11);
				CLR_BIT(TCCR1B,WGM12);
				CLR_BIT(TCCR1B,WGM13);
				break;
			case TIMER1_FAST_PWM_ICR1_TOP:
				CLR_BIT(TCCR1A,WGM10);
				SET_BIT(TCCR1A,WGM11);
				SET_BIT(TCCR1B,WGM12);
				SET_BIT(TCCR1B,WGM13);
				break;
			case TIMER1_FAST_PWM_OCR1A_TOP:
				SET_BIT(TCCR1A,WGM10);
				SET_BIT(TCCR1A,WGM11);
				SET_BIT(TCCR1B,WGM12);
				SET_BIT(TCCR1B,WGM13);
				break;
			}
		}else{
			RetValue = STD_TYPES_NOK;
		}

		// Timer_0 Prescalar Configuration
		if((TIME1_Cfg->prescalar >= TIMER1_STOP) && (TIME1_Cfg->prescalar <= EXTERNAL1_RISING))
		{
			TCCR1B |= TIME1_Cfg->prescalar;
		}else{
			RetValue = STD_TYPES_NOK;
		}


		// Timer_1 OCA Pin
		TCCR1A |= (TIME1_Cfg->OC1A_mode << COM1A0);

		// Timer_1 OCA Pin
		TCCR1A |= (TIME1_Cfg->OC1B_mode << COM1B0);


		// Timer_1 Interrupts
		TIMSK |= (TIME1_Cfg->OVF_Interrupt) | (TIME1_Cfg->ICU_Interrupt) | (TIME1_Cfg->OCA_Interrupt) | (TIME1_Cfg->OCB_Interrupt);



	}

	return RetValue;
}


u8 TIMER1_Stop(void)
{
	// No clock source
	CLR_BIT(TCCR1B,CS10);
	CLR_BIT(TCCR1B,CS11);
	CLR_BIT(TCCR1B,CS12);
	return STD_TYPES_OK;
}









ISR(TIMER0_OVF_vect)
{
	if(OVF_Number > 0){
		//		Lcd_ES_tdisplayNum(OVF_Number);
		//		Lcd_ES_tsendString("  ");
		OVF_Number--;
	}else {
		// If all overflows are done, disable the interrupt
		TIMSK &= ~(1 << TOIE0);
	}

}


ISR(TIMER1_CAPT_vect)
{
	if(Timer1_ICU_Fptr != NULLPTR)
	{
		Timer1_ICU_Fptr();
	}
}


ISR(TIMER0_COMP_vect)
{
	if(Timer0_OCM_Fptr != NULLPTR)
	{
		Timer0_OCM_Fptr();
	}
}




