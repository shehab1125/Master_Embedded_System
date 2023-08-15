/*
 * SYSTICK_PRI.h
 *
 *  Created on: Aug 14, 2023
 *      Author: Shehab
 */

#ifndef SYSTICK_SYSTICK_REG_H_
#define SYSTICK_SYSTICK_REG_H_

#define STK_CTRL                            *((volatile u32 *)0xE000E010)
#define STK_LOAD                            *((volatile u32 *)0xE000E014)
#define STK_VAL                             *((volatile u32 *)0xE000E018)
#define STK_CALIB                           *((volatile u32 *)0xE000E01C)

#endif /* SYSTICK_SYSTICK_REG_H_ */
