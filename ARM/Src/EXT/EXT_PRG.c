/*
 * EXT_PRG.c
 *
 *  Created on: Aug 13, 2023
 *      Author: Shehab
 */

#include"LIB/STD_types.h"
#include"LIB/BIT_math.h"

#include"../Inc/EXT/EXT_INT.h"
#include"../Inc/EXT/EXT_CFG.h"
#include"../Inc/EXT/EXT_REG.h"

/*
 * ***************************************************************************************************
 * ****************************************************************************************************
 * ***************************************************************************************************
 * ***************************************************************************************************
 * ****************************************************************************************************
 * ****************************************************************************************************
 * ********************************************uncompleted********************************************
 *
 *
 *
 *
 * */

void EXT_Vinti(){


#ifndef SYSCFG_EXTICR4
#define SYSCFG_EXTICR4		  *((volatile u32 *)(0x40010000 + 0x14))
#endif

	//SYSCFG_EXTICR4= ((0b0010)<<4); //select port C
	CLR_BIT(SYSCFG_EXTICR4,4);
	SET_BIT(SYSCFG_EXTICR4,5);
	CLR_BIT(SYSCFG_EXTICR4,6);
	CLR_BIT(SYSCFG_EXTICR4,7);
}

void EXT_u8EnableLine(u8 EXTI_ID){

	EXTI -> IMR1 = (1<<EXTI_ID);
}


void EXT_u8SetSenseMode(u8 A_Sense_mode,u8 EXTI_ID){
	if(A_Sense_mode == EXTI_FALLING_TRIGGER){
		SET_BIT(EXTI->FTSR1 ,EXTI_ID);
	}
}


void EXT_u8ClrIntruptFlag(u8 EXTI_ID){

	SET_BIT(EXTI -> PR1 , EXTI_ID);
}





