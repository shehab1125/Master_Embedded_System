/*
 * RCC_PRG.c
 *
 *  Created on: Aug 11, 2023
 *      Author: Shehab
 */

#include "LIB/BIT_math.h"
#include "LIB/STD_types.h"

#include "../../NTI_ARM/Inc/RCC/RCC_INT.h"
#include "../../NTI_ARM/Inc/RCC/RCC_reg.h"
#include"../../NTI_ARM/Inc/RCC/RCC_CFG.h"


void	RCC_voidSysClkInit(void){             //UNCOMPELETE

#if clock_mode == HSI_mode
	SET_BIT(RCC_CR,0);
	RCC_CFGR=0X00;
#endif
}



void	RCC_voidPerClkEn(u8 BusId, u8 PerId){
	switch (BusId) {
	case AHB_ID:
		SET_BIT(RCC_AHBENR,PerId);

		break;
	case APB1_ID:
		SET_BIT(RCC_APB1ENR	,PerId);
		break;
	case APB2_ID:
		SET_BIT(RCC_APB2ENR	,PerId);
		break;

	}

}

void	RCC_voidPerClkDis(u8 BusId, u8 PerId){
	switch (BusId) {
	case AHB_ID:
		CLR_BIT(RCC_AHBENR,PerId);

		break;
	case APB1_ID:
		CLR_BIT(RCC_APB1ENR	,PerId);
		break;
	case APB2_ID:
		CLR_BIT(RCC_APB2ENR	,PerId);
		break;

	}
}

/*
void	GPIO_SetPortADir( u8 DIR_ID){

	switch (DIR_ID) {
	case DIR_OUTPUT:
		SET_BIT(GPIO_MODER,10);
		break;
	}

}

void	GPIO_SetPortAVal( u8 VAL_ID){

	switch (VAL_ID) {
	case VAL_HIGH:
		SET_BIT(GPIO_ODR,5);
		break;
	}


}


 */
