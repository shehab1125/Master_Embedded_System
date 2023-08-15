/*
 * BTN_int.h
 *
 *  Created on: Aug 16, 2022
 *      Author: Shehab
 */

#ifndef HAL_BUTTON_BTN_INT_H_
#define HAL_BUTTON_BTN_INT_H_

 #define BTN0_ID 0
 #define BTN1_ID 1
 #define BTN2_ID 2
 #define BTN3_ID 3
 #define BTN4_ID 4
 #define BTN5_ID 5
 #define BTN6_ID 6
 #define BTN7_ID 7

 #define BTN_ON  1
 #define BTN_OFF 0          /* this e7tmalat is becouse the "u8" or the output we put in the second func*/

void BTN_vInit(u8  A_u8BTNID);

u8 BTN_u8GetState(u8 A_u8BTNID);

#endif /* HAL_BUTTON_BTN_INT_H_ */
