/*
 * ADC_reg.h
 *
 *  Created on: Aug 31, 2022
 *      Author: Shehab
 */

#ifndef MCAL_ADC_ADC_REG_H_
#define MCAL_ADC_ADC_REG_H_

#define ADMUX        *((volatile u8*)0x27)
#define ADCSRA       *((volatile u8*)0x26)
#define ADCH         *((volatile u8*)0x25)
#define ADCL         *((volatile u8*)0x24)
#define SFIOR        *((volatile u8*)0x50)

#define ADCL_DATA    *((volatile u16*)0x24)

#endif /* MCAL_ADC_ADC_REG_H_ */
