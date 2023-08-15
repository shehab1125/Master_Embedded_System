/*
 * RCC_INT.h
 *
 *  Created on: Aug 11, 2023
 *      Author: Shehab
 */

#ifndef RCC_INT_H_
#define RCC_INT_H_

/*clock modes */
/*
 * HSI_mode
 * HSE _mode
 * PLL _mode
 */
#define  AHB_ID   0
#define  APB1_ID  1
#define  APB2_ID  2

/*perphrails*/
#define  GPIOA_id  17
#define  GPIOC_id  19

/*dirctions*/
#define  DIR_OUTPUT  0
#define  DIR_INPUT   1

/*VALUES*/
#define  VAL_HIGH  1
#define  VAL_LOW   0



void	RCC_voidSysClkInit(void); //RCC_CR , RCC_CFGR
// RCC_voidPerClkEn(RCC_AHB1, 17);
void	RCC_voidPerClkEn(u8 BusId, u8 PerId);
void	RCC_voidPerClkDis(u8 BusId, u8 PerId);

void	GPIO_SetPortADir( u8 DIR_ID);
void	GPIO_SetPortAVal( u8 VAL_ID);

#endif /* RCC_INT_H_ */
