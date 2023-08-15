#include "../../LIB/STD_types.h"
#include "../../LIB/BIT_math.h"

#include <stddef.h>

#include "EXTI0_interface.h"
#include "EXTI0_privare.h"
#include "EXTI0_config.h"


 void (*EXT1_PFEXT)(void)=NULL;

void EXTI0_voidInit(void){

#if SENSE_MODE==EXTI0_FALLING
	 CLR_BIT(MCUCR,2);
	 SET_BIT(MCUCR,3);

#elif (SENSE_MODE==EXTI0_RISING)
SET_BIT(MCUCR,2);
SET_BIT(MCUCR,3);
	

#elif (SENSE_MODE==EXTI0_IOC)
SET_BIT(MCUCR,2);
SET_BIT(MCUCR,3);	

#elif (SENSE_MODE==EXTI0_LOW)
CLR_BIT(MCUCR,2);
CLR_BIT(MCUCR,3);	
#endif
//ENABLE the external interrupt
SET_BIT(GICR,7);
//CLEAR THE FLAG
SET_BIT(GIFR,7);
	
}

void EXTI0_voidDisable(void){
	CLR_BIT(GICR,7);
	
}

void EXT1SetCallBack(void (*copy_PF)(void)){
	(EXT1_PFEXT)=copy_PF;
}

void __vector_2(void) __attribute__((signal));
void __vector_2(void){
	EXT1_PFEXT();
}
