#ifndef GI_INTERFACE_H
#define GI_INTERFACE_H

#define EXTI_SREG_GIE_PIN		7
#define EXTI_u8_SREG		*((volatile u8 *)0x5F)

void EXTI_voidEnable_GIE(void);
void EXTI_voidDisable_GIE(void);

#endif
