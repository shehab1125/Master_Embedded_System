/*
 * NVIC_REG.h
 *
 *  Created on: Aug 13, 2023
 *      Author: Shehab
 */

#ifndef NVIC_NVIC_REG_H_
#define NVIC_NVIC_REG_H_



#define		NVIC_ISER0				*((volatile u32 *)0xE000E100)	//Enable Interrupt From 0 to 31
#define		NVIC_ISER1				*((volatile u32 *)0xE000E104)	//Enable Interrupt From 32 to 63
#define		NVIC_ISER2				*((volatile u32 *)0xE000E108)	//Enable Interrupt From 64 to 73

#define		NVIC_ICER0				*((volatile u32 *)0xE000E180)	//Disable Interrupt From 0 to 31
#define		NVIC_ICER1				*((volatile u32 *)0xE000E184)	//Disable Interrupt From 32 to 63
#define		NVIC_ICER2				*((volatile u32 *)0xE000E188)	//Disable Interrupt From 64 to 73

#define		NVIC_ISPR0				*((volatile u32 *)0xE000E200)	//SET Pending Flag From 0 to 31
#define		NVIC_ISPR1				*((volatile u32 *)0xE000E204)	//SET Pending Flag From 32 to 63
#define		NVIC_ISPR2				*((volatile u32 *)0xE000E208)	//SET Pending Flag From 64 to 73

#define		NVIC_ICPR0				*((volatile u32 *)0xE000E280)	//Clear Pending Flag From 0 to 31
#define		NVIC_ICPR1				*((volatile u32 *)0xE000E284)   //Clear Pending Flag From 32 to 63
#define		NVIC_ICPR2				*((volatile u32 *)0xE000E288)   //Clear Pending Flag From 64 to 73

#define		NVIC_IABR0				*((volatile u32 *)0xE000E300)	// Interrupt Active Bit From 0 to 31
#define		NVIC_IABR1				*((volatile u32 *)0xE000E304)	// Interrupt Active Bit From 32 to 63
#define		NVIC_IABR2				*((volatile u32 *)0xE000E308)	// Interrupt Active Bit From 64 to 73

#define		NVIC_IPR				((volatile u8 *)0xE000E400)




#endif /* NVIC_NVIC_REG_H_ */
