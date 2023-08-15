/*
 * NVIC_INT.h
 *
 *  Created on: Aug 13, 2023
 *      Author: Shehab
 */

#ifndef NVIC_NVIC_INT_H_
#define NVIC_NVIC_INT_H_




void NVIC_voidInit(void);
void NVIC_voidEnabeInterrupt(u8 InterruptNum);
void NVIC_voidDisableInterrupt(u8 InterruptNum);
void NVIC_voidSetPendingFlag(u8 InterruptNum);
void NVIC_voidClrPendingFlag(u8 InterruptNum);
u8 NVIC_u8ReadActiveFlag(u8 InterruptNum);
void NVIC_voidSetPriority(u8 InterruptNum,u8 priority);


#endif /* NVIC_NVIC_INT_H_ */
