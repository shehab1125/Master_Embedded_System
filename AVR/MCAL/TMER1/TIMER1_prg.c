/* Inclusion */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"


#include "TIMER1_int.h"
#include "TIMER1_REG.h"


static void (*GLB_PTRF_TIM1_ICF)(void) = ADDRESS_NULL;

void TIM1_vINT(){

	/* STEP 1: SET PIN STATE OCIA ->>> NON INVERTING (CLEAR ON COMPARE MATCH AND SET ON TOP) */
	CLR_BIT(TCCR1A,6);
	SET_BIT(TCCR1A,7);
	/*STEP2: SELECT MODE 14 FAST PWM   */
	CLR_BIT(TCCR1A,0);
	SET_BIT(TCCR1A,1);
	SET_BIT(TCCR1B,3);
	SET_BIT(TCCR1B,4);
	/*STEP3: SET ICR1 = 19999 AS A TOP TO MAKE THE FREQ 50 HZ , T(PERIOD)= 20MSEC */
	ICR1 = 19999;
	/*STEP4:SET INTIAL POSITION FOR SERVO = ZERO*/
	OCR1A = 750;
	/*SET PRESCALER AS A 8_PRESCALER*/
	CLR_BIT(TCCR1B,0);
	SET_BIT(TCCR1B,1);
	CLR_BIT(TCCR1B,0);


}

void TIM1_vInputCaptureUnintMode(){
	/*INTIALIZE TIMER 1 IN NORMAL MODE*/
	CLR_BIT(TCCR1A,0);
	CLR_BIT(TCCR1A,1);
	CLR_BIT(TCCR1B,3);
	CLR_BIT(TCCR1B,4);

	/*sense the  RISING EDGE*/
	SET_BIT(TCCR1B,6);

	/*ENABLE THE INTURRPT OF ICU*/
	SET_BIT(TIMSK,5);


	/*SET TIMER PRESCALER AS 8 BIT PRESCALER */
	CLR_BIT(TCCR1B,0);
	SET_BIT(TCCR1B,1);
	CLR_BIT(TCCR1B,0);


}


u16 TIM1_vReadICR1(){
	return ICR1;
}

void TIM1_vSetOCR1AValue(u16 COPY_U16VALUE){
	OCR1A = COPY_U16VALUE;
}

void TIM1_vSetICR1AValue(u16 COPY_U16ICR1VAL){

	ICR1 = COPY_U16ICR1VAL;
}


void TIM1_vchangetriggering(u8 Copy_u8Triggring){
if(Copy_u8Triggring == RISING_EDEG){
		SET_BIT(TCCR1B,6);   //sense rising edge
	}
	else
	{
		CLR_BIT(TCCR1B,6);   //sense falling edge
	}
}

void TIM1_vSetCallback(void(*fptr)(void)){
GLB_PTRF_TIM1_ICF = fptr;
}

void TIM1_vDisable_ICU_Inturrpt(){
	CLR_BIT(TIMSK,5);
}




void __vector_6(void)   __attribute__((signal)) ;
void __vector_6(void)
{
	/*Execute The  ISR  */
	GLB_PTRF_TIM1_ICF() ;
}
