/*
 * SYSTICK_PRG.c
 *
 *  Created on: Aug 14, 2023
 *      Author: Shehab
 */

#include"LIB/STD_types.h"
#include"LIB/BIT_math.h"

#include"../Inc/SYSTICK/SYSTICK_INT.h"
#include"../Inc/SYSTICK/SYSTICK_CFG.h"
#include"../Inc/SYSTICK/SYSTICK_REG.h"


void (*SYSTCK_PFSYSTCK)(void)= ADDRESS_NULL;

void SYSTCK_vInit()
{
#if clocksource == AHB_CLOCK
	SET_BIT(STK_CTRL,2);

#elif clocksource == AHB_8_CLOCK
	CLR_BIT(STK_CTRL,2);
#endif

}

void SYSTCK_vEnableTimer(){
	SET_BIT(STK_CTRL,0);
}

void SYSTCK_vDisableTimer(){
	CLR_BIT(STK_CTRL,0);
}

void SYSTCK_vEnableIntrupt(){
	SET_BIT(STK_CTRL,1);
}

void SYSTCK_vDisableIntrupt(){
	CLR_BIT(STK_CTRL,1);
}

void SYSTCK_vSetReloadValue(u32 A_RELOADVALUE){
	STK_LOAD=A_RELOADVALUE;

}

u8 SYSTCK_u8GetTimerFalg(){

	return GET_BIT(STK_CTRL,16);
}
void SYSTCK_vSetCallBack(void (*copy_PF)(void)){

	SYSTCK_PFSYSTCK=copy_PF;
}


void  SysTick_Handler()
{
	if(SYSTCK_PFSYSTCK != ADDRESS_NULL)
	{
		SYSTCK_PFSYSTCK();
	//	SYSTCK_u8GetTimerFalg();

	}
}







