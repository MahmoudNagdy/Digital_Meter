#include "../../LIB/STD_TYPES.h";
#include "../../LIB/BIT_MATH.h";

#include "EXTI_Private.h";
#include "EXTI_Config.h";

/* Global Poiter */

void (*EXTI[3])(void) = {NULL, NULL, NULL};


void setCallBack(void(*ptf)(void), u8 EXTI_Index){
	EXTI[EXTI_Index] = ptf;
}

/* EXTI0 Modes */
void EXTI0_LowLevel_MODE(void){
	CLR_BIT(EXTI_u8_MCUCR, EXTI_u8_ISC00);
	CLR_BIT(EXTI_u8_MCUCR, EXTI_u8_ISC01);
}

void EXTI0_FALLING_MODE(void){
	SET_BIT(EXTI_u8_MCUCR, EXTI_u8_ISC01);
	CLR_BIT(EXTI_u8_MCUCR, EXTI_u8_ISC00);
}

void EXTI0_AnyLogicalChange_MODE(void){
	CLR_BIT(EXTI_u8_MCUCR, EXTI_u8_ISC01);
	SET_BIT(EXTI_u8_MCUCR, EXTI_u8_ISC00);
}

void EXTI0_RISING_MODE(void){
	SET_BIT(EXTI_u8_MCUCR, EXTI_u8_ISC01);
	SET_BIT(EXTI_u8_MCUCR, EXTI_u8_ISC00);
}


/**********************************************************/


/* EXTI1 Modes */
void EXTI1_LowLevel_MODE(void){
	CLR_BIT(EXTI_u8_MCUCR, EXTI_u8_ISC10);
	CLR_BIT(EXTI_u8_MCUCR, EXTI_u8_ISC11);
}

void EXTI1_FALLING_MODE(void){
	SET_BIT(EXTI_u8_MCUCR, EXTI_u8_ISC11);
	CLR_BIT(EXTI_u8_MCUCR, EXTI_u8_ISC10);
}

void EXTI1_AnyLogicalChange_MODE(void){
	CLR_BIT(EXTI_u8_MCUCR, EXTI_u8_ISC11);
	SET_BIT(EXTI_u8_MCUCR, EXTI_u8_ISC10);
}

void EXTI1_RISING_MODE(void){
	SET_BIT(EXTI_u8_MCUCR, EXTI_u8_ISC11);
	SET_BIT(EXTI_u8_MCUCR, EXTI_u8_ISC10);
}


/**********************************************************/

/* EXTI2 Modes */

void EXTI2_RISING_MODE(void){
	SET_BIT(EXTI_u8_MCUCSR, EXTI_u8_ISC6);
}

void EXTI2_FALLING_MODE(void){
	CLR_BIT(EXTI_u8_MCUCSR, EXTI_u8_ISC6);
}

/**********************************************************/

void EXTI_voidEXTI0Enable(void){

	/* Selected Mode */
	EXTI0_RISING_MODE();

	/* Enable EXTI0 PIE */
	SET_BIT(EXTI_u8_GICR, EXTI_u8_Enable0_Pin);
}

void EXTI_voidEXTI1Enable(void){

	/* Selected Mode */
	EXTI1_AnyLogicalChange_MODE();

	/* Enable EXTI1 PIE */
	SET_BIT(EXTI_u8_GICR, EXTI_u8_Enable1_Pin);
}


void EXTI_INTEnable(u8 Copy_u8INTNumber, u8 Copy_u8INTMode){
	switch(Copy_u8INTNumber){
		case EXTI_INT0:
			/* Enable EXTI0 PIE */
			SET_BIT(EXTI_u8_GICR, EXTI_u8_Enable0_Pin);
			switch(Copy_u8INTMode){
				case Low_Level_Mode:
					EXTI0_LowLevel_MODE();
					break;

				case Falling_Mode:
					EXTI0_FALLING_MODE();
					break;

				case Any_Logical_Change_Mode:
					EXTI0_AnyLogicalChange_MODE();
					break;

				case Rising_Mode:
					EXTI0_RISING_MODE();
					break;
			}
			break;

		case EXTI_INT1:
			/* Enable EXTI1 PIE */
			SET_BIT(EXTI_u8_GICR, EXTI_u8_Enable1_Pin);
			switch(Copy_u8INTMode){
				case Low_Level_Mode:
					EXTI1_LowLevel_MODE();
					break;

				case Falling_Mode:
					EXTI1_FALLING_MODE();
					break;

				case Any_Logical_Change_Mode:
					EXTI1_AnyLogicalChange_MODE();
					break;

				case Rising_Mode:
					EXTI1_RISING_MODE();
					break;
			}
			break;
		case EXTI_INT2:
			SET_BIT(EXTI_u8_GICR, EXTI_u8_Enable2_Pin);
			switch(Copy_u8INTMode){
				case Rising_Mode:
					EXTI2_RISING_MODE();
					break;
				case Falling_Mode:
					EXTI2_FALLING_MODE();
					break;
			}
			break;
	}

}

void EXTI_voidINTDisable(u8 Copy_u8_INT_Index){
	switch(Copy_u8_INT_Index){
		case EXTI_INT0:
			CLR_BIT(EXTI_u8_GICR, EXTI_u8_Enable0_Pin);
			break;

		case EXTI_INT1:
			CLR_BIT(EXTI_u8_GICR, EXTI_u8_Enable1_Pin);
			break;
		
		case EXTI_INT2:
			CLR_BIT(EXTI_u8_GICR, EXTI_u8_Enable2_Pin);
			break;
	}
}


// EXTI 0

void __vector_1(void) __attribute__((signal));

void __vector_1(void){

	if(EXTI[EXTI_INT0] != NULL){
		EXTI[0]();
	}

}


// EXTI 1
void __vector_2(void) __attribute__((signal));

void __vector_2(void){

	if(EXTI[EXTI_INT1] != NULL){
			EXTI[1]();
	}

}


// EXTI 2
void __vector_3(void) __attribute__((signal));

void __vector_3(void){

	if(EXTI[EXTI_INT2] != NULL){
			EXTI[2]();
	}

}


