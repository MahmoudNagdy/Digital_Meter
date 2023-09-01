/*
 * Timer.h
 *
 *  Created on: Aug 3, 2023
 *      Author: Abdallah
 */

#ifndef MCAL_TIMER_TIMER_H_
#define MCAL_TIMER_TIMER_H_

#include "../Registers.h"
#include "../../LIB/ERROR_STATE.h"
#include "../../LIB/Bit_Math.h"
#include "../../LIB/STD_Types.h"
#include "../../MCAL/Dio/Dio_interface.h"


/*************************************
 * 		Config Structure : TIMER 0
 ************************************/


// Timer 0 Modes
typedef enum
{
	TIMER0_NORMAL_MODE=0,
	TIMER0_PHASE_CORRECT_MODE,
	TIMER0_CTC_MODE,
	TIMER0_FAST_PWM_MODE
}TIMER0_MODE_t;


// Timer 0 prescalar
typedef enum{
	TIMER0_STOP=0,
	TIMER0_PRESCALAR_1,
	TIMER0_PRESCALAR_8,
	TIMER0_PRESCALAR_64,
	TIMER0_PRESCALAR_256,
	TIMER0_PRESCALAR_1024,
	EXTERNAL_FALLING,
	EXTERNAL_RISING
}Timer0_Prescalar;


// OCO Pin Mode (HW Pin)
typedef enum{
	OC0_DISCONNECTED=0,
	OC0_TOGGLE,
	OC0_NON_INVERTING,     // Clear OC0 at Compare match
	OC0_INVERTING		   // Set OC0 at Compare match
}OC0_Mode_t;


typedef enum
{
	TOIE0_DISABLE,
	TOIE0_ENABLE = 0x01
}TOVFIE0_t;

typedef enum
{
	OCIE0_DISABLE,
	OCIE0_ENABLE = 0x02
}TOCMIE0_t;

typedef struct
{
	TIMER0_MODE_t mode;
	Timer0_Prescalar prescalar;
	OC0_Mode_t oc0_mode;
	TOVFIE0_t OVF_Interrupt;
	TOCMIE0_t OCM_Interrupt;
}TIMER0_Config_t;



/*************************************
 * 		Config Structure : TIMER 1
 ************************************/

// Timer 1 Modes
typedef enum
{
	TIMER1_NORMAL_MODE=0,
	TIMER1_FAST_PWM_ICR1_TOP,
	TIMER1_FAST_PWM_OCR1A_TOP
}TIMER1_MODE_t;


typedef enum{
	TIMER1_STOP=0,
	TIMER1_PRESCALAR_1,
	TIMER1_PRESCALAR_8,
	TIMER1_PRESCALAR_64,
	TIMER1_PRESCALAR_256,
	TIMER1_PRESCALAR_1024,
	EXTERNAL1_FALLING,
	EXTERNAL1_RISING
}Timer1_Prescalar;



typedef enum
{
	OCRA_DISCONNECTED=0,
	OCRA_TOGGLE,
	OCRA_NON_INVERTING,
	OCRA_INVERTING

}OC1A_Mode_t;

typedef enum
{
	OCRB_DISCONNECTED=0,
	OCRB_TOGGLE,
	OCRB_NON_INVERTING,
	OCRB_INVERTING

}OC1B_Mode_t;


typedef enum
{
	TOIE1_DISABLE,
	TOIE1_ENABLE = (1<<2)
}TOVFIE1_t;

typedef enum
{
	TICIE1_DISABLE,
	TICIE1_ENABLE = (1<<5)
}TICIE1_t;


typedef enum
{
	TOCIEIA_DISABLE,
	TOCIEIA_ENABLE = (1<<4)
}TOCIEIA_t;

typedef enum
{
	TOCIEIB_DISABLE,
	TOCIEIB_ENABLE = (1<<3)
}TOCIEIB_t;



typedef struct
{
	TIMER1_MODE_t mode;
	Timer1_Prescalar prescalar;
	OC1A_Mode_t OC1A_mode;
	OC1B_Mode_t OC1B_mode;
	TOVFIE1_t OVF_Interrupt;
	TICIE1_t ICU_Interrupt;
	TOCIEIA_t OCA_Interrupt;
	TOCIEIB_t OCB_Interrupt;
}TIMER1_Config_t;





/****************************
 * 		APIs
 **************************/

u8 TIMER0_Init(TIMER0_Config_t *TIME0_Cfg);
u8 TIMER1_Init(TIMER1_Config_t *TIME1_Cfg);

u8 TIMER0_Stop(void);
u8 TIMER1_Stop(void);

void Timer0_Set_Delay_ms(u32 delay_ms);


u8 TIMER0_GetCompareValue(u8 *CM_Value);
u8 TIMER0_SetCompareValue(u8 CM_Value);

u8 TIMER0_GetCounterValue(u8 *TCNT_Value);
u8 TIMER0_SetCounterValue(u8 TCNT_Value);

// In case of larger than 255
u8 TIMER0_GetOVF_Flag(u8 *OVF_Value);

void Timer0_OVF_SetCallBack(void (*Local_ptr_toFunc));
void Timer0_OCM_SetCallBack(void (*Local_ptr_toFunc));


u8 PWM_Set_DutyCycle(float dutyCycle);


void Timer1_ICU_InterruptEnable(void);
void Timer1_ICU_SetCallBack(void (*Local_ptr_toFunc));
void Timer1_ICU_InterruptDisable(void);




#endif /* MCAL_TIMER_TIMER_H_ */
