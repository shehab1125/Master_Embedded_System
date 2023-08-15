/*
 * RCC_PRI.h
 *
 *  Created on: Aug 11, 2023
 *      Author: Shehab
 */

#ifndef RCC_PRI_H_
#define RCC_PRI_H_

/*clock modes */

#define  HSI_mode     0
#define  HSE_mode     1
#define  PLL_mode     2




/*
 * RCC_PRG.c
 *
 *  Created on: Aug 11, 2023
 *      Author: Shehab
 */

#include "LIB/BIT_math.h"
#include "LIB/STD_types.h"

#include "../../NTI_ARM/Inc/GPIO/GPIO_INT.h"
#include "../../NTI_ARM/Inc/GPIO/GPIO_reg.h"
#include"../../NTI_ARM/Inc/GPIO/GPIO_CFG.h"



void DIO_vSetPinDir(u8 A_u8portId,u8 A_u8PinId,u8 A_u8Dir,u8 A_u8Mode){
	switch (A_u8portId){
	case PORTA_ID:
		switch (A_u8Dir){
		case DIR_INPUT:
			switch (A_u8Mode){

			case INPUT_FLOAT :
				//input mode
				CLR_BIT(GPIOA_MODER,2*A_u8PinId);
				CLR_BIT(GPIOA_MODER,((2*A_u8PinId)+1));

				//float
				CLR_BIT(GPIOA_PUPDR,2*A_u8PinId);;
				CLR_BIT(GPIOA_PUPDR,((2*A_u8PinId)+1));
				break;
			case INPUT_PULL_UP :
				//input mode
				CLR_BIT(GPIOA_MODER,((2*A_u8PinId)+1));
				CLR_BIT(GPIOA_MODER,((2*A_u8PinId)+1));

				//pull_up
				SET_BIT(GPIOA_PUPDR,((2*A_u8PinId)+1));
				CLR_BIT(GPIOA_PUPDR,((2*A_u8PinId)+1));

				break;
			case INPUT_PULL_DOWN :
				//input mode
				CLR_BIT(GPIOA_MODER,((2*A_u8PinId)+1));
				CLR_BIT(GPIOA_MODER,1);

				//pull_down
				CLR_BIT(GPIOA_PUPDR,((2*A_u8PinId)+1));
				SET_BIT(GPIOA_PUPDR,((2*A_u8PinId)+1));

				break;
			case INPUT_ANALOG :
				//analog mode
				SET_BIT(GPIOA_MODER,((2*A_u8PinId)+1));
				SET_BIT(GPIOA_MODER,((2*A_u8PinId)+1));

				break;
			}
			break;
			case DIR_OUTPUT:
				switch (A_u8Mode){

				case OUTPUT_PUSH_PULL_LOW_FREQ :
					//OUTPUT MODE
					SET_BIT(GPIOA_MODER,2*A_u8PinId);
					CLR_BIT(GPIOA_MODER,((2*A_u8PinId)+1));
					//PUSH_PULL
					CLR_BIT(GPIOA_OTYPER,A_u8PinId);
					//LOW_FREQ
					CLR_BIT(GPIOA_OSPEEDR,2*A_u8PinId);
					break;
				case OUTPUT_PUSH_PULL_MID_FREQ :
					//OUTPUT MODE
					SET_BIT(GPIOA_MODER,2*A_u8PinId);
					CLR_BIT(GPIOA_MODER,((2*A_u8PinId)+1));
					//PUSH_PULL
					CLR_BIT(GPIOA_OTYPER,A_u8PinId);
					//MID_FREQ
					SET_BIT(GPIOA_OSPEEDR,2*A_u8PinId);
					CLR_BIT(GPIOA_OSPEEDR,((2*A_u8PinId)+1));
					break;
				case OUTPUT_PUSH_PULL_HIGH_FREQ :
					//OUTPUT MODE
					SET_BIT(GPIOA_MODER,2*A_u8PinId);
					CLR_BIT(GPIOA_MODER,((2*A_u8PinId)+1));
					//PUSH_PULL
					CLR_BIT(GPIOA_OTYPER,A_u8PinId);
					//HIGH_FREQ
					SET_BIT(GPIOA_OSPEEDR,2*A_u8PinId);
					SET_BIT(GPIOA_OSPEEDR,((2*A_u8PinId)+1));
					break;
				case OUTPUT_OPEN_DRAIN_LOW_FREQ :
					//OUTPUT MODE
					SET_BIT(GPIOA_MODER,2*A_u8PinId);
					CLR_BIT(GPIOA_MODER,((2*A_u8PinId)+1));
					//OPEN DRAIN
					SET_BIT(GPIOA_OTYPER,A_u8PinId);
					//LOW_FREQ
					CLR_BIT(GPIOA_OSPEEDR,2*A_u8PinId);
					break;
				case OUTPUT_OPEN_DRAIN_MID_FREQ :
					//OUTPUT MODE
					SET_BIT(GPIOA_MODER,2*A_u8PinId);
					CLR_BIT(GPIOA_MODER,((2*A_u8PinId)+1));
					//OPEN DRAIN
					SET_BIT(GPIOA_OTYPER,A_u8PinId);
					//MID_FREQ
					SET_BIT(GPIOA_OSPEEDR,2*A_u8PinId);
					CLR_BIT(GPIOA_OSPEEDR,((2*A_u8PinId)+1));
					break;
				case OUTPUT_OPEN_DRAIN_HIGH_FREQ :
					//OUTPUT MODE
					SET_BIT(GPIOA_MODER,2*A_u8PinId);
					CLR_BIT(GPIOA_MODER,((2*A_u8PinId)+1));
					//OPEN DRAIN
					SET_BIT(GPIOA_OTYPER,A_u8PinId);
					//HIGH_FREQ
					SET_BIT(GPIOA_OSPEEDR,2*A_u8PinId);
					SET_BIT(GPIOA_OSPEEDR,((2*A_u8PinId)+1));
					break;
				case OUTPUT_ALTRNATIVE_PUSH_PULL:
					//ALTARNATIVE
					CLR_BIT(GPIOA_MODER,2*A_u8PinId);
					SET_BIT(GPIOA_MODER,((2*A_u8PinId)+1));
					//PUSH_PULL
					CLR_BIT(GPIOA_OTYPER,A_u8PinId);
					break;
				case OUTPUT_ALTRNATIVE_OPEN_DRAIN:
					//ALTARNATIVE
					CLR_BIT(GPIOA_MODER,2*A_u8PinId);
					SET_BIT(GPIOA_MODER,((2*A_u8PinId)+1));
					//OPEN DRAIN
					SET_BIT(GPIOA_OTYPER,A_u8PinId);
					break;
				}
				break;
		}
		break;
		case PORTB_ID:
			switch (A_u8Dir){
			case DIR_INPUT:
				switch (A_u8Mode){

				case INPUT_FLOAT :
					//input mode
					CLR_BIT(GPIOB_MODER,2*A_u8PinId);
					CLR_BIT(GPIOB_MODER,((2*A_u8PinId)+1));

					//float
					CLR_BIT(GPIOB_PUPDR,2*A_u8PinId);
					CLR_BIT(GPIOB_PUPDR,((2*A_u8PinId)+1));
					break;
				case INPUT_PULL_UP :
					//input mode
					CLR_BIT(GPIOB_MODER,2*A_u8PinId);
					CLR_BIT(GPIOB_MODER,((2*A_u8PinId)+1));

					//pull_up
					SET_BIT(GPIOB_PUPDR,2*A_u8PinId);
					CLR_BIT(GPIOB_PUPDR,((2*A_u8PinId)+1));

					break;
				case INPUT_PULL_DOWN :
					//input mode
					CLR_BIT(GPIOB_MODER,2*A_u8PinId);
					CLR_BIT(GPIOB_MODER,((2*A_u8PinId)+1));

					//pull_down
					CLR_BIT(GPIOB_PUPDR,2*A_u8PinId);
					SET_BIT(GPIOB_PUPDR,((2*A_u8PinId)+1));

					break;
				case INPUT_ANALOG :
					//analog mode
					SET_BIT(GPIOB_MODER,2*A_u8PinId);
					SET_BIT(GPIOB_MODER,((2*A_u8PinId)+1));

					break;
				}
				break;
				case DIR_OUTPUT:
					switch (A_u8Mode){

					case OUTPUT_PUSH_PULL_LOW_FREQ :
						//OUTPUT MODE
						SET_BIT(GPIOB_MODER,2*A_u8PinId);
						CLR_BIT(GPIOB_MODER,((2*A_u8PinId)+1));
						//PUSH_PULL
						CLR_BIT(GPIOB_OTYPER,A_u8PinId);
						//LOW_FREQ
						CLR_BIT(GPIOB_OSPEEDR,2*A_u8PinId);
						break;
					case OUTPUT_PUSH_PULL_MID_FREQ :
						//OUTPUT MODE
						SET_BIT(GPIOB_MODER,2*A_u8PinId);
						CLR_BIT(GPIOB_MODER,((2*A_u8PinId)+1));
						//PUSH_PULL
						CLR_BIT(GPIOB_OTYPER,A_u8PinId);
						//MID_FREQ
						SET_BIT(GPIOB_OSPEEDR,2*A_u8PinId);
						CLR_BIT(GPIOB_OSPEEDR,((2*A_u8PinId)+1));
						break;
					case OUTPUT_PUSH_PULL_HIGH_FREQ :
						//OUTPUT MODE
						SET_BIT(GPIOB_MODER,2*A_u8PinId);
						CLR_BIT(GPIOB_MODER,((2*A_u8PinId)+1));
						//PUSH_PULL
						CLR_BIT(GPIOB_OTYPER,A_u8PinId);
						//HIGH_FREQ
						SET_BIT(GPIOB_OSPEEDR,2*A_u8PinId);
						SET_BIT(GPIOB_OSPEEDR,((2*A_u8PinId)+1));
						break;
					case OUTPUT_OPEN_DRAIN_LOW_FREQ :
						//OUTPUT MODE
						SET_BIT(GPIOB_MODER,2*A_u8PinId);
						CLR_BIT(GPIOB_MODER,((2*A_u8PinId)+1));
						//OPEN DRAIN
						SET_BIT(GPIOB_OTYPER,A_u8PinId);
						//LOW_FREQ
						CLR_BIT(GPIOB_OSPEEDR,2*A_u8PinId);
						break;
					case OUTPUT_OPEN_DRAIN_MID_FREQ :
						//OUTPUT MODE
						SET_BIT(GPIOB_MODER,2*A_u8PinId);
						CLR_BIT(GPIOB_MODER,((2*A_u8PinId)+1));
						//OPEN DRAIN
						SET_BIT(GPIOB_OTYPER,A_u8PinId);
						//MID_FREQ
						SET_BIT(GPIOB_OSPEEDR,2*A_u8PinId);
						CLR_BIT(GPIOB_OSPEEDR,((2*A_u8PinId)+1));
						break;
					case OUTPUT_OPEN_DRAIN_HIGH_FREQ :
						//OUTPUT MODE
						SET_BIT(GPIOB_MODER,2*A_u8PinId);
						CLR_BIT(GPIOB_MODER,((2*A_u8PinId)+1));
						//OPEN DRAIN
						SET_BIT(GPIOB_OTYPER,A_u8PinId);
						//HIGH_FREQ
						SET_BIT(GPIOB_OSPEEDR,2*A_u8PinId);
						SET_BIT(GPIOB_OSPEEDR,((2*A_u8PinId)+1));
						break;
					case OUTPUT_ALTRNATIVE_PUSH_PULL:
						//ALTARNATIVE
						CLR_BIT(GPIOB_MODER,2*A_u8PinId);
						SET_BIT(GPIOB_MODER,((2*A_u8PinId)+1));
						//PUSH_PULL
						CLR_BIT(GPIOB_OTYPER,A_u8PinId);
						break;
					case OUTPUT_ALTRNATIVE_OPEN_DRAIN:
						//ALTARNATIVE
						CLR_BIT(GPIOB_MODER,2*A_u8PinId);
						SET_BIT(GPIOB_MODER,((2*A_u8PinId)+1));
						//OPEN DRAIN
						SET_BIT(GPIOB_OTYPER,A_u8PinId);
						break;
					}
					break;
			}

			break;
			case PORTC_ID:
				switch (A_u8Dir){
				case DIR_INPUT:
					switch (A_u8Mode){

					case INPUT_FLOAT :
						//input mode
						CLR_BIT(GPIOC_MODER,2*A_u8PinId);
						CLR_BIT(GPIOC_MODER,((2*A_u8PinId)+1));

						//float
						CLR_BIT(GPIOC_PUPDR,2*A_u8PinId);
						CLR_BIT(GPIOC_PUPDR,((2*A_u8PinId)+1));
						break;
					case INPUT_PULL_UP :
						//input mode
						CLR_BIT(GPIOC_MODER,2*A_u8PinId);
						CLR_BIT(GPIOC_MODER,((2*A_u8PinId)+1));

						//pull_up
						SET_BIT(GPIOC_PUPDR,2*A_u8PinId);
						CLR_BIT(GPIOC_PUPDR,((2*A_u8PinId)+1));

						break;
					case INPUT_PULL_DOWN :
						//input mode
						CLR_BIT(GPIOC_MODER,2*A_u8PinId);
						CLR_BIT(GPIOC_MODER,((2*A_u8PinId)+1));

						//pull_down
						CLR_BIT(GPIOC_PUPDR,2*A_u8PinId);
						SET_BIT(GPIOC_PUPDR,((2*A_u8PinId)+1));

						break;
					case INPUT_ANALOG :
						//analog mode
						SET_BIT(GPIOC_MODER,2*A_u8PinId);
						SET_BIT(GPIOC_MODER,((2*A_u8PinId)+1));

						break;
					}
					break;
					case DIR_OUTPUT:
						switch (A_u8Mode){

						case OUTPUT_PUSH_PULL_LOW_FREQ :
							//OUTPUT MODE
							SET_BIT(GPIOC_MODER,2*A_u8PinId);
							CLR_BIT(GPIOC_MODER,((2*A_u8PinId)+1));
							//PUSH_PULL
							CLR_BIT(GPIOC_OTYPER,A_u8PinId);
							//LOW_FREQ
							CLR_BIT(GPIOC_OSPEEDR,2*A_u8PinId);
							break;
						case OUTPUT_PUSH_PULL_MID_FREQ :
							//OUTPUT MODE
							SET_BIT(GPIOC_MODER,2*A_u8PinId);
							CLR_BIT(GPIOC_MODER,((2*A_u8PinId)+1));
							//PUSH_PULL
							CLR_BIT(GPIOC_OTYPER,A_u8PinId);
							//MID_FREQ
							SET_BIT(GPIOC_OSPEEDR,2*A_u8PinId);
							CLR_BIT(GPIOC_OSPEEDR,((2*A_u8PinId)+1));
							break;
						case OUTPUT_PUSH_PULL_HIGH_FREQ :
							//OUTPUT MODE
							SET_BIT(GPIOC_MODER,2*A_u8PinId);
							CLR_BIT(GPIOC_MODER,((2*A_u8PinId)+1));
							//PUSH_PULL
							CLR_BIT(GPIOC_OTYPER,A_u8PinId);
							//HIGH_FREQ
							SET_BIT(GPIOC_OSPEEDR,2*A_u8PinId);
							SET_BIT(GPIOC_OSPEEDR,((2*A_u8PinId)+1));
							break;
						case OUTPUT_OPEN_DRAIN_LOW_FREQ :
							//OUTPUT MODE
							SET_BIT(GPIOC_MODER,2*A_u8PinId);
							CLR_BIT(GPIOC_MODER,((2*A_u8PinId)+1));
							//OPEN DRAIN
							SET_BIT(GPIOC_OTYPER,A_u8PinId);
							//LOW_FREQ
							CLR_BIT(GPIOC_OSPEEDR,2*A_u8PinId);
							break;
						case OUTPUT_OPEN_DRAIN_MID_FREQ :
							//OUTPUT MODE
							SET_BIT(GPIOC_MODER,2*A_u8PinId);
							CLR_BIT(GPIOC_MODER,((2*A_u8PinId)+1));
							//OPEN DRAIN
							SET_BIT(GPIOC_OTYPER,A_u8PinId);
							//MID_FREQ
							SET_BIT(GPIOC_OSPEEDR,2*A_u8PinId);
							CLR_BIT(GPIOC_OSPEEDR,((2*A_u8PinId)+1));
							break;
						case OUTPUT_OPEN_DRAIN_HIGH_FREQ :
							//OUTPUT MODE
							SET_BIT(GPIOC_MODER,2*A_u8PinId);
							CLR_BIT(GPIOC_MODER,((2*A_u8PinId)+1));
							//OPEN DRAIN
							SET_BIT(GPIOC_OTYPER,A_u8PinId);
							//HIGH_FREQ
							SET_BIT(GPIOC_OSPEEDR,2*A_u8PinId);
							SET_BIT(GPIOC_OSPEEDR,((2*A_u8PinId)+1));
							break;
						case OUTPUT_ALTRNATIVE_PUSH_PULL:
							//ALTARNATIVE
							CLR_BIT(GPIOC_MODER,2*A_u8PinId);
							SET_BIT(GPIOC_MODER,((2*A_u8PinId)+1));
							//PUSH_PULL
							CLR_BIT(GPIOC_OTYPER,A_u8PinId);
							break;
						case OUTPUT_ALTRNATIVE_OPEN_DRAIN:
							//ALTARNATIVE
							CLR_BIT(GPIOC_MODER,2*A_u8PinId);
							SET_BIT(GPIOC_MODER,((2*A_u8PinId)+1));
							//OPEN DRAIN
							SET_BIT(GPIOC_OTYPER,A_u8PinId);
							break;
						}
						break;
				}

				break;
				case PORTD_ID:
					switch (A_u8Dir){
					case DIR_INPUT:
						switch (A_u8Mode){

						case INPUT_FLOAT :
							//input mode
							CLR_BIT(GPIOD_MODER,2*A_u8PinId);
							CLR_BIT(GPIOD_MODER,((2*A_u8PinId)+1));

							//float
							CLR_BIT(GPIOD_PUPDR,2*A_u8PinId);
							CLR_BIT(GPIOD_PUPDR,((2*A_u8PinId)+1));
							break;
						case INPUT_PULL_UP :
							//input mode
							CLR_BIT(GPIOD_MODER,2*A_u8PinId);
							CLR_BIT(GPIOD_MODER,((2*A_u8PinId)+1));

							//pull_up
							SET_BIT(GPIOD_PUPDR,2*A_u8PinId);
							CLR_BIT(GPIOD_PUPDR,((2*A_u8PinId)+1));

							break;
						case INPUT_PULL_DOWN :
							//input mode
							CLR_BIT(GPIOD_MODER,2*A_u8PinId);
							CLR_BIT(GPIOD_MODER,((2*A_u8PinId)+1));

							//pull_down
							CLR_BIT(GPIOD_PUPDR,2*A_u8PinId);
							SET_BIT(GPIOD_PUPDR,((2*A_u8PinId)+1));

							break;
						case INPUT_ANALOG :
							//analog mode
							SET_BIT(GPIOD_MODER,2*A_u8PinId);
							SET_BIT(GPIOD_MODER,((2*A_u8PinId)+1));

							break;
						}
						break;
						case DIR_OUTPUT:
							switch (A_u8Mode){

							case OUTPUT_PUSH_PULL_LOW_FREQ :
								//OUTPUT MODE
								SET_BIT(GPIOD_MODER,2*A_u8PinId);
								CLR_BIT(GPIOD_MODER,((2*A_u8PinId)+1));
								//PUSH_PULL
								CLR_BIT(GPIOD_OTYPER,A_u8PinId);
								//LOW_FREQ
								CLR_BIT(GPIOD_OSPEEDR,2*A_u8PinId);
								break;
							case OUTPUT_PUSH_PULL_MID_FREQ :
								//OUTPUT MODE
								SET_BIT(GPIOD_MODER,2*A_u8PinId);
								CLR_BIT(GPIOD_MODER,((2*A_u8PinId)+1));
								//PUSH_PULL
								CLR_BIT(GPIOD_OTYPER,A_u8PinId);
								//MID_FREQ
								SET_BIT(GPIOD_OSPEEDR,2*A_u8PinId);
								CLR_BIT(GPIOD_OSPEEDR,((2*A_u8PinId)+1));
								break;
							case OUTPUT_PUSH_PULL_HIGH_FREQ :
								//OUTPUT MODE
								SET_BIT(GPIOD_MODER,2*A_u8PinId);
								CLR_BIT(GPIOD_MODER,((2*A_u8PinId)+1));
								//PUSH_PULL
								CLR_BIT(GPIOD_OTYPER,A_u8PinId);
								//HIGH_FREQ
								SET_BIT(GPIOD_OSPEEDR,2*A_u8PinId);
								SET_BIT(GPIOD_OSPEEDR,((2*A_u8PinId)+1));
								break;
							case OUTPUT_OPEN_DRAIN_LOW_FREQ :
								//OUTPUT MODE
								SET_BIT(GPIOD_MODER,2*A_u8PinId);
								CLR_BIT(GPIOD_MODER,((2*A_u8PinId)+1));
								//OPEN DRAIN
								SET_BIT(GPIOD_OTYPER,A_u8PinId);
								//LOW_FREQ
								CLR_BIT(GPIOD_OSPEEDR,2*A_u8PinId);
								break;
							case OUTPUT_OPEN_DRAIN_MID_FREQ :
								//OUTPUT MODE
								SET_BIT(GPIOD_MODER,2*A_u8PinId);
								CLR_BIT(GPIOD_MODER,((2*A_u8PinId)+1));
								//OPEN DRAIN
								SET_BIT(GPIOD_OTYPER,A_u8PinId);
								//MID_FREQ
								SET_BIT(GPIOD_OSPEEDR,2*A_u8PinId);
								CLR_BIT(GPIOD_OSPEEDR,((2*A_u8PinId)+1));
								break;
							case OUTPUT_OPEN_DRAIN_HIGH_FREQ :
								//OUTPUT MODE
								SET_BIT(GPIOD_MODER,2*A_u8PinId);
								CLR_BIT(GPIOD_MODER,((2*A_u8PinId)+1));
								//OPEN DRAIN
								SET_BIT(GPIOD_OTYPER,A_u8PinId);
								//HIGH_FREQ
								SET_BIT(GPIOD_OSPEEDR,2*A_u8PinId);
								SET_BIT(GPIOD_OSPEEDR,((2*A_u8PinId)+1));
								break;
							case OUTPUT_ALTRNATIVE_PUSH_PULL:
								//ALTARNATIVE
								CLR_BIT(GPIOD_MODER,2*A_u8PinId);
								SET_BIT(GPIOD_MODER,((2*A_u8PinId)+1));
								//PUSH_PULL
								CLR_BIT(GPIOD_OTYPER,A_u8PinId);
								break;
							case OUTPUT_ALTRNATIVE_OPEN_DRAIN:
								//ALTARNATIVE
								CLR_BIT(GPIOD_MODER,2*A_u8PinId);
								SET_BIT(GPIOD_MODER,((2*A_u8PinId)+1));
								//OPEN DRAIN
								SET_BIT(GPIOD_OTYPER,A_u8PinId);
								break;
							}
							break;
					}
					break;
					case PORTF_ID:
						switch (A_u8Dir){
						case DIR_INPUT:
							switch (A_u8Mode){

							case INPUT_FLOAT :
								//input mode
								CLR_BIT(GPIOF_MODER,2*A_u8PinId);
								CLR_BIT(GPIOF_MODER,((2*A_u8PinId)+1));

								//float
								CLR_BIT(GPIOF_PUPDR,2*A_u8PinId);
								CLR_BIT(GPIOF_PUPDR,((2*A_u8PinId)+1));
								break;
							case INPUT_PULL_UP :
								//input mode
								CLR_BIT(GPIOF_MODER,2*A_u8PinId);
								CLR_BIT(GPIOF_MODER,((2*A_u8PinId)+1));

								//pull_up
								SET_BIT(GPIOF_PUPDR,2*A_u8PinId);
								CLR_BIT(GPIOF_PUPDR,((2*A_u8PinId)+1));

								break;
							case INPUT_PULL_DOWN :
								//input mode
								CLR_BIT(GPIOF_MODER,2*A_u8PinId);
								CLR_BIT(GPIOF_MODER,((2*A_u8PinId)+1));

								//pull_down
								CLR_BIT(GPIOF_PUPDR,2*A_u8PinId);
								SET_BIT(GPIOF_PUPDR,((2*A_u8PinId)+1));

								break;
							case INPUT_ANALOG :
								//analog mode
								SET_BIT(GPIOF_MODER,2*A_u8PinId);
								SET_BIT(GPIOF_MODER,((2*A_u8PinId)+1));

								break;
							}
							break;
							case DIR_OUTPUT:
								switch (A_u8Mode){

								case OUTPUT_PUSH_PULL_LOW_FREQ :
									//OUTPUT MODE
									SET_BIT(GPIOF_MODER,2*A_u8PinId);
									CLR_BIT(GPIOF_MODER,((2*A_u8PinId)+1));
									//PUSH_PULL
									CLR_BIT(GPIOF_OTYPER,A_u8PinId);
									//LOW_FREQ
									CLR_BIT(GPIOF_OSPEEDR,2*A_u8PinId);
									break;
								case OUTPUT_PUSH_PULL_MID_FREQ :
									//OUTPUT MODE
									SET_BIT(GPIOF_MODER,2*A_u8PinId);
									CLR_BIT(GPIOF_MODER,((2*A_u8PinId)+1));
									//PUSH_PULL
									CLR_BIT(GPIOF_OTYPER,A_u8PinId);
									//MID_FREQ
									SET_BIT(GPIOF_OSPEEDR,2*A_u8PinId);
									CLR_BIT(GPIOF_OSPEEDR,((2*A_u8PinId)+1));
									break;
								case OUTPUT_PUSH_PULL_HIGH_FREQ :
									//OUTPUT MODE
									SET_BIT(GPIOF_MODER,2*A_u8PinId);
									CLR_BIT(GPIOF_MODER,((2*A_u8PinId)+1));
									//PUSH_PULL
									CLR_BIT(GPIOF_OTYPER,A_u8PinId);
									//HIGH_FREQ
									SET_BIT(GPIOF_OSPEEDR,2*A_u8PinId);
									SET_BIT(GPIOF_OSPEEDR,((2*A_u8PinId)+1));
									break;
								case OUTPUT_OPEN_DRAIN_LOW_FREQ :
									//OUTPUT MODE
									SET_BIT(GPIOF_MODER,2*A_u8PinId);
									CLR_BIT(GPIOF_MODER,((2*A_u8PinId)+1));
									//OPEN DRAIN
									SET_BIT(GPIOF_OTYPER,A_u8PinId);
									//LOW_FREQ
									CLR_BIT(GPIOF_OSPEEDR,2*A_u8PinId);
									break;
								case OUTPUT_OPEN_DRAIN_MID_FREQ :
									//OUTPUT MODE
									SET_BIT(GPIOF_MODER,2*A_u8PinId);
									CLR_BIT(GPIOF_MODER,((2*A_u8PinId)+1));
									//OPEN DRAIN
									SET_BIT(GPIOF_OTYPER,A_u8PinId);
									//MID_FREQ
									SET_BIT(GPIOF_OSPEEDR,2*A_u8PinId);
									CLR_BIT(GPIOF_OSPEEDR,((2*A_u8PinId)+1));
									break;
								case OUTPUT_OPEN_DRAIN_HIGH_FREQ :
									//OUTPUT MODE
									SET_BIT(GPIOF_MODER,2*A_u8PinId);
									CLR_BIT(GPIOF_MODER,((2*A_u8PinId)+1));
									//OPEN DRAIN
									SET_BIT(GPIOF_OTYPER,A_u8PinId);
									//HIGH_FREQ
									SET_BIT(GPIOF_OSPEEDR,2*A_u8PinId);
									SET_BIT(GPIOF_OSPEEDR,((2*A_u8PinId)+1));
									break;
								case OUTPUT_ALTRNATIVE_PUSH_PULL:
									//ALTARNATIVE
									CLR_BIT(GPIOF_MODER,2*A_u8PinId);
									SET_BIT(GPIOF_MODER,((2*A_u8PinId)+1));
									//PUSH_PULL
									CLR_BIT(GPIOF_OTYPER,A_u8PinId);
									break;
								case OUTPUT_ALTRNATIVE_OPEN_DRAIN:
									//ALTARNATIVE
									CLR_BIT(GPIOF_MODER,2*A_u8PinId);
									SET_BIT(GPIOF_MODER,((2*A_u8PinId)+1));
									//OPEN DRAIN
									SET_BIT(GPIOF_OTYPER,A_u8PinId);
									break;
								}
								break;
						}

						break;

	}


}



