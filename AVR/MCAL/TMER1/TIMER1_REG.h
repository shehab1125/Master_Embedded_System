/*
 * TIMER1_REG.h
 *
 *  Created on: Sep 19, 2022
 *      Author: Shehab
 */

#ifndef MCAL_TMER1_TIMER1_REG_H_
#define MCAL_TMER1_TIMER1_REG_H_




#define TCCR1A    *((volatile u8*)(0x4F))
#define TCCR1B    *((volatile u8*)(0x4E))
#define OCR1A     *((volatile u16*)(0x4A))
#define ICR1      *((volatile u16*)(0x46))
#define TIMSK     *((volatile u8*)(0x59))






#endif /* MCAL_TMER1_TIMER1_REG_H_ */
