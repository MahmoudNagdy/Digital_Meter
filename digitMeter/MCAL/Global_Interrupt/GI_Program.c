#include "GI_Private.h";
#include "../../LIB/BIT_MATH.h";
#include "../../LIB/STD_TYPES.h";


/* Enable GIE (Enable Global Interrupt) */
void EXTI_voidEnable_GIE(void){
	SET_BIT(EXTI_u8_SREG, EXTI_SREG_GIE_PIN);
}

/* Disable GIE (Disable Global Interrupt) */
void EXTI_voidDisable_GIE(void){
	CLR_BIT(EXTI_u8_SREG, EXTI_SREG_GIE_PIN);
}