void DIO_vSetPinVal(u8 A_u8portId,u8 A_u8PinId,u8 A_u8Val){
	switch (A_u8portId){
	case PORTA_ID:WRT_BIT(GPIOA_ODR, A_u8PinId ,  A_u8Val); break;
	case PORTB_ID:WRT_BIT(GPIOB_ODR, A_u8PinId ,  A_u8Val); break;
	case PORTC_ID:WRT_BIT(GPIOC_ODR, A_u8PinId ,  A_u8Val); break;
	case PORTD_ID:WRT_BIT(GPIOD_ODR, A_u8PinId ,  A_u8Val); break;
	case PORTF_ID:WRT_BIT(GPIOF_ODR, A_u8PinId ,  A_u8Val); break;
	}

}

u8 DIO_u8GetPinVal(u8 A_u8portId,u8 A_u8PinId){
	u8 L_u8PinVal = 0;
	switch ( A_u8portId){
	case PORTA_ID: L_u8PinVal = GET_BIT(GPIOA_ODR, A_u8PinId); break;
	case PORTB_ID: L_u8PinVal = GET_BIT(GPIOB_ODR, A_u8PinId); break;
	case PORTC_ID: L_u8PinVal = GET_BIT(GPIOC_ODR, A_u8PinId); break;
	case PORTD_ID: L_u8PinVal = GET_BIT(GPIOD_ODR, A_u8PinId); break;
	case PORTF_ID: L_u8PinVal = GET_BIT(GPIOF_ODR, A_u8PinId); break;

	}
	return L_u8PinVal;

}























#endif /* RCC_PRI_H_ */
