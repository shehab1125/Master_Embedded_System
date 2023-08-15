/*
 * WDT_prg.c
 *
 *  Created on: Sep 20, 2022
 *      Author: Shehab
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "WDT_reg.h"
#include "WDT_pri.h"
#include "WDT_cfg.h"


void WDT_vEnable(){

#if WDT_TIME == WDT_Sleep_16_3_ms
	WDTCR = WDT_Sleep_16_3;
#elif WDT_TIME == WDT_Sleep_32_5_ms
	WDTCR = WDT_Sleep_32_5;
#elif WDT_TIME == WDT_Sleep_65_ms
	WDTCR = WDT_Sleep_65;
#elif WDT_TIME == WDT_Sleep_0_13
	WDTCR = WDT_Sleep_0_13;
#elif WDT_TIME == WDT_Sleep_0_26
	WDTCR = WDT_Sleep_0_26;
#elif WDT_TIME == WDT_Sleep_0_52
	WDTCR = WDT_Sleep_0_52;
#elif WDT_TIME == WDT_Sleep_1_sec
	WDTCR = WDT_Sleep_1_sec;
#elif WDT_TIME == WDT_Sleep_2_1_sec
	WDTCR = WDT_Sleep_2_1_sec;

#endif
			SET_BIT(WDTCR,3);
}

void WDT_vDisable(){
	/*IN THE SAME CYCLE WDE = 1 ,WDTDE =1*/
	WDTCR = 0XFF;
	/*within the next four cycle*/
	WDTCR = 0b00000000;
}

void WDT_vRefresh(void){
	asm("WDR");


}
