/*
 * ADC_pri.h
 *
 *  Created on: Aug 31, 2022
 *      Author: Shehab
 */

#ifndef MCAL_ADC_ADC_CFG_H_
#define MCAL_ADC_ADC_CFG_H_

/****************************************************************/
/** !comment : Please Enter the Voltage Reference				*/
/** 		   VOLTAGE_REFERENCE can be : 						*/
/*					    					AREF 				*/
/*						    				AVCC 				*/
/*							    			INTERNAL			*/
/****************************************************************/

#define VOLTAGE_REFERENCE			AVCC



/****************************************************************/
/** !comment : Please Enter the ADJUSTMENT						*/
/** 		   ADJUSTMENT can be : 								*/
/*					    					RIGHT_ADJUSTMENT	*/
/*							    			LEFT_ADJUSTMENT		*/
/****************************************************************/
/****************************************************************/
/** NOTE	 : The preferred adjustment for a 8 bits Resolution	*/
/*				is LEFT_ADJUSTMENT and for a 10 bits Resolution	*/
/*				is RIGHT_ADJUSTMENT								*/
/****************************************************************/

#define ADJUSTMENT				LEFT_ADJUSTMENT


/****************************************************************/
/** !comment : Please Enter the Voltage Reference				*/
/** 		   VOLTAGE_REFERENCE can be : 						*/
/*					    					AVCC 				*/
/*						    				AREF 				*/
/*							    			INTERNAL			*/
/****************************************************************/

#define ADC_CHANNEL_NUMBER		DIO_U8_PIN_1

/****************************************************************/
/** !comment : Please Enter the Voltage Reference				*/
/** 		   VOLTAGE_REFERENCE can be : 						*/
/*					    					AVCC 				*/
/*						    				AREF 				*/
/*							    			INTERNAL			*/
/****************************************************************/

#define ADC_AUTO_TRIGGER_SOURCE		FREE_RUNNING_MODE

/****************************************************************/
/** !comment : Please Enter the Voltage Reference				*/
/** 		   VOLTAGE_REFERENCE can be : 						*/
/*					    					AVCC 				*/
/*						    				AREF 				*/
/*							    			INTERNAL			*/
/****************************************************************/

#define ADC_PRESCALLER				DIVID_BY_64

#define ADC0_ID   0
#define ADC1_ID   1
#define ADC2_ID   2
#define ADC3_ID   3
#define ADC4_ID   4
#define ADC5_ID   5
#define ADC6_ID   6
#define ADC7_ID   7

#define ANALOG_CHANNEL ADC0_ID


#endif /* MCAL_ADC_ADC_CFG_H_ */
