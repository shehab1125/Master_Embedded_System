/*
 * RCC_reg.h
 *
 *  Created on: Aug 11, 2023
 *      Author: Shehab
 */

#ifndef RCC_REG_H_
#define RCC_REG_H_


#define		RCC_BASE_ADD		(0x40021000)


#define		RCC_CR				*((volatile u32 *)(RCC_BASE_ADD + 0x00))
#define		RCC_CFGR			*((volatile u32 *)(RCC_BASE_ADD + 0x04))
#define		RCC_CIR				*((volatile u32 *)(RCC_BASE_ADD + 0x08))
#define		RCC_APB2RSTR		*((volatile u32 *)(RCC_BASE_ADD + 0x0C))
#define		RCC_APB1RSTRCR	    *((volatile u32 *)(RCC_BASE_ADD + 0x010))
#define		RCC_AHBENR			*((volatile u32 *)(RCC_BASE_ADD + 0x14))
#define		RCC_APB2ENR			*((volatile u32 *)(RCC_BASE_ADD + 0x18))
#define		RCC_APB1ENR			*((volatile u32 *)(RCC_BASE_ADD + 0x1C))
#define		RCC_BDCR			*((volatile u32 *)(RCC_BASE_ADD + 0x20))
#define		RCC_CSR				*((volatile u32 *)(RCC_BASE_ADD + 0x24))
#define		RCC_AHBRSTR			*((volatile u32 *)(RCC_BASE_ADD + 0x28))
#define		RCC_CFGR2			*((volatile u32 *)(RCC_BASE_ADD + 0x2C))
#define		RCC_CFGR3			*((volatile u32 *)(RCC_BASE_ADD + 0x30))


/*GPIO*/
#define		GPIO_MODER			*((volatile u32 *)(0x48000000))
#define		GPIO_ODR			*((volatile u32 *)(0x48000014))


#endif /* RCC_REG_H_ */
