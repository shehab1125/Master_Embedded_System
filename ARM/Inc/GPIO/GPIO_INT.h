/*
 * RCC_INT.h
 *
 *  Created on: Aug 11, 2023
 *      Author: Shehab
 */

#ifndef GPIO_INT_H_
#define GPIO_INT_H_


#define PORTA_ID      0
#define PORTB_ID      1
#define PORTC_ID      2
#define PORTD_ID      3
#define PORTF_ID      4

#define PIN0_ID       0
#define PIN1_ID       1
#define PIN2_ID       2
#define PIN3_ID       3
#define PIN4_ID       4
#define PIN5_ID       5
#define PIN6_ID       6
#define PIN7_ID       7
#define PIN8_ID       8
#define PIN9_ID       9
#define PIN10_ID      10
#define PIN11_ID      11
#define PIN12_ID      12
#define PIN13_ID      13
#define PIN14_ID      14
#define PIN15_ID      15




#define DIR_OUTPUT_ALL 0X55555555;
#define DIR_INPUT_ALL  0


#define VAL_HIGH      1
#define VAL_LOW       0

#define VAL_HIGH_ALL  0XFFFF
#define VAL_LOW_ALL   0

/*modes*/
#define INPUT_FLOAT                   0
#define INPUT_PULL_UP                 1
#define INPUT_PULL_DOWN               2
#define INPUT_ANALOG                  3
#define OUTPUT_PUSH_PULL_LOW_FREQ     4
#define OUTPUT_PUSH_PULL_MID_FREQ     5
#define OUTPUT_PUSH_PULL_HIGH_FREQ    6
#define OUTPUT_OPEN_DRAIN_LOW_FREQ    7
#define OUTPUT_OPEN_DRAIN_MID_FREQ    8
#define OUTPUT_OPEN_DRAIN_HIGH_FREQ   9
#define OUTPUT_ALTRNATIVE_PUSH_PULL   10
#define OUTPUT_ALTRNATIVE_OPEN_DRAIN  11





void DIO_vSetPinDir(u8 A_u8portId,u8 A_u8PinId,u8 A_u8Mode);

void DIO_vSetPinVal(u8 A_u8portId,u8 A_u8PinId,u8 A_u8Val);

u8 DIO_u8GetPinVal(u8 A_u8portId,u8 A_u8PinId);

void DIO_vSetPortDir(u8 A_u8portId,u8 A_u8Dir,u8 A_u8Mode);

void DIO_vSetPortVal(u8 A_u8portId,u8 A_u8Val);

void DIO_vTogglePinVal(u8 A_u8PortId,u8 A_u8PinId);


#endif /* GPIO_INT_H_ */
