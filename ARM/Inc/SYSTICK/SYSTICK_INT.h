/*
 * SYSTICK_INT.h
 *
 *  Created on: Aug 14, 2023
 *      Author: Shehab
 */

#ifndef SYSTICK_SYSTICK_INT_H_
#define SYSTICK_SYSTICK_INT_H_

/** clock sources
 * AHB/8
 * Processor clock (AHB)
 */
#define AHB_8_CLOCK      0
#define AHB_CLOCK        1

void SYSTCK_vInit();
void SYSTCK_vEnableTimer();
void SYSTCK_vDisableTimer();
void SYSTCK_vEnableIntrupt();
void SYSTCK_vDisableIntrupt();
void SYSTCK_vSetReloadValue(u32 A_RELOADVALUE);
u8 SYSTCK_u8GetTimerFalg();
void SYSTCK_vSetCallBack(void (*copy_PF)(void));

#endif /* SYSTICK_SYSTICK_INT_H_ */
