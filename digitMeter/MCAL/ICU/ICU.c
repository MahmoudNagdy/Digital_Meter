/*
 * ICU.c
 *
 *  Created on: Aug 28, 2023
 *      Author: Abdallah
 */


#include "ICU.h"

static void ICU_Func(void);


volatile u16 ICU_Counter = 0;

volatile u16 firstEdgeCounts,secondEdgeCounts,thirdEdgeCounts;


volatile u32 totalTime,onTime,offTime;




void ICU_PWM_Measure(u32 *freq, u8 *duty)
{
	TIMER1_Config_t TIMER1Cfg = {TIMER1_NORMAL_MODE,TIMER1_PRESCALAR_64,OCRA_DISCONNECTED,OCRB_DISCONNECTED};
	TIMER1_Init(&TIMER1Cfg);

	TCNT1 = 0;

	Timer1_ICU_SetCallBack(ICU_Func);
	Timer1_ICU_Edge(ICU_RISING);
	Timer1_ICU_InterruptEnable();
	ICU_Counter = 1;


	while(ICU_Counter<=3);

	onTime = secondEdgeCounts - firstEdgeCounts;


	offTime = thirdEdgeCounts - secondEdgeCounts;

	*duty = ((u32)onTime*100.0)/((u32)(onTime+offTime));
	*freq = (u32)1000000.0/((u32)((offTime+onTime)*4));; // dutyCycle in percentage


	_delay_ms(50);
	TIMER1_Stop();

}


void Timer1_ICU_Edge(ICU_Edge_Select edge)
{
	switch(edge)
	{
	case ICU_FALLING:
		CLR_BIT(TCCR1B,ICES1);
		break;
	case ICU_RISING:
		SET_BIT(TCCR1B,ICES1);
		break;
	}
}




void ICU_Func(void)
{
	if(ICU_Counter == 1){
		firstEdgeCounts = ICR1;
		Timer1_ICU_Edge(ICU_FALLING);
		ICU_Counter = 2;
	}else if(ICU_Counter == 2){
		secondEdgeCounts = ICR1;
		Timer1_ICU_Edge(ICU_RISING);
		ICU_Counter = 3;
	}else if(ICU_Counter == 3){
		thirdEdgeCounts = ICR1;
		Timer1_ICU_InterruptDisable();
		ICU_Counter = 4;
	}
}
