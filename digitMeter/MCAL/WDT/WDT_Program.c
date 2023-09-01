#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "WDT_Config.h"
#include "WDT_Private.h"


void WDT_voidEnable(void){
	SET_BIT(WDT_u8_WDTCR_REG, WDT_Enable_Pin);
	
	/* Select Prescaler */
	SET_BIT(WDT_u8_WDTCR_REG, WDT_WDP0_Pin);
	SET_BIT(WDT_u8_WDTCR_REG, WDT_WDP1_Pin);
	SET_BIT(WDT_u8_WDTCR_REG, WDT_WDP2_Pin);
}

void WDT_voidDisable(void){
	SET_BIT(WDT_u8_WDTCR_REG, WDT_Enable_Pin);
	SET_BIT(WDT_u8_WDTCR_REG, WDT_Disable_Pin);
	
	WDT_u8_WDTCR_REG = 0x00;
}
