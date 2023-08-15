/*
 * NVIC_PRG.c
 *
 *  Created on: Aug 13, 2023
 *      Author: Shehab
 */

#include"LIB/STD_types.h"
#include"LIB/BIT_math.h"

#include"../Inc/NVIC/NVIC_INT.h"
#include"../Inc/NVIC/NVIC_CFG.h"
#include"../Inc/NVIC/NVIC_PRI.h"
#include"../Inc/NVIC/NVIC_REG.h"





void NVIC_voidInit(void)
{
#ifndef SCB_AIRCR
#define SCB_AIRCR		  *((volatile u32 *)0XE000ED0C)
#endif

	SCB_AIRCR = NUM_OF_GRP_SUB;
}
void NVIC_voidEnabeInterrupt(u8 InterruptNum)
{
	if(InterruptNum < 32)
	{
		NVIC_ISER0 = 1 << InterruptNum;
	}else if(InterruptNum < 64)
	{
		InterruptNum -= 32;
		NVIC_ISER1 = 1 << InterruptNum;
	}
	else if(InterruptNum < 74)
	{
		InterruptNum -= 64;
		NVIC_ISER2 = 1 << InterruptNum;
	}

}
void NVIC_voidDisableInterrupt(u8 InterruptNum)
{
	if(InterruptNum < 32)
	{
		NVIC_ICER0 = 1 << InterruptNum;
	}else if(InterruptNum < 64)
	{
		InterruptNum -= 32;
		NVIC_ICER1 = 1 << InterruptNum;
	}
	else if(InterruptNum < 74)
	{
		InterruptNum -= 64;
		NVIC_ICER2 = 1 << InterruptNum;
	}

}

void NVIC_voidSetPendingFlag(u8 InterruptNum)
{
	if(InterruptNum < 32)
	{
		NVIC_ISPR0 = 1 << InterruptNum;
	}else if(InterruptNum < 64)
	{
		InterruptNum -= 32;
		NVIC_ISPR1 = 1 << InterruptNum;
	}
	else if(InterruptNum < 74)
	{
		InterruptNum -= 64;
		NVIC_ISPR2 = 1 << InterruptNum;
	}

}
void NVIC_voidClrPendingFlag(u8 InterruptNum)
{
	if(InterruptNum < 32)
	{
		NVIC_ICPR0 = 1 << InterruptNum;
	}else if(InterruptNum < 64)
	{
		InterruptNum -= 32;
		NVIC_ICPR1 = 1 << InterruptNum;
	}
	else if(InterruptNum < 74)
	{
		InterruptNum -= 64;
		NVIC_ICPR2 = 1 << InterruptNum;
	}

}

u8 NVIC_u8ReadActiveFlag(u8 InterruptNum)
{
	u8 Local_u8Acive = 0;
	if(InterruptNum < 32)
	{
		Local_u8Acive = GET_BIT(NVIC_IABR0,InterruptNum);
	}else if(InterruptNum < 64)
	{
		InterruptNum -= 32;
		Local_u8Acive = GET_BIT(NVIC_IABR1,InterruptNum);
	}
	else if(InterruptNum < 74)
	{
		InterruptNum -= 64;
		Local_u8Acive = GET_BIT(NVIC_IABR2,InterruptNum);
	}

return Local_u8Acive;
}

void NVIC_voidSetPriority(u8 InterruptNum,u8 priority)
{
	if(InterruptNum <= 73){
	NVIC_IPR[InterruptNum] = (priority << 4);
  }
}
