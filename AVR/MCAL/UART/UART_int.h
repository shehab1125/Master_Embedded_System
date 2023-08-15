/*
 * UART_int.h
 *
 *  Created on: Sep 21, 2022
 *      Author: Shehab
 */

#ifndef UART_UART_INT_H_
#define UART_UART_INT_H_

void UART_vInt();

void UART_Send(u8 Copy_u8Data);

u8 UART_u8GetData();

void UART_vSendString(u8*Copy_u8Data);

u8 UART_vGetString(void);

void UART_vSend_ASC_String(u8*G_u8Data);

#endif /* UART_UART_INT_H_ */
