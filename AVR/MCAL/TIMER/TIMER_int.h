/*
 * TIMER_int.h

 *
 *  Created on: Sep 13, 2022
 *      Author: Shehab
 */
#include "../../LIB/STD_types.h"

#ifndef TIMER_TIMER_INT_H_

#define TIMER_TIMER_INT_H_

/*intialization of the timer ->>> enable timer -> prescaler -> timer  mode -> set oc0 pin state */
void MTIM0_vINT();

/*read from the counter*/
u8 MTIM0_read_data(void);

/*set the preload to count from the preload value*/
void MTIM0_vSetPreload(u8 Copy_u8PreloadValue);

/*set OCR value to be the top counts to generate CTC flag*/
void MTIM0_vSetOCRValue(u8 Copy_u8OCRValue);

/*set callback to execute ISR related with overflow event */
void MTIM0_vCallBack_OVRF(void(*Fptr)(void));

/*set callback to execute ISR related with CTC event */
void MTIM0_vCallBack_CTC(void(*Fptr)(void));

#endif /* TIMER_TIMER_INT_H_ */
