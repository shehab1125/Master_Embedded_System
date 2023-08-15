/*
 * TIMER_prg.c
 *
 *  Created on: Sep 13, 2022
 *      Author: Shehab
 */
#include "../../LIB/STD_types.h"
#include "../../LIB/BIT_math.h"

#include "TIMER_reg.h"
#include "TIMER_int.h"
#include "TIMER_pri.h"
#include "TIMER _cfg.h"

//static void (*GLB_PTRF_TIM0_OVF) (void)= ADDRESS_NULL;
static void (*GLB_PTRF_TIM0_CTC) (void)= ADDRESS_NULL;

/*intialization of the timer ->>> enable timer -> prescaler -> timer  mode -> set oc0 pin state */
void MTIM0_vINT(){

	/*fast pwm mode */
	SET_BIT(TCCR0,6);
	SET_BIT(TCCR0,3);

	/*NON_INVERTING mode*/
	SET_BIT(TCCR0,5);
	CLR_BIT(TCCR0,4);

	/*set 8 prescaler */
	CLR_BIT(TCCR0,0);
	SET_BIT(TCCR0,1);
	CLR_BIT(TCCR0,2);



}

u8 MTIM0_read_data(void){

	return TCNT0;

}

/*set the preload to cpunt from the preload value*/
void MTIM0_vSetPreload(u8 Copy_u8PreloadValue){
	TCNT0 = Copy_u8PreloadValue ;

}

/*set OCR value to be the top counts to generate CTC flag*/
void MTIM0_vSetOCRValue(u8 Copy_u8OCRValue){

	OCR0=Copy_u8OCRValue;

}


/*set callback to execute ISR related with overflow event */
void MTIM0_vCallBack_OVRF(void(*Fptr)(void)){

}

/*set callback to execute ISR related with CTC event */
void MTIM0_vCallBack_CTC(void(*Fptr)(void)){
	GLB_PTRF_TIM0_CTC= Fptr;

}


/*ISR OF CTC*/
void __vector_10(void)   __attribute__((signal));
void __vector_10(void)
{

	GLB_PTRF_TIM0_CTC();

}

/*ISR OF OVERFLOW*/
void __vector_11(void)   __attribute__((signal));
void __vector_11(void)
{
	/*excute the ISR [user routine]*/

}
