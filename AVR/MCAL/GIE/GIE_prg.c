/*
 * GIE_prg.c
 *
 *  Created on: 29 Aug 2022
 *      Author: Mohamed Osama
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "GIE_reg.h"
#include "GIE_int.h"

void GIE_vEnable(){
	SET_BIT(SREG,7);
}

void GIE_vDisable(){
	CLR_BIT(SREG,7);
}
