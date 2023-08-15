/*
   * TIMER_reg.h
 *
 *  Created on: Sep 13, 2022
 *      Author: Shehab
 */

#ifndef TIMER_TIMER_REG_H_
#define TIMER_TIMER_REG_H_
/*register defintion*/

#define TCCR0   *((volatile u8*)0x53)
#define TCNT0   *((volatile u8*)0x52)
#define OCR0    *((volatile u8*)0x5C)
#define TIMSK   *((volatile u8*)0x59)
#define TIFR    *((volatile u8*)0x58)

#endif /* TIMER_TIMER_REG_H_ */
