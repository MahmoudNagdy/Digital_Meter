/*
 * ICU.h
 *
 *  Created on: Aug 28, 2023
 *      Author: Abdallah
 */

#ifndef MCAL_ICU_ICU_H_
#define MCAL_ICU_ICU_H_

#include "../TIMER/Timer.h"
#include "../Registers.h"
#include "util/delay.h"
#include "../DIO/DIO_Interface.h"


typedef enum{
	ICU_FALLING,
	ICU_RISING
}ICU_Edge_Select;

void Timer1_ICU_Edge(ICU_Edge_Select edge);

void ICU_PWM_Measure(u32 *freq, u8 *duty);

#endif /* MCAL_ICU_ICU_H_ */
