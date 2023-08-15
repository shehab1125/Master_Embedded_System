/*
 * MBTN_pri.h
 *
 *  Created on: Aug 24, 2022
 *      Author: Shehab
 */

#ifndef HAL_KEYPAD_KP_PRI_H_
#define HAL_KEYPAD_KP_PRI_H_


#define ROW0_ID 0
#define ROW1_ID 1
#define ROW2_ID 2
#define ROW3_ID 3


#define COL0_ID 0
#define COL1_ID 1
#define COL2_ID 2
#define COL3_ID 3

static const u8 KPD_au8SwitchVal[4][4] =
{
  {
    0x04,
    0x08,
    0x0C,
    0x10 },
  {
    0x03,
    0x07,
    0x0B,
    0x0F },
  {
    0x02,
    0x06,
    0x0A,
    0x0E },
  {
    0x01,
    0x05,
    0x09,
    0x0D }
};

#endif /* HAL_KEYPAD_KP_PRI_H_ */
