/*
 * EXT_INT.h
 *
 *  Created on: Aug 13, 2023
 *      Author: Shehab
 */

#ifndef EXT_EXT_INT_H_
#define EXT_EXT_INT_H_

#define EXTI_FALLING_TRIGGER     0


void EXT_Vinti();
void EXT_u8EnableLine(u8 EXTI_ID);
void EXT_u8SetSenseMode(u8 A_Sense_mode,u8 EXTI_ID);
void EXT_u8ClrIntruptFlag(u8 EXTI_ID);


#endif /* EXT_EXT_INT_H_ */
