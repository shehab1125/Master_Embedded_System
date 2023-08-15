/* * UART_prg.c
 *
 *  Created on: Sep 21, 2022
 *      Author: Shehab
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "UART_int.h"
#include "UART_reg.h"

u8*G_u8Data;

void UART_vInt(){
	/*choose the UCSRC REG*/
	SET_BIT(UCSRC,7);
	/*UART MODE ->>>ASNCY*/
	CLR_BIT(UCSRC,6);
	/*non parity ->>>disable*/
	CLR_BIT(UCSRC,4);
	CLR_BIT(UCSRC,5);
	/*select 1 stop bit*/
	SET_BIT(UCSRC,3);
	/*data frame 8 bit*/
	SET_BIT(UCSRC,1);
	SET_BIT(UCSRC,2);
	CLR_BIT(UCSRB,2);
	/*select bond rate ->> 9600 b/sec  with atmega frequncy (16 MHZ)*/
	UBRRL = 51;
	/*enable reciver and transimeter(TX) and reciver (RX) */
	SET_BIT(UCSRB,4);
	SET_BIT(UCSRB,3);

}

void UART_Send(u8 Copy_u8Data){
	/*WAIT UNTIL THE EMPTY FLAG*/
	while(GET_BIT(UCSRA,5)==0);
	/*PUT YOUR DATA */
	UDR=Copy_u8Data;
}

u8 UART_u8GetData(){
	/*wait until recive flag is raised*/
	while(GET_BIT(UCSRA,7)==0);
	/*return data from UDR*/
	return UDR;
}

void UART_vSendString(u8 *Copy_u8Data){
	u8 L_Counter =0;
	while(Copy_u8Data[L_Counter]!=ADDRESS_NULL){
		UART_Send(Copy_u8Data[L_Counter]);
		L_Counter++;
	}
	UART_Send('\0');
}


u8 UART_vGetString(void) {
	u8 L_Counter = 0;
	u8 u8Data;

	u8Data = UART_u8GetData();
	while (u8Data != '\0') {
		L_Counter++;
		u8Data = UART_u8GetData();
	}
	return u8Data;
}

void UART_vSend_ASC_String(u8*L_u8Data){

	G_u8Data = L_u8Data;
	/*enable the tx interrupt*/
	SET_BIT(UCSRB,6);
	/*sending first char*/
	UDR=G_u8Data[0];

}


void __vector_15(void) __attribute__((signal));
void __vector_15(void){
	static u8 L_Counter =1;

	if(G_u8Data[L_Counter]!='\0'){

		UDR=G_u8Data[L_Counter];

		L_Counter++;
	}
	else if(G_u8Data[L_Counter]=='\0'){
		/*clear the tx interrupt*/
		CLR_BIT(UCSRB,6);
		UDR=G_u8Data[L_Counter];
		L_Counter =1;
	}
}

