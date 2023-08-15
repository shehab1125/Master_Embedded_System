/*
 * ADC_prg.c
 *
 *  Created on: Aug 31, 2022
 *      Author: Shehab
 */
#include "../../LIB/STD_types.h"
#include "../../LIB/BIT_math.h"
#include "ADC_cfg.h"

#include "ADC_int.h"
#include "ADC_reg.h"






void ADC_voidInit (void){

	//VOLTAGE_REFERENCE
	SET_BIT(ADMUX,6);
	CLR_BIT(ADMUX,7);

	//ADJUSTMENT
	CLR_BIT(ADMUX,5);

	// ADC_CHANNEL_NUMBER
#if ANALOG_CHANNEL==ADC0_ID
	CLR_BIT(ADMUX,0);
	CLR_BIT(ADMUX,1);
	CLR_BIT(ADMUX,2);
	CLR_BIT(ADMUX,3);
	CLR_BIT(ADMUX,4);

#elif ANALOG_CHANNEL ==ADC1_ID
	SET_BIT(ADMUX,0);
	CLR_BIT(ADMUX,1);
	CLR_BIT(ADMUX,2);
	CLR_BIT(ADMUX,3);
	CLR_BIT(ADMUX,4);

	/*complete */
#endif
	// disable ADC in initialization function
	CLR_BIT(ADCSRA,7);
	//disable ADC Auto Trigger in initialization function
	CLR_BIT(ADCSRA,5);
	// ADC Interrupt Flag ( Conversion Complete ) cleared by SW
	SET_BIT(ADCSRA,4);
	//ADC Interrupt Enable is cleared in initialization
	CLR_BIT(ADCSRA,3);
	//add prescaler
	CLR_BIT(ADCSRA,0);
	SET_BIT(ADCSRA,1);
	SET_BIT(ADCSRA,2);
}


//i have to review it
u16 ADC_u16ReadADCInMV(){
	u16 L_data=0;
	SET_BIT(ADCSRA,6);
	while(GET_BIT(ADCSRA,4)!=1);
	L_data=ADCL_DATA;
	SET_BIT(ADCSRA,4);
	return L_data;
}


void ADC_voidEnable(){
	SET_BIT(ADCSRA,3);
}

void ADC_voidInterrputEnable(){

}

void ADC_voidDisable(){
	CLR_BIT(ADCSRA,3);
}

void ADC_voidStartConversion(){
	SET_BIT(ADCSRA,6);
}

void ADC_voidAutoTrigger(){
	SET_BIT(ADCSRA,5);
	CLR_BIT(SFIOR,0);
	CLR_BIT(SFIOR,1);
	CLR_BIT(SFIOR,2);

}

