/*
 * LCD_int.h
 *
 *  Created on: Aug 22, 2022
 *      Author: Shehab
 */

#ifndef HAL_LCD_LCD_INT_H_
#define HAL_LCD_LCD_INT_H_

#include "../../Inc/LIB/STD_types.h"

#define  ROW0_ID 	0
#define  ROW1_ID	1
#define  ROW2_ID 	2
#define  ROW3_ID 	3


#define COL0_ID  0
#define COL1_ID  1
#define COL2_ID  2
#define COL3_ID  3
#define COL4_ID  4
#define COL5_ID  5
#define COL6_ID  6
#define COL7_ID  7
#define COL8_ID  8
#define COL9_ID  9
#define COL10_ID  10
#define COL11_ID  11
#define COL12_ID  12
#define COL13_ID  13
#define COL14_ID  14
#define COL15_ID  15
#define COL16_ID  16
#define COL17_ID  17
#define COL18_ID  18
#define COL19_ID  19


#define SHIFT_RIGHT 1
#define SHIFT_LEFT  2


void LCD_vInit();

void LCD_SendCommand(u8 cmd);

void LCDdispchar(u8 u8Data);

void LCD_vDispStr(u8*A_u8Str);

void LCD_vClrScr();

void LCD_vGoToRowCol(u8 A_u8ROW_ID ,u8 A_u8COL_ID);

void LCD_vDispNum(u32 A_u32Num);

void lcd_write_data(u8 A_u8Data);

void LCD_u8StoreSpecialChar(u8 u8CharNum, u8* pu8CharShape);

void LCD_u8DisplaySpecialChar(u8 u8CharNum, u8 A_u8ROW_ID, u8 A_u8COL_ID);

void LCD_ShiftSpecialChar(u8 u8CharNum, u8 A_u8Direction, u8 A_u8ROW_ID, u8 A_u8COL_ID, u8* pu8CharShape);

#endif /* HAL_LCD_LCD_INT_H_ */
