/*
 * MBTN_int.h
 *
 *  Created on: Aug 24, 2022
 *      Author: Shehab
 */

#ifndef HAL_KEYPAD_KP_INT_H_
#define HAL_KEYPAD_KP_INT_H_

#define NO_PRESSED_KEY 255

void KPD_vInit();

u8 KPD_vGetPressedKey();

#endif /* HAL_KEYPAD_KP_INT_H_ */
