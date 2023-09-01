#ifndef WDT_PRIVATE_H
#define WDT_PRIVATE_H

/* WDT Regesters Addresses */

#define WDT_u8_WDTCR_REG			*((volatile u8 *) 0x41)




/********************************************/

#define WDT_Enable_Pin				3
#define WDT_Disable_Pin				4


#define WDT_WDP0_Pin				0
#define WDT_WDP1_Pin				1
#define WDT_WDP2_Pin				2

#endif
