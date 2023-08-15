/*
 * BIT_math.h
 *
 *  Created on: Aug 15, 2022
 *      Author: Shehab
 */

#ifndef LIB_BIT_MATH_H_
#define LIB_BIT_MATH_H_



#define SET_BIT(variable,BIT_NUM)   variable|=(1<<BIT_NUM)
#define CLR_BIT(variable,BIT_NUM)   variable&=(~(1<<BIT_NUM))
#define TOG_BIT(variable,BIT_NUM)   variable^=(1<<BIT_NUM)
#define GET_BIT(variable,BIT_NUM)   ((variable>>BIT_NUM)&1)

/*
 * WRT_BIT is to assign 1 or 0 to  a specific bit in a register
 * while maintaining all the bits' value as it is.
 * Steps:
 * 		1- Clear the specific bit you want to write on
 * 		2- Insert the new value you want to write
 */
#define WRT_BIT(REG, BIT, VAL) ( (REG) = ( ( (REG) & (~(1<<(BIT))) ) | ( (VAL) << (BIT)  ) ) )
#endif /* LIB_BIT_MATH_H_ */

void	_delay_ms(unsigned long  int ticks);
